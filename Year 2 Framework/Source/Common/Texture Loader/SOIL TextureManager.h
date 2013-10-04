#ifndef SOIL_TEXTURE_MANAGER_H
#define SOIL_TEXTURE_MANAGER_H

#include "OpenGL SOIL.h"

using std::string;

class SOILTextureManager
{
public:
    static SOILTextureManager * getInstance();
    static void cleanupInstance();

    void loadTexture(const char * filename,GLuint &textureID,int &width,int &height); //loads a texture to my default settings
    void loadTexture(const char * filename,GLuint &textureID,int &width,int &height, bool loadAlpha);
    void loadTexture(const char * filename,GLuint &textureID,int &width,int &height, bool loadAlpha, unsigned int wrapper, unsigned int filter);

    void deleteTexture(GLuint textureID);
private:
    static SOILTextureManager * s_Instance;

    SOILTextureManager();
    ~SOILTextureManager();


};




#endif