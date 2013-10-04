#ifndef SOIL_TEXTURE_LIBRARY_H
#define SOIL_TEXTURE_LIBRARY_H

#include "OpenGL SOIL.h"

class SOILTextureInfo;
//This class will store all of the textures loaded by SOIL
//This class will also be simpleton
class SOILTextureLibrary
{
public:

    static SOILTextureLibrary * getInstance();
    static void cleanupInstance();
    void loadTextureLibrary();
    void cleanupTextureLibrary();
    SOILTextureInfo * getInfo(int index);
    void addToLibrary(SOILTextureInfo * textureInfo);
private:
    static SOILTextureLibrary * s_Instance;
    SOILTextureLibrary();
    ~SOILTextureLibrary();

    SOILTextureInfo ** m_ArrayOfTextures;

    int m_Cursor; //Which index are we creating on
};

#endif