#include"log.h"

namespace chengine
{

    std::vector<spdlog::sink_ptr> Log::__sinks;
    std::shared_ptr<spdlog::logger> Log::__core_logger;
    std::shared_ptr<spdlog::logger> Log::__client_logger;
    void Log::init_sinks()
    {
        static auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        static auto file_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>("logs/chengine.log", 1024*1024*5, 100);
        __sinks.push_back(console_sink);
        __sinks.push_back(file_sink);
    }
#define CONSOLE    0
#define FILE       1
    void Log::init_core_logger()
    {
		__core_logger = std::make_shared<spdlog::logger>("CHENgine", begin(__sinks), end(__sinks));
		__core_logger->set_level(CE_LEVEL_TRACE);
        __core_logger->set_pattern(__DEFAULT_LOG_FORMAT);
    }
    void Log::init_client_logger()
    {
		__client_logger = std::make_shared<spdlog::logger>("your_app", begin(__sinks), end(__sinks));
		__client_logger->set_level(CE_LEVEL_TRACE);
        __client_logger->set_pattern(__DEFAULT_LOG_FORMAT);
    }
    void Log::init()
    {
        Log::init_sinks();
        Log::init_core_logger();
        Log::init_client_logger();
    }
    void Log::set_stdout_level(chengine_log_level level)
    {
        __sinks[CONSOLE]->set_level(level);
    }
    void Log::set_your_pattern(const std::string &pattern)
    {
        __client_logger->set_pattern(pattern);
    }
#undef CONSOLE
#undef FILE
}