#pragma once

#include "Core.h"
#include "Window.h"
#include "Meaty/LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Meaty/ImGUI/ImGuiLayer.h"

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

		Window& GetWindow() const { return *m_Window; }

		inline static Application& Get() { return *instance; }
	private:
		ImGuiLayer* imGuiLayer;
		std::unique_ptr<Window>m_Window;
		bool running = true;
		LayerStack layerStack;

		static Application* instance;

		bool OnWindowClose(WindowCloseEvent& e);
	};

	// Defined by client application
	Application* CreateApplication();
}

