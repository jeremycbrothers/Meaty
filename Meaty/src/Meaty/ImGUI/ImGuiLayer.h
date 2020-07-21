#pragma once

#include "Meaty/Core/Layer.h"
#include "Meaty/Events/ApplicationEvent.h"
#include "Meaty/Events/KeyboardEvent.h"
#include "Meaty/Events/MouseEvent.h"


namespace Meaty
{

	class ImGuiLayer : public Layer
	{
	public: 
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnImGuiRender() override;
		
		void Begin();
		void End();
	private:
		float time = 0.0f;
	};
}
