#pragma one

#ifdef __CE_IN_WINDOWS
extern chengine::App* chengine::creat_app();
int main()
{
    auto app = chengine::creat_app();
    app->run();
    delete app;
    return 0;
}
#elif defined(__CE_IN_LINUX)
#error "Not in GNU/Linux now"
#endif
