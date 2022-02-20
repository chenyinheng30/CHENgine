#include"log.h"
#include"spdlog/sinks/stdout_color_sinks.h"
namespace chengine
{
    std::shared_ptr<spdlog::logger> Log::__core_logger;
    std::shared_ptr<spdlog::logger> Log::__client_logger;

    void Log::init_client_logger()
    {
		__core_logger = spdlog::stdout_color_mt("CHENgnine");
		__core_logger->set_level(spdlog::level::trace);
        __core_logger->set_pattern("%^[%T] %n: %v%$");
    }
    void Log::init_core_logger()
    {
		__client_logger = spdlog::stdout_color_mt("your_APP");
		__client_logger->set_level(spdlog::level::trace);
        __client_logger->set_pattern("%^[%T] %n: %v%$");
    }
    void Log::init()
    {
        Log::init_core_logger();
        Log::init_client_logger();
    }
}