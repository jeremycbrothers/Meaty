#pragma once

#include "Core.h"

namespace Meaty
{
	class MEATY_API Input
	{
	public:
		static bool IsKeyPressed(int keycode) { return instance->IsKeyPressed_Implementation(keycode); }
		static bool IsMouseButtonPressed(int button) { return instance->IsMouseButtonPressed_Implementation(button); }
		static float GetMouseX() { return instance->GetMouseX_Implementation(); }
		static float GetMouseY() { return instance->GetMouseY_Implementation(); }
		static std::pair<float, float> GetMousePos() { return instance->GetMousePos_Implementation(); }
	
	protected:
		virtual bool IsKeyPressed_Implementation(int keycode) = 0;
		virtual bool IsMouseButtonPressed_Implementation(int button) = 0;
		virtual float GetMouseX_Implementation() = 0;
		virtual float GetMouseY_Implementation() = 0;
		virtual std::pair<float, float> GetMousePos_Implementation() = 0;

	private:
		static Input* instance;
	};
}
