#pragma once

#ifdef TD_Platform_Windows

extern Thunder::Application* Thunder::CreateApplication();

void main(int argc, char** argv)
{
	auto app = Thunder::CreateApplication();
	app->Run();
	delete app;
}

#endif // TD_Platform_Windows