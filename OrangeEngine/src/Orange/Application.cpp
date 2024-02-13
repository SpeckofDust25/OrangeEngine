#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"
#include <iostream>


namespace Orange {

	Application::Application() { 

	}

	Application::~Application() {

	}
	
	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		ORANGE_TRACE(e.ToString());
	}
}