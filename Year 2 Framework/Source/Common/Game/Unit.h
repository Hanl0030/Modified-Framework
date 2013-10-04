#ifndef UNIT_H
#define UNIT_H

#include "../Utils/Utility Objects.h"

class OpenGLTexture;//forward declare

class Unit
{
public:
    Unit();
    ~Unit();

    virtual int update() = 0;
    virtual void draw() = 0;

    virtual Param getData() = 0; //Incase a method wasnt listed here Param can be used to fetch additional data without downcasting
    virtual void move(int direction = NULL) = 0; //move based on direction or internal algorithim of type

    virtual int checkState(int affect = NULL) = 0; //check the state of the unit, maybe do an algorithim based on the affect value and return the state they are in

    virtual void doAction(int action) = 0;
    virtual int getAction() = 0; //returns the last action performed

    //virtual void reset(string "filename"); //reset using a file
    //virtual void reset(datastruct data); reset using a data struct
    virtual void reset(); //reset to a default

    //Set and Get DrawPosition
    void setDrawPosition(float x, float y);
    void setDrawPosition(Vector2F position);
    void getDrawPosition(float &x, float &y);
    Vector2F getDrawPosition();
    //Set and Get DrawSize
    void setDrawSize(float width, float height);
    void setDrawSize(Size2F size);
    void getDrawSize(float &width, float &height);
    Size2F getDrawSize();
    //Set and Get DrawBounds
    void setDrawBounds(float x, float y, float width, float height);
    void setDrawBounds(RectF bounds);
    void getDrawBounds(float &x, float &y, float &width, float &height);
    RectF getDrawBounds();
    //Set and Get CollisionPosition
    virtual void setCollisionPosition(float x, float y) = 0;
    virtual void setCollisionPosition(Vector2F position) = 0;
    virtual void getCollisionPosition(float &x, float &y) = 0;
    virtual Vector2F getCollisionPosition() = 0;
    //Set and Get CollisionSize
    virtual void setCollisionSize(float width, float height) = 0;
    virtual void setCollisionSize(Size2F size) = 0;
    virtual void getCollisionSize(float &width, float &height) = 0;
    virtual Size2F getCollisionSize() = 0;
    //Set and Get CollisionBounds
    virtual void setCollisionBounds(float x, float y, float width, float height) = 0;
    virtual void setCollisionBounds(RectF bounds) = 0;
    virtual void getCollisionBounds(float &x, float &y, float &width, float &height) = 0;
    virtual RectF getCollisionBounds() = 0;
    //Set and Get HitPoints
    void setHitPoints(float hitPoints);
    float getHitPoints();
    //Set and get DamagePoints
    void setDamagePoints(float damagePoints);
    float getDamagePoints();
    //Set and get Velocity;
    void setVelocity(float xVelocity, float yVelocity);
    void setVelocity(Vector2F velocity);
    void getVelocity(float &xVelocity, float &yVelocity);
    Vector2F getVelocity();
    //Set and get Acceleration
    void setAcceleration(float xAcceleration, float yAcceleration);
    void setAcceleration(Vector2F acceleration);
    void getAcceleration(float &xAcceleration, float &yAcceleration);
    Vector2F getAcceleration();
    //Get ***Time return a time struct
    GameTime getTime();


protected:
    RectF m_DrawBounds; //The bounds of which we draw a primitive shape or texture
    //The collision bounds will be internal to each type of unit
    float m_HitPoints;      //Units all have the ability to be hurt by things
    float m_DamagePoints;   //Units all have the ability to damage things
    int m_State;            //Units will all have a state eg: Dead, Alive, Incapacitaed.. what determines that state is internal to each type
    OpenGLTexture m_Texture;
    Vector2F m_Velocity;    //Units have the ability to move on the x and y axis
    Vector2F m_Acceleration;//Velocity could be accelerated

    int m_LastAction;       //The last action a unit did ie: shoot, access object, slash, dash, spell name etc...

    //Might do a vector of buffs / debuffs or something

    //Clock variables
    int m_AliveTicks; //How many ticks have we been alive? Use this somewhere appropriate
    int m_DeadTicks;  //How many ticks have we been dead?  Use this somewhere appropriate

    int m_StateTicks;


    //General Class Stuff
    int m_ID;
    int m_IDCreate;
    int m_Type;
    int m_Family;

    
};


#endif