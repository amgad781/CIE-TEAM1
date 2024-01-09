#pragma once

//This file contains all classes bricks classes 
#include "collidable.h"


class grid;
class Collectables;

enum BrickType	//add more brick types
{	
	BRK_NRM,		//Normal Brick
	BRK_HRD,		//Hard Brick		
	BRK_BOMB,		// Bomb bricks
	BRK_Rock,		//Rock brick
	BRK_POWER,		// power bricks
	BRK_LASER,		//Laser brick
	BRK_REM			// removed bricks
};

enum PowerType 
{
	windglide,
	QuickSand,
	reversepaddle,
	widepaddle,
	narrowpaddle,
	magnet,
	fireball,
	multipleball,
	fasterball,
	slowerball,
	powersCount
};



////////////////////////////////////////////////////  class brick  ///////////////////////////////////////
//Base class for all bricks
class brick :public collidable
{
	int strength;
	bool colliding = false;
	grid* pGrid;
	BrickType brkType;
	bool isBrick = true;
public:
	brick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	int getstrength() const;
	void decreaseStrength();
	void setStrength(int strength);
	grid* getGrid();
	bool isThisBrick();
	bool isColliding() const;
	void setbrkType(BrickType BrkType);
	BrickType getbrkType();
	void collided();
	point getUprLft();

};



////////////////////////////////////////////////////  class normalBrick  /////////////////////////////////
class normalBrick :public brick
{
public:
	normalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();

};


////////////////////////////////////////////////////  class LaserBrick  /////////////////////////////////
class LaserBrick :public brick
{
public:
	LaserBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);

	void collisionAction();

};

///////////////////////////////////////////////////  class PowerBrick  /////////////////////////////////
class PowerBrick :public brick
{
	Collectables* collectable;
	PowerType power;
	point powerDropPoint;
public:
	PowerBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);

	void collisionAction();

};

////////////////////////////////////////////////////  class HardBrick  /////////////////////////////////
class HardBrick :public brick
{
public:
	HardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	
	void collisionAction();
};

////////////////////////////////////////////////////  class RockBrick  /////////////////////////////////
class RockBrick :public brick
{
public:
	RockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);

	void collisionAction();
};


////////////////////////////////////////////////////  class removedBrick  /////////////////////////////////
class removedBrick :public brick
{
public:
	removedBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
};

////////////////////////////////////////////////////  class BombBrick  /////////////////////////////////
class BombBrick :public brick
{
public:
	BombBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
};
