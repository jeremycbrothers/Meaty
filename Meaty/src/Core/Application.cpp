#include "mtpch.h"

#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Meaty
{
	Meaty::Application::Application()
	{
	}

	Meaty::Application::~Application()
	{
	}

	void Meaty::Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		MT_CORE_TRACE(e);
		MT_CLIENT_TRACE(e);

		while (true);
	}
}
