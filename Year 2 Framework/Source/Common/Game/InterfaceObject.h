#ifndef INTERFACEOBJECT_H
#define INTERFACEOBJECT_H

#include "GameObject.h"

//Mouse Process Definitions
#define INTERFACE_PROCESS_WAITING           1
#define INTERFACE_PROCESS_CLICKED           2
#define INTERFACE_PROCESS_COMPLETE          3
//Mouse Status Defintions
#define INTERFACE_MOUSE_STATUS_MOVING       0
#define INTERFACE_MOUSE_STATUS_LEFT_UP      1
#define INTERFACE_MOUSE_STATUS_LEFT_DOWN    2
#define INTERFACE_MOUSE_STATUS_RIGHT_UP     3
#define INTERFACE_MOUSE_STATUS_RIGHT_DOWN   4

//Method Call Definitions
const int INTERFACE_REQUEST_ID_CHANGE       = 0;
const int INTERFACE_GET_ID                  = 1;
const int INTERFACE_SET_BOUNDS_VAR_0        = 2;
const int INTERFACE_SET_BOUNDS_VAR_1        = 3;
const int INTERFACE_GET_BOUNDS_VAR_0        = 4;
const int INTERFACE_GET_BOUNDS_VAR_1        = 5;
const int INTERFACE_SET_SIZE_VAR_0          = 6;
const int INTERFACE_SET_SIZE_VAR_1          = 7;
const int INTERFACE_SET_WIDTH               = 8;
const int INTERFACE_SET_HEIGHT              = 9;
const int INTERFACE_GET_SIZE_VAR_0          = 10;
const int INTERFACE_GET_SIZE_VAR_1          = 11;
const int INTERFACE_GET_WIDTH               = 12;
const int INTERFACE_GET_HEIGHT              = 13;
const int INTERFACE_SET_MOUSE_PROPERTIES    = 14;
const int INTERFACE_SET_INTERACTIVE         = 15;
const int INTERFACE_GET_INTERACTIVE         = 16;
const int INTERFACE_SET_MOUSE_STATUS_VAR_0  = 17;
const int INTERFACE_SET_MOUSE_STATUS_VAR_1  = 18;
const int INTERFACE_GET_MOUSE_STATUS_VAR_0  = 19;
const int INTERFACE_GET_MOUSE_STATUS_VAR_1  = 20;
const int INTERFACE_SET_MOUSE_PROCESS_VAR_0 = 21;
const int INTERFACE_SET_MOUSE_PROCESS_VAR_1 = 22;
const int INTERFACE_GET_MOUSE_PROCESS_VAR_0 = 23;
const int INTERFACE_GET_MOUSE_PROCESS_VAR_1 = 24;
const int INTERFACE_SET_MOUSE_POSITION      = 25;
const int INTERFACE_GET_MOUSE_POSITION      = 26;
const int INTERFACE_CHECK_MOUSE_BOUNDS      = 27;
const int INTERFACE_HANDLE_INTERFACE        = 28;

class InterfaceObject : public GameObject
{
private:
protected:
	int m_PropID;
	RectF m_PropBounds;
	Vector2I m_FlagMouseStatus;
	Vector2I m_FlagMouseProcess;
	bool m_FlagMouseInBounds;			//Only to be used by class members
	bool m_FlagMouseInteractive;
	Vector2I m_PropMousePosition;
	bool m_FlagSendData;
	
    
    
    
public:
    InterfaceObject();
    virtual ~InterfaceObject();

    virtual void draw() = 0;  //Inheirited from GameObject
    virtual int update() = 0; //Inheirited from GameObject

    virtual void requestIDChange(int iD);
    virtual int getID();
	//Size Methods
    void setInterfaceBounds(RectF bounds);
    void setInterfaceBounds(float x, float y, float width, float height);
    RectF getInterfaceBounds();
    void getInterfaceBounds(float &x, float &y, float &width, float &height);
	
	void setSize(Size2F size);
	void setSize(float width, float height);
	void setWidth(float width);
	void setHeight(float height);
	Size2F getSize();
	void getSize(float &width, float &height);
	float getWidth();
	float getHeight();

	void setPosition(Vector2F position);//Inheirited from GameObject
    void setXPosition(float x);			//Inheirited from GameObject
    void setYPosition(float y);			//Inheirited from GameObject


	//Mouse Method
    void setMouseProperties(bool interactive, Vector2I mouseStatus, Vector2I mouseProcess);

    void setMouseInteractive(bool flag);
    bool getMouseInteractive();

    void setMouseStatus(Vector2I flag);
    void setMouseStatus(int flag_LeftButton, int flag_RightButton);
    Vector2I getMouseStatus();
    void getMouseStatus(int &flag_LeftButton, int &flag_RightButton);
	

	void setMouseProcess(Vector2I flag);
	void setMouseProcess(int flag_LeftButton, int flag_RightButton);
    Vector2I getMouseProcess();
	void getMouseProcess(int &flag_LeftButton,int &flag_RightButton);
	

	void setMousePosition(int xPosition, int yPosition);
	Vector2I getMousePosition();

	virtual bool checkMouseWithBounds();



    virtual void handleInterface(); //use maybe???


    
    

    virtual void callMethod(int methodName);
    virtual void callMethod(int methodName, Param a);
    virtual void callMethodReturn(int methodName, Param &a); //Used for single return method calls
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