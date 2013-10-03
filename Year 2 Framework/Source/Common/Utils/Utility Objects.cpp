#include "Utility Objects.h"


int CircleI::getLeft()
{
    return m_Position.x - m_Radius;
}
int CircleI::getRight()
{
    return m_Position.x + m_Radius;
}
int CircleI::getTop()
{
    return m_Position.y - m_Radius;
}
int CircleI::getBottom()
{
    return m_Position.y + m_Radius;
}
Vector2I CircleI::getCentre()
{
    return m_Position;
}

float CircleF::getLeft()
{
    return m_Position.x - m_Radius;
}

float CircleF::getRight()
{
    return m_Position.x + m_Radius;
}
float CircleF::getTop()
{
    return m_Position.y - m_Radius;
}
float CircleF::getBottom()
{
    return m_Position.y + m_Radius;
}
Vector2F CircleF::getCentre()
{
    return m_Position;
}


int RectI::getLeft()
{
    return m_Position.x;
}
int RectI::getRight()
{
    return m_Position.x + m_Size.width;
}
int RectI::getTop()
{
    return m_Position.y;
}
int RectI::getBottom()
{
    return m_Position.y + m_Size.height;
}
Vector2I RectI::getTopLeftVertex() //This is also the same as calling to get the position;
{
    return m_Position;
}
Vector2I RectI::getTopRightVertex()
{
    Vector2I vector;
    vector.x = getRight();
    vector.y = getTop();
    return vector;
}
Vector2I RectI::getBottomLeftVertex()
{
    Vector2I vector;
    vector.x = getLeft();
    vector.y = getBottom();
    return vector;
}
Vector2I RectI::getBottomRightVertex()
{
    Vector2I vector;
    vector.x = getRight();
    vector.y = getBottom();
    return vector;
}
Vector2I RectI::getCentre()
{
    Vector2I vector;
    vector.x = m_Position.x + (m_Size.width/2);
    vector.y = m_Position.y + (m_Size.height/2);
    return vector;
}

void RectF::setZero() //sets all values to zero
{
    m_Position.x = 0;
    m_Position.y = 0;
    m_Size.width = 0;
    m_Size.height = 0;

}
float RectF::getLeft()
{
    return m_Position.x;
}
float RectF::getRight()
{
    return m_Position.x + m_Size.width;
}
float RectF::getTop()
{
    return m_Position.y;
}
float RectF::getBottom()
{
    return m_Position.y + m_Size.height;
}
Vector2F RectF::getTopLeftVertex()//This is also the same as calling to get the position;
{
    return m_Position;
}
Vector2F RectF::getTopRightVertex()
{
    Vector2F vector;
    vector.x = getRight();
    vector.y = getTop();
    return vector;
}
Vector2F RectF::getBottomLeftVertex()
{
    Vector2F vector;
    vector.x = getLeft();
    vector.y = getBottom();
    return vector;
}
Vector2F RectF::getBottomRightVertex()
{
    Vector2F vector;
    vector.x = getRight();
    vector.y = getBottom();
    return vector;
}
Vector2F RectF::getCentre()
{
    Vector2F vector;
    vector.x = m_Position.x + (m_Size.width/2);
    vector.y = m_Position.y + (m_Size.height/2);
    return vector;
}
Param::Param()
{
    m_Type = 0;
}
Param::~Param()
{

}
void Param::setType(int type)
{
    m_Type = type;
}
int Param::getType()
{
    return m_Type;
}

CircleI scaleShape(CircleI circle, int scale)
{
    circle.m_Radius *= scale;

    return circle;
}
CircleF scaleShape(CircleF circle, float scale)
{
    circle.m_Radius *= scale;
    return circle;
}
RectI   scaleShape(RectI rect, int scale)
{
    rect.m_Size.width *= scale;
    rect.m_Size.height *= scale;
    return rect;
}
RectF   scaleShape(RectF rect, float scale)
{
    rect.m_Size.width *= scale;
    rect.m_Size.height *= scale;
    return rect;
}