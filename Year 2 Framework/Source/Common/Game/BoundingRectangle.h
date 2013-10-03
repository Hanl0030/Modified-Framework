#ifndef BOUNDINGRECTANGLE_H
#define BOUNDINGRECTANGLE_H

#include "Collideable.h"

//Method Call Definitions
const int RECTANGLE_CHECK_COLLISION_VAR_0       = COLLIDEABLE_CHECK_COLLISION_VAR_0; //If the user calls it by mistake it will still call what they are trying to call
const int RECTANGLE_CHECK_COLLISION_VAR_1       = COLLIDEABLE_GET_CURRENT_DIRECTION + 100;
const int RECTANGLE_CHECK_COLLISION_VAR_2       = COLLIDEABLE_GET_CURRENT_DIRECTION + 101;
const int RECTANGLE_REFINED_COLLISION_DETECTION = COLLIDEABLE_GET_CURRENT_DIRECTION + 102;
const int RECTANGLE_SET_POSITION                = COLLIDEABLE_GET_CURRENT_DIRECTION + 103;
const int RECTANGLE_SET_X_POSITION              = COLLIDEABLE_GET_CURRENT_DIRECTION + 104;
const int RECTANGLE_SET_Y_POSITION              = COLLIDEABLE_GET_CURRENT_DIRECTION + 105;

class BoundingRectangle : public Collideable
{
private:

protected:
    RectF m_RectangleBounds;
    bool m_ShowRectangleBounds;
    bool m_PerformRefinedCollisionDetection;

    virtual void collisionDetection(RectF rect);
    virtual void collisionDetection(CircleF circle);

public:
    BoundingRectangle();
    virtual ~BoundingRectangle();

    virtual void draw();
    virtual int update();
    virtual bool checkCollision(RectF bounds, int &intersectingSide);
    virtual bool checkCollision(CircleF bounds, int &intersectingSide);
    virtual bool checkCollision(Param bounds, int &intersectingSide); //basic collision detection (returns true if collision was detected)
    //This collisionDetection function is what is called if there was a collision
    //It will find at what point the intersection occurred if it was a circle
    //It will find at which side the external and internal geometry is intersecting at
    virtual void refinedCollisionDetection(Param bounds, int &intersectingSide);

    virtual void setPosition(Vector2F position);
    virtual void setXPosition(float x);
    virtual void setYPosition(float y);



    //Call Method Method's...
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