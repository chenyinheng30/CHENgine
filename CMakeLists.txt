cmake_minimum_required(VERSION 3.22)
project(CHENGINE VERSION 0.0)

configure_file(chengineConfig.h.in chengineConfig.h)

add_subdirectory(src chengine)

add_executable(sandbox "sandbox/sandbox.cpp")

target_link_libraries(sandbox PUBLIC App LogSystem)

target_include_directories(sandbox PUBLIC include spdlog/include)