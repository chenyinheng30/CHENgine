//实现默认的引擎应用
#include"chengine/app.h"
namespace chengine
{
    App::App(){}
    App::~App(){}
    void App::run()
    {
        while(true)
        {
            CE_CLIENT_WARN("default app running");
            Sleep(1000);
        }
    }
}