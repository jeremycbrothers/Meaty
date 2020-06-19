#pragma once

#ifdef MT_WINDOWS_PLATFORM
extern Meaty::Application* Meaty::CreateApplication();

int main(int argc, char** argv)
{
	printf("Meaty Engine");
	auto app = Meaty::CreateApplication();
	app->Run();
	delete app;
}
#else
#error This application only suports Windows OS! 
#endif