#include "Image.h"


Image::Image(float xPosition, float yPosition, float width, float height, string filename)
{
    m_Texture = 0;
    m_Rect.m_Position.x = xPosition;
    m_Rect.m_Position.y = yPosition;
    m_Rect.m_Size.width = width;
    m_Rect.m_Size.height = height;
    //if(filename != "")
    //{
    m_Texture = new OpenGLTexture("MenuScreenBackground");
    //}

}
Image::Image()
{
    m_Texture = 0;
    m_Rect.setZero();
}
Image::~Image()
{
}

void Image::draw()
{
   
        //OpenGLRenderer::getInstance()->drawTexture(m_Texture,m_Rect.m_Position.x,m_Rect.m_Position.y,m_Rect.m_Size.width,m_Rect.m_Size.height);
        OpenGLRenderer::getInstance()->drawTexture(m_Texture,0.0f,0.0f);
    
}
void Image::update()
{
}

void Image::setXPosition(int xPosition)
{
    m_Rect.m_Position.x = xPosition;
}
void Image::setYPosition(int yPosition)
{
    m_Rect.m_Position.y = yPosition;
}
void Image::setWidth(int width)
{
    m_Rect.m_Size.width = width;
}
void Image::setHeight(int height)
{
    m_Rect.m_Size.height = height;
}
float Image::getXPosition()
{
    return m_Rect.m_Position.x;
}
float Image::getYPosition()
{
    return m_Rect.m_Position.y;
}
float Image::getWidth()
{
    return m_Rect.m_Size.width;
}
float Image::getHeight()
{
    return m_Rect.m_Size.height;
}