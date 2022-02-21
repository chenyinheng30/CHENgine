#pragma one
#include"core.h"

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