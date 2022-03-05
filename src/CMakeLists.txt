add_library(App app.cpp)

target_include_directories(App PUBLIC ../include ../spdlog/include ../build)

add_library(LogSystem log.cpp)

target_include_directories(LogSystem PUBLIC ../include ../spdlog/include ../build)