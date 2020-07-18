#include "mtpch.h"
#include "MSW_Win.h"

namespace Meaty
{
	static bool initialized = false;

	Window* Window::Create(const WindowProperties& props)
	{
		return new MSW_Win(props);
	}

	Meaty::MSW_Win::MSW_Win(const WindowProperties& properties)
	{
		Init(properties);
	}

	Meaty::MSW_Win::~MSW_Win()
	{
		Shutdown();
	}

	void Meaty::MSW_Win::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(Window);
	}

	unsigned int Meaty::MSW_Win::GetWidth() const
	{
		return WinData.Width;
	}

	unsigned int Meaty::MSW_Win::GetHight() const
	{
		return WinData.Height;
	}

	void Meaty::MSW_Win::SetEventCallback(const EventCallbackFN& callbackFN)
	{
		WinData.CallbackFn = callbackFN;
	}

	void Meaty::MSW_Win::SetVSync(bool enabled)
	{
		if (enabled)
		{
			glfwSwapInterval(0);
		}
		else
		{
			glfwSwapInterval(1);
		}
		WinData.VSync = enabled;
	}

	bool Meaty::MSW_Win::IsVSyncEnabled() const
	{
		return WinData.VSync;
	}

	void Meaty::MSW_Win::Init(const WindowProperties properties)
	{
		WinData.Title = properties.Title;
		WinData.Width = properties.Width;
		WinData.Height = properties.Height;

		MT_CORE_INFO("Creating window {0} ({1}, {2})", properties.Title, properties.Width, properties.Height);

		if (!initialized)
		{
			int success = glfwInit();
			MT_CORE_ASSERT(success, "Could not initialize GLFW")
			initialized = true;
		}

		Window = glfwCreateWindow((int)WinData.Width, (int)WinData.Height, WinData.Title.c_str(), nullptr, nullptr);

		glfwMakeContextCurrent(Window);
		glfwSetWindowUserPointer(Window, &WinData);
		SetVSync(true);
	}

	void Meaty::MSW_Win::Shutdown()
	{
		glfwDestroyWindow(Window);
	}
}
