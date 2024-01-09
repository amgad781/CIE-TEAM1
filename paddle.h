#pragma once
#include "drawable.h"
#include "collidable.h"
#include "CMUgraphicsLib\CMUgraphics.h"
#include "gameConfig.h"



class game;
class Paddle :
    public collidable
{
    game* pGame;
    string paddleIconPath;
    CollisionInfo collisionInfo;
    int speed;
    int Width;

public:
    Paddle(point p_uprleft, int p_width, int p_height, game* pG);
    bool checkCollision(collidable *other);
    bool colliding();
    bool checkCollision_powerup(collidable* other);            /////////////////////////
    void collisionAction() override;
    void move(window* pWind);
    int getspeed()const;
    void setspeed(int speed);
};

