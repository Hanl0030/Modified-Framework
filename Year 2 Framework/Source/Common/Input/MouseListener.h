#ifndef MOUSE_LISTENER_H
#define MOUSE_LISTENER_H

#include "../Utils/Utility Objects.h"
//This is a simpleton Class
//Mouse events will be tracked and recorded in here

class MouseListener
{
private:
	float m_MouseX;
	float m_MouseY;

	bool m_MouseStateRight;
	bool m_MouseStateLeft;
	bool m_MouseStateMove;

	MouseListener();
	~MouseListener();

	static MouseListener * s_Instance;

public:
	static MouseListener * getInstance();
	static void cleanupInstance();


	void setPosition(float mouseX, float mouseY);
	void triggerLeftDown(); //inverts the left
	void triggerRightDown(); //inverts the right
	void triggerLeftUp();
	void triggerRightUp();
	void triggerMove();
	void defaultMove();

	//return position
	Vector2F getPosition();
	void getPosition(float &x, float &y);
	
	//return states
	bool getMouseLeft();
	bool getMouseRight();
	bool getMouseMove();
};

#endif