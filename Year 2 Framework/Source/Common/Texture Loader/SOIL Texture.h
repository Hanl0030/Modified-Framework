#ifndef SOIL_TEXTURE_H
#define SOIL_TEXTURE_H

#include "OpenGL SOIL.h"

using std::string;


class SOILTextureInfo
{
public:
    SOILTextureInfo(string filename, GLuint textureID, int sourceWidth, int sourceHeight);
    SOILTextureInfo();
    ~SOILTextureInfo();
    string getFilename();
    GLuint getTextureID();
    int getSourceWidth();
    int getSourceHeight();
private:
    //Basic Info
    string m_Filename;
    GLuint m_TextureID;
    int m_SourceWidth;
    int m_SourceHeight;
};

class SOILTexture
{
public:
    SOILTexture(const char* filename);
    SOILTexture(const char* filename, bool loadAlpha);
    SOILTexture(const char* filename, bool loadAlpha, unsigned int wrapper, unsigned int filter);
    ~SOILTexture();

    

private:
    //General Info for a texture
    GLuint m_TextureID;
    int m_SourceWidth;
    int m_SourceHeight;
    std::string m_Filename;
    //Advanced settings for texture loading
    bool m_LoadAlpha; //Do we load the alpha into source and destination?
    unsigned int m_LoadWrapper;
    unsigned int m_LoadFilter;
};

#endif