#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Meaty 
{
	class MEATY_API Log
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

// Engine core log macros
#define MT_CORE_ERROR(...) ::Meaty::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MT_CORE_WARN(...)  ::Meaty::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MT_CORE_INFO(...)  ::Meaty::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MT_CORE_TRACE(...) ::Meaty::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client log macros
#define MT_CLIENT_ERROR(...) ::Meaty::Log::GetClientLogger()->error(__VA_ARGS__)
#define MT_CLIENT_WARN(...)  ::Meaty::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MT_CLIENT_INFO(...)  ::Meaty::Log::GetClientLogger()->info(__VA_ARGS__)
#define MT_CLIENT_TRACE(...) ::Meaty::Log::GetClientLogger()->trace(__VA_ARGS__)