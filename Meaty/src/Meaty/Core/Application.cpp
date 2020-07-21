#include "mtpch.h"
#include "Application.h"
#include "Input.h"
#include <GLFW/glfw3.h>

namespace Meaty
{
	Application* Application::instance = nullptr;

	Meaty::Application::Application()
	{
		MT_CORE_ASSERT(!application, "Application already exists");
		instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));

		imGuiLayer = new ImGuiLayer();
		PushOverlay(imGuiLayer);
	}

	Meaty::Application::~Application()
	{
	}

	void Meaty::Application::Run()
	{
		while (running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			
			for (Layer* layer : layerStack)
			{
				layer->OnUpdate();
			}

			imGuiLayer->Begin();
			for (Layer* layer : layerStack)
			{
				layer->OnImGuiRender();
			}
			imGuiLayer->End();

			// Input testing
			//float xpos = Input::GetMousePos().first;
			//float ypos = Input::GetMousePos().second;

			//MT_CORE_INFO("Mouse position x: {0}", xpos);
			//MT_CORE_INFO("Mouse position y: {0}", ypos);

			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher Dispatcher(e);
		Dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));
		
		MT_CORE_INFO("{0}", e);
	
		for (auto iterator = layerStack.end(); iterator != layerStack.begin();)
		{
			(*--iterator)->OnEvent(e);
			if (e.IsHandeled)
				break;
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		layerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		layerStack.PushOverlay(layer);
		layer->OnAttach();
	}
	 
	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		running = false;
		return true;
	}
}
