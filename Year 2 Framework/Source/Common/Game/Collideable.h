#ifndef COLLIDEABLE_H
#define COLLIDEABLE_H

#include "GameObject.h"


#define DIRECTION_NULL  0
#define DIRECTION_UP    1
#define DIRECTION_DOWN  2
#define DIRECTION_LEFT  3
#define DIRECTION_RIGHT 4

//define call methods
const int COLLIDEABLE_CHECK_COLLISION_VAR_0   = 0 ;
const int COLLIDEABLE_MOVE_OBJECT             = 1 ;
const int COLLIDEABLE_SET_VELOCITY_VAR_0      = 2 ;
const int COLLIDEABLE_SET_VELOCITY_VAR_1      = 3 ;
const int COLLIDEABLE_SET_X_VELOCITY          = 4 ;
const int COLLIDEABLE_SET_Y_VELOCITY          = 5 ;
const int COLLIDEABLE_GET_VELOCITY_VAR_0      = 6 ;
const int COLLIDEABLE_GET_VELOCITY_VAR_1      = 7 ;
const int COLLIDEABLE_GET_X_VELOCITY          = 8 ;
const int COLLIDEABLE_GET_Y_VELOCITY          = 9 ;
const int COLLIDEABLE_INVERT_VELOCITY         = 10;
const int COLLIDEABLE_INVERT_X_VELOCITY       = 11;
const int COLLIDEABLE_INVERT_Y_VELOCITY       = 12;
const int COLLIDEABLE_SET_PREVIOUS_DIRECTION  = 13;
const int COLLIDEABLE_GET_PREVIOUS_DIRECTION  = 14;
const int COLLIDEABLE_SET_CURRENT_DIRECTION   = 15;
const int COLLIDEABLE_GET_CURRENT_DIRECTION   = 16;


class Collideable : public GameObject
{
private:

protected:
    Vector2F m_Velocity;
    int m_PreviousDirection;
    int m_CurrentDirection;
public:
    Collideable();
    virtual ~Collideable();

    virtual void draw() = 0;
    virtual int update() = 0;

    //Added from Collideable
    virtual bool checkCollision(Param bounds) = 0; //basic collision detection (returns true if collision was detected)
    virtual void moveObject(int direction = 0) = 0;

    virtual void setVelocity(Vector2F velocity);
    virtual void setVelocity(float xVelocity, float yVelocity);
    virtual void setXVelocity(float velocity);
    virtual void setYVelocity(float velocity);
    virtual Vector2F getVelocity();
    virtual void getVelocity(float &xVelocity, float &yVelocity);
    virtual float getXVelocity();
    virtual float getYVelocity();
    virtual void invertVelocity();
    virtual void invertXVelocity();
    virtual void invertYVelocity();

    virtual void setPreviousDirection(int direction);
    virtual void setCurrentDirection(int direction);
    virtual int getPreviousDirection();
    virtual int getCurrentDirection();

    //Call Method Method's...
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