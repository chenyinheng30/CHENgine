#pragma one
#include<memory>
#include"spdlog/spdlog.h"
namespace chengine
{
    class Log
    {
        static std::shared_ptr<spdlog::logger> __core_logger;
        static std::shared_ptr<spdlog::logger> __client_logger;
        static void init_core_logger();
    public:
        inline static std::shared_ptr<spdlog::logger>& get_core_logger(){return __core_logger;}
        inline static std::shared_ptr<spdlog::logger>& get_client_logger(){return __client_logger;}
        static void init_client_logger();
        static void init();
    };

}
// Log Macros
#define CE_CORE_TRACE(...)  ::chengine::Log::get_core_logger()->trace(__VA_ARGS__)
#define CE_CORE_INFO(...)   ::chengine::Log::get_core_logger()->info(__VA_ARGS__)
#define CE_CORE_WARN(...)   ::chengine::Log::get_core_logger()->warn(__VA_ARGS__)
#define CE_CORE_ERROR(...)  ::chengine::Log::get_core_logger()->error(__VA_ARGS__)
#define CE_CORE_FATAL(...)  ::chengine::Log::get_core_logger()->fatal(__VA_ARGS__)

#define CE_CLIENT_TRACE(...)    ::chengine::Log::get_client_logger()->trace(__VA_ARGS__)
#define CE_client_INFO(...)     ::chengine::Log::get_client_logger()->info(__VA_ARGS__)
#define CE_client_WARN(...)	    ::chengine::Log::get_client_logger()->warn(__VA_ARGS__)
#define CE_client_ERROR(...)    ::chengine::Log::get_client_logger()->error(__VA_ARGS__)
#define CE_client_FATAL(...)    ::chengine::Log::get_client_logger()->fatal(__VA_ARGS__)