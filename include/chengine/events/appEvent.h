#include"chengine/events/event.h"
namespace chengine{
    class AppEvent:public Event
    {
    protected:
        CE_DEFINE_GET_EVENT_CATEGORY(EventCategoryApplication:1)
    };
	class WindowResizeEvent : public AppEvent
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

	class WindowMovedEvent : public AppEvent
	{
	public:
		WindowMovedEvent(unsigned int x, unsigned int y)
			: x(x), y(y) {}

		unsigned int get_width() const { return x; }
		unsigned int get_height() const { return y; }

        //to_string
        CE_DEBUG_DEFINE_TO_STRING(
            std::stringstream ss;
            ss << this->get_class_name() <<": (" << x << "," << y << ")";
            return ss.str();
        );
        // 确定事件类型
        CE_DEFINE_GET_STATIC_TYPE(WindowMovedEvent);
        CE_DEBUG_DEFINE_GET_CLASS_NAME(WindowMovedEvent);
	private:
		unsigned int x, y;
	};

	class WindowCloseEvent : public AppEvent
	{
	public:
		WindowCloseEvent() = default;

        CE_DEBUG_DEFINE_TO_STRING(
            std::stringstream ss;
            ss << this->get_class_name() <<" get";
            return ss.str();
        );

        // 确定事件类型
        CE_DEFINE_GET_STATIC_TYPE(WindowCloseEvent);
        CE_DEBUG_DEFINE_GET_CLASS_NAME(WindowCloseEvent);
	};

	class WindowFocusEvent : public AppEvent
	{
	public:
		WindowFocusEvent() = default;

        CE_DEBUG_DEFINE_TO_STRING(
            std::stringstream ss;
            ss << this->get_class_name() <<" get";
            return ss.str();
        );

        // 确定事件类型
        CE_DEFINE_GET_STATIC_TYPE(WindowFocusEvent);
        CE_DEBUG_DEFINE_GET_CLASS_NAME(WindowFocusEvent);
	};

	class WindowLostFocusEvent : public AppEvent
	{
	public:
		WindowLostFocusEvent() = default;

        CE_DEBUG_DEFINE_TO_STRING(
            std::stringstream ss;
            ss << this->get_class_name() <<" get";
            return ss.str();
        );

        // 确定事件类型
        CE_DEFINE_GET_STATIC_TYPE(WindowLostFocusEvent);
        CE_DEBUG_DEFINE_GET_CLASS_NAME(WindowLostFocusEvent);
	};

	class AppTickEvent : public AppEvent
	{
	public:
		AppTickEvent() = default;
        CE_DEBUG_DEFINE_TO_STRING(
            std::stringstream ss;
            ss << this->get_class_name() <<" get";
            return ss.str();
        );
        // 确定事件类型
        CE_DEFINE_GET_STATIC_TYPE(AppTickEvent);
        CE_DEBUG_DEFINE_GET_CLASS_NAME(AppTickEvent);
	};

	class AppUpdateEvent : public AppEvent
	{
	public:
		AppUpdateEvent() = default;
        CE_DEBUG_DEFINE_TO_STRING(
            std::stringstream ss;
            ss << this->get_class_name() <<" get";
            return ss.str();
        );
        // 确定事件类型
        CE_DEFINE_GET_STATIC_TYPE(AppUpdateEvent);
        CE_DEBUG_DEFINE_GET_CLASS_NAME(AppUpdateEvent);
	};

	class AppRenderEvent : public AppEvent
	{
	public:
		AppRenderEvent() = default;
        CE_DEBUG_DEFINE_TO_STRING(
            std::stringstream ss;
            ss << this->get_class_name() <<" get";
            return ss.str();
        );
        // 确定事件类型
        CE_DEFINE_GET_STATIC_TYPE(AppRenderEvent);
        CE_DEBUG_DEFINE_GET_CLASS_NAME(AppRenderEvent);
	};
}
