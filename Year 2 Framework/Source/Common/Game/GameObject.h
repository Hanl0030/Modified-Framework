#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../OpenGL/OpenGL.h"
#include "../Utils/Utility Objects.h"
//Game Object definitions
//Tier 1
#define GAME_OBJECT                     0
//Tier 2
#define COLLIDEABLE_OBJECT              1
#define INTERFACE_OBJECT                2
#define IMAGE_OBJECT                    10
//Sub-Tier  2
#define BOUNDING_CIRCLE_OBJECT          3
#define BOUNDING_RECTANGLE_OBJECT       4
//Tier 3
#define BALL_OBJECT                     5
#define PADDLE_OBJECT                   6
#define BRICK_OBJECT                    7
#define LIFE_BAR_OBJECT                 8
#define BUTTON_OBJECT                   9

class GameObject
{
private:

protected:
    Vector2F m_Position; //position of game object
    int m_Type;            //For checking what type of object it is
public:
    GameObject();
    virtual ~GameObject();

    virtual int getType();
    virtual void draw() = 0;
    virtual int update() = 0;

    //set position methods
    virtual void setPosition(float x, float y);
    virtual void setPosition(Vector2F position);
    virtual void setXPosition(float x);
    virtual void setYPosition(float y);
    //get position methods
    virtual void getPosition(float &x, float &y);
    virtual Vector2F getPosition();
    virtual float getXPosition();
    virtual float getYPosition();

    virtual void callMethod(int methodName) = 0;
    virtual void callMethod(int methodName, Param a) = 0;
    virtual void callMethodReturn(int methodName, Param &a) = 0;
    virtual void callMethod(int methodName, Param a, Param &b) = 0;
    virtual void callMethod(int methodName, Param a, Param b, Param &c) = 0;
    virtual void callMethod(int methodName, Param a, Param b, Param &c, Param &d) = 0;
    virtual void callMethod(int methodName, Param a, Param b, Param c, Param &d, Param &e) = 0;
    virtual void callMethod(int methodName, Param a, Param b, Param c, Param &d, Param &e, Param &f) = 0;
    virtual void callMethod(int methodName, Param a, Param b, Param c, Param d, Param &e, Param &f, Param &g) = 0;
    virtual void callMethod(int methodName, Param a, Param b, Param c, Param d, Param &e, Param &f, Param &g, Param &h) = 0;
    virtual void callMethod(int methodName, Param a, Param b, Param c, Param d, Param e, Param &f, Param &g, Param &h, Param &i) = 0;
    virtual void callMethod(int methodName, Param a, Param b, Param c, Param d, Param e, Param &f, Param &g, Param &h, Param &i, Param &j) = 0;
    


};


#endif