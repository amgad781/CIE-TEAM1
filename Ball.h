#pragma once
#include "collidable.h"

class grid;

class ball :public collidable
{
	CollisionInfo collisionInfo;
	point r_uprleft;
	point prevUprLft;
	bool isBall = true;
	bool isFireBall = false;
	double Xinc, Yinc;
	grid* bricksgrid;
	int x;
	int y;
	collidable* collided = nullptr;
public:
	ball(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void Ball_Movement(window* wind);
	void collisionAction();
	bool checkCollision(collidable* other);
;	double getXinc() const;
	double getYinc() const;
	void setXinc(double newIncrease);
	void setYinc(double newIncrease);
	point getUpperLeft() const;
	bool isThisBall();
	bool isThisFireBall();
	
	bool getIsBall() const;
	void setIsBall(bool value);
	bool getIsFireBall() const;
	void setIsFireBall(bool value);

	void SetPoint();
	double getuprLft() const;
	int getPointx() const;
	int getPointy() const;
	void setpeed(double Factor);
	void setInitial(window* pWind);
	void Sapce(window* pWind);
	//void ResetBall(window* pWind);
	//void multipleBalls();
};





