#include"chengine/include/events/event.h"
namespace chengine{
    class AppEvent:public Event
    {
    protected:
        CE_DEFINE_GET_EVENT_CATEGORY(EventCategoryApplication:1)
    };
	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: __width(width), __height(height) {}

		unsigned int get_width() const { return __width; }
		unsigned int get_height() const { return __height; }

        //to_string
        CE_DEBUG_DEFINE_TO_STRING(
            std::stringstream ss;
            ss << this->get_class_name() <<": " << __width << "x" << __height;
            return ss.str();
        );
        // 确定事件类型
        CE_DEFINE_GET_STATIC_TYPE(WindowResizeEvent);
        CE_DEBUG_DEFINE_GET_CLASS_NAME(WindowResizeEvent);
	private:
		unsigned int __width, __height;
	};

	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;

        CE_DEBUG_DEFINE_TO_STRING(
            std::stringstream ss;
            ss << this->get_class_name() <<"get";
            return ss.str();
        );

        // 确定事件类型
        CE_DEFINE_GET_STATIC_TYPE(WindowCloseEvent);
        CE_DEBUG_DEFINE_GET_CLASS_NAME(WindowCloseEvent);
	};

	class AppTickEvent : public Event
	{
	public:
		AppTickEvent() = default;
        CE_DEBUG_DEFINE_TO_STRING(
            std::stringstream ss;
            ss << this->get_class_name() <<"get";
            return ss.str();
        );
        // 确定事件类型
        CE_DEFINE_GET_STATIC_TYPE(AppTickEvent);
        CE_DEBUG_DEFINE_GET_CLASS_NAME(AppTickEvent);
	};

	class AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() = default;
        CE_DEBUG_DEFINE_TO_STRING(
            std::stringstream ss;
            ss << this->get_class_name() <<"get";
            return ss.str();
        );
        // 确定事件类型
        CE_DEFINE_GET_STATIC_TYPE(AppUpdateEvent);
        CE_DEBUG_DEFINE_GET_CLASS_NAME(AppUpdateEvent);
	};

	class AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() = default;
        CE_DEBUG_DEFINE_TO_STRING(
            std::stringstream ss;
            ss << this->get_class_name() <<"get";
            return ss.str();
        );
        // 确定事件类型
        CE_DEFINE_GET_STATIC_TYPE(AppRenderEvent);
        CE_DEBUG_DEFINE_GET_CLASS_NAME(AppRenderEvent);
	};
}
