#pragma one
/*do not include other file*/
#ifdef __CE_IN_WINDOWS
extern chengine::App* chengine::creat_app();
int main()
{

    chengine::Log::init();
    CE_CORE_WARN("Initialized Log!");

    CE_CORE_TRACE("Creating your app...");
    auto app = chengine::creat_app();
    CE_CORE_TRACE("Created your app!");
    app->run();
    delete app;
    return 0;
}
#elif defined(__CE_IN_LINUX)
#error "Not in GNU/Linux now"
#endif
