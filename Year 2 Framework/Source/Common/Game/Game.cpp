#include "Game.h"

#include "../OpenGL/OpenGL.h"
#include "../Constants/Constants.h"
#include "..//Utils/Utils.h"
#include "../Utils/Utility Objects.h"
#include "../Screen Manager/ScreenManager.h"
#include "Interface Object.h"
#include "Button.h"
#include "../../Common/Input/MouseListener.h"


Game::Game()
{
	testButton = NULL;//Set the button to null
	testButton = new Button(0,1); //Create the button giving it a general ID that can be changed and a specific ID that CANNOT be changed
}


Game::~Game()
{
	if(testButton != NULL) //Delete that button upon destruction
	{
		delete testButton;
		testButton = 0;
	}
}

void Game::update(double aDelta)
{
	Param tempParam; //Create a temp param to store data

	if(testButton != NULL)//If we created the param
	{
        tempParam.m_Param.i = testButton->update();// call update on the param and store the int in our tempParam we made
	}
	

}

void Game::paint()
{
	if(testButton != NULL)
	{
		testButton->draw(); //If the button was not null draw it
	}
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
