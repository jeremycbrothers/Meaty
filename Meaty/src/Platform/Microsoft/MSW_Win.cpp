#include "mtpch.h"
#include "MSW_Win.h"
#include "Meaty/Events/ApplicationEvent.h"
#include "Meaty/Events/KeyboardEvent.h"
#include "Meaty/Events/MouseEvent.h"

namespace Meaty
{
	static bool initialized = false;

	static void GLFWErrorCallback(int Error, const char* Description)
	{
		MT_CORE_ERROR("GLFW Error ({0}): {1}", Error, Description);
	}

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

	unsigned int Meaty::MSW_Win::GetHeight() const
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
			MT_CORE_ASSERT(success, "Could not initialize GLFW");
			glfwSetErrorCallback(GLFWErrorCallback);
			initialized = true;
		}

		Window = glfwCreateWindow((int)WinData.Width, (int)WinData.Height, WinData.Title.c_str(), nullptr, nullptr);

		glfwMakeContextCurrent(Window);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		MT_CORE_ASSERT(status, "Failed to initialize GLAD");
		glfwSetWindowUserPointer(Window, &WinData);
		SetVSync(true);

		glfwSetWindowSizeCallback(Window, [](GLFWwindow* CallbackWindow, int CallbackWidth, int CallbackHeight)
		{
			WindowData& Data = *(WindowData*)glfwGetWindowUserPointer(CallbackWindow);
			WindowResizeEvent ResizeEvent(CallbackWidth, CallbackHeight);
			Data.CallbackFn(ResizeEvent);
			Data.Width = CallbackWidth;
			Data.Height = CallbackHeight;
		});

		glfwSetWindowCloseCallback(Window, [](GLFWwindow* CallbackWindow) 
		{
			WindowData& Data = *(WindowData*)glfwGetWindowUserPointer(CallbackWindow);
			WindowCloseEvent CloseEvent;
			Data.CallbackFn(CloseEvent);

		});

		glfwSetCursorPosCallback(Window, [](GLFWwindow* CallbackWindow, double XPos, double YPos) 
		{
			WindowData& Data = *(WindowData*)glfwGetWindowUserPointer(CallbackWindow);
			MouseMovedEvent MouseMoveEvent((float)XPos, (float)YPos);
			Data.CallbackFn(MouseMoveEvent);

		});

		glfwSetKeyCallback(Window, [](GLFWwindow* CallbackWindow, int Key, int ScanCode, int Action, int Mods)
		{
			WindowData& Data = *(WindowData*)glfwGetWindowUserPointer(CallbackWindow);
			// switch on key code
			switch (Action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent KeyPressedEvent(Key, 0);
					Data.CallbackFn(KeyPressedEvent);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent KeyReleasedEvent(Key);
					Data.CallbackFn(KeyReleasedEvent);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent KeyPressedEvent(Key, 1);
					Data.CallbackFn(KeyPressedEvent);
					break;
				}
			}
		});

		glfwSetMouseButtonCallback(Window, [](GLFWwindow* CallbackWindow, int Button, int Action, int Mods)
		{
			WindowData& Data = *(WindowData*)glfwGetWindowUserPointer(CallbackWindow);
			// switch on button
			switch (Action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent MouseButtonPressedEvent(Button);
					Data.CallbackFn(MouseButtonPressedEvent);
					break;
				}
				case GLFW_RELEASE:
				{	MouseButtonReleasedEvent MouseButtonReleasedEvent(Button);
					Data.CallbackFn(MouseButtonReleasedEvent);
					break;
				}
			}

		});

		glfwSetScrollCallback(Window, [](GLFWwindow* CallbackWindow, double XOffset, double YOffset) 
		{
			WindowData& Data = *(WindowData*)glfwGetWindowUserPointer(CallbackWindow);
			MouseScrolledEvent MouseScrolledEvent((float)XOffset, (float)YOffset);
			Data.CallbackFn(MouseScrolledEvent);

		});
	}

	void Meaty::MSW_Win::Shutdown()
	{
		glfwDestroyWindow(Window);
	}
}
