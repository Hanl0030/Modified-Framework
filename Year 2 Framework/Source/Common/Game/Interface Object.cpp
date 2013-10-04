#include "Interface Object.h"
#include "../Constants/Constants.h"
#include "../Global Count/ObjectCounter.h"



InterfaceObject::InterfaceObject(int id,int idCreate)
{
	m_ID = id;
	m_IDCreate = idCreate;
	m_Type = INTERFACE_OBJECT_TYPE;
	m_Family = INTERFACE_OBJECT_FAMILY;
	m_Bounds.m_Position.x = INTERFACE_DEFAULT_POSITION_X;
	m_Bounds.m_Position.y = INTERFACE_DEFAULT_POSITION_Y;
	m_Bounds.m_Size.width = INTERFACE_DEFAULT_SIZE_WIDTH;
	m_Bounds.m_Size.height = INTERFACE_DEFAULT_SIZE_HEIGHT;
	m_Texture = 0;
}
InterfaceObject::InterfaceObject()
{
	m_ID = g_NumberOfInterfaceObject_InterfaceObject;
	m_IDCreate = g_NumberOfObjects;
	m_Type = INTERFACE_OBJECT_TYPE;
	m_Family = INTERFACE_OBJECT_FAMILY;
	m_Bounds.m_Position.x = INTERFACE_DEFAULT_POSITION_X;
	m_Bounds.m_Position.y = INTERFACE_DEFAULT_POSITION_Y;
	m_Bounds.m_Size.width = INTERFACE_DEFAULT_SIZE_WIDTH;
	m_Bounds.m_Size.height = INTERFACE_DEFAULT_SIZE_HEIGHT;
	m_Texture = 0;
}
InterfaceObject::~InterfaceObject()
{
    if(m_Texture != NULL)
    {
        delete m_Texture;
        m_Texture = 0;
    }
}

void InterfaceObject::setPosition(float x, float y)
{
    m_Bounds.m_Position.x = x;
    m_Bounds.m_Position.y = y;
}
void InterfaceObject::setPosition(Vector2F position)
{
    m_Bounds.m_Position = position;
}
void InterfaceObject::getPosition(float &x, float &y)
{
    x = m_Bounds.m_Position.x;
    y = m_Bounds.m_Position.y;
}
Vector2F InterfaceObject::getPosition()
{
	return m_Bounds.m_Position;
}

void InterfaceObject::setSize(float width, float height)
{
    m_Bounds.m_Size.width = width;
    m_Bounds.m_Size.height = height;
}
void InterfaceObject::setSize(Size2F size)
{
    m_Bounds.m_Size = size;
}
void InterfaceObject::getSize(float &width, float &height)
{
    width = m_Bounds.m_Size.width;
    height = m_Bounds.m_Size.height;
}
Size2F InterfaceObject::getSize()
{
	return m_Bounds.m_Size;
}

void InterfaceObject::setBounds(float x, float y, float width, float height)
{
    m_Bounds.m_Position.x = x;
    m_Bounds.m_Position.y = y;
}
void InterfaceObject::setBounds(RectF bounds)
{
    m_Bounds = bounds;
}
void InterfaceObject::getBounds(float &x, float &y, float &width, float &height)
{
    x = m_Bounds.m_Position.x;
    y = m_Bounds.m_Position.y;
    width = m_Bounds.m_Size.width;
    height = m_Bounds.m_Size.height;
}
RectF InterfaceObject::getBounds()
{
	return m_Bounds;
}

void InterfaceObject::setID(int id)
{
    m_ID = id;
}
	
int InterfaceObject::getID()
{
	return m_ID;
}
int InterfaceObject::getIDCreate()
{
	return m_IDCreate;
}
int InterfaceObject::getType()
{
	return m_Type;
}
int InterfaceObject::getFamily()
{
	return m_Family;
}


Param InterfaceObject::getData(int type)
{
	Param tempParam; //create a temp Param
	tempParam.m_Param.d = 0; //store the specified data
	return tempParam; //return the param holding the data
}