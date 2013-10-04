#include "MouseListener.h"


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
void MouseListener::setPosition(float mouseX, float mouseY)
{
    m_MouseX = mouseX;
    m_MouseY = mouseY;
}
//Call these triggers to setup the mouse states
void MouseListener::triggerLeftDown()
{
	//If we pressed the left button then it cannot be up
    m_MouseStateLeft = true;
}
void MouseListener::triggerRightDown()
{
	//If we pressed the right button then it cannot be up
    m_MouseStateRight = true;
	
}
void MouseListener::triggerLeftUp()
{
	//If the left button was unpressed then it cannot be pressed
    m_MouseStateLeft = false;
}
void MouseListener::triggerRightUp()
{
	//If the right button was unpressed then it cannot be pressed
    m_MouseStateRight = false;
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

Vector2F MouseListener::getPosition()
{
	Vector2F tempVector;
	tempVector.x = (float)m_MouseX;
	tempVector.y = (float)m_MouseY;
	return tempVector;
}

void MouseListener::getPosition(float &x, float &y)
{
	x = (float)m_MouseX;
	y = (float)m_MouseY;
}

bool MouseListener::getMouseLeft()
{
	return m_MouseStateLeft;
}
bool MouseListener::getMouseRight()
{
	return m_MouseStateRight;
}
bool MouseListener::getMouseMove()
{
	return m_MouseStateMove;
}