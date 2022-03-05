cmake_minimum_required(VERSION 3.22)
project(CHENGINE VERSION 0.0)

option(__CE_IN_WINDOWS "chenge in windows" ON)
option(__CE_DEBUG "in debug" ON)

configure_file(chengineConfig.h.in chengineConfig.h)

add_subdirectory(src chengine)

add_executable(sandbox "sandbox/sandbox.cpp")

target_link_libraries(sandbox PUBLIC App LogSystem)

target_include_directories(sandbox PUBLIC include spdlog/include build)