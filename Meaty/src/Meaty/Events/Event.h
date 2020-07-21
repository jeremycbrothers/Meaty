#pragma once

#include "mtpch.h"
#include "Meaty/Core/Core.h"

namespace Meaty
{
	enum class EventType
	{
		NONE = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategories
	{
		NONE = 0,
		M_Application = BIT(0),	
		M_Input		= BIT(1),
		M_Keyborad	= BIT(2),
		M_Mouse		= BIT(3),
		M_MouseButton	= BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
							    virtual EventType GetEventType() const override { return GetStaticType(); }\
							    virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class MEATY_API Event
	{
		friend class EventDispatcher;
	public:
		/** 
			These functions are so basic that they can probably just be defined here in the parent class.
			However, right now the design does not contain members do create said definitions. 
			Consder making them ;)
		*/
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategories category)
		{
			return GetCategoryFlags() & category;
		}

		bool IsHandeled = false;
	};

	/**
		TODO: Research and comment the syntax of this class as some things
			  do not appear intuitive.
	*/
	class MEATY_API EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& eventToDispatch) : currentEvent(eventToDispatch) {}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (currentEvent.GetEventType() == T::GetStaticType())
			{
				currentEvent.IsHandeled = func(*(T*)&currentEvent);
				return true;
			}
			return false;
		}

	private:
		Event& currentEvent;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}