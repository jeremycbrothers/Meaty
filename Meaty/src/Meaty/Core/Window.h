#pragma once

#include "mtpch.h"

#include "Core.h"
#include "Meaty/Events/Event.h"

namespace Meaty
{
	struct WindowProperties
	{
		std::string Title;
		unsigned int Width, Height;

		WindowProperties(std::string title = "Meaty Engine", unsigned int width = 1280, unsigned int height = 720)
			: Title(title), Width(width), Height(height) {}
	};

	class MEATY_API Window
	{
	public:
		using EventCallbackFN = std::function<void(Event&)>;
		virtual ~Window() {};

		virtual void OnUpdate() = 0;
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;
		virtual void* GetNativeWindow() const = 0;
		virtual void SetEventCallback(const EventCallbackFN& callbackFN) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSyncEnabled() const = 0;

		static Window* Create(const WindowProperties& wp = WindowProperties());
	};
}