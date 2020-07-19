#pragma once

#include "Core.h"
#include "Window.h"
#include "Meaty/LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

namespace Meaty
{
	class MEATY_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

	private:
		std::unique_ptr<Window>m_Window;
		bool running = true;
		LayerStack layerStack;

		bool OnWindowClose(WindowCloseEvent& e);
	};

	// Defined by client application
	Application* CreateApplication();
}

