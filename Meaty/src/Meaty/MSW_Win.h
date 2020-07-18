#pragma once

#include "Window.h"
#include "Meaty/Window.h"
#include <GLFW/glfw3.h>

namespace Meaty
{
	class MEATY_API MSW_Win : public Window
	{
	public:
		MSW_Win(const WindowProperties& properties);
		virtual ~MSW_Win();

		void OnUpdate() override;
		inline unsigned int GetWidth() const override;
		inline unsigned int GetHight() const override;
		inline void SetEventCallback(const EventCallbackFN& callbackFN) override;
		void SetVSync(bool enabled) override;
		bool IsVSyncEnabled() const override;

	private:
		virtual void Init(const WindowProperties properties);
		virtual void Shutdown();

	private:
		GLFWwindow* Window;
		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;
			EventCallbackFN CallbackFn;
		};

		WindowData WinData;
	};
}