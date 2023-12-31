#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Thunder {
	
	class TD_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

} // namespace Thunder

// Core log macros
#define TD_CORE_TRACE(...)    ::Thunder::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TD_CORE_INFO(...)     ::Thunder::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TD_CORE_WARN(...)     ::Thunder::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TD_CORE_ERROR(...)    ::Thunder::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TD_CORE_CRITICAL(...) ::Thunder::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define TD_CORE_FATAL(...)    ::Thunder::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define TD_TRACE(...)         ::Thunder::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TD_INFO(...)          ::Thunder::Log::GetClientLogger()->info(__VA_ARGS__)
#define TD_WARN(...)          ::Thunder::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TD_ERROR(...)         ::Thunder::Log::GetClientLogger()->error(__VA_ARGS__)
#define TD_CRITICAL(...)      ::Thunder::Log::GetClientLogger()->critical(__VA_ARGS__)
#define TD_FATAL(...)         ::Thunder::Log::GetClientLogger()->fatal(__VA_ARGS__)
