#include "ObjectCounter.h"

//Global counters for objects

int g_NumberOfObjects = 0; //How many objects there are in the world?

//Naming convention
//Naming a family
//g_NumberOfFamilyName
//Naming a object of type family
//g_NumberOfObjectName_FamilyName

int g_NumberOfInterfaceFamily = 0; //How many objects have been created that are part of the interface family
int g_NumberOfInterfaceObject_InterfaceObject = 0; //How many specific interface objects are there? Should be 0 because it's abstract
int g_NumberOfButtons_InterfaceObject = 0; //How many specific buttons of type interface object 