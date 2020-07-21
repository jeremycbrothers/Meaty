#pragma once

#ifdef MT_WINDOWS_PLATFORM
extern Meaty::Application* Meaty::CreateApplication();

int main(int argc, char** argv)
{
	Meaty::Log::Init();
	MT_CORE_WARN("Initialized Log!");
	MT_CLIENT_WARN("Initialized Client Log!");
	
	printf("Meaty Engine\n");
	auto app = Meaty::CreateApplication();
	app->Run();
	delete app;
}
#else
#error This application only suports Windows OS! 
#endif