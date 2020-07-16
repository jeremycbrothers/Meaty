#pragma once

#include "../Core.h"

// Add these as pre compiled headers
#include <string>
#include <functional>

namespace Meaty
{
	enum class EventTypes
	{
		NONE = 0,
		keydown, keyup, keyheld,
		mousebutton_down, mousebutton_up,
		window_resize, window_minimize, window_maximize
	};

	enum EventCategories
	{
		NONE = 0,
		KEYBOARD_EVENT = BIT(1),
		MOUSE_EVENT   = BIT(2),
		WINDOW_EVENT  = BIT(3)
	};

	class MEATY_API Event
	{
		friend class EventDispatcher;
	public:
		/** 
			These functions are so basic that they can probably just be defined here in the parent class.
			However, right now the design does not contain members do create said definitions. 
			Consder making them ;)
		*/
		virtual Event GetEventType() const = 0;
		virtual char* GetName() const = 0;
		virtual int GetCategoryFlag() const = 0;
		virtual std::string ToString() { return GetName(); }

	private:
		bool IsHandeled = false;
	};

	class MEATY_API EventDispatcher
	{

	};
}