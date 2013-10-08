#ifndef SOIL_TEXTURE_LIBRARY_H
#define SOIL_TEXTURE_LIBRARY_H

#include "OpenGL SOIL.h"

using std::vector;

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
    
private:
    void addToLibrary(SOILTextureInfo * textureInfo = NULL);
    static SOILTextureLibrary * s_Instance;
    SOILTextureLibrary();
    ~SOILTextureLibrary();

    vector < SOILTextureInfo * > m_TextureInfo;
    friend class SOILTextureManager; //Giver SOIL Texture Manager access to our private members
};

#endif