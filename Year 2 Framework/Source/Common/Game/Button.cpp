#include "Button.h"
#include "../Constants/Constants.h"
#include "../Global Count/ObjectCounter.h"
#include "../OpenGL/OpenGL.h"
#include "../Input/MouseListener.h"

//Constructors... Just set defaults
Button::Button(int id, int idCreate, float x, float y, float width, float height, string filename)
{
	m_ID = id;
	m_IDCreate = idCreate;
	m_Type = BUTTON_TYPE;
	m_Family = BUTTON_FAMILY;
	m_Bounds.m_Position.x = x;
	m_Bounds.m_Position.y = y;
	m_Bounds.m_Size.width = width;
	m_Bounds.m_Size.height = height;
	m_Texture = NULL;
	m_Texture = new OpenGLTexture(filename.c_str());
    m_ButtonState = BUTTON_NULL;
	m_WaitingForLeftUp = false ;
	m_WaitingForRightUp = false;
}

Button::Button(int id, int idCreate, float x, float y, float width ,float height)
{
	m_ID = id;
	m_IDCreate = idCreate;
	m_Type = BUTTON_TYPE;
	m_Family = BUTTON_FAMILY;
	m_Bounds.m_Position.x = x;
	m_Bounds.m_Position.y = y;
	m_Bounds.m_Size.width = width;
	m_Bounds.m_Size.height = height;
	m_Texture = NULL;
    m_ButtonState = BUTTON_NULL;
	m_WaitingForLeftUp = false ;
	m_WaitingForRightUp = false;
}
Button::Button(int id, int idCreate)
{
	m_ID = id;
	m_IDCreate = idCreate;
	m_Type = BUTTON_TYPE;
	m_Family = BUTTON_FAMILY;
	m_Bounds.m_Position.x = BUTTON_DEFAULT_POSITION_X;
	m_Bounds.m_Position.y = BUTTON_DEFAULT_POSITION_Y;
	m_Bounds.m_Size.width = BUTTON_DEFAULT_SIZE_WIDTH;
	m_Bounds.m_Size.height = BUTTON_DEFAULT_SIZE_HEIGHT;
	m_Texture = NULL;

	m_ButtonState = BUTTON_NULL;
	m_WaitingForLeftUp = false ;
	m_WaitingForRightUp = false;
}
Button::Button()
{
	m_ID = g_NumberOfButtons_InterfaceObject;
	m_IDCreate = g_NumberOfObjects;
	m_Type = BUTTON_TYPE;
	m_Family = BUTTON_FAMILY;
	m_Bounds.m_Position.x = BUTTON_DEFAULT_POSITION_X;
	m_Bounds.m_Position.y = BUTTON_DEFAULT_POSITION_Y;
	m_Bounds.m_Size.width = BUTTON_DEFAULT_SIZE_WIDTH;
	m_Bounds.m_Size.height = BUTTON_DEFAULT_SIZE_HEIGHT;
	m_Texture = NULL;
    m_ButtonState = BUTTON_NULL;
	m_WaitingForLeftUp = false ;
	m_WaitingForRightUp = false;
}
Button::~Button()
{
    //deleting the texture is done in the InterfaceObject destructor
}

int Button::update()
{
	if(mouseInBounds() == true) //Is the mouse x and y position within the bounding rectangle of this button?
    {
        if(MouseListener::getInstance()->getMouseLeft() == true && m_WaitingForLeftUp == false)//Is the left mouse button being pressed? and are we waiting for it to come up?
        {
            m_WaitingForLeftUp = true; //If the above was true / false then we are now waiting for it to come back up
        }
        if(MouseListener::getInstance()->getMouseRight() == true && m_WaitingForRightUp == false)//Is the right mouse button being pressed? and are we waiting for it to come up?
        {
            m_WaitingForRightUp = true;//If the above was true / false then we are waiting for it to come back up
        }

        updateState(); //Update the state of the mouse
    }
    else //If mouse x and y position is not within the bounding rectangle of this button then the button is in a NULL state
    {
        m_ButtonState = BUTTON_NULL; //
    }

	return m_ButtonState; //If someone wants to use the update to "capture" the state of the mouse button were going to return the state it's in.
}
void Button::draw()
{   
    //Temporary Testing Code
    //It checks which state the button is in then sets the foreground color for the next drawing operations to be...
    if(m_Texture == 0)
    {
        if(m_ButtonState == BUTTON_LEFT_PRESSED)
        {
            OpenGLRenderer::getInstance()->setForegroundColor(OpenGLColorGreen());
        }
        else if(m_ButtonState == BUTTON_RIGHT_PRESSED)
        {
            OpenGLRenderer::getInstance()->setForegroundColor(OpenGLColorRed());
        }
        else if(m_ButtonState == BUTTON_HOVER)
        {
            OpenGLRenderer::getInstance()->setForegroundColor(OpenGLColorYellow());
        }
        else if(m_ButtonState == BUTTON_NULL)
        {
            OpenGLRenderer::getInstance()->setForegroundColor(OpenGLColorBlack());
        }
        else
        {
            OpenGLRenderer::getInstance()->setForegroundColor(OpenGLColorCyan());
        }
        //Draw the rectangle representing the button
	    OpenGLRenderer::getInstance()->drawRectangle(m_Bounds.m_Position.x,m_Bounds.m_Position.y,m_Bounds.m_Size.width,m_Bounds.m_Size.height);
    }
    else //If we have a texture draw it, not the primitive
    {
        OpenGLRenderer::getInstance()->drawTexture(m_Texture,m_Bounds.m_Position.x,m_Bounds.m_Position.y,m_Bounds.m_Size.width,m_Bounds.m_Size.height);
    }
}

void Button::updateState() //This gets called in update by default
{
    if(MouseListener::getInstance()->getMouseLeft() == false && m_WaitingForLeftUp == true)//If the mouse left button is up and were waiting for it
    {
        m_WaitingForLeftUp = false; //were no longer waiting for it to come up
        m_ButtonState = BUTTON_LEFT_PRESSED; //The state is that left button was successfully pressed down
    }
    else if(MouseListener::getInstance()->getMouseRight() == false && m_WaitingForRightUp == true)//If the mouse right button is up and were waiting for it
    {
        m_WaitingForRightUp = false;//were no longer waiting for it to come up
        m_ButtonState = BUTTON_RIGHT_PRESSED;//The state is that the right button was succ
    }
    else
    {
        m_ButtonState = BUTTON_HOVER; //If we have not let either of the buttons up while were waiting for them to be up, we must be hovering over the button
        //Remember this code is executed assuming the mouse x and y position is within the bounds of the button still
    }
    
}

bool Button::mouseInBounds()
{
    //Simple bounding box collision revamp
	m_MousePosition = MouseListener::getInstance()->getPosition(); //get the position of the mouse

	//Check to see if the mouse is within bounds

	//Are we completely to the left
	if(m_MousePosition.x < m_Bounds.m_Position.x)
	{
		return false;
	}//Are we completely to the right
	else if(m_MousePosition.x > m_Bounds.m_Position.x + m_Bounds.m_Size.width)
	{
		return false;
	}//Are we completely on the top
	else if(m_MousePosition.y < m_Bounds.m_Position.y)
	{
		return false;
	}//Are we completely below
	else if(m_MousePosition.y > m_Bounds.m_Position.y + m_Bounds.m_Size.height)
	{
		return false;
	}
	else//If we were not completely avoiding the bounding rectangle then we are obviously within its bounds
	{
		return true;
	}
}

Param Button::getData(int data)
{
    //Take the data that we got and go through a conditional statement checking if it matches
    
	Param tempParam;
	tempParam.m_Param.i = 0; //Default value of our union within the Param struct
                             //Change to something more meaningfull like 4096

	if(data == BUTTON_GET_STATE)
	{
		tempParam.m_Param.i = m_ButtonState;
	}
    //Keep in mind this is a virtual function, it is intended to be overwritten by other interface objects that will have other data that won't be accessed if they are declared of type InterfaceObject
    //You can downcast
	return tempParam; //the temp Param
}