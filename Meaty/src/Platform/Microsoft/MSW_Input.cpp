#include "mtpch.h"
#include "MSW_Input.h"
#include "Meaty/Core/Application.h"
#include <GLFW/glfw3.h>

namespace Meaty
{
	Input* Input::instance = new MSW_Input();

	bool MSW_Input::IsKeyPressed_Implementation(int keycode)
	{
		int status = 0;
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		return glfwGetKey(window, keycode) == (GLFW_PRESS || GLFW_REPEAT);
	}

	bool MSW_Input::IsMouseButtonPressed_Implementation(int button)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		return glfwGetMouseButton(window, button) == GLFW_PRESS || GLFW_RELEASE;
	}

	float MSW_Input::GetMouseX_Implementation()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto [x, y] = GetMousePos_Implementation();
		return y;
	}
	float MSW_Input::GetMouseY_Implementation()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto [x, y] = GetMousePos_Implementation();
		return x;
	}
	std::pair<float, float> MSW_Input::GetMousePos_Implementation()
	{
		double xpos, ypos;
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		glfwGetCursorPos(window, &xpos, &ypos);
		return { (float)xpos, (float)ypos};
	}
}