#include "SOIL TextureLibrary.h"
#include "../Global Count/ObjectCounter.h"
#include "SOIL Texture.h"
#include "SOIL TextureManager.h"
SOILTextureLibrary * SOILTextureLibrary::s_Instance = 0;

SOILTextureLibrary * SOILTextureLibrary::getInstance()
{
    if(s_Instance == 0)
    {
        s_Instance = new SOILTextureLibrary();
    }
    return s_Instance;
}

void SOILTextureLibrary::cleanupInstance()
{
    if(s_Instance != NULL)
    {
        delete s_Instance;
        s_Instance = 0;
    }
}
SOILTextureLibrary::SOILTextureLibrary()
{
}
SOILTextureLibrary::~SOILTextureLibrary()
{
    for(int i = 0; i < m_TextureInfo.size() ; i++)
    {
        delete m_TextureInfo.at(i);
        m_TextureInfo.at(i) = 0;
    }
    m_TextureInfo.clear();
}
void SOILTextureLibrary::loadTextureLibrary()
{
    SOILTexture * bushPNG = new SOILTexture("../../../Resources/Bush.png");
    delete bushPNG;
    bushPNG = 0;
}
void SOILTextureLibrary::cleanupTextureLibrary()
{
    //maybe delete all the textures from loadTextureLibrary here
}

SOILTextureInfo * SOILTextureLibrary::getInfo(int index)
{
    if(index >= 0 && index < m_TextureInfo.size()) //error checking
    { 
        return m_TextureInfo.at(index); //return the specified index
    }


    return 0;
}


void SOILTextureLibrary::addToLibrary(SOILTextureInfo * textureInfo)
{
   if(textureInfo != NULL)
   {
       m_TextureInfo.push_back(textureInfo);
   }
}