#pragma once

#include "Core.h"

namespace Thunder {

	class TD_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
} // namespace Thunder