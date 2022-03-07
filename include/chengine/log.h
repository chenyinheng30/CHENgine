#pragma once
#include<map>
#include<vector>
#include<memory>
#include"chengine/core.h"
#include"spdlog/spdlog.h"
#include"spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/rotating_file_sink.h"

typedef spdlog::level::level_enum chengine_log_level;
namespace chengine
{
    class Log
    {
        
        static std::map<std::string,spdlog::sink_ptr> __sinks;
        static std::shared_ptr<spdlog::logger> __core_logger;
        static std::shared_ptr<spdlog::logger> __client_logger;
        static void init_sinks();
        static void init_core_logger();
        static void init_client_logger();
    public:
        inline static std::shared_ptr<spdlog::logger>& get_core_logger(){return __core_logger;}
        inline static std::shared_ptr<spdlog::logger>& get_client_logger(){return __client_logger;}
        static void init();
    };
}
// Log Macros
#ifdef __CE_DEBUG
#define CE_CORE_TRACE(...)  ::chengine::Log::get_core_logger()->trace(__VA_ARGS__)
#define CE_CORE_INFO(...)   ::chengine::Log::get_core_logger()->info(__VA_ARGS__)
#define CE_CORE_WARN(...)   ::chengine::Log::get_core_logger()->warn(__VA_ARGS__)
#define CE_CORE_ERROR(...)  ::chengine::Log::get_core_logger()->error(__VA_ARGS__)
#define CE_CORE_FATAL(...)  ::chengine::Log::get_core_logger()->fatal(__VA_ARGS__)
#else
#define CE_CORE_TRACE(...)  
#define CE_CORE_INFO(...)   
#define CE_CORE_WARN(...)   
#define CE_CORE_ERROR(...)  
#define CE_CORE_FATAL(...)  
#endif

#define CE_CLIENT_TRACE(...)    ::chengine::Log::get_client_logger()->trace(__VA_ARGS__)
#define CE_CLIENT_INFO(...)     ::chengine::Log::get_client_logger()->info(__VA_ARGS__)
#define CE_CLIENT_WARN(...)	    ::chengine::Log::get_client_logger()->warn(__VA_ARGS__)
#define CE_CLIENT_ERROR(...)    ::chengine::Log::get_client_logger()->error(__VA_ARGS__)
#define CE_CLIENT_FATAL(...)    ::chengine::Log::get_client_logger()->fatal(__VA_ARGS__)