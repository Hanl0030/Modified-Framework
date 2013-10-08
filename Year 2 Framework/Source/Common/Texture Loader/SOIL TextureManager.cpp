#include "SOIL TextureManager.h"
#include "SOIL Texture.h"
#include "SOIL TextureLibrary.h"
#include "../../Windows/Windows Game/SOIL.h"

//Simpleton
SOILTextureManager * SOILTextureManager::s_Instance = 0;
SOILTextureManager * SOILTextureManager::getInstance()
{
    if(s_Instance == 0)
    {
        s_Instance = new SOILTextureManager();
    }
    return s_Instance;
}

void SOILTextureManager::cleanupInstance()
{
    if(s_Instance != 0)
    {
        delete s_Instance;
        s_Instance = 0;
    }
}
//Constructor
SOILTextureManager::SOILTextureManager()
{

}
//Destructor
SOILTextureManager::~SOILTextureManager()
{
    if(s_Instance != 0)
    {
        delete s_Instance;
        s_Instance = 0;
    }
}

void SOILTextureManager::loadTexture(const char * filename,GLuint &textureID,int &width,int &height) //loads a texture to my default settings
{
    glGenTextures(1,&textureID); //Create a texture and retrieve the id of it in memory
    glBindTexture(GL_TEXTURE_2D,textureID); //Tell opengl we want access to that texture
    unsigned char * data = SOIL_load_image(filename,&width,&height,0,SOIL_LOAD_RGBA); //Filestream loading in the image data
    if(data == 0)
    {
        SOIL_free_image_data(data); //free image data
        glDeleteTextures(1,&textureID); //delete the texture from memory
        return;
    }
    glTexImage2D(GL_TEXTURE_2D, //Format
                0,              //Leave 0
                GL_RGBA,        //Color Format
                width,          //image width
                height,         //image height
                0,              //leave 0
                GL_RGBA,        //Color format
                GL_UNSIGNED_BYTE, //Byte type
                data);          //The data we loaded
    SOIL_free_image_data(data); //Free the image data

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); //Apply the wrapping method
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); //Apply the wrapping method
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //Apply the filtering method
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //Apply the filtering method

    SOILTextureInfo * textureInfo = new SOILTextureInfo(filename,textureID,width,height); //create an info class
    SOILTextureLibrary::getInstance()->addToLibrary(textureInfo); //add the info to our library

}
void SOILTextureManager::loadTexture(const char * filename,GLuint &textureID,int &width,int &height, bool loadAlpha)
{
    glGenTextures(1,&textureID); //create a texture
    glBindTexture(GL_TEXTURE_2D,textureID); //use it
    unsigned char * data = 0;


    if(loadAlpha == true)
    {
    data = SOIL_load_image(filename,&width,&height,0,SOIL_LOAD_RGBA); //Load RGBA
    }
    else
    {
    data = SOIL_load_image(filename,&width,&height,0,SOIL_LOAD_RGB); //Load RGB
    }


    if(data == 0)
    {
        SOIL_free_image_data(data); //free image data
        glDeleteTextures(1,&textureID); //delete the texture from memory
        return;
    }
    if(loadAlpha == true)
    {
        glTexImage2D(GL_TEXTURE_2D, //Format
                0,              //Leave 0
                GL_RGBA,        //Color Format
                width,          //image width
                height,         //image height
                0,              //leave 0
                GL_RGBA,        //Color format
                GL_UNSIGNED_BYTE, //Byte type
                data);          //The data we loaded
    }
    else
    {
        glTexImage2D(GL_TEXTURE_2D, //Format
                0,              //Leave 0
                GL_RGB,        //Color Format
                width,          //image width
                height,         //image height
                0,              //leave 0
                GL_RGB,        //Color format
                GL_UNSIGNED_BYTE, //Byte type
                data);          //The data we loaded
    }
    
    SOIL_free_image_data(data); //Free the image data
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); //Apply the wrapping method
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); //Apply the wrapping method
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //Apply the filtering method
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //Apply the filtering method

    SOILTextureInfo * textureInfo = new SOILTextureInfo(filename,textureID,width,height); //create an info class
    SOILTextureLibrary::getInstance()->addToLibrary(textureInfo); //add the info to our library
}
void SOILTextureManager::deleteTexture(GLuint textureID)
{
    if(textureID != 0) //If the texture exists in memory
    {
        glDeleteTextures(1,&textureID); //Delete it from memory!
    }
}