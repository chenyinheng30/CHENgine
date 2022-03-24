#include"chengine/windows.h"
class WindowsWindow : public Window
{

public:
    WindowsWindow(const WindowProps& props);
    ~WindowsWindow()=default;

    void on_updata() override;
    void on_event() override;
    void set_event_callback(const std::function<const bool(Event*)> callback);
};