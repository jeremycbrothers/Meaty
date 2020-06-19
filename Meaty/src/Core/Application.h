#pragma once

#include "Core.h"

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

