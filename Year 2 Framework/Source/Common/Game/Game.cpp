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



Game::Game()
{
    SOILTextureLibrary::getInstance()->loadTextureLibrary();
    m_SoilTexture = SOILTextureLibrary::getInstance()->getInfo(0);
    /*m_Texture = SOIL_load_OGL_texture
        (
        "../../../Resources/MenuScreenBackground.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        NULL//SOIL_FLAG_INVERT_Y
        );*/
    
    //glBindTexture(GL_TEXTURE_2D, m_Texture);
    //glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    m_DevTexture = NULL;
    m_DevTexture = new OpenGLTexture("Bush");
    
    //Soil example texture loading
    glGenTextures(1,&m_Texture); //make a texture
    glBindTexture(GL_TEXTURE_2D,m_Texture); //bind the texture

    int width, height; //make variables to store image size
    unsigned char*image = SOIL_load_image("../../../Resources/MenuScreenBackground.png",&width,&height,0,SOIL_LOAD_RGBA); //load the image
    //returns 0 if error loading image
    if(image == 0)
    {
        MessageBox(NULL,"Error",NULL,MB_OK);
    }
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE,image); //load the image in the opengl buffer

    SOIL_free_image_data(image); //free the image data
    //apply filters and shit
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //glGenerateMipmap(GL_TEXTURE_2D);

    
}


Game::~Game()
{
	if(m_DevTexture != NULL)
    {
        delete m_DevTexture;
        m_DevTexture = 0;
    }
}

void Game::update(double aDelta)
{
	
	

}

void Game::paint()
{
    //Draws a semi transparent rectangle
    /*glColor4ub(255,0,0,25);
	glBegin(GL_QUADS);
    glVertex2f(0.0f,0.0f);
    glVertex2f(100.0f,0.0f);
    glVertex2f(100.0f,100.0f);
    glVertex2f(0.0f,100.0f);
    glEnd();*/
    
    glColor4ub(255,255,255,150);
    //glRotatef(180.0f,0.0f,0.0f,0.0f);
    glBindTexture(GL_TEXTURE_2D,m_SoilTexture->getTextureID());
    //glBindTexture(GL_TEXTURE_2D, m_DevTexture->getId()); //Devil, is ok....
	glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);glVertex2f(0.0f,0.0f);
    glTexCoord2f(0.5f, 0.0f);glVertex2f(1024.0f,0.0f);
    glTexCoord2f(0.5f, 0.5);glVertex2f(1024.0f,768.0f);
    glTexCoord2f(0.0f, 0.5);glVertex2f(0.0f,768.0f);
    glEnd();
    //glRotatef(180.0f,0.0f,0.0f,0.0f);
    

    //Note the OpenGLRenderer is not affected by my raw opengl commands
    //OpenGLRenderer::getInstance()->drawRectangle(0.0f,0.0f,400.0f,500.0f);
    
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
