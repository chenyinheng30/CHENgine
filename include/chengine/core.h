#pragma once
//编译设置
#include"chengineConfig.h"
#ifdef __CE_IN_WINDOWS
    #include<Windows.h>
#elif defined(__CE_IN_LINUX)
    #error "Not in GNU/Linux now"
#else

#endif

