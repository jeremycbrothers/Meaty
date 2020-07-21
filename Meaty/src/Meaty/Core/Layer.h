#pragma once

#include "Meaty/Core/Core.h"
#include "Meaty/Events/Event.h"

namespace Meaty
{
	class MEATY_API Layer
	{
	public:
		Layer(std::string name = "Layer");
		virtual ~Layer();

		virtual void OnAttach();
		virtual void OnDetach();
		virtual void OnUpdate();
		virtual void OnImGuiRender();
		virtual void OnEvent(Event& e);

	protected:
		std::string debugName;
	};
}
