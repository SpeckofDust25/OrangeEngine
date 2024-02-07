#pragma once

#include "Core.h"
#include <spdlog/spdlog.h>
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Orange {
	class ORANGE_API_ Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core Log Macros
#define ORANGE_CORE_ERROR(...)			::Orange::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ORANGE_CORE_WARN(...)			::Orange::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ORANGE_CORE_INFO(...)			::Orange::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ORANGE_CORE_TRACE(...)			::Orange::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ORANGE_CORE_FATAL(...)			::Orange::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log Macros
#define ORANGE_ERROR(...)				::Orange::Log::GetClientLogger()->error(__VA_ARGS__)
#define ORANGE_WARN(...)				::Orange::Log::GetClientLogger()->warn(__VA_ARGS__)													
#define ORANGE_INFO(...)				::Orange::Log::GetClientLogger()->info(__VA_ARGS__)
#define ORANGE_TRACE(...)				::Orange::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ORANGE_FATAL(...)				::Orange::Log::GetClientLogger()->fatal(__VA_ARGS__)
