#pragma once

#include "Core.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace Incore
{
	namespace Core
	{
		class Logger
		{
		public:

			/* Initializes the logger */
			static void Init();

			/* Returns the incore/engine logger */
			inline static Reference<spdlog::logger>& GetIncoreLogger() { return s_incorelogger; }

			/* Returns the runtime logger */
			inline static Reference<spdlog::logger>& GetRuntimeLogger() { return s_runtimelogger; }

		private:

			static Reference<spdlog::logger> s_incorelogger;
			static Reference<spdlog::logger> s_runtimelogger;

		};
	}
}

#if defined (ENABLE_LOGGING)
	#define INCORE_TRACE(...)		::Incore::Core::Logger::GetIncoreLogger()->trace(__VA_ARGS__)
	#define INCORE_INFO(...)		::Incore::Core::Logger::GetIncoreLogger()->info(__VA_ARGS__)
	#define INCORE_WARN(...)		::Incore::Core::Logger::GetIncoreLogger()->warn(__VA_ARGS__)
	#define INCORE_ERROR(...)		::Incore::Core::Logger::GetIncoreLogger()->error(__VA_ARGS__)
	#define INCORE_CRITICAL(...)	::Incore::Core::Logger::GetIncoreLogger()->critical(__VA_ARGS__)

	#define RUNTIME_TRACE(...)		::Incore::Core::Logger::GetRuntimeLogger()->trace(__VA_ARGS__)
	#define RUNTIME_INFO(...)		::Incore::Core::Logger::GetRuntimeLogger()->info(__VA_ARGS__)
	#define RUNTIME_WARN(...)		::Incore::Core::Logger::GetRuntimeLogger()->warn(__VA_ARGS__)
	#define RUNTIME_ERROR(...)		::Incore::Core::Logger::GetRuntimeLogger()->error(__VA_ARGS__)
	#define RUNTIME_CRITICAL(...)	::Incore::Core::Logger::GetRuntimeLogger()->critical(__VA_ARGS__)
#else
	#define INCORE_TRACE(...)
	#define INCORE_INFO(...)
	#define INCORE_WARN(...)
	#define INCORE_ERROR(...)
	#define INCORE_CRITICAL(...)

	#define RUNTIME_TRACE(...)
	#define RUNTIME_INFO(...)
	#define RUNTIME_WARN(...)
	#define RUNTIME_ERROR(...)
	#define RUNTIME_CRITICAL(...)
#endif

#if defined (ENABLE_ASSERTS) 
	#if defined (_MSC_VER)
		#define INCORE_ASSERT(x, ...) { if(!(x)) { INCORE_CRITICAL("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
		#define RUNTIME_ASSERT(x, ...) { if(!(x)) { RUNTIME_CRITICAL("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#else
		#define INCORE_ASSERT(x, ...) { if (!(x)) { INCORE_CRITICAL("Assertion Failed: {0}", __VA_ARGS__); __builtin_trap(); }
		#define RUNTIME_ASSERT(x, ...) { if (!(x)) { RUNTIME_CRITICAL("Assertion Failed: {0}", __VA_ARGS__); __builtin_trap(); }
	#endif
#else
	#define INCORE_ASSERT(x, ...)
	#define RUNTIME_ASSERT(x, ...)
#endif