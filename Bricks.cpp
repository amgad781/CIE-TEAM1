#include "Bricks.h"
#include "game.h"




////////////////////////////////////////////////////  class brick  ///////////////////////////////////////
brick::brick(point r_uprleft, int r_width, int r_height, game* r_pGame):
	collidable(r_uprleft, r_width, r_height, r_pGame)
{
	pGrid = pGame->getGrid();
	
}

bool brick::isThisBrick()
{
	return isBrick;
}

void brick::decreaseStrength()
{
	strength--;
}

void brick::setStrength(int strength)
{
	this->strength = strength;
}

grid* brick::getGrid()
{
	return pGrid;
}

int brick::getstrength() const
{
	return strength;
}

bool brick::isColliding() const
{
	return colliding;
}

void brick::setbrkType(BrickType BrkType)
{
	brkType = BrkType;
}

BrickType brick::getbrkType()
{
	return brkType;
}

void brick::collided()
{
	colliding = true;
}

point brick::getUprLft()
{
	return uprLft;
}

////////////////////////////////////////////////////  class normalBrick  /////////////////////////////////
normalBrick::normalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame):
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\NormalBrick.jpg";
	setStrength(config.normalBrickStrength);
}

void normalBrick::collisionAction()
{
	decreaseStrength();
	grid* pGrid = getGrid();
	if (this->getstrength() == 0)
	{
		pGrid->removeBrick(this->uprLft);
	}
}


////////////////////////////////////////////////////  class LaserBrick  /////////////////////////////////
LaserBrick::LaserBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\LaserBrick.jpg";
	setStrength(config.LaserBrickStrength);
}

void LaserBrick::collisionAction()
{
	decreaseStrength();
	grid* pGrid = getGrid();
	if (this->getstrength() == 0)
	{
		pGrid->removeBrick(this->uprLft);
	}
}

////////////////////////////////////////////////////  class LaserBrick  /////////////////////////////////
PowerBrick::PowerBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\Powebrick.jpg";
	powerDropPoint.x = uprLft.x + (width / 2);
	powerDropPoint.y = uprLft.y + (height);
	setStrength(config.PowerBrickStrength);
	srand(time(0));
	int randIndex = rand() % powersCount;
	power = static_cast<PowerType>(randIndex);
	
}

void PowerBrick::collisionAction()
{
	decreaseStrength();
	grid* pGrid = getGrid();
	pGame->getGrid()->addCollectable(power, powerDropPoint);
	if (this->getstrength() == 0)
	{
		pGrid->removeBrick(this->uprLft);
	}

}

////////////////////////////////////////////////////  class HardBrick  /////////////////////////////////

HardBrick::HardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\Hardbrick.jpg";
	setStrength(config.hardBrickStrength);
}

void HardBrick::collisionAction()
{
	decreaseStrength();
	grid* pGrid = getGrid();
	if (this->getstrength() == 0)
	{
		pGrid->removeBrick(this->uprLft);
	}
}

////////////////////////////////////////////////////  class RockBrick  /////////////////////////////////


RockBrick::RockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\Rockbrick.jpg";
	setStrength(config.RockBrickStrength);
}

void RockBrick::collisionAction()
{
	grid* pGrid = getGrid();
	if (this->getstrength() == 0)
	{
		//pGrid->removeBrick(this);
	}
}

////////////////////////////////////////////////////  class removedBrick  /////////////////////////////////

removedBrick::removedBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\removed.jpg";
}

void removedBrick::collisionAction()
{
	decreaseStrength();
}

////////////////////////////////////////////////////  class BombBrick  /////////////////////////////////
BombBrick::BombBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\BombBrick2.jpg";
	setStrength(config.bombBrickStrength);
}

void BombBrick::collisionAction()
{
	decreaseStrength();
}

