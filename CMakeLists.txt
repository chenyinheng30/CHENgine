cmake_minimum_required(VERSION 3.22)
project(CHENGINE VERSION 0.0)

option(__CE_IN_WINDOWS "chenge in windows" ON)
option(__CE_DEBUG "in debug" ON)

#LogSystem configuration
option(CE_USING_CORE_LOG_LEVEL   "using your core log level!" OFF)
option(CE_USING_CLIENT_LOG_LEVEL "using your client log level!" OFF)
option(CE_USING_LOG_FORMAT       "using your log format!" OFF)
option(CE_USING_LOG_FILES_SIZE   "using your log files size!" OFF)
option(CE_USING_LOG_FILES_COUNT  "using your log files count!" OFF)
option(CE_USING_LOG_FILES_DIR    "using your log files dir!" OFF)
option(CE_USING_LOG_FILES_NAME   "using your log files name!" OFF)
option(CE_USING_YOUR_APP_NAME    "using your app name!" OFF)

configure_file(chengineConfig.h.in chengineConfig.h)

add_subdirectory(src chengine)

add_executable(sandbox "sandbox/sandbox.cpp")

target_link_libraries(sandbox PUBLIC App LogSystem)

target_include_directories(sandbox PUBLIC include spdlog/include build)