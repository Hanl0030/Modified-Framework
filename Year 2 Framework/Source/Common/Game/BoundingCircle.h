#ifndef BOUNDINGCIRCLE_H
#define BOUNDINGCIRCLE_H

#include "Collideable.h"

const int CIRCLE_CHECK_COLLISION_VAR_0                      = COLLIDEABLE_CHECK_COLLISION_VAR_0;
const int CIRCLE_CHECK_COLLISION_VAR_1                      = COLLIDEABLE_GET_CURRENT_DIRECTION + 100;
const int CIRCLE_CHECK_COLLISION_VAR_2                      = COLLIDEABLE_GET_CURRENT_DIRECTION + 101;           
const int CIRCLE_REFINED_COLLISION_DETECTION                = COLLIDEABLE_GET_CURRENT_DIRECTION + 102;
const int CIRCLE_MOVE_OBJECT                                = COLLIDEABLE_GET_CURRENT_DIRECTION + 103;
const int CIRCLE_SET_POSITION                               = COLLIDEABLE_GET_CURRENT_DIRECTION + 104;
const int CIRCLE_SET_X_POSITION                             = COLLIDEABLE_GET_CURRENT_DIRECTION + 105; 
const int CIRCLE_SET_Y_POSITION                             = COLLIDEABLE_GET_CURRENT_DIRECTION + 106;


class BoundingCircle : public Collideable
{
private:

protected:
    CircleF m_CircleBounds;
    bool m_ShowCircleBounds;
    bool m_PerformRefinedCollisionDetection;

    virtual void collisionDetection(RectF rect);
    virtual void collisionDetection(CircleF circle);
public:
    BoundingCircle();
    ~BoundingCircle();
    virtual void draw();
    virtual int update();

    virtual bool checkCollision(RectF bounds, int &intersectingSide);
    virtual bool checkCollision(CircleF bounds, int &intersectingSide);
    virtual bool checkCollision(Param bounds, int &intersectingSide);

    virtual void refinedCollisionDetection(Param bounds, int &intersectingSide);

    virtual void moveObject(int direction = 0);

    virtual void setPosition(Vector2F position);
    virtual void setXPosition(float x);
    virtual void setYPosition(float y);




    //Call Method, Methods

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