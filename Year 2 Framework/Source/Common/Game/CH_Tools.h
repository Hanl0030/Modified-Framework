#ifndef CH_TOOLS_H
#define CH_TOOLS_H

/// <CH_TOOLS.h made by Nathan Hanlan>
/// <This header file includes different classes / functions I have made and used in my programs>

#include <windows.h>		// Header File For Windows
#include <stdio.h>			// Header File For Standard Input/Output
#include <gl\GL.h>          // Header File For The OpenGL32 Library
#include <gl\GLU.h>         // Header File For The GLu32 Library
#include <ctime>
#include <cstdlib> 		
#include <string>
#include <sstream>

using std::string;
using std::stringstream;
using std::wstringstream;
using std::wstring;

/// <CLASS : CH_Float_Point>
/// <Desc: Stores two floats>
/// <Last Modified: 15/08/2013>
class CH_Float_Point
{
public:
	float x;
	float y;
	CH_Float_Point();
};

/// <CLASS : CH_RectF>
/// <Desc: This stores variables for a rectangle>
/// <all the datatypes are floats hence the F> 
/// <Last Modified: 18/07/2013>

class CH_RectF
{
public:
	//create variables for different methods of logic
	float m_Height;
	float m_Width;
    float m_CentreWidth;
    float m_CentreHeight;
	//points of the rectangle
	CH_Float_Point m_Centre;
	CH_Float_Point m_TopLeft;
	CH_Float_Point m_TopRight;
	CH_Float_Point m_BottomLeft;
	CH_Float_Point m_BottomRight;

	CH_RectF();
	void Calculate(float x = 0.0f, float y = 0.0f, float width = 0.0f, float height = 0.0f); //calculate the centre point using x y  of the top left corner and width and height
	void SetLeft(float x);
    void SetTop(float y);
    void SetWidth(float width);
    void SetHeight(float height);
    
    float GetLeft();
    float GetRight();
    float GetTop();
    float GetBottom();
    float GetWidth();
    float GetHeight();
    
};

/// <CLASS : CH_RectV2F>
/// <Desc: This is the second version of CH_RectF>
/// <Instead of basing all the variables around the centre point>
/// <All the variables are based around x and y at the bottom left>
/// <The centrepoint is still kept and we even make use of the CH_Float_Point class>
/// <Last Modified: 15/08/2013>
class CH_RectV2F
{
public:
	float x;
	float y;
	float w;
	float h;

	CH_Float_Point topleft;
	CH_Float_Point topright;
	CH_Float_Point bottomright;
	CH_Float_Point bottomleft;
	CH_Float_Point centre;


	CH_RectV2F();
	/// <FUNCTION : CalculateCentre>
	/// <Return : Void>
	/// <Arguments:  >
	/// <Desc :  Takes the and x and y coordinates and calculates the centre based on the w and h>
	/// <Last Modified:15/08/2013 >
	void CalculateCentre();
	/// <FUNCTION : CalculateCorners>
	/// <Return : Void>
	/// <Arguments:  >
	/// <Desc : Calculates all the corners of the rectangle>
	/// <Last Modified:15/08/2013 >
	void CalculateCorners();
	/// <FUNCTION : CalculateAllPoints>
	/// <Return : Void>
	/// <Arguments: >
	/// <Desc : Does what it says>
	/// <Last Modified:15/08/2013 >
	void CalculateAllPoints();
	
};
/// <CLASS : CH_ClipSectionF>
/// <Desc: This class was specifically designed for CH_SpriteAnimation>
/// <it holds four coordinates that make a rectangle on the source of the image> 
/// <for image clipping>
/// <Last Modified: 18/07/2013>
class CH_ClipSectionF
{
public:
	float x1;//the 
	float y1;
	float x2;
	float y2;
	CH_ClipSectionF();
};

/// <CLASS : CH_FrameSectionF>
/// <Desc: This class was specifically designed for CH_SpriteAnimation>
/// <it holds the two ticks that will get checked> 
/// <Last Modified: 18/07/2013>
class CH_FrameSectionF
{
public:
	float startTick;
	float endTick;
	CH_FrameSectionF();
};

class CH_Vector2
{
public:
	CH_Vector2();
	float x;
	float y;
};

class CH_Vector3
{
public:
	CH_Vector3();
	float x;
	float y;
	float z;
};
/// <CLASS : CH_Color>
/// <Desc: This stores variables to make a color,>
/// <red, green, blue, alpha> 
/// <Last Modified: 15/08/2013>
class CH_Color
{
public:
	GLubyte r;
	GLubyte g;
	GLubyte b;
	GLubyte a;
	CH_Color();
};
/// <FUNCTION : CH_ButtonPress>
/// <Return : bool>
/// <Arguments: float mousex, float mouseY, CH_RectF button>
/// <Desc : Takes in the variables and detects if the mouse coords>
/// <were within the button area.>
/// <Note this is not used with CH_Button class>
/// <Last Modified:15/08/2013 >
//bool CH_ButtonPress( CH_RectF button, float mouseX = 0.0f, float mouseY = 0.0f);

/// <FUNCTION : CH_BBoxCollision>
/// <Return : bool>
/// <Arguments: CH_RectF a, CH_RectF b>
/// <Desc : Takes the two rects and checks for collision, returns true if there is>
/// <Last Modified:15/08/2013 >
bool CH_BBoxCollision(CH_RectF a, CH_RectF b);
/// <FUNCTION : CH_BBoxCollision>
/// <Return : bool>
/// <Arguments: CH_RectV2F a, CH_RectV2F b>
/// <Desc : Takes the two rects and checks for collision, returns true if there is>
/// <Last Modified:15/08/2013 >
bool CH_BBoxCollision(CH_RectV2F a, CH_RectV2F b);

/// <FUNCTION : CH_GetMouseCoords>
/// <Return : CH_Vector2>
/// <Arguments: HWND hWnd>
/// <Desc : Retrieves the mouse coords for the win32 window>
/// <and the space within the opengl scene/viewport>
/// <Last Modified:15/08/2013 >
CH_Vector2 CH_GetMouseCoords(HWND hWnd);

/// <FUNCTION : OutputGLCursorPosition>
/// <Return : void>
/// <Arguments: const HWND & Hwnd, const LPARAM & lParam>
/// <Desc : Changes the window caption to out put cursor coordinates>
/// <Last Modified:15/08/2013 >
void OutputGLCursorPosition(const HWND & hWnd, const LPARAM & lParam);

float GenerateRandomNumber(int maxNumber = 0, int minNumber = 0);

#endif