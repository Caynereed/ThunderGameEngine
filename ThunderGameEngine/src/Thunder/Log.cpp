#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Thunder {
	
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		// Set the pattern for the loggers
		spdlog::set_pattern("%^[%T] %n: %v%$");

		// Create the core logger
		s_CoreLogger = spdlog::stdout_color_mt("THUNDER");
		s_CoreLogger->set_level(spdlog::level::trace);

		// Create the client logger
		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}