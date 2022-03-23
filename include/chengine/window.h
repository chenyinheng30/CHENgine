#pragma once
/*开始构建window的抽象*/

struct WindowProps
{
    unsigned int width, height;
    std::string title;

    WindowProps(unsigned int width = 1280, \
    unsigned int height = 720, \
    std::string title = "Chengine Window")
        : width(width), height(height), title(title) {};
};


class Window
{
public:
    virtual ~Window() = default;

    virtual void on_update() = 0;
    virtual void on_event() = 0;

    virtual int get_width() const = 0;
    virtual int get_height() const = 0;

    virtual void setEventCallBack(const std::function<const bool(Event*)> callback) = 0;

    static Window* create(const WindowProps& props = WindowProps());
};

