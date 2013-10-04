#ifndef INTERFACE_OBJECT_H
#define INTERFACE_OBJECT_H

#include "../Utils/Utility Objects.h"

class OpenGLTexture;

class InterfaceObject
{
public:
	InterfaceObject(int id,int idCreate);
	InterfaceObject();
	virtual ~InterfaceObject();

	virtual int update() = 0;
	virtual void draw() = 0;

	void setPosition(float x, float y);
	void setPosition(Vector2F position);
	void getPosition(float &x, float &y);
	Vector2F getPosition();

	void setSize(float width, float height);
	void setSize(Size2F size);
	void getSize(float &width, float &height);
	Size2F getSize();

	void setBounds(float x, float y, float width, float height);
	void setBounds(RectF bounds);
	void getBounds(float &x, float &y, float &width, float &height);
	RectF getBounds();

	void setID(int id);
	
	int getID();
	int getIDCreate();
	int getType();
	int getFamily();

	//This method is virtual meaning it is intended to be rewritten down the line
	//The method takes one argument which is of type int which will be used to check what the return value will be
	//eg, the user could type io.getData(INT_STATE); and it would return a Param struct holding the data.
	virtual Param getData(int type);
	
	

protected:
	Vector2F m_MousePosition; // track the mouse position
	//Since interface objects are going to have a texture they will have a rectangle for itself
	RectF m_Bounds;	//Stores the position and size of the interface objects
	int m_ID;		//Stores the ID for general purpose
	int m_IDCreate;	//Stores the ID for when it was created in an array & or vector
	int m_Type;		//Stores the type of object of this family it is
	int m_Family;	//Stores which family this object belongs to
	OpenGLTexture * m_Texture; //Stores the texture
};

#endif