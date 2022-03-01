//实现默认的引擎应用
#include"app.h"
namespace chengine
{
    App::App(){}
    App::~App(){}
    void App::run()
    {
        while(true)
        {
            CE_CORE_WARN("default app running");
            Sleep(1000);
        }
    }
}