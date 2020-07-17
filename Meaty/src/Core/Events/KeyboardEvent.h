#pragma once

#include "Event.h"

namespace Meaty
{
	class MEATY_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return keyCode; }

		EVENT_CLASS_CATEGORY(M_Keyborad | M_Input)

	protected:
		KeyEvent(int keyCode) : keyCode(keyCode) {}

		int keyCode;
	};

	class MEATY_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatcount)
			: KeyEvent(keycode), repeatCount(repeatcount) {}

		inline int GetRepeatCount() const { return repeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Key pressed event: " << keyCode << " (" << repeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int repeatCount;
	};

	class MEATY_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Key released event: " << keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}