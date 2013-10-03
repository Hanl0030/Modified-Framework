#include "MouseListener.h"
#include "../Constants/Mouse/Mouse Constants.h"

//simpleton ftw
MouseListener * MouseListener::s_Instance = 0;



MouseListener * MouseListener::getInstance()
{
	if(s_Instance == 0)
	{
        s_Instance = new MouseListener();
	}
	return s_Instance;
}
void MouseListener::cleanupInstance()
{
	if(s_Instance != 0)
	{
		delete s_Instance;
		s_Instance = 0;
	}
}

MouseListener::MouseListener()
{

}


MouseListener::~MouseListener()
{
	if(s_Instance != 0)
	{
		delete s_Instance;
		s_Instance = 0;
	}
}

//Call this in each mouse event handle to get the position
void MouseListener::setPosition(int mouseX, int mouseY)
{
    m_MouseX = mouseX;
    m_MouseY = mouseY;
}
//Call these triggers to setup the mouse states
void MouseListener::triggerLeftDown()
{
	//If we pressed the left button then it cannot be up
    m_MouseStateLeftUp = false;
    m_MouseStateLeftDown = true;
}
void MouseListener::triggerRightDown()
{
	//If we pressed the right button then it cannot be up
    m_MouseStateRightUp = false;
    m_MouseStateRightDown = true;
}
void MouseListener::triggerLeftUp()
{
	//If the left button was unpressed then it cannot be pressed
    m_MouseStateLeftDown = false;
    m_MouseStateLeftUp = true;
}
void MouseListener::triggerRightUp()
{
	//If the right button was unpressed then it cannot be pressed
    m_MouseStateRightUp = false;
    m_MouseStateRightDown = true;
}
void MouseListener::triggerMove()
{
	//if we are moving the mouse then true
    m_MouseStateMove = true;
}


void MouseListener::defaultMove()
{
	m_MouseStateMove = false;
}
