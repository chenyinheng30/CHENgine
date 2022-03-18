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
    template<typename RE,typename AG>
    class CallBackBase
    {
    public:
        CallBackBase(){};
        virtual RE operator()(AG* e)=0;
    };
    template<typename F,typename FN>
    class ECallBack:public CallBackBase<void,Event>
    {
    protected:
        F __fn;
    public:
        ECallBack()=default;
        virtual void add_fn(const FN&& fn)=0;
    };
    
    template<typename EF>
    class ECallBackFactory
    {
    public:
        virtual EF* create_event_callback()=0;
    };

    template<typename EF>
    class DECallBackFactory:public ECallBackFactory<EF>
    {
    public:
        virtual EF* create_event_callback()override{
            return new EF();
        };
    };

    template<typename EVENT,typename FN>
    class Event_Fn:public ECallBack<FN,FN>
    {
        Event_Fn()=default;
    public:
        virtual void operator()(Event* e)override
        {
            FN fn = this->__fn;
            const EVENT* event = dynamic_cast<const EVENT*>(e);
            if(fn(event))
                e->handle();
        }
        virtual void add_fn(const FN&& fn)override
        {
            this->__fn = fn;
        }
        template<typename EF>
        friend EF* DECallBackFactory<EF>::create_event_callback();
    };

    template<template<typename,typename>typename EF=Event_Fn,\
    template<typename>typename CBF=DECallBackFactory>
    class EventDispatcher
    {
        std::unordered_map<std::type_index,\
        CallBackBase<void,Event>*> __event_map;
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
            if(__event_map.count(EVENT::get_static_type()))
            {
                dynamic_cast<EF<EVENT,FN>*>(__event_map[EVENT::get_static_type()])->add_fn(std::move(fn));
            }else{
                CBF<EF<EVENT,FN>> cbf;
                auto ef = cbf.create_event_callback();
                ef->add_fn(std::move(fn));
                __event_map[EVENT::get_static_type()] = ef;
            }
        };
        bool dispatch(Event* e)
        {
            if(e->is_handle())
                return true;
            auto menber=__event_map.find(e->get_event_type());
            if(menber!=__event_map.end())
            {
                (*(menber->second))(e);
                return true;
            }
            return false;
        };
    };
    template<typename EF>
    class EventHandleSListFactory:public ECallBackFactory<EF>
    {
    public:
        virtual EF* create_event_callback()override
        {
            static EF* ef=new EF();
            return ef;
        };
    };
    template<typename EVENT,typename FN>
    class EventHandleSList:public ECallBack<std::vector<FN>,FN>
    {
        EventHandleSList()=default;
    public:
        virtual void add_fn(const FN&& fn)override
        {
            this->__fn.push_back(std::move(fn));
        };
        virtual void operator()(Event* e)override
        {
            for(auto& fn:this->__fn)
            {
                if(fn(dynamic_cast<const EVENT*>(e)))
                {
                    e->handle();
                    break;
                }
            }
        };
        template<typename EF>
        friend EF* EventHandleSListFactory<EF>::create_event_callback();
    };
}