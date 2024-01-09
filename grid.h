#pragma once

#include "drawable.h"
#include "Bricks.h"
#include "Collectables.h"


class game;

class grid:public drawable
{
	
	brick*** brickMatrix;		//2D array of brick pointers
	grid* pGrid; // Assuming 'pGrid' is a member variable representing the grid
	window* pWind;
	int rows, cols;
	vector<Collectables*> collectables;

public:
	grid(point r_uprleft, int r_width, int r_height, game* r_pGame);
	~grid();
	void draw() const;
	int addBrick(BrickType brkType, point clickedPoint);
	int addSavedBrick(int rowindex, int colindex, BrickType type);
	void removeBombBrick(point uprleft);
	void removeLaserBrick(point uprleft);
	int deleteBrick(brick*** brickMatrix, point clickedPoint);
	//void removeBrick(brick*** brickMatrix);
	void removeBrick(point uprleft);
	int getRows() const;
	int getCols() const;
	brick*** getBrickMatrix() const;
	grid* getGrid() const;
	brick*** getbrickMatrix();

	void addCollectable(PowerType powertype, point collisionPoint);
	void removeCollectable(Collectables* collectable);
	vector<Collectables*> getCollecVector() const;
	//BrickType getBrickType(point clickedPoint);
	//void removeBrick(brick*** brickMatrix);

};


