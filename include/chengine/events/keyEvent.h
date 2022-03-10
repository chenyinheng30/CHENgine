#include"chengine/include/events/event.h"

unsing KeyCode=char;

namespace chengine {

	class KeyEvent : public Event
	{
	public:
		KeyCode get_key_code() const { return __keyCode; }

        // 确定事件所属的类
		CE_DEFINE_GET_EVENT_CATEGORY(EventCategoryKeyboard:1,EventCategoryInput:1);
	protected:
		KeyEvent(const KeyCode keycode)
			: __keyCode(keycode) {}

		KeyCode __keyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(const KeyCode keycode, const uint16_t repeatCount)
			: KeyEvent(keycode), __repeatCount(repeatCount) {}

		uint16_t get_repeat_count() const { return __repeatCount; }

        //事件转字符串
        CE_DEBUG_DEFINE_TO_STRING(
            std::stringstream ss;
            ss << this->get_class_name() <<": " << __keyCode << " (" << __repeatCount << " repeats)";
            return ss.str();
        );
        // 确定事件类型
        CE_DEFINE_GET_STATIC_TYPE(KeyPressedEvent);
        CE_DEBUG_DEFINE_GET_CLASS_NAME(KeyPressedEvent);
	private:
		uint16_t __repeatCount;
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(const KeyCode keycode)
			: KeyEvent(keycode) {}
        
        //事件转字符串
        CE_DEBUG_DEFINE_TO_STRING(
            std::stringstream ss;
            ss << this->get_class_name() <<": " << __keyCode;
            return ss.str();
        );
		// 确定事件类型
        CE_DEFINE_GET_STATIC_TYPE(KeyReleasedEvent);
        CE_DEBUG_DEFINE_GET_CLASS_NAME(KeyReleasedEvent);
	};

	class KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(const KeyCode keycode)
			: KeyEvent(keycode) {}

        //事件转字符串
        CE_DEBUG_DEFINE_TO_STRING(
            std::stringstream ss;
            ss << this->get_class_name() <<": " << __keyCode;
            return ss.str();
        );
		// 确定事件类型
        CE_DEFINE_GET_STATIC_TYPE(KeyTypedEvent);
        CE_DEBUG_DEFINE_GET_CLASS_NAME(KeyTypedEvent);
	};
}