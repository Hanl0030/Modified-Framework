#ifndef BUTTON_H
#define BUTTON_H

#include "Interface Object.h"
#include <string>

using std::string;


//To use

//Class dependant on    
//                      InterfaceObject.h
//                      class InterfaceObject
//                      string
//                      MouseListener.h
//                      OpenGL.h
//                      ObjectCounter.h
//                      Constants.h
//                      UtilityObjects.h
//Design Logic:
//The user will constantly be putting input into the button
//the input to the button will be tracked in the MouseListener (Simpleton Design && See MouseListener.h for more info)
//the update method of Button use the listener to grab the input data and determine its state
//update returns the mouse state as well as BUTTON_GET_STATE passed as a parameter to getData();
//Display:
//The button will draw its primitive shape and flash with colors matching a state
//If a texture was loaded onto the button (AT CREATION ONLY) the button will then have the texture ontop of the primitive shape;
class Button : public InterfaceObject
{
public:
    //Overloaded constructor to take in the filename for a texture
	Button(int id, int idCreate, float x, float y, float width, float height, string filename);
    //Overloaded constructor to take in position and size
	Button(int id, int idCreate, float x, float y, float width ,float height);
    //Overloaded constructor to take in the id and create
	Button(int id, int idCreate);
    //Default contructor, will setup defaults..
	Button();
	virtual ~Button();

	virtual int update(); //Kept virtual in case there are other iterations of button down the road
	virtual void draw(); //See update comment

	
	virtual Param getData(int data); //See update comment
	

private:
    //Updates the state of the button, called in update()
	void updateState(); //See comments in the .cpp file for more info
    //Checks if the mouse x and y position are within the bounds of the button, called in update()
	bool mouseInBounds();//See comments in the .cpp file for more info

	int m_ButtonState; //Stores the state that the button is in
	bool m_WaitingForLeftUp; //Flag for mouse states
	bool m_WaitingForRightUp;//Flag for mouse states


};

#endif