#pragma once
#include"chengine/core.h"
#include"chengine/log.h"
namespace chengine
{
    class App
    {
    
    public:
        App();
        virtual ~App();
        virtual void run();
    };
    App* creat_app();
}