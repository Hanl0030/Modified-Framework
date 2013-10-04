#ifndef UTILITY_OBJECTS_H
#define UTILITY_OBJECTS_H

#include "../OpenGL/OpenGL.h"

//#include <string>

#define UNION_TYPE_RECTF 1
#define UNION_TYPE_RECTI 2
#define UNION_TYPE_CIRCLEF 3
#define UNION_TYPE_CIRCLEI 4

struct GameTime
{
    double m_TimeSinceCreation;
    int m_Alive;
    int m_Dead; 
    int m_State;
    //more variables to come regarding GameTime
    

};    


union Flag
	{
	int intFlag[2];
	float floatFlag[2];
	bool boolFlag[8];
	unsigned char uCharFlag[8];
	};

struct ReturnFlag
{
   
    int m_CurrentScreen; //This effectively should become the previous screen
    int m_NextScreen; //This  effectively should become the current screen
    Flag m_Flag;
	
};


struct Size2I
{
    int width;
    int height;
};
struct Size2F
{
    float width;
    float height;
};
struct Size2D
{
    double width;
    double height;
};
struct Vector2I
{
    int x;
    int y;
};
struct Vector2F
{
    float x;
    float y;
};
struct Vector2D
{
    double x;
    double y;
};

struct Vector3I
{
    int x;
    int y;
    int z;
};
struct Vector3F
{
    float x;
    float y;
    float z;
};
struct Vector3D
{
    double x;
    double y;
    double z;
};

struct ColorUChar
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

struct CircleI
{
    //not m_Position Is Centrered
    Vector2I m_Position;
    int m_Radius;

    int getLeft();
    int getRight();
    int getTop();
    int getBottom();
    Vector2I getCentre();
};
struct CircleF
{
    Vector2F m_Position;
    float m_Radius;

    float getLeft();
    float getRight();
    float getTop();
    float getBottom();
    Vector2F getCentre();
};
struct RectI
{
    Vector2I m_Position;
    Size2I m_Size;

    int getLeft();
    int getRight();
    int getTop();
    int getBottom();
    Vector2I getTopLeftVertex(); //This is also the same as calling to get the position;
    Vector2I getTopRightVertex();
    Vector2I getBottomLeftVertex();
    Vector2I getBottomRightVertex();
    Vector2I getCentre();
    
};
struct RectF
{
    Vector2F m_Position;
    Size2F m_Size;
    
    void setZero(); //sets all values to zero
    float getLeft();
    float getRight();
    float getTop();
    float getBottom();
    Vector2F getTopLeftVertex(); //This is also the same as calling to get the position;
    Vector2F getTopRightVertex();
    Vector2F getBottomLeftVertex();
    Vector2F getBottomRightVertex();
    Vector2F getCentre();
};




union uParam
{
    double d;
    char c;
    unsigned char uc;
    short s;
    unsigned short us;
    int i;
    unsigned int ui;
    bool b;
    float f;
    Size2I size2i;
    Size2F size2f;
    Size2D size2d;
    Vector2I vec2i;
    Vector2F vec2f;
    Vector2D vec2d;
    Vector3I vec3i;
    Vector3F vec3f;
    Vector3D vec3d;
    ColorUChar coluc;
    CircleI circi;
    CircleF circf;
    RectI recti;
    RectF rectf;
    ReturnFlag rflag;
    GameTime gTime;
    OpenGLTexture * texgl; //Is this safe?

};

class Param
{
private:
    int m_Type;
public:
    Param();
    ~Param();
    void setType(int type);
    int getType();

    //Maybe Write Different setMethods for setting each type of variable in m_Param
    uParam m_Param;
};



CircleI scaleShape(CircleI circle, int scale = 1);
CircleF scaleShape(CircleF circle, float scale = 1.0f);
RectI   scaleShape(RectI rect, int scale = 1);
RectF   scaleShape(RectF rect, float scale = 1.0f);

#endif