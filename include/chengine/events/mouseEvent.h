#include"chengine/events/event.h"

class MouseButtonPressed:public Event
{
    int x,y;
public:
    MouseButtonPressed(int x,int y):x(x),y(y){};
    int getX(){return x;};
    int getY(){return y;};
    CE_DEFINE_GET_STATIC_TYPE(MouseButtonPressed);
    CE_DEFINE_GET_EVENT_CATEGORY(EventCategoryMouse:1,EventCategoryInput:1);
    CE_DEFINE_GET_CLASS_NAME(MouseButtonPressed);
};
class MouseButtonReleased:public Event
{
    int x,y;
public:
    MouseButtonReleased(int x,int y):x(x),y(y){};
    int getX(){return x;};
    int getY(){return y;};
    CE_DEFINE_GET_STATIC_TYPE(MouseButtonReleased);
    CE_DEFINE_GET_EVENT_CATEGORY(EventCategoryMouse:1,EventCategoryInput:1);
    CE_DEFINE_GET_CLASS_NAME(MouseButtonReleased);
};
class MouseMoved:public Event
{
    int x,y;
public:
    MouseMoved(int x,int y):x(x),y(y){};
    int getX(){return x;};
    int getY(){return y;};
    CE_DEFINE_GET_STATIC_TYPE(MouseMoved);
    CE_DEFINE_GET_EVENT_CATEGORY(EventCategoryMouse:1,EventCategoryInput:1);
    CE_DEFINE_GET_CLASS_NAME(MouseMoved);

};
class MouseScrolled:public Event
{
    int xLine,yLine;
public:
    MouseScrolled(int xLine,int yLine):xLine(xLine),yLine(yLine){};
    int getXLine(){return xLine;};
    int getYLine(){return yLine;};
    CE_DEFINE_GET_STATIC_TYPE(MouseScrolled);
    CE_DEFINE_GET_EVENT_CATEGORY(EventCategoryMouse:1,EventCategoryInput:1);
    CE_DEFINE_GET_CLASS_NAME(MouseScrolled);
};