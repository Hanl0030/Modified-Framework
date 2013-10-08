#include "Renderer.h"
#include "SOIL Texture.h"









Renderer * Renderer::s_Instance = 0;

Renderer * Renderer::getInstance()
{
    if(s_Instance == 0)
    {
        s_Instance = new Renderer();
    }
    return s_Instance;
}
void Renderer::cleanupInstance()
{
    if(s_Instance != 0)
    {
        delete s_Instance;
        s_Instance = 0;
    }
}

Renderer::Renderer()
{

}
Renderer::~Renderer()
{
    if(s_Instance != 0)
    {
        delete s_Instance;
        s_Instance = 0;
    }
}
void Renderer::drawPoint(PointDrawInfo info)
{
    //Vertex Array Mode



    glEnableClientState(GL_VERTEX_ARRAY); //Enable vertex array
    glVertexPointer(info.s_VertexSize,GL_FLOAT,0,info.m_Vertices);

    glEnableClientState(GL_COLOR_ARRAY); //enable the color array
    glColorPointer(info.s_ColorSize,GL_FLOAT,0, info.m_Colors );

    glDrawArrays(GL_POINT,0,info.s_VertexCount); //draw a point with vertex and color pointers and # of points
    //disable the clientstates
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

}

void Renderer::drawLine(LineDrawInfo info)
{
    glPushMatrix();

    glTranslatef(info.m_Vertices[0],info.m_Vertices[1],0.0f);

    /*glTranslatef(info.getAnchorX(),info.getAnchorY(),0.0f);
    glRotatef(info.m_Rotation,0.0f,0.0f,1.0f);
    glTranslatef(-info.getAnchorX(),-info.getAnchorY(),0.0f);*/

    //glTranslatef(50.0f,50.0f,0.0f);
    glRotatef(info.m_Rotation,0.0f,0.0f,1.0f);
    //glTranslatef(90.0f,-100.0f,0.0f);

    glEnableClientState(GL_VERTEX_ARRAY); //Enable vertex array
    glVertexPointer(info.s_VertexSize,GL_FLOAT,0,info.m_Vertices);

    glEnableClientState(GL_COLOR_ARRAY); //enable the color array
    glColorPointer(info.s_ColorSize,GL_FLOAT,0, info.m_Colors );

    glDrawArrays(GL_LINES,0,info.s_VertexCount); //draw a point with vertex and color pointers and # of points
    //disable the clientstates
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    glPopMatrix();
}

void Renderer::drawTriangle(TriangleDrawInfo info)
{
    glPushMatrix();
    
    //glTranslatef(info.m_Vertices[0],info.m_Vertices[1],0.0f);

    glTranslatef(info.getAnchorX(),info.getAnchorY(),0.0f);
    glRotatef(45.0f,0.0f,0.0f,1.0f);
    glTranslatef(-info.getAnchorX(),-info.getAnchorY(),0.0f);


    glEnableClientState(GL_VERTEX_ARRAY); //Enable vertex array
    glVertexPointer(info.s_VertexSize,GL_FLOAT,0,info.m_Vertices);

    glEnableClientState(GL_COLOR_ARRAY); //enable the color array
    glColorPointer(info.s_ColorSize,GL_FLOAT,0, info.m_Colors );

    glDrawArrays(GL_TRIANGLES,0,info.s_VertexCount); //draw a point with vertex and color pointers and # of points
    //disable the clientstates
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    glPopMatrix();
}

void Renderer::drawRectangle(RectangleDrawInfo info)
{
    glPushMatrix();

    glTranslatef(info.m_Vertices[0],info.m_Vertices[1],0.0f);

    glTranslatef(info.getWidth()/2,info.getHeight()/2,0.0f);
    glRotatef(425.0f,0.0f,0.0f,1.0f);
    glTranslatef(-info.getWidth()/2,-info.getHeight()/2,0.0f);

    glEnableClientState(GL_VERTEX_ARRAY); //Enable vertex array
    glVertexPointer(info.s_VertexSize,GL_FLOAT,0,info.m_Vertices);

    glEnableClientState(GL_COLOR_ARRAY); //enable the color array
    glColorPointer(info.s_ColorSize,GL_FLOAT,0, info.m_Colors );
    
    glDrawArrays(GL_TRIANGLE_FAN,0,info.s_VertexCount);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);


    glPopMatrix();
}
void Renderer::drawPolygon(PolygonDrawInfo info)
{
    /*glBegin(GL_POLYGON);
        for(int i =0 ; i < 16; i++)
        {
            glColor4ub(info.red[i],info.green[i],info.blue[i],info.alpha[i]); glVertex2f(info.x[i], info.y[i]);
        }
    glEnd();*/
}
void Renderer::drawTexture(TextureDrawInfo info)
{
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glTexCoordPointer(2,GL_FLOAT,0,info.m_UVCoordinates);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,info.m_TextureInfo->getTextureID());

    glEnableClientState(GL_VERTEX_ARRAY); //Enable vertex array
    glVertexPointer(info.s_VertexSize,GL_FLOAT,0,info.m_Vertices);

    glEnableClientState(GL_COLOR_ARRAY); //enable the color array
    glColorPointer(info.s_ColorSize,GL_FLOAT,0, info.m_Colors );
    
    glDrawArrays(GL_TRIANGLE_FAN,0,info.s_VertexCount);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisable(GL_TEXTURE_2D);
}

