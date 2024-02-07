#pragma once

#ifdef ORANGE_PLATFORM_WINDOWS

extern Orange::Application* Orange::CreateApplication();

int main(int argc, char** argv) {
	Orange::Log::Init();
	
	ORANGE_CORE_INFO("Initialized Log!");
	ORANGE_INFO("Hello");

	auto app = Orange::CreateApplication();
	app->Run();
	delete app;
}
#endif