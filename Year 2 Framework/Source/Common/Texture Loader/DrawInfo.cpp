#include "Renderer.h"
#include "SOIL Texture.h"

PointDrawInfo::PointDrawInfo(float x, float y, float red, float blue, float green, float alpha)
{

    //set the vertices
    m_Vertices[0] = x;  m_Vertices[1] = y;
    //set the colors
    m_Colors[0] = red;      m_Colors[1] = green;    m_Colors[2] = blue;     m_Colors[3] = alpha;   //topleft


}
PointDrawInfo::PointDrawInfo(Vector2F position, ColorFloat color)
{
    //set the vertices
    m_Vertices[0] = position.x; m_Vertices[1] = position.y;
    //set the colors
    m_Colors[0] = color.r;      m_Colors[1] = color.g;     m_Colors[2] = color.b;      m_Colors[3] = color.a;
}
PointDrawInfo::PointDrawInfo()
{
    m_Vertices[0] = 0.0f;    m_Vertices[1] = 0.0f;    //topleft
    m_Colors[0] = 1.0f;     m_Colors[1] = 0.0f;     m_Colors[2] = 1.0f;     m_Colors[3] = 1.0f;   //topleft
}
PointDrawInfo::~PointDrawInfo()
{

}
void PointDrawInfo::setX(float x)
{
    m_Vertices[0] = x;
}
void PointDrawInfo::setY(float y)
{
    m_Vertices[1] = y;
}
void PointDrawInfo::setPosition(float x, float y)
{
    //set the vertices
    m_Vertices[0] = x;  m_Vertices[1] = y;
}
void PointDrawInfo::setPosition(Vector2F position)
{
    m_Vertices[0] = position.x; m_Vertices[1] = position.y;
}
void PointDrawInfo::setColor(float red, float green, float blue, float alpha)
{
    m_Colors[0] = red;      m_Colors[1] = green;    m_Colors[2] = blue;     m_Colors[3] = alpha;   //topleft
}

LineDrawInfo::LineDrawInfo(float x1, float y1, float x2, float y2, float red, float green, float blue, float alpha, float rotation)
{
    //setup vertices
    m_Vertices[0] = x1;      m_Vertices[1] = y1;            
    m_Vertices[2] = x2;      m_Vertices[3] = y2;           
    //setup colors
    m_Colors[0] = red;      m_Colors[1] = green;    m_Colors[2] = blue;     m_Colors[3] = alpha;   
    m_Colors[4] = red;      m_Colors[5] = green;    m_Colors[6] = blue;     m_Colors[7] = alpha;   
    
    m_Rotation = rotation;
    calculateCentre();
    setAnchor(RENDERER_VERTEX_CENTER);
}
LineDrawInfo::LineDrawInfo(Vector2F startPoint, Vector2F endPoint, ColorFloat color, float rotation)
{
    //setup vertices
    m_Vertices[0] = startPoint.x;    m_Vertices[1] = startPoint.y;            
    m_Vertices[2] = endPoint.x;      m_Vertices[3] = endPoint.y;           
    //setup colors
    m_Colors[0] = color.r;      m_Colors[1] = color.g;    m_Colors[2] = color.b;     m_Colors[3] = color.a;   
    m_Colors[4] = color.r;      m_Colors[5] = color.g;    m_Colors[6] = color.b;     m_Colors[7] = color.a;   
    
    m_Rotation = rotation;
    calculateCentre();
    setAnchor(RENDERER_VERTEX_CENTER);
}
LineDrawInfo::LineDrawInfo()
{
    //setup vertices
    m_Vertices[0] = 0.0f;    m_Vertices[1] = 0.0f;    //topleft
    m_Vertices[2] = 0.0f;    m_Vertices[3] = 0.0f;    //topright         
    //setup colors
    m_Colors[0] = 1.0f;     m_Colors[1] = 0.0f;     m_Colors[2] = 1.0f;     m_Colors[3] = 1.0f;   //topleft
    m_Colors[4] = 1.0f;     m_Colors[5] = 0.0f;     m_Colors[6] = 1.0f;     m_Colors[7] = 1.0f;   //topright  

    m_Rotation = 0.0f;
    calculateCentre();
    setAnchor(RENDERER_VERTEX_CENTER);
}
LineDrawInfo::~LineDrawInfo()
{

}
void LineDrawInfo::setStartPointX(float x)
{
    m_Vertices[0] = x;
    calculateCentre();
}
void LineDrawInfo::setStartPointY(float y)
{
    m_Vertices[1] = y;
    calculateCentre();
}
void LineDrawInfo::setStartPoint(Vector2F position)
{
    m_Vertices[0] = position.x;
    m_Vertices[1] = position.y;
    calculateCentre();
}
void LineDrawInfo::setEndPointX(float x)
{
    m_Vertices[2] = x;
    calculateCentre();
}
void LineDrawInfo::setEndPointY(float y)
{
    m_Vertices[3] = y;
    calculateCentre();
}
void LineDrawInfo::setEndPoint(Vector2F position)
{
    m_Vertices[2] = position.x;
    m_Vertices[3] = position.y;
    calculateCentre();
}
void LineDrawInfo::setPoints(float x1, float y1, float x2, float y2)
{
    //setup vertices
    m_Vertices[0] = x1;      m_Vertices[1] = y1;            
    m_Vertices[2] = x2;      m_Vertices[3] = y2;  
    calculateCentre();
}
void LineDrawInfo::setPoints(Vector2F startPoint, Vector2F endPoint)
{
    //setup vertices
    m_Vertices[0] = startPoint.x;    m_Vertices[1] = startPoint.y;            
    m_Vertices[2] = endPoint.x;      m_Vertices[3] = endPoint.y;
    calculateCentre();
}
void LineDrawInfo::setColor(float red, float green, float blue, float alpha)
{
    //setup colors
    m_Colors[0] = red;      m_Colors[1] = green;    m_Colors[2] = blue;     m_Colors[3] = alpha;   
    m_Colors[4] = red;      m_Colors[5] = green;    m_Colors[6] = blue;     m_Colors[7] = alpha;   
}
void LineDrawInfo::setColorVertex(unsigned int vertex, float red, float green, float blue, float alpha)
{
    //setup colors
    switch(vertex)
    {
        case RENDERER_VERTEX_1:
            m_Colors[0] = red;      m_Colors[1] = green;    m_Colors[2] = blue;     m_Colors[3] = alpha; 
            break;
        case RENDERER_VERTEX_2:
            m_Colors[4] = red;      m_Colors[5] = green;    m_Colors[6] = blue;     m_Colors[7] = alpha;
            break;
        default:
            m_Colors[0] = red;      m_Colors[1] = green;    m_Colors[2] = blue;     m_Colors[3] = alpha;   
            m_Colors[4] = red;      m_Colors[5] = green;    m_Colors[6] = blue;     m_Colors[7] = alpha;   
            break;
    }
}
void LineDrawInfo::setAnchor(int vertex) //I only want to be able to rotate on a vertex or centre
{
    switch(vertex)
    {
        case RENDERER_VERTEX_1:
            m_Anchor.x = m_Vertices[0];
            m_Anchor.y = m_Vertices[1];
            break;
        case RENDERER_VERTEX_2:
            m_Anchor.x = m_Vertices[2];
            m_Anchor.y = m_Vertices[3];
            break;
        case RENDERER_VERTEX_CENTER:
            m_Anchor = m_CentreVertex;
            break;
    }
}
Vector2F LineDrawInfo::getAnchor()
{
    return m_Anchor;
}
float LineDrawInfo::getAnchorX()
{
    return m_Anchor.x;
}
float LineDrawInfo::getAnchorY()
{
    return m_Anchor.y;
}
void LineDrawInfo::calculateCentre()
{
    //Calculate the distance while keeping their negative or positive value
    float distanceX =  m_Vertices[0] - m_Vertices[2]; 
    float distanceY =  m_Vertices[1] - m_Vertices[3];
    //divie by two to get the centre
    distanceX = distanceX/2; 
    distanceY = distanceY/2;
    //append to distance giving us the centre
    m_CentreVertex.x = distanceX += m_Vertices[0];
    m_CentreVertex.y = distanceY += m_Vertices[1];
}
Vector2F LineDrawInfo::getCentre()
{
    return m_CentreVertex;
}



TriangleDrawInfo::TriangleDrawInfo(Vector2F firstPoint, Vector2F secondPoint, Vector2F thirdPoint, ColorFloat color,float rotation, bool isFilled)
{
    //setup the vertices
    m_Vertices[0] = firstPoint.x;      m_Vertices[1] = firstPoint.y;    //vertex 1
    m_Vertices[2] = secondPoint.x;     m_Vertices[3] = secondPoint.y;    //vertex 2
    m_Vertices[4] = thirdPoint.x;      m_Vertices[5] = thirdPoint.y;    //vertex 3

    m_Colors[0] = color.r;      m_Colors[1] = color.g;    m_Colors[2] = color.b;     m_Colors[3] = color.a;   //vertex 1
    m_Colors[4] = color.r;      m_Colors[5] = color.g;    m_Colors[6] = color.b;     m_Colors[7] = color.a;   //vertex 2
    m_Colors[8] = color.r;      m_Colors[9] = color.g;    m_Colors[10] = color.b;    m_Colors[11] = color.a;  //vertex 3

    m_Rotation = rotation;
    calculateCentre();
    setAnchor(RENDERER_VERTEX_CENTER);
}
TriangleDrawInfo::TriangleDrawInfo()
{
    //setup the vertices
    m_Vertices[0] = 0.0f;      m_Vertices[1] = 0.0f;    //vertex 1
    m_Vertices[2] = 0.0f;      m_Vertices[3] = 0.0f;    //vertex 2
    m_Vertices[4] = 0.0f;      m_Vertices[5] = 0.0f;    //vertex 3

    m_Colors[0] = 0.0f;      m_Colors[1] = 0.0f;    m_Colors[2] = 0.0f;     m_Colors[3] = 0.0f;   //vertex 1
    m_Colors[4] = 0.0f;      m_Colors[5] = 0.0f;    m_Colors[6] = 0.0f;     m_Colors[7] = 0.0f;   //vertex 2
    m_Colors[8] = 0.0f;      m_Colors[9] = 0.0f;    m_Colors[10] = 0.0f;    m_Colors[11] = 0.0f;  //vertex 3

    m_Rotation = 0.0f;
    calculateCentre();
    setAnchor(RENDERER_VERTEX_CENTER);
}
TriangleDrawInfo::~TriangleDrawInfo()
{

}
void TriangleDrawInfo::setPointX(unsigned int vertex, float x)
{
    switch(vertex)
    {
        case RENDERER_VERTEX_1:
            m_Vertices[0] = x;     //vertex 1
            break;
        case RENDERER_VERTEX_2:
            m_Vertices[2] = x;
            break;
        case RENDERER_VERTEX_3:
            m_Vertices[4] = x;
            break;
    }

    calculateCentre();
}
void TriangleDrawInfo::setPointY(unsigned int vertex, float y)
{
    switch(vertex)
    {
        case RENDERER_VERTEX_1:
            m_Vertices[1] = y;    //vertex 1
            break;
        case RENDERER_VERTEX_2:
            m_Vertices[3] = y;
            break;
        case RENDERER_VERTEX_3:
             m_Vertices[5] = y;
             break;
    }
    calculateCentre();
}
void TriangleDrawInfo::setPoint(unsigned int vertex, Vector2F position)
{
    switch(vertex)
    {
        case RENDERER_VERTEX_1:
            m_Vertices[0] = position.x;      m_Vertices[1] = position.y;    //vertex 1
            break;
        case RENDERER_VERTEX_2:
            m_Vertices[2] = position.x;      m_Vertices[3] = position.y;
            break;
        case RENDERER_VERTEX_3:
            m_Vertices[4] = position.x;      m_Vertices[5] = position.y;
            break;
    }
    calculateCentre();
}
void TriangleDrawInfo::setPoints(Vector2F firstPoint, Vector2F secondPoint, Vector2F thirdPoint)
{
    //setup the vertices
    m_Vertices[0] = firstPoint.x;      m_Vertices[1] = firstPoint.y;    //vertex 1
    m_Vertices[2] = secondPoint.x;     m_Vertices[3] = secondPoint.y;    //vertex 2
    m_Vertices[4] = thirdPoint.x;      m_Vertices[5] = thirdPoint.y;    //vertex 3
    calculateCentre();
}
void TriangleDrawInfo::setColor(float red, float green, float blue, float alpha)
{
    m_Colors[0] = red;      m_Colors[1] = green;    m_Colors[2] = blue;     m_Colors[3] = alpha;   //vertex 1
    m_Colors[4] = red;      m_Colors[5] = green;    m_Colors[6] = blue;     m_Colors[7] = alpha;   //vertex 2
    m_Colors[8] = red;      m_Colors[9] = green;    m_Colors[10] = blue;    m_Colors[11] = alpha;  //vertex 3
}
void TriangleDrawInfo::setColorVertex(unsigned int vertex, float red, float green, float blue, float alpha)
{
    switch(vertex)
    {
        case RENDERER_VERTEX_1:
            m_Colors[0] = red;      m_Colors[1] = green;    m_Colors[2] = blue;     m_Colors[3] = alpha;   //vertex 1
            break;                                
        case RENDERER_VERTEX_2:                   
            m_Colors[4] = red;      m_Colors[5] = green;    m_Colors[6] = blue;     m_Colors[7] = alpha;   //vertex 2
            break;                                
        case RENDERER_VERTEX_3:                   
            m_Colors[8] = red;      m_Colors[9] = green;    m_Colors[10] = blue;    m_Colors[11] = alpha;  //vertex 3
            break;                                
        default:                                  
            m_Colors[0] = red;      m_Colors[1] = green;    m_Colors[2] = blue;     m_Colors[3] = alpha;   //vertex 1
            m_Colors[4] = red;      m_Colors[5] = green;    m_Colors[6] = blue;     m_Colors[7] = alpha;   //vertex 2
            m_Colors[8] = red;      m_Colors[9] = green;    m_Colors[10] = blue;    m_Colors[11] = alpha;  //vertex 3
            break;
    }
}
void TriangleDrawInfo::setAnchor(int vertex) //I only want to be able to rotate on a vertex or centre
{
    switch(vertex)
    {
        case RENDERER_VERTEX_1:
            m_Anchor.x = m_Vertices[0];
            m_Anchor.y = m_Vertices[1];
            break;
        case RENDERER_VERTEX_2:
            m_Anchor.x = m_Vertices[2];
            m_Anchor.y = m_Vertices[3];
            break;
        case RENDERER_VERTEX_3:
            m_Anchor.x = m_Vertices[4];
            m_Anchor.y = m_Vertices[5];
            break;
        case RENDERER_VERTEX_CENTER:
            m_Anchor = m_CentreVertex;
            break;
    }
}
Vector2F TriangleDrawInfo::getAnchor()
{
    return m_Anchor;
}
float TriangleDrawInfo::getAnchorX()
{
    return m_Anchor.x;
}
float TriangleDrawInfo::getAnchorY()
{
    return m_Anchor.y;
}
void TriangleDrawInfo::calculateCentre()
{
    //find the mid points for x and y
    //vertex a - vertex b = midpoint
    //use midpoint and vertex c for rest
    float midpointX;
    midpointX = m_Vertices[0] - m_Vertices[2];
    m_CentreVertex.x = (m_Vertices[4] + (2/3)(midpointX - m_Vertices[4]));
    float midpointY;
    midpointY = m_Vertices[1] - m_Vertices[3];
    m_CentreVertex.y = (m_Vertices[5] + (2/3)(midpointY - m_Vertices[5]));

    
}
Vector2F TriangleDrawInfo::getCentre()
{
    return m_CentreVertex;
}


//Rectangle Draw Info
RectangleDrawInfo::RectangleDrawInfo(Vector2F position, Size2F size, ColorFloat color,float rotation, bool isFilled)
{
    m_IsFilled = isFilled;
    m_X = position.x;
    m_Y = position.y;
    m_Width = size.width;
    m_Height = size.height;
    //set verticies
    //x axis vertex                             //y axis vertex
    m_Vertices[0] = position.x;                 m_Vertices[1] = position.y;                  //topleft
    m_Vertices[2] = position.x + size.width;    m_Vertices[3] = position.y;                  //topright
    m_Vertices[4] = position.x + size.width;    m_Vertices[5] = position.y + size.height;    //bottomright
    m_Vertices[6] = position.x;                 m_Vertices[7] = position.y + size.height;    //bottomleft

    //set color
    //red color                 //green color              //blue color                //alpha color
    m_Colors[0] = color.r;      m_Colors[1] = color.g;     m_Colors[2] = color.b;      m_Colors[3] = color.a;   //topleft
    m_Colors[4] = color.r;      m_Colors[5] = color.g;     m_Colors[6] = color.b;      m_Colors[7] = color.a;   //topright
    m_Colors[8] = color.r;      m_Colors[9] = color.g;     m_Colors[10] = color.b;     m_Colors[11] = color.a;  //bottomright
    m_Colors[12] = color.r;     m_Colors[13] = color.g;    m_Colors[14] = color.b;     m_Colors[15] = color.a;  //bottomleft

    m_Rotation = rotation;
}
RectangleDrawInfo::RectangleDrawInfo(float x, float y, float width, float height, float red, float green, float blue, float alpha,float rotation, bool isFilled)
{
    m_IsFilled = isFilled;
    m_X = x;
    m_Y = y;
    m_Width = width;
    m_Height = height;
    //set verticies
    //x axis vertex                 //y axis vertex
    m_Vertices[0] = x;              m_Vertices[1] = y;              //topleft
    m_Vertices[2] = x + width;      m_Vertices[3] = y;              //topright
    m_Vertices[4] = x + width;      m_Vertices[5] = y + height;    //bottomright
    m_Vertices[6] = x;              m_Vertices[7] = y + height;    //bottomleft

    //set color
    //red color             //green color           //blue color            //alpha color
    m_Colors[0] = red;      m_Colors[1] = green;    m_Colors[2] = blue;     m_Colors[3] = alpha;   //topleft
    m_Colors[4] = red;      m_Colors[5] = green;    m_Colors[6] = blue;     m_Colors[7] = alpha;   //topright
    m_Colors[8] = red;      m_Colors[9] = green;    m_Colors[10] = blue;    m_Colors[11] = alpha;  //bottomright
    m_Colors[12] = red;     m_Colors[13] = green;   m_Colors[14] = blue;    m_Colors[15] = alpha;  //bottomleft

    m_Rotation = rotation;
}
RectangleDrawInfo::RectangleDrawInfo()
{
    m_IsFilled = true;
    m_X = 0.0f;
    m_Y = 0.0f;
    m_Width = 0.0f;
    m_Height = 0.0f;
    
    //set verticies
    //x axis vertex          //y axis vertex
    m_Vertices[0] = 0.0f;    m_Vertices[1] = 0.0f;    //topleft
    m_Vertices[2] = 0.0f;    m_Vertices[3] = 0.0f;    //topright
    m_Vertices[4] = 0.0f;    m_Vertices[5] = 0.0f;    //bottomright
    m_Vertices[6] = 0.0f;    m_Vertices[7] = 0.0f;    //bottomleft

    //set color
    //red color             //green color           //blue color            //alpha color
    m_Colors[0] = 1.0f;     m_Colors[1] = 0.0f;     m_Colors[2] = 1.0f;     m_Colors[3] = 1.0f;   //topleft
    m_Colors[4] = 1.0f;     m_Colors[5] = 0.0f;     m_Colors[6] = 1.0f;     m_Colors[7] = 1.0f;   //topright
    m_Colors[8] = 1.0f;     m_Colors[9] = 0.0f;     m_Colors[10] = 1.0f;    m_Colors[11] = 1.0f;  //bottomright
    m_Colors[12] = 1.0f;    m_Colors[13] = 0.0f;    m_Colors[14] = 1.0f;    m_Colors[15] = 1.0f;  //bottomleft

    m_Rotation = 0.0f;
}
RectangleDrawInfo::~RectangleDrawInfo()
{

}
void RectangleDrawInfo::setX(float x)
{
    m_X = x;
    //x axis vertex      
    m_Vertices[0] = x;          //topleft   
    m_Vertices[2] = x + m_Width;//topright
    m_Vertices[4] = x + m_Width;//bottomright
    m_Vertices[6] = x;          //bottomleft
}
void RectangleDrawInfo::setY(float y)
{
    m_Y = y;
    //y axis vertex              
    m_Vertices[1] = y;           //topleft
    m_Vertices[3] = y;           //topright
    m_Vertices[5] = y + m_Height;//bottomright
    m_Vertices[7] = y + m_Height;//bottomleft
}
void RectangleDrawInfo::setPosition(float x, float y)
{
    m_X;
    m_Y;
    //x axis vertex          //y axis vertex
    m_Vertices[0] = x;              m_Vertices[1] = y;               //topleft
    m_Vertices[2] = x + m_Width;    m_Vertices[3] = y;               //topright
    m_Vertices[4] = x + m_Width;    m_Vertices[5] = y + m_Height;    //bottomright
    m_Vertices[6] = x;              m_Vertices[7] = y + m_Height;    //bottomleft
}
void RectangleDrawInfo::setPosition(Vector2F position)
{
    m_X = position.x;
    m_Y = position.y;
    //x axis vertex          //y axis vertex
    m_Vertices[0] = position.x;              m_Vertices[1] = position.y;               //topleft
    m_Vertices[2] = position.x + m_Width;    m_Vertices[3] = position.y;               //topright
    m_Vertices[4] = position.x + m_Width;    m_Vertices[5] = position.y + m_Height;    //bottomright
    m_Vertices[6] = position.x;              m_Vertices[7] = position.y + m_Height;    //bottomleft
}
void RectangleDrawInfo::setWidth(float width)
{
    m_Width = width;
    //x axis vertex                  
    m_Vertices[0] = m_X;             
    m_Vertices[2] = m_X + width;   
    m_Vertices[4] = m_X + width;   
    m_Vertices[6] = m_X;             
}
void RectangleDrawInfo::setHeight(float height)
{
    m_Height = height;
    //y axis vertex
    m_Vertices[1] = m_Y;               //topleft
    m_Vertices[3] = m_Y;               //topright
    m_Vertices[5] = m_Y + height;    //bottomright
    m_Vertices[7] = m_Y + height;    //bottomleft
}
void RectangleDrawInfo::setSize(float width, float height)
{
    m_Width = width;
    m_Height = height;
    //x axis vertex                 //y axis vertex
    m_Vertices[0] = m_X;            m_Vertices[1] = m_Y;               //topleft
    m_Vertices[2] = m_X + width;    m_Vertices[3] = m_Y;               //topright
    m_Vertices[4] = m_X + width;    m_Vertices[5] = m_Y + height;    //bottomright
    m_Vertices[6] = m_X;            m_Vertices[7] = m_Y + height;    //bottomleft
}
void RectangleDrawInfo::setSize(Size2F size)
{
    m_Width = size.width;
    m_Height = size.height;
    //x axis vertex                      //y axis vertex
    m_Vertices[0] = m_X;                 m_Vertices[1] = m_Y;                   //topleft
    m_Vertices[2] = m_X + size.width;    m_Vertices[3] = m_Y;                   //topright
    m_Vertices[4] = m_X + size.width;    m_Vertices[5] = m_Y + size.height;     //bottomright
    m_Vertices[6] = m_X;                 m_Vertices[7] = m_Y + size.height;     //bottomleft
}
void RectangleDrawInfo::setRectangle(float x, float y, float width, float height)
{
    m_X = x;
    m_Y = y;
    m_Width = width;
    m_Height = height;
    //x axis vertex               //y axis vertex
    m_Vertices[0] = x;            m_Vertices[1] = y;             //topleft
    m_Vertices[2] = x + width;    m_Vertices[3] = y;             //topright
    m_Vertices[4] = x + width;    m_Vertices[5] = y + height;    //bottomright
    m_Vertices[6] = x;            m_Vertices[7] = y + height;    //bottomleft
}
void RectangleDrawInfo::setRectangle(Vector2F position, Size2F size)
{
     m_X = position.x;
     m_Y = position.y;
     m_Width = size.width;
     m_Height = size.height;
     //x axis vertex                            //y axis vertex
     m_Vertices[0] = position.x;                m_Vertices[1] = position.y;             //topleft
     m_Vertices[2] = position.x + size.width;   m_Vertices[3] = position.y;             //topright
     m_Vertices[4] = position.x + size.width;   m_Vertices[5] = position.y + size.height;    //bottomright
     m_Vertices[6] = position.x;                m_Vertices[7] = position.y + size.height;    //bottomleft
}
void RectangleDrawInfo::setRectangle(RectF rectangle)
{
     m_X = rectangle.m_Position.x;
     m_Y = rectangle.m_Position.y;
     m_Width = rectangle.m_Size.width;
     m_Height = rectangle.m_Size.height;
     //x axis vertex               //y axis vertex
     m_Vertices[0] = rectangle.m_Position.x;                                m_Vertices[1] = rectangle.m_Position.y;             //topleft
     m_Vertices[2] = rectangle.m_Position.x + rectangle.m_Size.width;       m_Vertices[3] = rectangle.m_Position.y;             //topright
     m_Vertices[4] = rectangle.m_Position.x + rectangle.m_Size.width;       m_Vertices[5] = rectangle.m_Position.y + rectangle.m_Size.height;    //bottomright
     m_Vertices[6] = rectangle.m_Position.x;                                m_Vertices[7] = rectangle.m_Position.y + rectangle.m_Size.height;    //bottomleft
}
void RectangleDrawInfo::setColor(float red, float green, float blue, float alpha)
{
    //set color
    //red color             //green color           //blue color            //alpha color
    m_Colors[0] = red;     m_Colors[1] = green;     m_Colors[2] = blue;     m_Colors[3] = alpha;   //topleft
    m_Colors[4] = red;     m_Colors[5] = green;     m_Colors[6] = blue;     m_Colors[7] = alpha;   //topright
    m_Colors[8] = red;     m_Colors[9] = green;     m_Colors[10] = blue;    m_Colors[11] = alpha;  //bottomright
    m_Colors[12] = red;    m_Colors[13] = green;    m_Colors[14] = blue;    m_Colors[15] = alpha;  //bottomleft
}
void RectangleDrawInfo::setColorVertex(unsigned int vertex, float red, float green, float blue, float alpha)
{
    //set color
    //red color             //green color           //blue color            //alpha color
    switch(vertex)
    {
        case RENDERER_VERTEX_1:
            m_Colors[0] = red;     m_Colors[1] = green;     m_Colors[2] = blue;     m_Colors[3] = alpha;   //topleft
            break;
        case RENDERER_VERTEX_2:
            m_Colors[4] = red;     m_Colors[5] = green;     m_Colors[6] = blue;     m_Colors[7] = alpha;   //topright
            break;
        case RENDERER_VERTEX_3:
            m_Colors[8] = red;     m_Colors[9] = green;     m_Colors[10] = blue;    m_Colors[11] = alpha;  //bottomright
            break;
        case RENDERER_VERTEX_4:
            m_Colors[12] = red;    m_Colors[13] = green;    m_Colors[14] = blue;    m_Colors[15] = alpha;  //bottomleft
            break;
        default:
            //write an error report
            //Set all vertex colors..
            m_Colors[0] = red;     m_Colors[1] = green;     m_Colors[2] = blue;     m_Colors[3] = alpha; 
            m_Colors[4] = red;     m_Colors[5] = green;     m_Colors[6] = blue;     m_Colors[7] = alpha; 
            m_Colors[8] = red;     m_Colors[9] = green;     m_Colors[10] = blue;    m_Colors[11] = alpha;
            m_Colors[12] = red;    m_Colors[13] = green;    m_Colors[14] = blue;    m_Colors[15] = alpha;
            break;
    }
}
float RectangleDrawInfo::getX()
{
    return m_X;
}
float RectangleDrawInfo::getY()
{
    return m_Y;
}
float RectangleDrawInfo::getWidth()
{
    return m_Width;
}
float RectangleDrawInfo::getHeight()
{
    return m_Height;
}

//Polygon draw info


PolygonDrawInfo::PolygonDrawInfo()
{

}
PolygonDrawInfo::~PolygonDrawInfo()
{

}
TextureDrawInfo::TextureDrawInfo(Vector2F position, Size2F size, ColorFloat color, SOILTextureInfo * textureInfo, float rotation)
{
    m_X = position.x;
    m_Y = position.y;
    m_Width = size.width;
    m_Height = size.height;
    //set verticies
    //x axis vertex                             //y axis vertex
    m_Vertices[0] = position.x;                 m_Vertices[1] = position.y;                  //topleft
    m_Vertices[2] = position.x + size.width;    m_Vertices[3] = position.y;                  //topright
    m_Vertices[4] = position.x + size.width;    m_Vertices[5] = position.y + size.height;    //bottomright
    m_Vertices[6] = position.x;                 m_Vertices[7] = position.y + size.height;    //bottomleft

    //set color
    //red color                 //green color              //blue color                //alpha color
    m_Colors[0] = color.r;      m_Colors[1] = color.g;     m_Colors[2] = color.b;      m_Colors[3] = color.a;   //topleft
    m_Colors[4] = color.r;      m_Colors[5] = color.g;     m_Colors[6] = color.b;      m_Colors[7] = color.a;   //topright
    m_Colors[8] = color.r;      m_Colors[9] = color.g;     m_Colors[10] = color.b;     m_Colors[11] = color.a;  //bottomright
    m_Colors[12] = color.r;     m_Colors[13] = color.g;    m_Colors[14] = color.b;     m_Colors[15] = color.a;  //bottomleft

    m_MinU = 0.0f;
    m_MaxU = 1.0f;
    m_MinV = 0.0f;
    m_MaxV = 1.0f;

    m_UVCoordinates[0] = 0.0f;      m_UVCoordinates[1] = 0.0f;
    m_UVCoordinates[2] = 1.0f;      m_UVCoordinates[3] = 0.0f;
    m_UVCoordinates[4] = 1.0f;      m_UVCoordinates[5] = 1.0f;
    m_UVCoordinates[6] = 0.0f;      m_UVCoordinates[7] = 1.0f;

    m_Rotation = rotation;
}
TextureDrawInfo::TextureDrawInfo(RectF rectangle, ColorFloat color, SOILTextureInfo * textureInfo, float rotation)
{
    m_TextureInfo = textureInfo;

    m_X = rectangle.m_Position.x;
    m_Y = rectangle.m_Position.y;
    m_Width = rectangle.m_Size.width;
    m_Height = rectangle.m_Size.height;
    //set verticies
    //x axis vertex                                                     //y axis vertex
    m_Vertices[0] = rectangle.m_Position.x;                             m_Vertices[1] = rectangle.m_Position.y;                  //topleft
    m_Vertices[2] = rectangle.m_Position.x + rectangle.m_Size.width;    m_Vertices[3] = rectangle.m_Position.y;                  //topright
    m_Vertices[4] = rectangle.m_Position.x + rectangle.m_Size.width;    m_Vertices[5] = rectangle.m_Position.y + rectangle.m_Size.height;    //bottomright
    m_Vertices[6] = rectangle.m_Position.x;                             m_Vertices[7] = rectangle.m_Position.y + rectangle.m_Size.height;    //bottomleft

    //set color
    //red color                 //green color              //blue color                //alpha color
    m_Colors[0] = color.r;      m_Colors[1] = color.g;     m_Colors[2] = color.b;      m_Colors[3] = color.a;   //topleft
    m_Colors[4] = color.r;      m_Colors[5] = color.g;     m_Colors[6] = color.b;      m_Colors[7] = color.a;   //topright
    m_Colors[8] = color.r;      m_Colors[9] = color.g;     m_Colors[10] = color.b;     m_Colors[11] = color.a;  //bottomright
    m_Colors[12] = color.r;     m_Colors[13] = color.g;    m_Colors[14] = color.b;     m_Colors[15] = color.a;  //bottomleft

    m_MinU = 0.0f;
    m_MaxU = 1.0f;
    m_MinV = 0.0f;
    m_MaxV = 1.0f;

    m_UVCoordinates[0] = 0.0f;      m_UVCoordinates[1] = 0.0f;
    m_UVCoordinates[2] = 1.0f;      m_UVCoordinates[3] = 0.0f;
    m_UVCoordinates[4] = 1.0f;      m_UVCoordinates[5] = 1.0f;
    m_UVCoordinates[6] = 0.0f;      m_UVCoordinates[7] = 1.0f;

    m_Rotation = rotation;
}
TextureDrawInfo::TextureDrawInfo()
{
    m_X = 0.0f;
    m_Y = 0.0f;
    m_Width = 0.0f;
    m_Height = 0.0f;
    
    //set verticies
    //x axis vertex          //y axis vertex
    m_Vertices[0] = 0.0f;    m_Vertices[1] = 0.0f;    //topleft
    m_Vertices[2] = 0.0f;    m_Vertices[3] = 0.0f;    //topright
    m_Vertices[4] = 0.0f;    m_Vertices[5] = 0.0f;    //bottomright
    m_Vertices[6] = 0.0f;    m_Vertices[7] = 0.0f;    //bottomleft

    //set color
    //red color             //green color           //blue color            //alpha color
    m_Colors[0] = 1.0f;     m_Colors[1] = 0.0f;     m_Colors[2] = 1.0f;     m_Colors[3] = 1.0f;   //topleft
    m_Colors[4] = 1.0f;     m_Colors[5] = 0.0f;     m_Colors[6] = 1.0f;     m_Colors[7] = 1.0f;   //topright
    m_Colors[8] = 1.0f;     m_Colors[9] = 0.0f;     m_Colors[10] = 1.0f;    m_Colors[11] = 1.0f;  //bottomright
    m_Colors[12] = 1.0f;    m_Colors[13] = 0.0f;    m_Colors[14] = 1.0f;    m_Colors[15] = 1.0f;  //bottomleft


    m_MinU = 0.0f;
    m_MaxU = 1.0f;
    m_MinV = 0.0f;
    m_MaxV = 1.0f;

    m_UVCoordinates[0] = 0.0f;      m_UVCoordinates[1] = 0.0f;
    m_UVCoordinates[2] = 1.0f;      m_UVCoordinates[3] = 0.0f;
    m_UVCoordinates[4] = 1.0f;      m_UVCoordinates[5] = 1.0f;
    m_UVCoordinates[6] = 0.0f;      m_UVCoordinates[7] = 1.0f;
    
    m_Rotation = 0.0f;
}
TextureDrawInfo::~TextureDrawInfo()
{
    m_TextureInfo = 0;
}
void TextureDrawInfo::setX(float x)
{
    m_X = x;

    //x axis vertex      
    m_Vertices[0] = x;
    m_Vertices[2] = x + m_Width;
    m_Vertices[4] = x + m_Width;
    m_Vertices[6] = x;
}
void TextureDrawInfo::setY(float y)
{
    m_Y = y;
    //y axis vertex
    m_Vertices[1] = y;    //topleft
    m_Vertices[3] = y;    //topright
    m_Vertices[5] = y + m_Height;    //bottomright
    m_Vertices[7] = y + m_Height;    //bottomleft
}
void TextureDrawInfo::setPosition(float x, float y)
{
    m_X = x;
    m_Y = y;

    //set verticies
    //x axis vertex                 //y axis vertex
    m_Vertices[0] = x;              m_Vertices[1] = y;    //topleft
    m_Vertices[2] = x + m_Width;    m_Vertices[3] = y;    //topright
    m_Vertices[4] = x + m_Width;    m_Vertices[5] = y + m_Height;    //bottomright
    m_Vertices[6] = x;              m_Vertices[7] = y + m_Height;    //bottomleft
}
void TextureDrawInfo::setPosition(Vector2F position)
{
    m_X = position.x;
    m_Y = position.y;

    //set verticies
    //x axis vertex                 //y axis vertex
    m_Vertices[0] = position.x;              m_Vertices[1] = position.y;    //topleft
    m_Vertices[2] = position.x + m_Width;    m_Vertices[3] = position.y;    //topright
    m_Vertices[4] = position.x + m_Width;    m_Vertices[5] = position.y + m_Height;    //bottomright
    m_Vertices[6] = position.x;              m_Vertices[7] = position.y + m_Height;    //bottomleft
}
void TextureDrawInfo::setWidth(float width)
{
    m_Width = width;
    //x axis vertex             
    m_Vertices[0] = m_X;          
    m_Vertices[2] = m_X + width;
    m_Vertices[4] = m_X + width;
    m_Vertices[6] = m_X;          
}
void TextureDrawInfo::setHeight(float height)
{
    m_Height = height;
     //y axis vertex
    m_Vertices[1] = m_Y;    //topleft
    m_Vertices[3] = m_Y;    //topright
    m_Vertices[5] = m_Y + height;    //bottomright
    m_Vertices[7] = m_Y + height;    //bottomleft
}
void TextureDrawInfo::setSize(float width, float height)
{
    m_Width = width;
    m_Height = height;
    //x axis vertex             
    m_Vertices[0] = m_X;            m_Vertices[1] = m_Y;    //topleft
    m_Vertices[2] = m_X + width;    m_Vertices[3] = m_Y;    //topright
    m_Vertices[4] = m_X + width;    m_Vertices[5] = m_Y + height;    //bottomright
    m_Vertices[6] = m_X;            m_Vertices[7] = m_Y + height;    //bottomleft
}
void TextureDrawInfo::setSize(Size2F size)
{
    m_Width = size.width;
    m_Height = size.height;
    //x axis vertex             
    m_Vertices[0] = m_X;                    m_Vertices[1] = m_Y;    //topleft
    m_Vertices[2] = m_X + size.width;       m_Vertices[3] = m_Y;    //topright
    m_Vertices[4] = m_X + size.width;       m_Vertices[5] = m_Y + size.height;    //bottomright
    m_Vertices[6] = m_X;                    m_Vertices[7] = m_Y + size.height;    //bottomleft
}
void TextureDrawInfo::setRectangle(float x, float y, float width, float height)
{
    m_X = x;
    m_Y = y;
    m_Width = width;
    m_Height = height;
    //x axis vertex             
    m_Vertices[0] = x;              m_Vertices[1] = y;    //topleft
    m_Vertices[2] = x + width;      m_Vertices[3] = y;    //topright
    m_Vertices[4] = x + width;      m_Vertices[5] = y + height;    //bottomright
    m_Vertices[6] = x;              m_Vertices[7] = y + height;    //bottomleft
}
void TextureDrawInfo::setRectangle(Vector2F position, Size2F size)
{
    m_X = position.x;
    m_Y = position.y;
    m_Width = size.width;
    m_Height = size.height;
    //x axis vertex             
    m_Vertices[0] = position.x;                    m_Vertices[1] = position.y;    //topleft
    m_Vertices[2] = position.x + size.width;       m_Vertices[3] = position.y;    //topright
    m_Vertices[4] = position.x + size.width;       m_Vertices[5] = position.y + size.height;    //bottomright
    m_Vertices[6] = position.x;                    m_Vertices[7] = position.y + size.height;    //bottomleft
}
void TextureDrawInfo::setRectangle(RectF rectangle)
{
    m_X = rectangle.m_Position.x;
    m_Y = rectangle.m_Position.y;
    m_Width = rectangle.m_Size.width;
    m_Height = rectangle.m_Size.height;
    //x axis vertex             
    m_Vertices[0] = rectangle.m_Position.x;                                 m_Vertices[1] = rectangle.m_Position.y;    //topleft
    m_Vertices[2] = rectangle.m_Position.x + rectangle.m_Size.width;        m_Vertices[3] = rectangle.m_Position.y;    //topright
    m_Vertices[4] = rectangle.m_Position.x + rectangle.m_Size.width;        m_Vertices[5] = rectangle.m_Position.y + rectangle.m_Size.height;    //bottomright
    m_Vertices[6] = rectangle.m_Position.x;                                 m_Vertices[7] = rectangle.m_Position.y + rectangle.m_Size.height;    //bottomleft
}
void TextureDrawInfo::setColor(float red, float green, float blue, float alpha)
{
    //set color
    //red color             //green color           //blue color            //alpha color
    m_Colors[0] = red;     m_Colors[1] = green;     m_Colors[2] = blue;     m_Colors[3] = alpha;   //topleft
    m_Colors[4] = red;     m_Colors[5] = green;     m_Colors[6] = blue;     m_Colors[7] = alpha;   //topright
    m_Colors[8] = red;     m_Colors[9] = green;     m_Colors[10] = blue;    m_Colors[11] = alpha;  //bottomright
    m_Colors[12] = red;    m_Colors[13] = green;    m_Colors[14] = blue;    m_Colors[15] = alpha;  //bottomleft
}
void TextureDrawInfo::setColorVertex(unsigned int vertex, float red, float green, float blue, float alpha)
{
    //set color
    //red color             //green color           //blue color            //alpha color
    switch(vertex)
    {
        case RENDERER_VERTEX_1:
            m_Colors[0] = red;     m_Colors[1] = green;     m_Colors[2] = blue;     m_Colors[3] = alpha;   //topleft
            break;
        case RENDERER_VERTEX_2:
            m_Colors[4] = red;     m_Colors[5] = green;     m_Colors[6] = blue;     m_Colors[7] = alpha;   //topright
            break;
        case RENDERER_VERTEX_3:
            m_Colors[8] = red;     m_Colors[9] = green;     m_Colors[10] = blue;    m_Colors[11] = alpha;  //bottomright
            break;
        case RENDERER_VERTEX_4:
            m_Colors[12] = red;    m_Colors[13] = green;    m_Colors[14] = blue;    m_Colors[15] = alpha;  //bottomleft
            break;
        default:
            //write an error report
            //Set all vertex colors..
            m_Colors[0] = red;     m_Colors[1] = green;     m_Colors[2] = blue;     m_Colors[3] = alpha; 
            m_Colors[4] = red;     m_Colors[5] = green;     m_Colors[6] = blue;     m_Colors[7] = alpha; 
            m_Colors[8] = red;     m_Colors[9] = green;     m_Colors[10] = blue;    m_Colors[11] = alpha;
            m_Colors[12] = red;    m_Colors[13] = green;    m_Colors[14] = blue;    m_Colors[15] = alpha;
            break;
    }
}
void TextureDrawInfo::setMinU(float u)
{
    m_MinU = u;
    m_UVCoordinates[0] = u;      
    m_UVCoordinates[6] = u;      
}
void TextureDrawInfo::setMaxU(float u)
{
    m_MaxU = u;
    m_UVCoordinates[2] = u;      
    m_UVCoordinates[4] = u;      
}
void TextureDrawInfo::setMinV(float v)
{
    m_MinV = v;
    m_UVCoordinates[1] = v;
    m_UVCoordinates[3] = v;

}
void TextureDrawInfo::setMaxV(float v)
{
    m_MaxV = v;
    m_UVCoordinates[5] = v;
    m_UVCoordinates[7] = v;
}
void TextureDrawInfo::setUV(float minU, float maxU, float minV, float maxV)
{
    m_MinU = minU;
    m_MaxU = maxU;
    m_MinV = minV;
    m_MaxV = maxV;
    m_UVCoordinates[0] = minU;      m_UVCoordinates[1] = minV;
    m_UVCoordinates[2] = maxU;      m_UVCoordinates[3] = minV;
    m_UVCoordinates[4] = maxU;      m_UVCoordinates[5] = maxV;
    m_UVCoordinates[6] = minU;      m_UVCoordinates[7] = maxV;
}