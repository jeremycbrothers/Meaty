#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Meaty
{
	class MEATY_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

	};

	// Defined by client application
	Application* CreateApplication();
}

