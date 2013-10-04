#include "Interface Objects Constants.h"
//Family names
const int FAMILY_INTERFACE_OBJECT = 0;


//Type names and their constants
//InterfaceObject setup constants
const int INTERFACE_OBJECT_TYPE = 0;
const int INTERFACE_OBJECT_FAMILY = FAMILY_INTERFACE_OBJECT;
const float INTERFACE_DEFAULT_POSITION_X = 0.0f;
const float INTERFACE_DEFAULT_POSITION_Y = 0.0f;
const float INTERFACE_DEFAULT_SIZE_WIDTH = 100.0f;
const float INTERFACE_DEFAULT_SIZE_HEIGHT = 100.0f;

//Button setup constants
const int BUTTON_TYPE = 1;
const int BUTTON_FAMILY = FAMILY_INTERFACE_OBJECT;
const float BUTTON_DEFAULT_POSITION_X = 0.0f;
const float BUTTON_DEFAULT_POSITION_Y = 0.0f;
const float BUTTON_DEFAULT_SIZE_WIDTH = 100.0f;
const float BUTTON_DEFAULT_SIZE_HEIGHT = 100.0f;

//Button States
const int BUTTON_NULL = 0;
const int BUTTON_LEFT_PRESSED = 1;
const int BUTTON_RIGHT_PRESSED = 2;
const int BUTTON_HOVER = 3;

//Button getData() valid parameter
const int BUTTON_GET_STATE = 1;