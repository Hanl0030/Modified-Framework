#include "CH_Tools.h"


CH_Float_Point::CH_Float_Point()
{
	x = 0.0f;
	y = 0.0f;
}

CH_RectF::CH_RectF()
{
	m_Width = 0.0f;
	m_Height = 0.0f;
    m_CentreWidth = 0.0f;
    m_CentreHeight = 0.0f;

}

void CH_RectF::Calculate(float x, float y, float width, float height)
{
	m_Width = width;
	m_Height = height;
    m_CentreWidth = width/2;
    m_CentreHeight = height/2;

	m_TopLeft.x = x;
	m_TopLeft.y = y;
	m_TopRight.x = x + width;
	m_TopRight.y = y;
	m_BottomLeft.x = x;
	m_BottomLeft.y = y + height;
	m_BottomRight.x = x + width;
	m_BottomRight.y = y + height;

    m_Centre.x = x + m_CentreWidth;
    m_Centre.y = y + m_CentreHeight;

}
void CH_RectF::SetLeft(float x)
{
    Calculate(x,m_TopLeft.y,m_Width,m_Height);
}
void CH_RectF::SetTop(float y)
{
    Calculate(m_TopLeft.x,y,m_Width,m_Height);
}
void CH_RectF::SetWidth(float width)
{
    Calculate(m_TopLeft.x,m_TopLeft.y,width,m_Height);
}
void CH_RectF::SetHeight(float height)
{
    Calculate(m_TopLeft.x,m_TopLeft.y,m_Width,height);
}
float CH_RectF::GetLeft()
{
    return m_TopLeft.x;
}
float CH_RectF::GetRight()
{
    return m_TopRight.x;
}
float CH_RectF::GetTop()
{
    return m_TopLeft.y;
}
float CH_RectF::GetBottom()
{
    return m_BottomLeft.y;
}
float CH_RectF::GetWidth()
{
    return m_Width;
}
float CH_RectF::GetHeight()
{
    return m_Height;
}

CH_RectV2F::CH_RectV2F()
{
	x = 0.0f;
	y = 0.0f;
	w = 0.0f;
	h = 0.0f;
}
void CH_RectV2F::CalculateCentre()
{
	centre.x = x + w/2;
	centre.y = y + h/2;
}
void CH_RectV2F::CalculateCorners()
{
	topleft.x = x;
	topleft.y = y;

	topright.x = x + w;
	topright.y = y;

	bottomright.x = x + w;
	bottomright.y = y + h;

	bottomleft.x = x;
	bottomleft.y = y + h;
}
void CH_RectV2F::CalculateAllPoints()
{
	centre.x = x + w/2;
	centre.y = y + h/2;

	topleft.x = x;
	topleft.y = y;

	topright.x = x + w;
	topright.y = y;

	bottomright.x = x + w;
	bottomright.y = y + h;

	bottomleft.x = x;
	bottomleft.y = y + h;
}

CH_ClipSectionF::CH_ClipSectionF()
{
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
}

CH_FrameSectionF::CH_FrameSectionF()
{
	startTick = 0;
	endTick = 0;
}

CH_Vector2::CH_Vector2()
{
	x = 0;
	y = 0;
}

CH_Vector3::CH_Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

CH_Color::CH_Color()
{
	r = 255;
	g = 255;
	b = 255;
	a = 255;
}



/*bool CH_ButtonPress(CH_RectF button, float mouseX, float mouseY)
{
	if(mouseX > button.topleftx && mouseX < button.bottomrightx)
	{
		if(mouseY > button.toplefty && mouseY < button.bottomrighty)
		{
			return true;
		}
	}

	return false;
}*/

bool CH_BBoxCollision(CH_RectF a, CH_RectF b)
{
    if(a.GetBottom() < b.GetTop())
	{
		return false; //object a is higher than object b
	}
    else if(a.GetLeft() > b.GetRight())
	{ 
		return false; //object a is below object b
	}
	else if(a.GetRight() < b.GetLeft())
	{
		return false; //object a is to the left of object b
	}
	else if(a.GetTop() > b.GetBottom())
	{
		return false; //object a is to the right of object b
	}
	else
	{
		return true;
	}

	return 0;
}
bool CH_BBoxCollision(CH_RectV2F a, CH_RectV2F b)
{
	if(a.y + a.h < b.y)
	{
		return false; //object a is higher than object b
	}
	else if(a.y > b.y + b.h)
	{ 
		return false; //object a is below object b
	}
	else if(a.x + a.w < b.x)
	{
		return false; //object a is to the left of object b
	}
	else if(a.x > b.x + b.w)
	{
		return false; //object a is to the right of object b
	}
	else
	{
		return true;
	}

	return 0;
}

CH_Vector2 CH_GetMouseCoords(HWND hWnd)
{
	GLint viewport[4];
	GLdouble modelview[16];
	GLdouble projection[16];
	GLfloat winX, winY, winZ;
	GLdouble posX, posY, posZ;

	CH_Vector2 returningVector;
    
	glGetDoublev(GL_MODELVIEW_MATRIX,modelview);
	glGetDoublev(GL_PROJECTION_MATRIX,projection);
	glGetIntegerv(GL_VIEWPORT, viewport);

    
	POINT mouse; //stores the x and y of the current mouse
	GetCursorPos(&mouse); //gets the current cursor coordinates
	ScreenToClient(hWnd,&mouse); //converts the screen coordinates of a specified point on the screen to client-area coordinates.

    
	winX = (float)mouse.x;
	winY = (float)mouse.y;
	winY = (float)viewport[3]-winY;
	winZ = 0;

	glReadPixels(winX,winY,1,1,GL_DEPTH_COMPONENT,GL_FLOAT,&winZ);
    //LINKER ERROR WITH THIS
	//gluUnProject(winX,winY,winZ,modelview,projection,viewport,&posX,&posY,&posZ);
    

	returningVector.x = posX;
	returningVector.y = posY;

	return returningVector;
}

void OutputGLCursorPosition(const HWND & hWnd, const LPARAM & lParam)
{
	CH_Vector2 glCoords;
	glCoords = CH_GetMouseCoords(hWnd);

	static int x = 0;
	static int y = 0;

	x = LOWORD(lParam);
	y = HIWORD(lParam);

	static float GL_X = 0;
	static float GL_Y = 0;

	GL_X = glCoords.x;
	GL_Y = glCoords.y;

	static wstringstream inputStream;

	inputStream.str(L"");

	inputStream << L"X: ";
	inputStream << x;
	inputStream << L" Y: ";
	inputStream << y;

	inputStream << L"  GL_X: ";
	inputStream << GL_X;
	inputStream << L" GL_Y: ";
	inputStream << GL_Y;

    //Fix this no conversion from string to wstring/lpstring
	//SetWindowText(hWnd,inputStream.str().c_str());
    
}

float GenerateRandomNumber(int maxNumber , int minNumber )//Randomnumber function that has 1 argument to see what the max Number can be.
{
	
	float randomNumber = 0.0f;
	randomNumber = rand() % maxNumber + minNumber; //creating a random number between 1 and the maximum number.
	//randomNumber = minNumber + (float)rand()/((float)1 / (maxNumber-minNumber));
	return randomNumber; //returns the randomNumber
}
