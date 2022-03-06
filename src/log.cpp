#include"chengine/log.h"

namespace chengine
{

    std::map<std::string,spdlog::sink_ptr> Log::__sinks;
    std::shared_ptr<spdlog::logger> Log::__core_logger;
    std::shared_ptr<spdlog::logger> Log::__client_logger;
    void Log::init_sinks()
    {
        __sinks["console"] = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        __sinks["files"] = std::make_shared<spdlog::sinks::rotating_file_sink_mt>("logs/chengine.log", 1024*1024*5, 100);
    }
    void Log::init_core_logger()
    {

		__core_logger = std::make_shared<spdlog::logger>("CHENgine");
        for(auto& sink : __sinks)
        {
            __core_logger->sinks().push_back(sink.second);
        }
		__core_logger->set_level(CE_LEVEL_TRACE);
        __core_logger->set_pattern(__DEFAULT_LOG_FORMAT);
    }
    void Log::init_client_logger()
    {
		__client_logger = std::make_shared<spdlog::logger>("your_app");
        for(auto& sink : __sinks)
        {
            __core_logger->sinks().push_back(sink.second);
        }
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
        __sinks["console"]->set_level(level);
    }
    void Log::set_your_pattern(const std::string &pattern)
    {
        __client_logger->set_pattern(pattern);
    }
}