#pragma once
#include"chengine/core.h"
#include"chengine/debug.h"
#include <unordered_map>
#include<vector>
#include<typeindex>
#include<functional>
#include<any>
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

    class EventDispatcher
    {
        class Fn_Base
        {
        protected:
            std::any __fn;
        public:
            Fn_Base(const std::any& fn):__fn(fn){};
            virtual const bool operator()(const Event* e)=0;
        };
        std::unordered_map<std::type_index,Fn_Base*> __event_map;
        template<typename EVENT,typename FN>
        class Event_Fn:public Fn_Base
        {
        public:
            Event_Fn(const FN& fn):Fn_Base(fn){};
            virtual const bool operator()(const Event* e)override
            {
                return std::any_cast<FN>(this->__fn)(dynamic_cast<const EVENT*>(e));
            }
        };
    public:
        EventDispatcher()=default;
        ~EventDispatcher()
        {
            for(auto& it:__event_map)
            {
                delete it.second;
            }
        };
        /* 传入一个临时的函对象的右值引用 */
        template<typename EVENT,typename FN>void push_back(FN&& fn)
        {
            /*将添加一个断言，判断EVENT是否是Event的子类 */
            __event_map[EVENT::get_static_type()] = \
            new Event_Fn<EVENT,FN>(std::move(fn));
        };
        bool dispatch(Event* e)
        {
            auto menber=__event_map.find(e->get_event_type());
            if(menber!=__event_map.end())
            {
                if((*(menber->second))(e))
                    e->handle();
                return true;
            }
            return false;
        };
    };

    template<typename EVENT,typename FN>
    class EventHandleSList
    {
        std::vector<FN> __handle_list;
    public:
        void push_back(const FN&& fn)
        {
            __handle_list.push_back(fn);
        };
        void operator()(EVENT* e)
        {
            for(auto& fn:__handle_list)
            {
                if(fn(e))
                    e->handle();
            }
        };
    };

}