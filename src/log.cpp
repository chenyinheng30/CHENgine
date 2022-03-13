#include"chengine/log.h"

#define __CE_LEVEL_TRACE    spdlog::level::trace
#define __CE_LEVEL_DEBUG    spdlog::level::debug
#define __CE_LEVEL_INFO     spdlog::level::info
#define __CE_LEVEL_WARN     spdlog::level::warn
#define __CE_LEVEL_ERROR    spdlog::level::err
#define __CE_LEVEL_CRITICAL spdlog::level::critical
#define __CE_LEVEL_OFF      spdlog::level::off

/*default setting*/
#define __CE_DEFAULT_CORE_LOG_LEVEL     __CE_LEVEL_TRACE
#define __CE_DEFAULT_CLIENT_LOG_LEVEL   __CE_LEVEL_TRACE
#define __CE_DEFAULT_LOG_FORMAT    "[%D %T.%e]%^<%l>%n%$-%t: %v"
#define __CE_DEFAULT_LOG_FILES_SIZE     5
#define __CE_DEFAULT_LOG_FILES_COUNT    100
#define __CE_DEFAULT_LOG_FILES_DIR      "logs/"
#define __CE_DEFAULT_LOG_FILES_NAME     "chengine.log"
#define __CE_DEFAULT_YOUR_APP_NAME      "your_app"

#ifdef CE_USING_CORE_LOG_LEVEL
#define CE_CORE_LOG_LEVEL CE_USING_CORE_LOG_LEVEL
#else
#define CE_CORE_LOG_LEVEL __CE_DEFAULT_CORE_LOG_LEVEL
#endif

#ifdef CE_USING_CLIENT_LOG_LEVEL
#define CE_CLIENT_LOG_LEVEL CE_USING_CLIENT_LOG_LEVEL
#else
#define CE_CLIENT_LOG_LEVEL __CE_DEFAULT_CLIENT_LOG_LEVEL
#endif

#ifdef CE_USING_CLIENT_LOG_FORMAT 
#define CE_CLIENT_LOG_FORMAT CE_CLIENT_LOG_FORMAT
#else
#define CE_CLIENT_LOG_FORMAT __CE_DEFAULT_LOG_FORMAT
#endif

#ifdef CE_USING_LOG_FILES_SIZE
#define CE_LOG_FILES_SIZE CE_USING_LOG_FILES_SIZE
#else
#define CE_LOG_FILES_SIZE __CE_DEFAULT_LOG_FILES_SIZE
#endif

#ifdef CE_USING_LOG_FILES_COUNT
#define CE_LOG_FILES_COUNT CE_USING_LOG_FILES_COUNT
#else
#define CE_LOG_FILES_COUNT __CE_DEFAULT_LOG_FILES_COUNT
#endif

#ifdef CE_USING_LOG_FILES_DIR
#define CE_LOG_FILES_DIR CE_USING_LOG_FILES_DIR
#else
#define CE_LOG_FILES_DIR __CE_DEFAULT_LOG_FILES_DIR
#endif

/*depend on CE_LOG_FILES_DIR*/
#ifdef CE_USING_LOG_FILES_PATH
#define CE_LOG_FILES_PATH CE_LOG_FILES_DIR CE_USING_LOG_FILES_NAME
#else
#define CE_LOG_FILES_PATH CE_LOG_FILES_DIR __CE_DEFAULT_LOG_FILES_NAME
#endif

#ifdef CE_USING_YOUR_APP_NAME
#define CE_YOUR_APP_NAME CE_USING_YOUR_APP_NAME
#else
#define CE_YOUR_APP_NAME __CE_DEFAULT_YOUR_APP_NAME
#endif

namespace chengine
{

    std::map<std::string,spdlog::sink_ptr> Log::__sinks;
    std::shared_ptr<spdlog::logger> Log::__core_logger;
    std::shared_ptr<spdlog::logger> Log::__client_logger;
    inline void Log::init_sinks()
    {
        __sinks["console"] = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        const int log_files_size = CE_LOG_FILES_SIZE;
        const int log_files_count = CE_LOG_FILES_COUNT;
        __sinks["files"] = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(CE_LOG_FILES_PATH,1024*1024*log_files_size,log_files_count);
    }
    inline void Log::init_core_logger()
    {

		__core_logger = std::make_shared<spdlog::logger>("CHENgine");
        for(auto& sink : __sinks)
        {
    __core_logger->sinks().push_back(sink.second);
        }
		__core_logger->set_level(CE_CORE_LOG_LEVEL);
        __core_logger->set_pattern(__CE_DEFAULT_LOG_FORMAT);
    }
    inline void Log::init_client_logger()
    {
		__client_logger = std::make_shared<spdlog::logger>(CE_YOUR_APP_NAME);
        for(auto& sink : __sinks)
        {
    __client_logger->sinks().push_back(sink.second);
        }
		__client_logger->set_level(CE_CLIENT_LOG_LEVEL);
        __client_logger->set_pattern(CE_CLIENT_LOG_FORMAT);
    }
    void Log::init()
    {
        Log::init_sinks();
        Log::init_core_logger();
        Log::init_client_logger();
    }
}