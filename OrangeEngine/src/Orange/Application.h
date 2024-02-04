#pragma once
#include "Core.h"

namespace Orange {
	class ORANGE_API_ Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	//To be defined in client
	Application* CreateApplication();
}
