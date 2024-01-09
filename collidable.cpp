#include "collidable.h"

collidable::collidable(point r_uprleft, int r_width, int r_height, game* r_pGame):
			drawable(r_uprleft, r_width, r_height,  r_pGame)
{
}

int collidable::getUprLftX() const
{
	return uprLft.x;
}

int collidable::getUprLftY() const
{
	return uprLft.y;
}

int collidable::getWidth() const
{
	return width;
}

int collidable::getHeight() const
{
	return height;
}

collidable* collidable::getcollidableobj() const
{
	return collidableobj;
}

void collidable::setcollidableobj(collidable* obj)
{
	this->collidableobj = obj;
}
