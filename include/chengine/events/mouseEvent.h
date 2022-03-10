#pragma once
#include"chengine/events/event.h"

namespace chengine{
    class MouseEvent:public Event
    {
    public:
        CE_DEFINE_GET_EVENT_CATEGORY(EventCategoryInput:1,EventCategoryMouse:1);
    protected:
        MouseEvent(){};
    };
    class MouseButtonPressed:public MouseEvent
    {
        int x,y;
    public:
        MouseButtonPressed(int x,int y):x(x),y(y){};
        int getX()const{return x;};
        int getY()const{return y;};
        CE_DEFINE_GET_STATIC_TYPE(MouseButtonPressed);
        CE_DEBUG_DEFINE_GET_CLASS_NAME(MouseButtonPressed);
    };
    class MouseButtonReleased:public MouseEvent
    {
        int x,y;
    public:
        MouseButtonReleased(int x,int y):x(x),y(y){};
        int getX()const{return x;};
        int getY()const{return y;};
        CE_DEFINE_GET_STATIC_TYPE(MouseButtonReleased);
        CE_DEBUG_DEFINE_GET_CLASS_NAME(MouseButtonReleased);
    };
    class MouseMoved:public MouseEvent
    {
        int x,y;
    public:
        MouseMoved(int x,int y):x(x),y(y){};
        int getX()const{return x;};
        int getY()const{return y;};
        CE_DEFINE_GET_STATIC_TYPE(MouseMoved);
        CE_DEBUG_DEFINE_GET_CLASS_NAME(MouseMoved);

    };
    class MouseScrolled:public MouseEvent
    {
        int xLine,yLine;
    public:
        MouseScrolled(int xLine,int yLine):xLine(xLine),yLine(yLine){};
        int getXLine()const{return xLine;};
        int getYLine()const{return yLine;};
        CE_DEFINE_GET_STATIC_TYPE(MouseScrolled);
        CE_DEBUG_DEFINE_GET_CLASS_NAME(MouseScrolled);
    };
}