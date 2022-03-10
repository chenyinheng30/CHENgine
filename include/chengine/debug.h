#pragma once
#include<string>

#include"chengine/core.h"
namespace chengine
{
#ifdef __CE_DEBUG
    #define CE_FOR_DEBUG(...) __VA_ARGS__
#else
    #define CE_FOR_DEBUG(...)
#endif
    class Debug
    {
    public:
            Debug() = default;
            ~Debug() = default;
            CE_FOR_DEBUG
            (
                virtual std::string get_class_name()const=0;
            )
    };
}
#define CE_DEFINE_GET_CLASS_NAME(class) CE_FOR_DEBUG(virtual std::string get_class_name()const{return #class;};)