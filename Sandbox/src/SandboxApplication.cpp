#include "Engine.h"

class ExampleLayer : public Meaty::Layer
{
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override
	{
		//MT_CLIENT_INFO("Example layer: Update");

		if (Meaty::Input::IsKeyPressed(MT_KEY_TAB))
			MT_CLIENT_TRACE("Tab key pressed.");
	}

	void OnEvent(Meaty::Event& e) override
	{
		//MT_CLIENT_INFO("{0}", e);
	}
};

class SandboxApplication : public Meaty::Application
{
public:
	SandboxApplication()
	{
		PushLayer(new ExampleLayer());
	}

	~SandboxApplication()
	{

	}
};

Meaty::Application* Meaty::CreateApplication()
{
	return new SandboxApplication();
}