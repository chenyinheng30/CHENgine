#pragma once
#include<memory>
#include"chengine/core.h"
#include"spdlog/spdlog.h"
#include"spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/rotating_file_sink.h"

#define CE_LEVEL_TRACE    spdlog::level::trace
#define CE_LEVEL_DEBUG    spdlog::level::debug
#define CE_LEVEL_INFO     spdlog::level::info
#define CE_LEVEL_WARN     spdlog::level::warn
#define CE_LEVEL_ERROR    spdlog::level::err
#define CE_LEVEL_CRITICAL spdlog::level::critical
#define CE_LEVEL_OFF      spdlog::level::off
typedef spdlog::level::level_enum chengine_log_level;
namespace chengine
{

    class Log
    {
        
        static std::vector<spdlog::sink_ptr> __sinks;
        static std::shared_ptr<spdlog::logger> __core_logger;
        static std::shared_ptr<spdlog::logger> __client_logger;
        static void init_sinks();
        static void init_core_logger();
        static void init_client_logger();
    public:
        inline static std::shared_ptr<spdlog::logger>& get_core_logger(){return __core_logger;}
        inline static std::shared_ptr<spdlog::logger>& get_client_logger(){return __client_logger;}
        static void init();
        static void set_stdout_level(chengine_log_level level);
        static void set_your_pattern(const std::string& pattern);
        static void set_your_name(const std::string& name);
    };
}
// Log Macros
#ifndef __DEFAULT_LOG_FORMAT
#define __DEFAULT_LOG_FORMAT "[%D %T.%e]%^<%l>%n%$-%t: %v"
#endif
#ifdef __CE_DEBUG
#define CE_CORE_TRACE(...)  ::chengine::Log::get_core_logger()->trace(__VA_ARGS__)
#define CE_CORE_INFO(...)   ::chengine::Log::get_core_logger()->info(__VA_ARGS__)
#define CE_CORE_WARN(...)   ::chengine::Log::get_core_logger()->warn(__VA_ARGS__)
#define CE_CORE_ERROR(...)  ::chengine::Log::get_core_logger()->error(__VA_ARGS__)
#define CE_CORE_FATAL(...)  ::chengine::Log::get_core_logger()->fatal(__VA_ARGS__)
#elif
#define CE_CORE_TRACE(...)  
#define CE_CORE_INFO(...)   
#define CE_CORE_WARN(...)   
#define CE_CORE_ERROR(...)  
#define CE_CORE_FATAL(...)  
#endif

#define CE_CLIENT_TRACE(...)    ::chengine::Log::get_client_logger()->trace(__VA_ARGS__)
#define CE_client_INFO(...)     ::chengine::Log::get_client_logger()->info(__VA_ARGS__)
#define CE_client_WARN(...)	    ::chengine::Log::get_client_logger()->warn(__VA_ARGS__)
#define CE_client_ERROR(...)    ::chengine::Log::get_client_logger()->error(__VA_ARGS__)
#define CE_client_FATAL(...)    ::chengine::Log::get_client_logger()->fatal(__VA_ARGS__)