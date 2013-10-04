#include "SOIL Texture.h"
#include "SOIL TextureManager.h"
#include "../Global Count/ObjectCounter.h" //For checking with a debug flag


SOILTextureInfo::SOILTextureInfo(string filename, GLuint textureID, int sourceWidth, int sourceHeight)
{
    m_Filename = filename;
    m_TextureID = textureID;
    m_SourceWidth = sourceWidth;
    m_SourceHeight = sourceHeight;
}

SOILTextureInfo::SOILTextureInfo()
{
    m_Filename = "";
    m_TextureID = 0;
    m_SourceWidth = 0;
    m_SourceHeight = 0;
}
SOILTextureInfo::~SOILTextureInfo()
{

}

string SOILTextureInfo::getFilename()
{
    return m_Filename;
}
GLuint SOILTextureInfo::getTextureID()
{
    return m_TextureID;
}
int SOILTextureInfo::getSourceWidth()
{
    return m_SourceWidth;
}
int SOILTextureInfo::getSourceHeight()
{
    return m_SourceHeight;
}









SOILTexture::SOILTexture(const char* filename)
{
    m_Filename = filename;
    //Default Loading Method being used
    m_LoadAlpha = true;
    m_LoadWrapper = WRAP_REPEAT;
    m_LoadFilter = FILTER_LINEAR;
    SOILTextureManager::getInstance()->loadTexture(m_Filename.c_str(),m_TextureID,m_SourceWidth,m_SourceHeight);
 
}
SOILTexture::SOILTexture(const char* filename, bool loadAlpha)
{
    m_Filename = filename;
    //specific alpha
    m_LoadAlpha = loadAlpha;
    //Default Loading Wrappers and Filters
    m_LoadWrapper = WRAP_REPEAT;
    m_LoadFilter = FILTER_LINEAR;
    SOILTextureManager::getInstance()->loadTexture(m_Filename.c_str(),m_TextureID,m_SourceWidth,m_SourceHeight,m_LoadAlpha);
    
    
}
SOILTexture::SOILTexture(const char* filename, bool loadAlpha, unsigned int wrapper, unsigned int filter)
{
    m_Filename = filename;
    //specific alpha
    m_LoadAlpha = loadAlpha;
    //Default Loading Wrappers and Filters
    m_LoadWrapper = wrapper;
    m_LoadFilter = filter;
    //I wont do the checking here i'll do it in texture manager
    SOILTextureManager::getInstance()->loadTexture(m_Filename.c_str(),m_TextureID,m_SourceWidth,m_SourceHeight,m_LoadAlpha,m_LoadWrapper,m_LoadFilter);
    
}
SOILTexture::~SOILTexture()
{
    if(GAME_DEBUG_MODE == false)
    {
        SOILTextureManager::getInstance()->deleteTexture(m_TextureID); //deletes the texture from memory
    }
}