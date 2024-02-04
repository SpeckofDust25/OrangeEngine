#pragma once

#ifdef ORANGE_PLATFORM_WINDOWS

extern Orange::Application* Orange::CreateApplication();

int main(int argc, char** argv) {
	auto app = Orange::CreateApplication();
	app->Run();
	delete app;
}
#endif