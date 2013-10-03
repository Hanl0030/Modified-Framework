#ifndef IMAGE_H
#define IMAGE_H

#include "../OpenGL/OpenGL.h"
#include "../Utils/Utility Objects.h"
#include <string>

using std::string;

class Image
{
private:
    OpenGLTexture * m_Texture;
    RectF m_Rect;
public:
    Image(float xPosition, float yPosition, float width, float height, string filename);
    Image();
    ~Image();

    void draw();
    void update();

    void setXPosition(int xPosition);
    void setYPosition(int yPosition);
    void setWidth(int width);
    void setHeight(int height);

    float getXPosition();
    float getYPosition();
    float getWidth();
    float getHeight();

};

#endif