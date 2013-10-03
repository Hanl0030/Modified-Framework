#include "BoundingCircle.h"

BoundingCircle::BoundingCircle()
{
    m_Type = BOUNDING_CIRCLE_OBJECT;
    m_CircleBounds.m_Position.x = 0;
    m_CircleBounds.m_Position.y = 0;
    m_CircleBounds.m_Radius = 0;
    m_ShowCircleBounds = true;
    m_PerformRefinedCollisionDetection = false;
    
}
BoundingCircle::~BoundingCircle()
{
}
void BoundingCircle::draw()
{
    if(m_ShowCircleBounds == true)
    {
        OpenGLRenderer::getInstance()->drawCircle(m_CircleBounds.m_Position.x,m_CircleBounds.m_Position.y,m_CircleBounds.m_Radius);
    }
}
int BoundingCircle::update()
{
    return -1;
}

bool BoundingCircle::checkCollision(RectF bounds, int &intersectingSide)
{
    
    if(m_PerformRefinedCollisionDetection == true)
    {
        collisionDetection(bounds);
    }
    //TO DO: Add the basic collision detection code
    return true;
}
bool BoundingCircle::checkCollision(CircleF bounds, int &intersectingSide)
{
    if(m_PerformRefinedCollisionDetection == true)
    {
        collisionDetection(bounds);
    }
    //TO DO: Add the basic collision detection code
    return true;
}
bool BoundingCircle::checkCollision(Param bounds, int &intersectingSide)
{
    if(bounds.getType() != UNION_TYPE_RECTF || bounds.getType() != UNION_TYPE_CIRCLEF)
    {
        return false;
    }
    //TO DO: Add the basic collision detection code
    return true;
}

void BoundingCircle::refinedCollisionDetection(Param bounds, int &intersectingSide)
{
}
void BoundingCircle::collisionDetection(RectF rect)
{
}
void BoundingCircle::collisionDetection(CircleF circle)
{
}
void BoundingCircle::moveObject(int direction)
{
    switch(direction)
    {
    case DIRECTION_UP:
       setYPosition(m_Position.y -= m_Velocity.y);
       break;
    case DIRECTION_DOWN:
        setYPosition(m_Position.y += m_Velocity.y);
        break;
    case DIRECTION_LEFT:
        setXPosition(m_Position.x -= m_Velocity.x);
        break;
    case DIRECTION_RIGHT:
        setXPosition(m_Position.x += m_Velocity.x);
        break;
    case DIRECTION_NULL:
        //If no direction roam???
        break;
    }
}

void BoundingCircle::setPosition(Vector2F position)
{
    m_Position = position;
    m_CircleBounds.m_Position = position;
}

void BoundingCircle::setXPosition(float x)
{
    m_Position.x = x;
    m_CircleBounds.m_Position.x = x;
}
void BoundingCircle::setYPosition(float y)
{
    m_Position.y = y;
    m_CircleBounds.m_Position.y = y;
}


void BoundingCircle::callMethod(int methodName)
{
    switch(methodName)
    {
    case COLLIDEABLE_INVERT_VELOCITY:
        invertVelocity();
        break;
    case COLLIDEABLE_INVERT_X_VELOCITY:
        invertXVelocity();
        break;
    case COLLIDEABLE_INVERT_Y_VELOCITY:
        invertYVelocity();
        break;
    
    }
}
void BoundingCircle::callMethod(int methodName, Param a)
{
    switch(methodName)
    {
    case COLLIDEABLE_SET_VELOCITY_VAR_0:
        setVelocity(a.m_Param.vec2f);
        break;
    case COLLIDEABLE_SET_VELOCITY_VAR_1:
        setVelocity(a.m_Param.vec2f.x,a.m_Param.vec2f.y);
        break;
    case COLLIDEABLE_SET_X_VELOCITY:
        setXVelocity(a.m_Param.f);
        break;
    case COLLIDEABLE_SET_Y_VELOCITY:
        setYVelocity(a.m_Param.f);
        break;
    case COLLIDEABLE_SET_PREVIOUS_DIRECTION:
        setPreviousDirection(a.m_Param.i);
        break;
    case COLLIDEABLE_SET_CURRENT_DIRECTION:
        setCurrentDirection(a.m_Param.i);
        break;
    case CIRCLE_SET_POSITION:
        setPosition(a.m_Param.vec2f);
        break;
    case CIRCLE_SET_X_POSITION:
        setXPosition(a.m_Param.f);
        break;
    case CIRCLE_SET_Y_POSITION:
        setYPosition(a.m_Param.f);
        break;
    case CIRCLE_MOVE_OBJECT:
        moveObject(a.m_Param.i);
        break;
    }
    
}
void BoundingCircle::callMethodReturn(int methodName, Param &a)
{
    switch(methodName)
    {
    case COLLIDEABLE_GET_VELOCITY_VAR_0:
        a.m_Param.vec2f = getVelocity();
        break;
    case COLLIDEABLE_GET_VELOCITY_VAR_1:
        getVelocity(a.m_Param.vec2f.x,a.m_Param.vec2f.y);
        break;
    case COLLIDEABLE_GET_X_VELOCITY:
        a.m_Param.f = getXVelocity();
        break;
    case COLLIDEABLE_GET_Y_VELOCITY:
        a.m_Param.f = getYVelocity();
        break;
    case COLLIDEABLE_GET_PREVIOUS_DIRECTION:
        a.m_Param.i = getPreviousDirection();
        break;
    case COLLIDEABLE_GET_CURRENT_DIRECTION:
        a.m_Param.i = getCurrentDirection();
        break;

    }
}
void BoundingCircle::callMethod(int methodName, Param a, Param &b)
{
    switch(methodName)
    {
    case CIRCLE_REFINED_COLLISION_DETECTION:
        refinedCollisionDetection(a,b.m_Param.i);
        break;
    }
}
void BoundingCircle::callMethod(int methodName, Param a, Param b, Param &c)
{
    switch(methodName)
    {
   
        break;
    }
}
void BoundingCircle::callMethod(int methodName, Param a, Param b, Param &c, Param &d)
{
    switch(methodName)
    {
    case CIRCLE_CHECK_COLLISION_VAR_0:
        c.m_Param.b = checkCollision(a,d.m_Param.i);
        break;
    case CIRCLE_CHECK_COLLISION_VAR_1:
        c.m_Param.b = checkCollision(a.m_Param.rectf,d.m_Param.i);
        break;
    case CIRCLE_CHECK_COLLISION_VAR_2:
        c.m_Param.b = checkCollision(a.m_Param.circf,d.m_Param.i);
        break;
    }
}
void BoundingCircle::callMethod(int methodName, Param a, Param b, Param c, Param &d, Param &e)
{
    switch(methodName)
    {

    }
}
void BoundingCircle::callMethod(int methodName, Param a, Param b, Param c, Param &d, Param &e, Param &f)
{
    switch(methodName)
    {
    
    }
}
void BoundingCircle::callMethod(int methodName, Param a, Param b, Param c, Param d, Param &e, Param &f, Param &g)
{
    switch(methodName)
    {
    
    }
}
void BoundingCircle::callMethod(int methodName, Param a, Param b, Param c, Param d, Param &e, Param &f, Param &g, Param &h)
{
    switch(methodName)
    {
    
    }
}
void BoundingCircle::callMethod(int methodName, Param a, Param b, Param c, Param d, Param e, Param &f, Param &g, Param &h, Param &i)
{
    switch(methodName)
    {

    }
}
void BoundingCircle::callMethod(int methodName, Param a, Param b, Param c, Param d, Param e, Param &f, Param &g, Param &h, Param &i, Param &j)
{
    switch(methodName)
    {

    }
}