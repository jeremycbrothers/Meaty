#pragma once

#include "Event.h"

namespace Meaty
{
	class KeyEvent : public Event
	{
	public:
		int GetKeyCode();
		virtual Event GetEventType();
		virtual char* GetName();
		virtual int GetCategoryFlag();

	protected:
		int keycode;
		KeyEvent(int kc) : keycode(kc) {}
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int kc, int rc)
			: keycode(kc), repeatcount(rc) {}

	private:
		int repeatcount;
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int kc)
			: keycode(kc) {}

	};
}