#include "Game.h"

#include "../OpenGL/OpenGL.h"
#include "../Constants/Constants.h"
#include "../Utils/Utils.h"
#include "../Utils/Utility Objects.h"
#include "../Screen Manager/ScreenManager.h"
#include "Interface Object.h"
#include "Button.h"
#include "../../Common/Input/MouseListener.h"

#include "../../Windows/Windows Game/SOIL.h" //THhis is working flawlessly
//Soil features - can load in textures that aren't power of 2 * power of 2
//can stretch images
//can use alpha channel
//can use cut parts of the texture and display it
//can tint the texture
#include "../Texture Loader/SOIL Texture.h"
#include "../Texture Loader/SOIL TextureLibrary.h"
#include "../Texture Loader/Renderer.h"
/*#include <memory>
#include <cassert>
#include <process.h>*/
#include "../../Windows/Windows Game/glext.h"



Game::Game()
{
    SOILTextureLibrary::getInstance()->loadTextureLibrary();
    m_SoilTexture = SOILTextureLibrary::getInstance()->getInfo(0);

    m_RectDrawInfo = new RectangleDrawInfo();
    //setup the rect draw info
    m_RectDrawInfo->setColorVertex(RENDERER_VERTEX_1,1.0f,0.0f,0.0f,1.0f);
    m_RectDrawInfo->setColorVertex(RENDERER_VERTEX_2,0.0f,1.0f,0.0f,1.0f);
    m_RectDrawInfo->setColorVertex(RENDERER_VERTEX_3,0.0f,0.0f,1.0f,1.0f);
    m_RectDrawInfo->setColorVertex(RENDERER_VERTEX_4,0.5f,0.5f,0.5f,0.5f);
    m_RectDrawInfo->setRectangle(0.0f,0.0f,100.0f,100.0f);

    m_TextureDrawInfo = new TextureDrawInfo();
    //setup the texture draw info
    m_TextureDrawInfo->setColor(1.0f,1.0f,1.0f,1.0);
    m_TextureDrawInfo->setRectangle(250.0f,0.0f,100.0f,100.0f);
    m_TextureDrawInfo->setUV(0.0f,1.0f,0.0f,1.0f);
    m_TextureDrawInfo->m_TextureInfo = m_SoilTexture;
    m_TextureDrawInfo->setColor(0.0f,0.0f,0.0f,1.0f);
    m_TextureDrawInfo->setColorVertex(RENDERER_VERTEX_3,0.5f,0.5f,0.5f,1.0f);

    m_LineDrawInfo = new LineDrawInfo(100.0f,200.0f,200.0f,300.0f,1.0f,1.0f,1.0f,1.0f,0.0f);
    m_TriangleDrawInfo = new TriangleDrawInfo();
    Vector2F tempPosition;
    tempPosition.x = 0.0f;
    tempPosition.y = 0.0f;
    m_TriangleDrawInfo->setPoint(RENDERER_VERTEX_1,tempPosition);
    tempPosition.x = 100.0f;
    tempPosition.y = 0.0f;
    m_TriangleDrawInfo->setPoint(RENDERER_VERTEX_2,tempPosition);
    tempPosition.x = 100.0f;
    tempPosition.y = 100.0f;
    m_TriangleDrawInfo->setPoint(RENDERER_VERTEX_3,tempPosition);
    m_TriangleDrawInfo->setColor(1.0f,1.0f,1.0f,1.0);
    m_TriangleDrawInfo->setAnchor(RENDERER_VERTEX_CENTER);
    
    //m_TriangleDrawInfo->
   
}


Game::~Game()
{
	if(m_RectDrawInfo != 0)
    {
        delete m_RectDrawInfo;
        m_RectDrawInfo = 0;
    }
    if(m_TextureDrawInfo != 0)
    {
        delete m_TextureDrawInfo;
        m_TextureDrawInfo = 0;
    }
    if(m_LineDrawInfo != 0)
    {
        delete m_LineDrawInfo;
        m_LineDrawInfo = 0;
    }
}

void Game::update(double aDelta)
{
	
	

}

void Game::paint()
{
    Renderer::getInstance()->drawRectangle(*m_RectDrawInfo);
    Renderer::getInstance()->drawTexture(*m_TextureDrawInfo);
    Renderer::getInstance()->drawLine(*m_LineDrawInfo);
    Renderer::getInstance()->drawTriangle(*m_TriangleDrawInfo);
}

void Game::reset()
{

}

void Game::gameOver()
{

}

const char* Game::getName()
{
	return GAME_SCREEN_NAME;
}

void Game::screenWillAppear()
{
  OpenGLRenderer::getInstance()->setBackgroundColor(OpenGLColorCornflowerBlue());
}
void Game::mouseMovementEvent(float aDeltaX, float aDeltaY, float aPositionX, float aPositionY)
{
	MouseListener::getInstance()->setPosition(aPositionX,aPositionY);
	MouseListener::getInstance()->triggerMove();
}

void Game::mouseLeftClickDownEvent(float positionX, float positionY)
{
	MouseListener::getInstance()->setPosition(positionX, positionY);
	MouseListener::getInstance()->triggerLeftDown();
}
void Game::mouseRightClickDownEvent(float positionX, float positionY)
{
	MouseListener::getInstance()->setPosition(positionX, positionY);
	MouseListener::getInstance()->triggerRightDown();
}
void Game::mouseLeftClickUpEvent(float positionX, float positionY)
{
	MouseListener::getInstance()->setPosition(positionX, positionY);
	MouseListener::getInstance()->triggerLeftUp();
    //MessageBox(0,"LEFT test",NULL,MB_OK);
}
void Game::mouseRightClickUpEvent(float positionX, float positionY)
{
	MouseListener::getInstance()->setPosition(positionX, positionY);
	MouseListener::getInstance()->triggerRightUp();
    //MessageBox(0,"RIGHT test",NULL,MB_OK);
}
    
//Key up and down event methods, can be overridden
void Game::keyDownEvent(int keyCode)
{
}
void Game::keyUpEvent(int aKeyCode)
{

}
