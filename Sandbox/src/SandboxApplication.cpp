#include "Engine.h"

class SandboxApplication : public Meaty::Application
{
public:
	SandboxApplication()
	{

	}

	~SandboxApplication()
	{

	}
};

Meaty::Application* Meaty::CreateApplication()
{
	return new SandboxApplication();
}