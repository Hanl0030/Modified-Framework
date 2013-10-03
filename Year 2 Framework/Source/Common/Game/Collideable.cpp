#include "Collideable.h"

Collideable::Collideable()
{
    m_Type = COLLIDEABLE_OBJECT;
    m_Velocity.x = 0;
    m_Velocity.y = 0;
    m_PreviousDirection = DIRECTION_NULL;
    m_CurrentDirection = DIRECTION_NULL;
}
Collideable::~Collideable()
{

}

void Collideable::setVelocity(Vector2F velocity)
{
    m_Velocity = velocity;
}
void Collideable::setVelocity(float xVelocity, float yVelocity)
{
   setXVelocity(xVelocity);
   setYVelocity(yVelocity);
}
void Collideable::setXVelocity(float velocity)
{
    m_Velocity.x = velocity;
}
void Collideable::setYVelocity(float velocity)
{
    m_Velocity.y = velocity;
}
Vector2F Collideable::getVelocity()
{
    return m_Velocity;
}
void Collideable::getVelocity(float &xVelocity, float &yVelocity)
{
    xVelocity = getXVelocity();
    yVelocity = getYVelocity();
}
float Collideable::getXVelocity()
{
    return m_Velocity.x;
}
float Collideable::getYVelocity()
{
    return m_Velocity.y;
}
void Collideable::invertVelocity()
{
    invertXVelocity();
    invertYVelocity();
}

void Collideable::invertXVelocity()
{
    m_Velocity.x = (-1.0f * m_Velocity.x);
}
void Collideable::invertYVelocity()
{
    m_Velocity.y = (-1.0f * m_Velocity.y);
}

void Collideable::setPreviousDirection(int direction)
{
    m_PreviousDirection = direction;
}
void Collideable::setCurrentDirection(int direction)
{
    m_CurrentDirection = direction;
}

int Collideable::getPreviousDirection()
{
    return m_PreviousDirection;
}
int Collideable::getCurrentDirection()
{
    return m_CurrentDirection;
}

void Collideable::callMethod(int methodName)
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
void Collideable::callMethod(int methodName, Param a)
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
    }
    
}
void Collideable::callMethodReturn(int methodName, Param &a)
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
void Collideable::callMethod(int methodName, Param a, Param &b)
{
    switch(methodName)
    {

    }
}
void Collideable::callMethod(int methodName, Param a, Param b, Param &c)
{
    switch(methodName)
    {

    }
}
void Collideable::callMethod(int methodName, Param a, Param b, Param &c, Param &d)
{
    switch(methodName)
    {

    }
}
void Collideable::callMethod(int methodName, Param a, Param b, Param c, Param &d, Param &e)
{
    switch(methodName)
    {

    }
}
void Collideable::callMethod(int methodName, Param a, Param b, Param c, Param &d, Param &e, Param &f)
{
    switch(methodName)
    {

    }
}
void Collideable::callMethod(int methodName, Param a, Param b, Param c, Param d, Param &e, Param &f, Param &g)
{
    switch(methodName)
    {
    
    }
}
void Collideable::callMethod(int methodName, Param a, Param b, Param c, Param d, Param &e, Param &f, Param &g, Param &h)
{
    switch(methodName)
    {
    
    }
}
void Collideable::callMethod(int methodName, Param a, Param b, Param c, Param d, Param e, Param &f, Param &g, Param &h, Param &i)
{
    switch(methodName)
    {

    }
}
void Collideable::callMethod(int methodName, Param a, Param b, Param c, Param d, Param e, Param &f, Param &g, Param &h, Param &i, Param &j)
{
    switch(methodName)
    {

    }
}