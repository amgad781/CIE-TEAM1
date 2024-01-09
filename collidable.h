#pragma once
#include "drawable.h"
struct CollisionInfo {
    bool isColliding;
    point collisionPoint;
};
///////////////////////////////////////   collidable classes   /////////////////////////////////
//Base class for all collidable (objects that may collide with other objects)
class collidable :public drawable
{
public:
    collidable(point r_uprleft, int r_width, int r_height, game* r_pGame);
   
    virtual void collisionAction() = 0;    //action that should be performed upon collision
    int getUprLftX() const;
    int getUprLftY() const;
    int getWidth() const;
    int getHeight() const;
    collidable* getcollidableobj() const;
    void setcollidableobj(collidable*);

private:

    collidable* collidableobj;
};


