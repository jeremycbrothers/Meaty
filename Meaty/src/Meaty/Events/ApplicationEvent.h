#pragma once

#include "Event.h"

namespace Meaty
{
	class MEATY_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: windowWidth(width), windowHeight(height) {}
	
		inline unsigned int GetWidth() const { return windowWidth; }
		inline unsigned int GetHeight() const { return windowHeight; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Window resize event: " << windowWidth << ", " << windowHeight;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(M_Application)

	private:
		unsigned int windowWidth, windowHeight;
	};

	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(M_Application)
	};
}