#include "Game.h"

#include "../OpenGL/OpenGL.h"
#include "../Constants/Constants.h"
#include "..//Utils/Utils.h"
#include "../Screen Manager/ScreenManager.h"


Game::Game()
{

}


Game::~Game()
{

}

void Game::update(double aDelta)
{


}

void Game::paint()
{
;
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

}

void Game::mouseLeftClickDownEvent(float positionX, float positionY)
{

}
void Game::mouseRightClickDownEvent(float positionX, float positionY)
{
}
void Game::mouseLeftClickUpEvent(float positionX, float positionY)
{

}
void Game::mouseRightClickUpEvent(float positionX, float positionY)
{
}
    
//Key up and down event methods, can be overridden
void Game::keyDownEvent(int keyCode)
{
}
void Game::keyUpEvent(int aKeyCode)
{

}
