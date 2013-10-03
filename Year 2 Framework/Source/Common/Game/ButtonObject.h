#ifndef BUTTONOBJECT_H
#define BUTTONOBJECT_H

#include "InterfaceObject.h"
#include <string>

using std::string;

//set to last InterfaceObject defintion + 100 this is the section of defintions that can be used for ButtonObject method calls
const int BUTTON_SET_TEXTURE            = INTERFACE_HANDLE_INTERFACE + 100;
const int BUTTON_GET_TEXTURE            = INTERFACE_HANDLE_INTERFACE + 101;
const int BUTTON_SET_DRAW_BOUNDS        = INTERFACE_HANDLE_INTERFACE + 102;
const int BUTTON_GET_DRAW_BOUNDS        = INTERFACE_HANDLE_INTERFACE + 103;
const int BUTTON_SET_DRAW_TEXTURE       = INTERFACE_HANDLE_INTERFACE + 104;
const int BUTTON_GET_DRAW_TEXTURE       = INTERFACE_HANDLE_INTERFACE + 105;
const int BUTTON_SET_CURRENT_SCREEN     = INTERFACE_HANDLE_INTERFACE + 106;
const int BUTTON_SET_NEXT_SCREEN        = INTERFACE_HANDLE_INTERFACE + 107;
const int BUTTON_GET_CURRENT_SCREEN     = INTERFACE_HANDLE_INTERFACE + 108;
const int BUTTON_GET_NEXT_SCREEN        = INTERFACE_HANDLE_INTERFACE + 109;


class ButtonObject : public InterfaceObject
{
private:
    
protected:
    OpenGLTexture * m_Texture;
    bool m_DrawBounds;
    bool m_DrawTexture;
    ReturnFlag m_ReturnFlag;
public:
    ButtonObject(float xPosition = 0.0f, float yPosition = 0.0f, float width = 0.0f, float height =0.0f, int iD = 0, string filename = "");
    ButtonObject(float xPosition = 0.0f, float yPosition = 0.0f, int iD = 0, string filename = "");
    ButtonObject();
    virtual ~ButtonObject();

    virtual void draw(); //From GameObject  >> InterfaceObject
    virtual int update(); //From GameObject >> InterfaceObject
 
    void setTexture(OpenGLTexture * texture);
    OpenGLTexture * getTexture();

    void setDrawBounds(bool flag);
    void setDrawTexture(bool flag);
    bool getDrawBounds();
    bool getDrawTexture();

    void setCurrentScreen(int flag);
    void setNextScreen(int flag);
    int getCurrentScreen();
    int getNextScreen();

    virtual void callMethod(int methodName);
    virtual void callMethod(int methodName, Param a);
    virtual void callMethodReturn(int methodName, Param &a);
    virtual void callMethod(int methodName, Param a, Param &b);
    virtual void callMethod(int methodName, Param a, Param b, Param &c);
    virtual void callMethod(int methodName, Param a, Param b, Param &c, Param &d);
    virtual void callMethod(int methodName, Param a, Param b, Param c, Param &d, Param &e);
    virtual void callMethod(int methodName, Param a, Param b, Param c, Param &d, Param &e, Param &f);
    virtual void callMethod(int methodName, Param a, Param b, Param c, Param d, Param &e, Param &f, Param &g);
    virtual void callMethod(int methodName, Param a, Param b, Param c, Param d, Param &e, Param &f, Param &g, Param &h);
    virtual void callMethod(int methodName, Param a, Param b, Param c, Param d, Param e, Param &f, Param &g, Param &h, Param &i);
    virtual void callMethod(int methodName, Param a, Param b, Param c, Param d, Param e, Param &f, Param &g, Param &h, Param &i, Param &j);
    
};

#endif