#include "GameObject.h"

GameObject::GameObject()
{
    m_Type = GAME_OBJECT;
}
GameObject::~GameObject()
{

}

int GameObject::getType()
{
    return m_Type;
}

//set position methods
void GameObject::setPosition(float x, float y)
{
    setXPosition(x);
    setYPosition(y);
}
void GameObject::setPosition(Vector2F position)
{
    m_Position = position;
}
void GameObject::setXPosition(float x)
{
    m_Position.x = x;
}
void GameObject::setYPosition(float y)
{
    m_Position.y = y;
}
//get position methods
void GameObject::getPosition(float &x, float &y)
{
    x = getXPosition();
    y = getYPosition();
}
Vector2F GameObject::getPosition()
{
    return m_Position;
}
float GameObject::getXPosition()
{
    return m_Position.x;
}
float GameObject::getYPosition()
{
    return m_Position.y;
}