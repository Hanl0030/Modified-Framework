#include "BoundingRectangle.h"

BoundingRectangle::BoundingRectangle()
{
    m_Type = BOUNDING_RECTANGLE_OBJECT;
    m_RectangleBounds.m_Position.x = 0.0f;
    m_RectangleBounds.m_Position.y = 0.0f;
    m_RectangleBounds.m_Size.width = 0.0f;
    m_RectangleBounds.m_Size.height = 0.0f;
    m_ShowRectangleBounds = true;
    m_PerformRefinedCollisionDetection = true;
    
}
BoundingRectangle::~BoundingRectangle()
{
}

void BoundingRectangle::draw()
{
    if(m_ShowRectangleBounds == true)
    {
        OpenGLRenderer::getInstance()->drawRectangle(m_RectangleBounds.m_Position.x,m_RectangleBounds.m_Position.y,m_RectangleBounds.m_Size.width,m_RectangleBounds.m_Size.height);
    }
}
int BoundingRectangle::update()
{
    return -1;
}

bool BoundingRectangle::checkCollision(RectF bounds, int &intersectingSide)
{
    //Do simple bounding box collision

    //if there was a collision
    if(m_PerformRefinedCollisionDetection == true)
    {
        collisionDetection(bounds);
    }
    return true;
}
bool BoundingRectangle::checkCollision(CircleF bounds, int &intersectingSide)
{
    //do corner checks
    //do side checks
    //if there was a collision further the investigation
    if(m_PerformRefinedCollisionDetection == true)
    {
        collisionDetection(bounds);
    }
    return true;
}
bool BoundingRectangle::checkCollision(Param bounds, int &intersectingSide)//basic collision detection (returns true if collision was detected)
{
    //Check if the parameter is of type rect or circle
    int type = bounds.getType();
    if(type != UNION_TYPE_RECTF || type != UNION_TYPE_CIRCLEF)
    {
        return false; //were not  calculating collision with integers
    }
    if(type == UNION_TYPE_RECTF)
    {
        //Do simple bounding box collision detection
    }
    if(type == UNION_TYPE_CIRCLEF)
    {
        //Do Corner Checks

        //Do Side Checks
    }

    //if we haven't returned then we do refiendCollisionDetection
    if(m_PerformRefinedCollisionDetection == true)
    {
        refinedCollisionDetection(bounds, intersectingSide);
    }
    return true;
}

void BoundingRectangle::refinedCollisionDetection(Param bounds, int &intersectingSide)
{
    Vector2F pointOfIntersection;
    if(bounds.getType() == UNION_TYPE_RECTF)
    {
        collisionDetection(bounds.m_Param.rectf);
    }
    else
    {
        collisionDetection(bounds.m_Param.circf);
    }
}
void BoundingRectangle::collisionDetection(RectF rect)
{
    //Check to see if y is within the member left and right x
    //if right is > member left - then move right
    //if left is < member right - then move left
    //if 
    //see notes
}
void BoundingRectangle::collisionDetection(CircleF circle)
{
    //see notes
}
void BoundingRectangle::setPosition(Vector2F position)
{
    m_Position = position;
    m_RectangleBounds.m_Position = position;
}
void BoundingRectangle::setXPosition(float x)
{
    m_Position.x = x;
    m_RectangleBounds.m_Position.x;
}
void BoundingRectangle::setYPosition(float y)
{
    m_Position.y = y;
    m_RectangleBounds.m_Position.y;
}


void BoundingRectangle::callMethod(int methodName)
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
void BoundingRectangle::callMethod(int methodName, Param a)
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
    case RECTANGLE_SET_POSITION:
        setPosition(a.m_Param.vec2f);
        break;
    case RECTANGLE_SET_X_POSITION:
        setXPosition(a.m_Param.f);
        break;
    case RECTANGLE_SET_Y_POSITION:
        setYPosition(a.m_Param.f);
        break;
    }
    
}
void BoundingRectangle::callMethodReturn(int methodName, Param &a)
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
void BoundingRectangle::callMethod(int methodName, Param a, Param &b)
{
    switch(methodName)
    {
    case RECTANGLE_REFINED_COLLISION_DETECTION:
        refinedCollisionDetection(a,b.m_Param.i);
        break;
    }
}
void BoundingRectangle::callMethod(int methodName, Param a, Param b, Param &c)
{
    switch(methodName)
    {
   
        break;
    }
}
void BoundingRectangle::callMethod(int methodName, Param a, Param b, Param &c, Param &d)
{
    switch(methodName)
    {
    case RECTANGLE_CHECK_COLLISION_VAR_0:
        c.m_Param.b = checkCollision(a,d.m_Param.i);
        break;
    case RECTANGLE_CHECK_COLLISION_VAR_1:
        c.m_Param.b = checkCollision(a.m_Param.rectf,d.m_Param.i);
        break;
    case RECTANGLE_CHECK_COLLISION_VAR_2:
        c.m_Param.b = checkCollision(a.m_Param.circf,d.m_Param.i);
        break;
    }
}
void BoundingRectangle::callMethod(int methodName, Param a, Param b, Param c, Param &d, Param &e)
{
    switch(methodName)
    {

    }
}
void BoundingRectangle::callMethod(int methodName, Param a, Param b, Param c, Param &d, Param &e, Param &f)
{
    switch(methodName)
    {
    
    }
}
void BoundingRectangle::callMethod(int methodName, Param a, Param b, Param c, Param d, Param &e, Param &f, Param &g)
{
    switch(methodName)
    {
    
    }
}
void BoundingRectangle::callMethod(int methodName, Param a, Param b, Param c, Param d, Param &e, Param &f, Param &g, Param &h)
{
    switch(methodName)
    {
    
    }
}
void BoundingRectangle::callMethod(int methodName, Param a, Param b, Param c, Param d, Param e, Param &f, Param &g, Param &h, Param &i)
{
    switch(methodName)
    {

    }
}
void BoundingRectangle::callMethod(int methodName, Param a, Param b, Param c, Param d, Param e, Param &f, Param &g, Param &h, Param &i, Param &j)
{
    switch(methodName)
    {

    }
}