#pragma once

#include "Meaty/Core/Input.h"

namespace Meaty
{
	class MSW_Input : public Input
	{
	protected:
		virtual bool IsKeyPressed_Implementation(int keycode) override;
		virtual bool IsMouseButtonPressed_Implementation(int button)override;
		virtual float GetMouseX_Implementation() override;
		virtual float GetMouseY_Implementation() override;
		virtual std::pair<float, float> GetMousePos_Implementation() override;
	};
}
