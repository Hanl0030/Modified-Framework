#include "InterfaceObject.h"

InterfaceObject::InterfaceObject()
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
}

InterfaceObject::~InterfaceObject()
{

}

void InterfaceObject::requestIDChange(int iD)
{
	if(m_PropID == 0)
	{
		m_PropID = iD;
	}
	else
	{
		//Write Warning in Log
	}
}
int InterfaceObject::getID()
{
	return m_PropID;
}
//Size Methods
void InterfaceObject::setInterfaceBounds(RectF bounds)
{
	m_PropBounds = bounds;
}
void InterfaceObject::setInterfaceBounds(float x, float y, float width, float height)
{
	m_PropBounds.m_Position.x = x;
	m_PropBounds.m_Position.y = y;
	m_PropBounds.m_Size.width = width;
	m_PropBounds.m_Size.height = height;
}
RectF InterfaceObject::getInterfaceBounds()
{
	return m_PropBounds;
}
void InterfaceObject::getInterfaceBounds(float &x, float &y, float &width, float &height)
{
	x = m_PropBounds.m_Position.x;
	y = m_PropBounds.m_Position.y;
	width = m_PropBounds.m_Size.width;
	height = m_PropBounds.m_Size.height;
}

void InterfaceObject::setSize(Size2F size)
{
	m_PropBounds.m_Size = size;
}
void InterfaceObject::setSize(float width, float height)
{
	m_PropBounds.m_Size.width = width;
	m_PropBounds.m_Size.height = height;
}
void InterfaceObject::setWidth(float width)
{
	m_PropBounds.m_Size.width = width;
}
void InterfaceObject::setHeight(float height)
{
	m_PropBounds.m_Size.height = height;
}
Size2F InterfaceObject::getSize()
{
	return m_PropBounds.m_Size;
}
void InterfaceObject::getSize(float &width, float &height)
{
	width = m_PropBounds.m_Size.width;
	height = m_PropBounds.m_Size.height;
}
float InterfaceObject::getWidth()
{
	return m_PropBounds.m_Size.width;
}
float InterfaceObject::getHeight()
{
	return m_PropBounds.m_Size.height;
}

void InterfaceObject::setPosition(Vector2F position)//Inheirited from GameObject
{
	m_Position = position;
	m_PropBounds.m_Position = position;
}
void InterfaceObject::setXPosition(float x)			//Inheirited from GameObject
{
	m_Position.x = x;
	m_PropBounds.m_Position.x = x;
}
void InterfaceObject::setYPosition(float y)			//Inheirited from GameObject
{
	m_Position.x = y;
	m_PropBounds.m_Position.y = y;
}

//Mouse Method
void InterfaceObject::setMouseProperties(bool interactive, Vector2I mouseStatus, Vector2I mouseProcess)
{
	m_FlagMouseInteractive = interactive;
	m_FlagMouseStatus = mouseStatus;
	m_FlagMouseProcess = mouseProcess;
}

void InterfaceObject::setMouseInteractive(bool flag)
{
	m_FlagMouseInteractive = flag;
}
bool InterfaceObject::getMouseInteractive()
{
	return m_FlagMouseInteractive;
}


void InterfaceObject::setMouseStatus(int flag_LeftButton, int flag_RightButton)
{
	m_FlagMouseStatus.x = flag_LeftButton;
	m_FlagMouseStatus.y = flag_RightButton;
}
void InterfaceObject::setMouseStatus(Vector2I flag)
{
	m_FlagMouseStatus = flag;
}
void InterfaceObject::getMouseStatus(int &flag_LeftButton, int &flag_RightButton)
{
	flag_LeftButton = m_FlagMouseStatus.x;
	flag_RightButton = 	m_FlagMouseStatus.y; 
}
Vector2I InterfaceObject::getMouseStatus()
{
	return m_FlagMouseStatus;
}

void InterfaceObject::setMouseProcess(Vector2I flag)
{
	m_FlagMouseProcess = flag;
}
void InterfaceObject::setMouseProcess(int flag_LeftButton, int flag_RightButton)
{
	m_FlagMouseProcess.x = flag_LeftButton;
	m_FlagMouseProcess.y = flag_RightButton;
}
void InterfaceObject::getMouseProcess(int &flag_LeftButton,int &flag_RightButton)
{
	flag_LeftButton = m_FlagMouseProcess.x;
	flag_RightButton = m_FlagMouseProcess.y;
}
Vector2I InterfaceObject::getMouseProcess()
{
	return m_FlagMouseProcess;
}

void InterfaceObject::setMousePosition(int xPosition, int yPosition)
{
	m_PropMousePosition.x = xPosition;
	m_PropMousePosition.y = yPosition;
}
Vector2I InterfaceObject::getMousePosition()
{
	return m_PropMousePosition;
}


bool InterfaceObject::checkMouseWithBounds()
{
	if(m_PropMousePosition.x > m_PropBounds.getRight())
    {
		m_FlagMouseInBounds = false;
		return false;
    }
    else if(m_PropMousePosition.x < m_PropBounds.getLeft())
    {
		m_FlagMouseInBounds = false;
		return false;
    }
    else if(m_PropMousePosition.y > m_PropBounds.getBottom())
    {
		m_FlagMouseInBounds = false;
		return false;
    }
    else if(m_PropMousePosition.y < m_PropBounds.getTop())
    {
		m_FlagMouseInBounds = false;
		return false;
    }
    else
    {
		m_FlagMouseInBounds = true;
        return true;
    }
}

void InterfaceObject::handleInterface() //use maybe???
{
	//if the mouse is up
	if(m_FlagMouseProcess.x == INTERFACE_PROCESS_WAITING)
	{
		
		if(m_FlagMouseStatus.x == INTERFACE_MOUSE_STATUS_LEFT_DOWN && m_FlagMouseInBounds == true)
		{
			m_FlagMouseProcess.x = INTERFACE_PROCESS_CLICKED;
		}
	}
	if(m_FlagMouseProcess.x == INTERFACE_PROCESS_CLICKED)
	{
		if(m_FlagMouseStatus.x == INTERFACE_MOUSE_STATUS_LEFT_UP && m_FlagMouseInBounds)
		{
			m_FlagSendData = true;
		}
	}
}

void InterfaceObject::callMethod(int methodName)
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
void InterfaceObject::callMethod(int methodName, Param a)
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
    }
}
void InterfaceObject::callMethodReturn(int methodName, Param &a)
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

    }
}
void InterfaceObject::callMethod(int methodName, Param a, Param &b)
{
    switch(methodName)
    {

    }
}
void InterfaceObject::callMethod(int methodName, Param a, Param b, Param &c)
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
void InterfaceObject::callMethod(int methodName, Param a, Param b, Param &c, Param &d)
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
void InterfaceObject::callMethod(int methodName, Param a, Param b, Param c, Param &d, Param &e)
{
    switch(methodName)
    {

    }
}
void InterfaceObject::callMethod(int methodName, Param a, Param b, Param c, Param &d, Param &e, Param &f)
{
    switch(methodName)
    {

    }
}
void InterfaceObject::callMethod(int methodName, Param a, Param b, Param c, Param d, Param &e, Param &f, Param &g)
{
    switch(methodName)
    {
    
    }
}
void InterfaceObject::callMethod(int methodName, Param a, Param b, Param c, Param d, Param &e, Param &f, Param &g, Param &h)
{
    switch(methodName)
    {
    
    }
}
void InterfaceObject::callMethod(int methodName, Param a, Param b, Param c, Param d, Param e, Param &f, Param &g, Param &h, Param &i)
{
    switch(methodName)
    {

    }
}
void InterfaceObject::callMethod(int methodName, Param a, Param b, Param c, Param d, Param e, Param &f, Param &g, Param &h, Param &i, Param &j)
{
    switch(methodName)
    {

    }
}