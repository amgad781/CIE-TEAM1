#include "grid.h"
#include "game.h"
#include "gameConfig.h"

grid::grid(point r_uprleft, int wdth, int hght, game* pG):
	drawable(r_uprleft, wdth, hght, pG)
{
	pWind = pG->getWind();
	rows = height / config.brickHeight;
	cols = width / config.brickWidth;

	brickMatrix = new brick ** [rows];
	for (int i = 0; i < rows; i++)
		brickMatrix[i] = new brick * [cols];

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			brickMatrix[i][j] = nullptr;
}

int grid::getRows() const
{
	return rows;
}

int grid::getCols() const
{
	return cols;
}

brick*** grid::getBrickMatrix() const
{
	return brickMatrix;
}



grid::~grid()
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (brickMatrix[i][j])
				delete brickMatrix[i][j];	//delete all allocated bricks

	for (int i = 0; i < rows; i++)
		delete brickMatrix[i];

	delete brickMatrix;

}

void grid::draw() const
{
	window* pWind = pGame->getWind();
	//draw lines showing the grid
	pWind->SetPen(config.gridLinesColor,1);

	//draw horizontal lines
	for (int i = 0; i < rows; i++) {
		int y = uprLft.y + (i + 1) * config.brickHeight;
		pWind->DrawLine(0, y, width, y);
	}
	//draw vertical lines
	for (int i = 0; i < cols; i++) {
		int x = (i + 1) * config.brickWidth;
		pWind->DrawLine(x, uprLft.y, x, uprLft.y+ rows* config.brickHeight);
	}

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (brickMatrix[i][j])
				brickMatrix[i][j]->draw();	//draw exisiting bricks


}

int grid::addBrick(BrickType brkType, point clickedPoint)
{
	//TODO:
	// 1- Check that the clickedPoint is within grid range (and return -1)
	// 2- Check that the clickedPoint doesnot overlap with an exisiting brick (return 0)

	//Here we assume that the above checks are passed
	
	//From the clicked point, find out the index (row,col) of the corrsponding cell in the grid
	int gridCellRowIndex = (clickedPoint.y-uprLft.y) / config.brickHeight;
	int gridCellColIndex = clickedPoint.x / config.brickWidth;

	//Now, align the upper left corner of the new brick with the corner of the clicked grid cell
	point newBrickUpleft;
	newBrickUpleft.x = uprLft.x + gridCellColIndex * config.brickWidth;
	newBrickUpleft.y = uprLft.y + gridCellRowIndex * config.brickHeight;

	switch (brkType)
	{
	case BRK_NRM:	//The new brick to add is Normal Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new normalBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;

		//TODO: 
		// handle more types
	case BRK_HRD:	//The new brick to add is Normal Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new HardBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;

	case BRK_REM:	//The new brick to add is Normal Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new removedBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;

	case BRK_BOMB:	//The new brick to add is Normal Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new BombBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;


	case BRK_Rock:	//The new brick to add is Rock Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new RockBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;

	case BRK_LASER:	//The new brick to add is Normal Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new LaserBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;

	case BRK_POWER:	//The new brick to add is Normal Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new PowerBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;

	}
	return 1;
}


int grid::addSavedBrick(int rowindex, int colindex, BrickType type)
{

	//Now, align the upper left corner of the new brick with the corner of the clicked grid cell
	point newBrickUpleft;
	newBrickUpleft.x = uprLft.x + colindex * config.brickWidth;
	newBrickUpleft.y = uprLft.y + rowindex * config.brickHeight;

	/*window* pWind = pGame->getWind();
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			delete brickMatrix[i][j];
			brickMatrix[i][j] = nullptr;
		}
	}*/
	//draw lines showing the grid
	pWind->SetPen(config.bkGrndColor);
	pWind->SetBrush(config.bkGrndColor);
	pWind->DrawRectangle(0, config.toolBarHeight, config.windWidth, config.gridHeight);

	pWind->SetPen(config.gridLinesColor, 1);
	//draw horizontal lines
	for (int i = 0; i < rows; i++) {
		int y = uprLft.y + (i + 1) * config.brickHeight;
		pWind->DrawLine(0, y, width, y);
	}
	//draw vertical lines
	for (int i = 0; i < cols; i++) {
		int x = (i + 1) * config.brickWidth;
		pWind->DrawLine(x, uprLft.y, x, uprLft.y + rows * config.brickHeight);
	}

	switch (type - 1)
	{
	case BRK_NRM:	//The new brick to add is Normal Brick
		brickMatrix[rowindex][colindex] = new normalBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;

		//TODO: 
		// handle more types
	case BRK_HRD:	//The new brick to add is Normal Brick
		brickMatrix[rowindex][colindex] = new HardBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;

	case BRK_BOMB:	//The new brick to add is Normal Brick
		brickMatrix[rowindex][colindex] = new BombBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;


	case BRK_Rock:	//The new brick to add is Rock Brick
		brickMatrix[rowindex][colindex] = new RockBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;

	case BRK_LASER:	//The new brick to add is Normal Brick
		brickMatrix[rowindex][colindex] = new LaserBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;

	case BRK_POWER:	//The new brick to add is Normal Brick
		brickMatrix[rowindex][colindex] = new PowerBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;


	}
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (brickMatrix[i][j])
				brickMatrix[i][j]->draw();
	return 1;

}

grid* grid::getGrid() const
{
	return pGrid;
}

brick*** grid::getbrickMatrix()
{
	return brickMatrix;
}

void grid::removeCollectable(Collectables* collectable)
{
	delete collectable;
}

vector<Collectables*> grid::getCollecVector() const
{
	return collectables;
}

int grid::deleteBrick(brick*** brickMatrix, point clickedPoint)
{

	//this->brickMatrix = brickMatrix;
	//grid* bricksGrid;
	//// Check that the clickedPoint is within grid range
	//if (clickedPoint.x < uprLft.x || clickedPoint.x >= uprLft.x + width ||
	//	clickedPoint.y < uprLft.y || clickedPoint.y >= uprLft.y + height)
	//{
	//	return -1; // Clicked point is outside the grid
	//}

	// From the clicked point, find out the index (row, col) of the corresponding cell in the grid
	int gridCellRowIndex = (clickedPoint.y - uprLft.y) / config.brickHeight;
	int gridCellColIndex = (clickedPoint.x - uprLft.x) / config.brickWidth;

	// Check if there is a brick at the clicked cell
	if (brickMatrix[gridCellRowIndex][gridCellColIndex]!=nullptr)
	{
		// Delete the brick and assign nullptr to its position
		delete brickMatrix[gridCellRowIndex][gridCellColIndex];
		brickMatrix[gridCellRowIndex][gridCellColIndex] = nullptr;

		// Redraw the grid
		//
		// pGrid->draw();

		return 1; // Brick successfully deleted
	}

	return 0; // No brick found at the clicked cell
}

//void grid::removeBrick(brick*** brickMatrix)
//{
//	this->brickMatrix = brickMatrix;
//	for (int i = 0; i < rows; i++)
//		for (int j = 0; j < cols; j++)
//			if (brickMatrix[i][j]->getstrength() == 0)
//			{
//				delete brickMatrix[i][j];
//				brickMatrix[i][j] = nullptr;
//			}
//
//}

void grid::removeBrick(point uprleft ) {
	int gridCellRowIndex = uprleft.y / config.brickHeight;
	int gridCellColIndex = uprleft.x / config.brickWidth;
	pWind->SetPen(LAVENDER);
	pWind->SetBrush(LAVENDER);
	pWind->DrawRectangle(uprleft.x, uprleft.y, uprleft.x + config.brickWidth, uprleft.y + config.brickHeight);
	delete brickMatrix[gridCellRowIndex][gridCellColIndex];
	brickMatrix = nullptr;
}


void grid::addCollectable(PowerType powertype, point PowerDropPoint)
{
	switch (powertype)
	{
	case windglide:
		collectables.push_back(new WindGlide(PowerDropPoint, config.collectableSide, config.collectableSide, pGame));
		break;
	case QuickSand:
		collectables.push_back(new Quicksand(PowerDropPoint, config.collectableSide, config.collectableSide, pGame));
		break;
	case reversepaddle:
		collectables.push_back(new ReversePaddle(PowerDropPoint, config.collectableSide, config.collectableSide, pGame));
		break;
	case widepaddle:
		collectables.push_back(new WidePaddle(PowerDropPoint, config.collectableSide, config.collectableSide, pGame));
		break;
	case narrowpaddle:
		collectables.push_back(new NarrowPaddle(PowerDropPoint, config.collectableSide, config.collectableSide, pGame));
		break;
	case magnet:
		collectables.push_back(new Magnet(PowerDropPoint, config.collectableSide, config.collectableSide, pGame));
		break;
	case fireball:
		collectables.push_back(new FireBall(PowerDropPoint, config.collectableSide, config.collectableSide, pGame));
		break;
	case multipleball:
		collectables.push_back(new MultipleBall(PowerDropPoint, config.collectableSide, config.collectableSide, pGame));
		break;
	case fasterball:
		collectables.push_back(new FasterBall(PowerDropPoint, config.collectableSide, config.collectableSide, pGame));
		break;
	case slowerball:
		collectables.push_back(new SlowerBall(PowerDropPoint, config.collectableSide, config.collectableSide, pGame));
		break;
	default:
		// Default action for unknown value
		break;
	}
}