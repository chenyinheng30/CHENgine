#include"chenge/core.h"
#include"chenge/debug.h"
#include<hash_map>
namespace chengine
{
    // enum class EventType
    // {
    //     None = 0,
    //     WindowClose,
    //     WindowResize,
    //     WindowFocus,
    //     WindowLostFocus,
    //     WindowMoved,
    //     AppTick,
    //     AppUpdate,
    //     AppRender,
    //     KeyPressed,
    //     KeyReleased,
    //     KeyTyped,
    //     MouseButtonPressed,
    //     MouseButtonReleased,
    //     MouseMoved,
    //     MouseScrolled
    // };
    #define __CE_EVENTCATEGORY_FLAG_SIZE 1
    struct EventCategory
    {
        bool EventCategoryApplication : __CE_EVENTCATEGORY_FLAG_SIZE,
        bool EventCategoryInput       : __CE_EVENTCATEGORY_FLAG_SIZE,
        bool EventCategoryKeyboard    : __CE_EVENTCATEGORY_FLAG_SIZE,
        bool EventCategoryMouse       : __CE_EVENTCATEGORY_FLAG_SIZE,
        bool EventCategoryMouseButton : __CE_EVENTCATEGORY_FLAG_SIZE
    };
#define CE_DEFINE_GET_STATIC_TYPE(eventType) static inline const std::type_info&  get_static_type()const{return typeid(eventType);}
#define CE_DEFINE_GET_EVENT_CATEGORY(...) virtual const EventCategory& get_category_flags()const override{static const EventCategory = {__VA_ARGS__};return EventCategory;}
#define 
    class Event:public Debug
    {
        bool __is_handle;
    public:
        Event():__is_handle(false){};
        virtual ~Event()=0;

        inline bool is_handle()const final{return __is_handle;}; 
        inline void handle()final{__is_handle = true;};
        virtual const std::type_info& get_event_type()const final{return typeid(*this);};
        CE_DEFINE_GET_STATIC_TYPE(Event)
        virtual const EventCategory& get_category_flags()const=0;
    };
    template<typename FN>
    class EventDispatcher
    {
        using std::unordered_map=EventFnMap;
        EventFnMap<std::type_info&,FN,std::type_info::hash_code> __event_map;
    public:
        template<typename EVENT>void push_back(const FN&& fn)
        {
            __event_map.insert(std::make_pair(EVENT::get_static_type(),fn));
        }
        FN get_function(Event& e)
        {
            auto fn=__event_map.find(e.get_event_type());
            if(fn!=__event_map.end())
            {
                return fn->second;
            }else{
                return nullptr;
            }
        }
    };
}