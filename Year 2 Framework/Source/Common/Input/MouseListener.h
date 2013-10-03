#ifndef MOUSE_LISTENER_H
#define MOUSE_LISTENER_H

//This is a simpleton Class
//Mouse events will be tracked and recorded in here

class MouseListener
{
private:
	int m_MouseX;
	int m_MouseY;


	bool m_MouseStateLeftDown;
	bool m_MouseStateRightDown;
	bool m_MouseStateLeftUp;
	bool m_MouseStateRightUp;
	bool m_MouseStateMove;

	int m_MouseState;

	MouseListener();
	~MouseListener();

	static MouseListener * s_Instance;

public:
	static MouseListener * getInstance();
	static void cleanupInstance();


	void setPosition(int mouseX, int mouseY);
	void triggerLeftDown();
	void triggerRightDown();
	void triggerLeftUp();
	void triggerRightUp();
	void triggerMove();
	void defaultMove();
};

#endif