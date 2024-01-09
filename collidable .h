#pragma once
#include "drawable.h"

///////////////////////////////////////   collidable classes   /////////////////////////////////
//Base class for all collidable (objects that may collide with other objects)
class collidable :public drawable
{
public:
    collidable(point r_uprleft, int r_width, int r_height, game* r_pGame);
   
    virtual void collisionAction(collidable*other) = 0;    //action that should be performed upon collision
    int getUprLftX() const;
    int getUprLftY() const;
    int getWidth() const;
    int getHeight() const;

private:
    
};


