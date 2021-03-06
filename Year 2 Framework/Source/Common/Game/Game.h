#ifndef GAME_H
#define GAME_H

#include <vector>
#include "../Screen Manager/Screen.h"
#include "../OpenGL/OpenGL.h"
class OpenGLTexture;
class InterfaceObject; //For InterfaceObjects
class SOILTextureInfo;
class RectangleDrawInfo;
class TextureDrawInfo;
class LineDrawInfo;
class TriangleDrawInfo;


class Game : public Screen
{
public:
  Game();
  ~Game();
  
  //Game lifecycle methods
  void update(double delta);
  void paint();
  void reset();
  
  //Game Over method, call this when to end the game
  void gameOver();

  //Screen name, must be implemented, it's a pure
  //virtual method in the Screen class
  const char* getName();
  
  //Screen event method, inherited from the screen class
  void screenWillAppear();

  //GameObject Methods
  /*void addGameObject(GameObject* gameObject);
  GameObject* getGameObjectByType(const char* type);*/

private:
  //Mouse Events
  void mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY);
  void mouseLeftClickDownEvent(float positionX, float positionY);
  void mouseRightClickDownEvent(float positionX, float positionY);
  void mouseLeftClickUpEvent(float positionX, float positionY);
  void mouseRightClickUpEvent(float positionX, float positionY);
    
//Key up and down event methods, can be overridden
  void keyDownEvent(int keyCode);
  void keyUpEvent(int keyCode);


  //Vector to hold the GameObjects
  //std::vector<GameObject*> m_GameObjects;
  
  //Timer variable to delay reseting the game has ended
  double m_GameOverTimer;
  GLuint m_Texture;
  OpenGLTexture * m_DevTexture;
  SOILTextureInfo * m_SoilTexture;
  RectangleDrawInfo * m_RectDrawInfo;
  TextureDrawInfo * m_TextureDrawInfo;
  LineDrawInfo * m_LineDrawInfo;
  TriangleDrawInfo * m_TriangleDrawInfo;
};

#endif