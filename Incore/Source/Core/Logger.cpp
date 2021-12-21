#include "ipch.h"
#include "Logger.h"

namespace Incore
{
	namespace Core
	{
		Reference<spdlog::logger> Logger::s_incorelogger;
		Reference<spdlog::logger> Logger::s_runtimelogger;

		void Logger::Init()
		{
			std::vector<spdlog::sink_ptr> logSinks;
			logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
			logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("Incore.log", true));

			logSinks[0]->set_pattern("%^[%T] %n: %v%$");
			logSinks[1]->set_pattern("[%T] [%l] %n: %v");

			s_incorelogger = std::make_shared<spdlog::logger>("INCORE", begin(logSinks), end(logSinks));
			spdlog::register_logger(s_incorelogger);
			s_incorelogger->set_level(spdlog::level::trace);
			s_incorelogger->flush_on(spdlog::level::trace);

			s_runtimelogger = std::make_shared<spdlog::logger>("RUNTIME", begin(logSinks), end(logSinks));
			spdlog::register_logger(s_runtimelogger);
			s_runtimelogger->set_level(spdlog::level::trace);
			s_runtimelogger->flush_on(spdlog::level::trace);
		}
	}
}