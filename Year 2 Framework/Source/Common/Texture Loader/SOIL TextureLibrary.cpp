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
    m_Cursor = 0;
    m_ArrayOfTextures = 0;
    m_ArrayOfTextures = new SOILTextureInfo * [SOIL_TOTAL_TEXTURES];
    //if the array is 0 something went wrong
    for(int i = 0; i < SOIL_TOTAL_TEXTURES; i++)
    {
        m_ArrayOfTextures[i] = 0;
    }
}
SOILTextureLibrary::~SOILTextureLibrary()
{
    delete [] m_ArrayOfTextures;
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
    if(m_ArrayOfTextures[index] != 0)
    {
        return m_ArrayOfTextures[index];
    }


    return 0;
}


void SOILTextureLibrary::addToLibrary(SOILTextureInfo * textureInfo)
{
    if(m_Cursor >= SOIL_TOTAL_TEXTURES || m_Cursor < 0) //if were out of bounds dont write to memory
    {
        MessageBox(NULL,"SOILTextureLibrary Cursor out of bounds", "Error Add to to Library", MB_OK);
        return;
    }
    if(m_ArrayOfTextures[m_Cursor] == 0) //If were writing on is equal to 0
    {
        m_ArrayOfTextures[m_Cursor] = textureInfo; //overwrite it
    }
    m_Cursor ++; //move the cursor
}