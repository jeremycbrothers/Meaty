#pragma once

#include "Event.h"

namespace Meaty
{
	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y)
			: mouseX(x), mouseY(y) {}

		inline float GetXPos() const { return mouseX; }
		inline float GeyYPos() const { return mouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse moved event: " << mouseX << ", " << mouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(M_Mouse | M_Input)
	private:
		float mouseX, mouseY;
	};

	class MEATY_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: XOffset(xOffset), YOffset(yOffset) {}

		inline float GetXOffset() const { return XOffset; }
		inline float GetYOffset() const { return YOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse scroll event: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(M_Mouse | M_Input)

	private:
		float XOffset, YOffset;
	};

	class MEATY_API MouseButtonEvent : public Event 
	{
	public:
		inline int GetMouseButton() const { return button; }

		EVENT_CLASS_CATEGORY(M_Mouse | M_Input)

	protected:
		MouseButtonEvent(int button) : button(button) {}

		int button;
	};

	class MEATY_API MouseButtonPressedEvent : public MouseButtonEvent 
	{
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse button pressed event: " << button;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(MouseButtonPressed)
	};

	class MEATY_API MouseButtonReleasedEvent : public MouseButtonEvent 
	{
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse button released event: " << button;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(MouseButtonReleased)
	};

}