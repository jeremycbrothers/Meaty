#include "mtpch.h"
#include "Application.h"
#include <GLFW/glfw3.h>

namespace Meaty
{
	Meaty::Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
	}

	Meaty::Application::~Application()
	{
	}

	void Meaty::Application::Run()
	{
		while (running)
		{
			//glClearColor(1, 0, 1, 1);
			//glClear(GL_COLOR_BUFFER_BIT);
			
			for (Layer* layer : layerStack)
			{
				layer->OnUpdate();
			}

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
	}

	void Application::PushOverlay(Layer* layer)
	{
		layerStack.PushOverlay(layer);
	}
	 
	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		running = false;
		return true;
	}
}
