#pragma once
#include"chengine/core.h"
#include"chengine/debug.h"
#include <unordered_map>
#include<typeindex>
namespace chengine
{
    #define __CE_EVENTCATEGORY_FLAG_SIZE 1
    struct EventCategory
    {
        bool EventCategoryApplication : __CE_EVENTCATEGORY_FLAG_SIZE;
        bool EventCategoryInput       : __CE_EVENTCATEGORY_FLAG_SIZE;
        bool EventCategoryKeyboard    : __CE_EVENTCATEGORY_FLAG_SIZE;
        bool EventCategoryMouse       : __CE_EVENTCATEGORY_FLAG_SIZE;
        bool EventCategoryMouseButton : __CE_EVENTCATEGORY_FLAG_SIZE;
    };
#define CE_DEFINE_GET_STATIC_TYPE(eventType) static inline const std::type_index&  get_static_type(){static const std::type_index event_type=std::type_index(typeid(eventType));return event_type;}
#define CE_DEFINE_GET_EVENT_CATEGORY(...) virtual const EventCategory& get_category_flags()const override{static const EventCategory category= {__VA_ARGS__};return category;}
    class Event:public Debug
    {
        bool __is_handle;
    public:
        Event():__is_handle(false){};
        virtual ~Event()=0;

        inline virtual bool is_handle()const final{return __is_handle;}; 
        inline virtual void handle()final{__is_handle = true;};
        virtual const std::type_index& get_event_type()const final{static const std::type_index this_type=std::type_index(typeid(*this));return this_type;};
        CE_DEFINE_GET_STATIC_TYPE(Event);
        virtual const EventCategory& get_category_flags()const=0;
    };

    template<typename FN>
    class EventDispatcher
    {
        std::unordered_map<std::type_index,FN> __event_map;
    public:
        template<typename EVENT>void push_back(const FN&& fn)
        {
            __event_map[EVENT::get_static_type()] = fn;
        };
        bool dispatch(Event* e)
        {
            auto menber=__event_map.find(e->get_event_type());
            if(menber!=__event_map.end())
            {
                menber->second(e);
                return true;
            }
            return false;
        };
    };
}