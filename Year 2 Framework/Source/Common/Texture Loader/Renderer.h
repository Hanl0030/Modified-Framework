#ifndef RENDERER_H
#define RENDERER_H


#include "OpenGL SOIL.h"
#include "../Utils/Utility Objects.h"

#define RENDERER_VERTEX_1      1
#define RENDERER_VERTEX_2      2   
#define RENDERER_VERTEX_3      3
#define RENDERER_VERTEX_4      4
#define RENDERER_VERTEX_CENTER 5

class SOILTextureInfo;

class PointDrawInfo
{
public:
    PointDrawInfo(float x, float y, float red, float blue, float green, float alpha);
    PointDrawInfo(Vector2F position, ColorFloat color);
    PointDrawInfo();
    ~PointDrawInfo();
    //helpful set methods
    void setX(float x);
    void setY(float y);
    void setPosition(float x, float y);
    void setPosition(Vector2F position);
    void setColor(float red, float green, float blue, float alpha);
    //raw data
    //4 represents 4 point multiplied by 4 (red, green,blue,alpha) values
    static const int s_ColorSize = 4;
    //4 represents 4 point multiplied by 4 (red, green,blue,alpha) values
    static const int s_VertexSize = 2; //2d
    static const int s_VertexCount = 1; //how many points
    GLfloat m_Colors[s_ColorSize * s_VertexCount]; //How many colors
    float m_Vertices[s_VertexSize * s_VertexCount]; //vertexSize * vertexCount
    
};
class LineDrawInfo
{
public:
    LineDrawInfo(float x1, float y1, float x2, float y2, float red, float green, float blue, float alpha, float rotation = 0.0f);
    LineDrawInfo(Vector2F startPoint, Vector2F endPoint, ColorFloat color, float rotation);
    LineDrawInfo();
    ~LineDrawInfo();
    void setStartPointX(float x);
    void setStartPointY(float y);
    void setStartPoint(Vector2F position);
    void setEndPointX(float x);
    void setEndPointY(float y);
    void setEndPoint(Vector2F position);
    void setPoints(float x1, float y1, float x2, float y2);
    void setPoints(Vector2F startPoint, Vector2F endPoint);
    void setColor(float red, float green, float blue, float alpha);
    void setColorVertex(unsigned int vertex, float red, float green, float blue, float alpha);
    //raw data
    //4 represents 4 point multiplied by 4 (red, green,blue,alpha) values
    static const int s_ColorSize = 4;
    //4 represents 4 point multiplied by 4 (red, green,blue,alpha) values
    static const int s_VertexSize = 2; //2d
    static const int s_VertexCount = 2; //how many points
    GLfloat m_Colors[s_ColorSize * s_VertexCount]; //How many colors
    float m_Vertices[s_VertexSize * s_VertexCount]; //vertexSize * vertexCount
    float m_Rotation;
    void setAnchor(int vertex); //I only want to be able to rotate on a vertex or centre
    Vector2F getAnchor();
    float getAnchorX();
    float getAnchorY();

    void calculateCentre();
    Vector2F getCentre();
private:
    Vector2F m_Anchor; //This point at which we rotate upon
    Vector2F m_CentreVertex;
};
class TriangleDrawInfo
{
public:
    TriangleDrawInfo(Vector2F firstPoint, Vector2F secondPoint, Vector2F thirdPoint, ColorFloat color, float rotation = 0.0f, bool isFilled = false);
    TriangleDrawInfo();
    ~TriangleDrawInfo();
    void setPointX(unsigned int vertex, float x);
    void setPointY(unsigned int vertex, float y);
    void setPoint(unsigned int vertex, Vector2F position);
    void setPoints(Vector2F firstPoint, Vector2F secondPoint, Vector2F thirdPoint);
    void setColor(float red, float green, float blue, float alpha);
    void setColorVertex(unsigned int vertex, float red, float green, float blue, float alpha);
    //raw data
    //4 represents 4 point multiplied by 4 (red, green,blue,alpha) values
    static const int s_ColorSize = 4;
    //4 represents 4 point multiplied by 4 (red, green,blue,alpha) values
    static const int s_VertexSize = 2; //2d
    static const int s_VertexCount = 3; //how many points
    GLfloat m_Colors[s_ColorSize * s_VertexCount]; //How many colors
    float m_Vertices[s_VertexSize * s_VertexCount]; //vertexSize * vertexCount

    float m_Rotation;
    void setAnchor(int vertex); //I only want to be able to rotate on a vertex or centre
    Vector2F getAnchor();
    float getAnchorX();
    float getAnchorY();

    void calculateCentre();
    Vector2F getCentre();
private:
    Vector2F m_Anchor; //This point at which we rotate upon
    Vector2F m_CentreVertex;
};
class RectangleDrawInfo
{
public:
    //Constructors are responsible for setting generic info
    RectangleDrawInfo(Vector2F position, Size2F size, ColorFloat color,float rotation, bool isFilled);
    RectangleDrawInfo(float x, float y, float width, float height, float red, float green, float blue, float alpha,float rotation, bool isFilled = true);
    RectangleDrawInfo();
    ~RectangleDrawInfo();
    //Helpful set methods
    void setX(float x);
    void setY(float y);
    void setPosition(float x, float y);
    void setPosition(Vector2F position);
    void setWidth(float width);
    void setHeight(float height);
    void setSize(float width, float height);
    void setSize(Size2F size);
    void setRectangle(float x, float y, float width, float height);
    void setRectangle(Vector2F position, Size2F size);
    void setRectangle(RectF rectangle);
    void setColor(float red, float green, float blue, float alpha);
    void setColorVertex(unsigned int vertex, float red, float green, float blue, float alpha);
    float getX();
    float getY();
    float getWidth();
    float getHeight();
    //Raw Data - for users who need to set a specific. Note you should know what you're doing
    bool m_IsFilled;
    //4 represents 4 point multiplied by 4 (red, green,blue,alpha) values
    static const int s_ColorSize = 4;
    //4 represents 4 point multiplied by 4 (red, green,blue,alpha) values
    static const int s_VertexSize = 2; //2d
    static const int s_VertexCount = 4; //how many points
    GLfloat m_Colors[s_ColorSize * s_VertexCount]; //How many colors
    float m_Vertices[s_VertexSize * s_VertexCount]; //vertexSize * vertexCount
    float m_Rotation;
private:
    float m_X;
    float m_Y;
    float m_Width;
    float m_Height;
};
class PolygonDrawInfo
{
public:
    PolygonDrawInfo();
    ~PolygonDrawInfo();
    GLubyte red[16];
    GLubyte green[16];
    GLubyte blue[16];
    GLubyte alpha[16];

    float x[16];
    float y[16];
};
class TextureDrawInfo
{
public:
    //If you're using a texture you're probably using it in a more advanced
    //Were also by default setting the UV coordinates to min 0 max 1
    //But you can change it after with setUV or any of the other methods
    TextureDrawInfo(Vector2F position, Size2F size, ColorFloat color, SOILTextureInfo * textureInfo, float rotation);
    TextureDrawInfo(RectF rectangle, ColorFloat color, SOILTextureInfo * textureInfo, float rotation);
    TextureDrawInfo();
    ~TextureDrawInfo();
    //Helpful set methods
    void setX(float x);
    void setY(float y);
    void setPosition(float x, float y);
    void setPosition(Vector2F position);
    void setWidth(float width);
    void setHeight(float height);
    void setSize(float width, float height);
    void setSize(Size2F size);
    void setRectangle(float x, float y, float width, float height);
    void setRectangle(Vector2F position, Size2F size);
    void setRectangle(RectF rectangle);
    void setColor(float red, float green, float blue, float alpha);
    void setColorVertex(unsigned int vertex, float red, float green, float blue, float alpha);
    void setMinU(float u);
    void setMaxU(float u);
    void setMinV(float v);
    void setMaxV(float v);
    void setUV(float minU, float maxU, float minV, float maxV);



    //4 represents 4 point multiplied by 4 (red, green,blue,alpha) values
    static const int s_ColorSize = 4;
    //4 represents 4 point multiplied by 4 (red, green,blue,alpha) values
    static const int s_VertexSize = 2; //2d
    static const int s_VertexCount = 4; //how many points
    GLfloat m_Colors[s_ColorSize * s_VertexCount]; //How many colors
    float m_Vertices[s_VertexSize * s_VertexCount]; //vertexSize * vertexCount
    float m_UVCoordinates[s_VertexSize * s_VertexCount];

    SOILTextureInfo * m_TextureInfo;

    float getX();
    float getY();
    float getWidth();
    float getHeight();

    float m_Rotation;
private:
    float m_X;
    float m_Y;
    float m_Width;
    float m_Height;

    float m_MinU;
    float m_MaxU;
    float m_MinV;
    float m_MaxV;

    
};

//simpleton method

class Renderer
{
public:
    static Renderer * getInstance();
    static void cleanupInstance();

    void drawPoint(PointDrawInfo info);
    void drawLine(LineDrawInfo info);
    void drawTriangle(TriangleDrawInfo info);
    void drawRectangle(RectangleDrawInfo info);
    void drawPolygon(PolygonDrawInfo info);
    void drawTexture(TextureDrawInfo info);
    void drawAnimatedTexture();

private:
    static Renderer * s_Instance;
    Renderer();
    ~Renderer();

};

#endif