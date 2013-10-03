#include "ButtonObject.h"

ButtonObject::ButtonObject(float xPosition, float yPosition,float width, float height, int iD, string filename)
{
    //Game Object
	m_Type = INTERFACE_OBJECT;
	m_Position.x = xPosition;
	m_Position.y = yPosition;
	//Interface Object
    
    m_PropID = iD;
	m_PropBounds.m_Position.x = xPosition;
	m_PropBounds.m_Position.y = yPosition;
	m_PropBounds.m_Size.width = width;
	m_PropBounds.m_Size.height = height;
	m_FlagMouseStatus.x = INTERFACE_MOUSE_STATUS_LEFT_UP;
	m_FlagMouseStatus.y = INTERFACE_MOUSE_STATUS_LEFT_UP;
	m_FlagMouseProcess.x = INTERFACE_PROCESS_WAITING;
	m_FlagMouseProcess.y = INTERFACE_PROCESS_WAITING;
	m_FlagMouseInBounds = false;
	m_FlagMouseInteractive = false;
	m_PropMousePosition.x = 0;
	m_PropMousePosition.y = 0;
	m_FlagSendData = false;
    //Button Object
    m_DrawTexture = false;
    m_Texture = 0;
    if(filename != "")
    {
        m_Texture = new OpenGLTexture(filename.c_str());
        m_DrawTexture = true;
    }
    m_DrawBounds = true;
    
    m_ReturnFlag.m_CurrentScreen = 0;
    m_ReturnFlag.m_NextScreen = 0;
    for(int i = 0; i < sizeof(Flag) ; i++)
    {
        m_ReturnFlag.m_Flag.uCharFlag[i] = 0;
    }
}
ButtonObject::ButtonObject(float xPosition, float yPosition, int iD, string filename)
{
   //Game Object
	m_Type = INTERFACE_OBJECT;
	m_Position.x = xPosition;
	m_Position.y = yPosition;
	//Interface Object
    
    m_PropID = iD;
	m_PropBounds.m_Position.x = xPosition;
	m_PropBounds.m_Position.y = yPosition;
	m_PropBounds.m_Size.width = 50;
	m_PropBounds.m_Size.height = 50;
	m_FlagMouseStatus.x = INTERFACE_MOUSE_STATUS_LEFT_UP;
	m_FlagMouseStatus.y = INTERFACE_MOUSE_STATUS_LEFT_UP;
	m_FlagMouseProcess.x = INTERFACE_PROCESS_WAITING;
	m_FlagMouseProcess.y = INTERFACE_PROCESS_WAITING;
	m_FlagMouseInBounds = false;
	m_FlagMouseInteractive = false;
	m_PropMousePosition.x = 0;
	m_PropMousePosition.y = 0;
	m_FlagSendData = false;
    //Button Object
    m_Texture = 0;
    m_DrawBounds = true;
    m_DrawTexture = false;
    m_ReturnFlag.m_CurrentScreen = 0;
    m_ReturnFlag.m_NextScreen = 0;
    for(int i = 0; i < sizeof(m_ReturnFlag.m_Flag) ; i++)
    {
        m_ReturnFlag.m_Flag.uCharFlag[i] = 0;
    }
}
ButtonObject::ButtonObject()
{
    //Game Object
	m_Type = INTERFACE_OBJECT;
	m_Position.x = 0;
	m_Position.y = 0;
	//Interface Object
    
    m_PropID = 0;
	m_PropBounds.m_Position.x = 0;
	m_PropBounds.m_Position.y = 0;
	m_PropBounds.m_Size.width = 50;
	m_PropBounds.m_Size.height = 50;
	m_FlagMouseStatus.x = INTERFACE_MOUSE_STATUS_LEFT_UP;
	m_FlagMouseStatus.y = INTERFACE_MOUSE_STATUS_LEFT_UP;
	m_FlagMouseProcess.x = INTERFACE_PROCESS_WAITING;
	m_FlagMouseProcess.y = INTERFACE_PROCESS_WAITING;
	m_FlagMouseInBounds = false;
	m_FlagMouseInteractive = false;
	m_PropMousePosition.x = 0;
	m_PropMousePosition.y = 0;
	m_FlagSendData = false;
    //Button Object
    m_Texture = 0;
    m_DrawBounds = true;
    m_DrawTexture = false;
    m_ReturnFlag.m_CurrentScreen = 0;
    m_ReturnFlag.m_NextScreen = 0;
    for(int i = 0; i < sizeof(m_ReturnFlag.m_Flag) ; i++)
    {
        m_ReturnFlag.m_Flag.uCharFlag[i] = 0;
    }
}
ButtonObject::~ButtonObject()
{
    if(m_Texture != 0 )
    {
        delete m_Texture;
        m_Texture = 0;
    }
}

void ButtonObject::draw()
{
    
}
int ButtonObject::update()
{
    

    return -1; //Returns -1 which signals there is no screen change;
}

void ButtonObject::setTexture(OpenGLTexture * texture)
{
    m_Texture = texture;
}
OpenGLTexture * ButtonObject::getTexture()
{
    return m_Texture;
}

void ButtonObject::setDrawBounds(bool flag)
{
    m_DrawBounds = flag;
}
void ButtonObject::setDrawTexture(bool flag)
{
    m_DrawTexture = flag;
}
bool ButtonObject::getDrawBounds()
{
    return m_DrawBounds;
}
bool ButtonObject::getDrawTexture()
{
    return m_DrawTexture;
}

void ButtonObject::setCurrentScreen(int flag)
{
    m_ReturnFlag.m_CurrentScreen = flag;
}
void ButtonObject::setNextScreen(int flag)
{
    m_ReturnFlag.m_NextScreen = flag;
}
int ButtonObject::getCurrentScreen()
{
    return m_ReturnFlag.m_CurrentScreen;
}
int ButtonObject::getNextScreen()
{
    return m_ReturnFlag.m_NextScreen;
}


void ButtonObject::callMethod(int methodName)
{
    switch(methodName)
    {
    case INTERFACE_HANDLE_INTERFACE:
        handleInterface();
        break;
    case INTERFACE_CHECK_MOUSE_BOUNDS:
        checkMouseWithBounds();
        break;
    
    }
}
void ButtonObject::callMethod(int methodName, Param a)
{
    switch(methodName)
    {
    case INTERFACE_REQUEST_ID_CHANGE:
        requestIDChange(a.m_Param.i);
        break;
    case INTERFACE_SET_BOUNDS_VAR_0:
        setInterfaceBounds(a.m_Param.rectf);
        break;
    case INTERFACE_SET_BOUNDS_VAR_1:
        setInterfaceBounds(a.m_Param.rectf.m_Position.x,a.m_Param.rectf.m_Position.y,a.m_Param.rectf.m_Size.width,a.m_Param.rectf.m_Size.height);
        break;
    case INTERFACE_SET_SIZE_VAR_0:
        setSize(a.m_Param.size2f);
        break;
    case INTERFACE_SET_SIZE_VAR_1:
        setSize(a.m_Param.size2f.width,a.m_Param.size2f.height);
        break;
    case INTERFACE_SET_WIDTH:
        setWidth(a.m_Param.f);
        break;
    case INTERFACE_SET_HEIGHT:
        setHeight(a.m_Param.f);
        break;
    case INTERFACE_SET_INTERACTIVE:
        setMouseInteractive(a.m_Param.b);
        break;
    case INTERFACE_SET_MOUSE_STATUS_VAR_0:
        setMouseStatus(a.m_Param.vec2i);
        break;
    case INTERFACE_SET_MOUSE_STATUS_VAR_1:
        setMouseStatus(a.m_Param.vec2i.x,a.m_Param.vec2i.y);
        break;
    case INTERFACE_SET_MOUSE_PROCESS_VAR_0:
        setMouseProcess(a.m_Param.vec2i);
        break;
    case INTERFACE_SET_MOUSE_PROCESS_VAR_1:
        setMouseProcess(a.m_Param.vec2i.x,a.m_Param.vec2i.y);
        break;
    case BUTTON_SET_TEXTURE:
        setTexture(a.m_Param.texgl);
        break;
    case BUTTON_SET_DRAW_BOUNDS:
        setDrawBounds(a.m_Param.b);
        break;
    case BUTTON_SET_DRAW_TEXTURE:
        setDrawTexture(a.m_Param.b);
        break;
    case BUTTON_SET_CURRENT_SCREEN:
        setCurrentScreen(a.m_Param.i);
        break;
    case BUTTON_SET_NEXT_SCREEN:
        setNextScreen(a.m_Param.i);
        break;
    }
}
void ButtonObject::callMethodReturn(int methodName, Param &a)
{
    switch(methodName)
    {
    case INTERFACE_GET_ID:
        a.m_Param.i = getID();
        break;
    case INTERFACE_GET_BOUNDS_VAR_0:
        a.m_Param.rectf = getInterfaceBounds();
        break;
    case INTERFACE_GET_BOUNDS_VAR_1:
        getInterfaceBounds(a.m_Param.rectf.m_Position.x,a.m_Param.rectf.m_Position.y,a.m_Param.rectf.m_Size.width,a.m_Param.rectf.m_Size.height);
        break;
    case INTERFACE_GET_SIZE_VAR_0:
        a.m_Param.size2f = getSize();
        break;
    case INTERFACE_GET_SIZE_VAR_1:
        getSize(a.m_Param.size2f.width,a.m_Param.size2f.height);
        break;
    case INTERFACE_GET_WIDTH:
        a.m_Param.f = getWidth();
        break;
    case INTERFACE_GET_HEIGHT:
        a.m_Param.f = getHeight();
        break;
    case INTERFACE_GET_INTERACTIVE:
        a.m_Param.b = getMouseInteractive();
        break;
    case INTERFACE_GET_MOUSE_STATUS_VAR_0:
        a.m_Param.vec2i = getMouseStatus();
        break;
    case INTERFACE_GET_MOUSE_STATUS_VAR_1:
        getMouseStatus(a.m_Param.vec2i.x,a.m_Param.vec2i.y);
        break;
    case INTERFACE_GET_MOUSE_PROCESS_VAR_0:
        a.m_Param.vec2i = getMouseProcess();
        break;
    case INTERFACE_GET_MOUSE_PROCESS_VAR_1:
        getMouseProcess(a.m_Param.vec2i.x,a.m_Param.vec2i.y);
        break;
    case INTERFACE_GET_MOUSE_POSITION:
        a.m_Param.vec2i = getMousePosition();
        break;
    case BUTTON_GET_TEXTURE:
        a.m_Param.texgl = getTexture();
        break;
    case BUTTON_GET_DRAW_BOUNDS:
        a.m_Param.b = getDrawBounds();
        break;
    case BUTTON_GET_DRAW_TEXTURE:
        a.m_Param.b = getDrawTexture();
        break;
    case BUTTON_GET_CURRENT_SCREEN:
        a.m_Param.i = getCurrentScreen();
        break;
    case BUTTON_GET_NEXT_SCREEN:
        a.m_Param.i = getNextScreen();
        break;
    }
}
void ButtonObject::callMethod(int methodName, Param a, Param &b)
{
    switch(methodName)
    {

    }
}
void ButtonObject::callMethod(int methodName, Param a, Param b, Param &c)
{
    switch(methodName)
    {
    case INTERFACE_SET_SIZE_VAR_1:
        setSize(a.m_Param.f,b.m_Param.f);
        break;
    case INTERFACE_SET_MOUSE_STATUS_VAR_1:
        setMouseStatus(a.m_Param.i,b.m_Param.i);
        break;
    case INTERFACE_SET_MOUSE_PROCESS_VAR_1:
        setMouseProcess(a.m_Param.i,b.m_Param.i);
        break;
    case INTERFACE_SET_MOUSE_POSITION:
        setMousePosition(a.m_Param.i,a.m_Param.i);
        break;
    }
}
void ButtonObject::callMethod(int methodName, Param a, Param b, Param &c, Param &d)
{
    switch(methodName)
    {
    case INTERFACE_GET_SIZE_VAR_1:
        getSize(c.m_Param.f,d.m_Param.f);
        break;
    case INTERFACE_GET_MOUSE_STATUS_VAR_1:
        getMouseStatus(c.m_Param.i,d.m_Param.i);
        break;
    case INTERFACE_GET_MOUSE_PROCESS_VAR_1:
        getMouseProcess(c.m_Param.i,d.m_Param.i);
        break;
    }
}
void ButtonObject::callMethod(int methodName, Param a, Param b, Param c, Param &d, Param &e)
{
    switch(methodName)
    {

    }
}
void ButtonObject::callMethod(int methodName, Param a, Param b, Param c, Param &d, Param &e, Param &f)
{
    switch(methodName)
    {

    }
}
void ButtonObject::callMethod(int methodName, Param a, Param b, Param c, Param d, Param &e, Param &f, Param &g)
{
    switch(methodName)
    {
    
    }
}
void ButtonObject::callMethod(int methodName, Param a, Param b, Param c, Param d, Param &e, Param &f, Param &g, Param &h)
{
    switch(methodName)
    {
    
    }
}
void ButtonObject::callMethod(int methodName, Param a, Param b, Param c, Param d, Param e, Param &f, Param &g, Param &h, Param &i)
{
    switch(methodName)
    {

    }
}
void ButtonObject::callMethod(int methodName, Param a, Param b, Param c, Param d, Param e, Param &f, Param &g, Param &h, Param &i, Param &j)
{
    switch(methodName)
    {

    }
}