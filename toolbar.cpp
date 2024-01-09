#include "toolbar.h"
#include "game.h"
#include "grid.h"
#include "gameConfig.h"
#include<fstream>
#include <sstream>
#include <array>  |
#include <vector>
////////////////////////////////////////////////////  class toolbarIcon   ////////////////////////////////////////////////////
toolbarIcon::toolbarIcon(point r_uprleft, int r_width, int r_height, game* r_pGame):
	drawable(r_uprleft, r_width, r_height,  r_pGame)
{}




////////////////////////////////////////////////////  class iconAddNormalBrick   //////////////////////////////////////////////
iconAddNormalBrick::iconAddNormalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame):
	toolbarIcon(r_uprleft, r_width, r_height,  r_pGame)
{}

void iconAddNormalBrick::onClick()
{
	
	pGame->printMessage("Click on empty cells to add Normal Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_NRM, clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");

}

////////////////////////////////////////////////////  class iconAddHardBrick   //////////////////////////////////////////////
iconAddHardBrick::iconAddHardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddHardBrick::onClick()
{
	pGame->printMessage("Click on empty cells to add Hard Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_HRD, clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");
}



////////////////////////////////////////////////////  class iconAddPOWERBrick   //////////////////////////////////////////////
iconAddPowerBrick::iconAddPowerBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddPowerBrick::onClick()
{
	pGame->printMessage("Click on empty cells to add a random power ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_POWER, clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");
}


////////////////////////////////////////////////////  class iconAddRockBrick   //////////////////////////////////////////////
iconAddRockBrick::iconAddRockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddRockBrick::onClick()
{

	pGame->printMessage("Click on empty cells to add Rock Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_Rock, clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");

}




////////////////////////////////////////////////////  class iconAddLaserBrick   //////////////////////////////////////////////
iconAddLaserBrick::iconAddLaserBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddLaserBrick::onClick()
{

	pGame->printMessage("Click on empty cells to add Laser Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_LASER, clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");

}

////////////////////////////////////////////////////  class iconAddBombBrick   //////////////////////////////////////////////
iconAddBombBrick::iconAddBombBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconAddBombBrick::onClick()
{
	pGame->printMessage("Click on empty cells to add Bomb Bricks  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();
		pGrid->addBrick(BRK_BOMB, clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");
}



////////////////////////////////////////////////////  class iconSave   //////////////////////////////////////////////
iconSave::iconSave(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconSave::onClick()
{
	pGame->printMessage("Design is saving");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	grid* pGrid = pGame->getGrid();
	brick*** Brick = pGrid->getBrickMatrix();
	//brick* brick;
	BrickType brktype;
	int cols = pGrid->getCols();
	int rows = pGrid->getRows();
	ofstream savefile("save.txt");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (Brick[i][j] != nullptr) {
				savefile << i << " ";
				savefile << j << " ";
				brktype = Brick[i][j]->getbrkType();
				if (brktype == BRK_NRM) {
					savefile << "1" << "\n";
				}
				else if (brktype == BRK_HRD) {
					savefile << "2" << "\n";
				}
				else if (brktype == BRK_BOMB) {
					savefile << "3" << "\n";
				}
				else if (brktype == BRK_Rock) {
					savefile << "4" << "\n";
				}
				else if (brktype == BRK_POWER) {
					savefile << "5" << "\n";
				}
				else if (brktype == BRK_LASER) {
					savefile << "6" << "\n";
				}

			}
		}
	}
	savefile.close();
}

////////////////////////////////////////////////////  class iconRemove   //////////////////////////////////////////////
iconRemove::iconRemove(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}


void iconRemove::onClick()
{
	pGame->printMessage("Click on brick  to remove brick  ==> Right-Click to stop <==");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	while (t == LEFT_CLICK)
	{
		point clicked;
		clicked.x = x;
		clicked.y = y;
		grid* pGrid = pGame->getGrid();

		pGrid->deleteBrick(pGrid->getbrickMatrix(), clicked);
		pGrid->addBrick(BRK_REM, clicked);
		//pGrid->deleteBrick(pGrid->getbrickMatrix(), clicked);
		pGrid->draw();
		t = pGame->getMouseClick(x, y);
	}
	pGame->printMessage("");
}



//void iconRemove::onClick()
//{
//	pGame->printMessage("Click on the bricks to delete them  ==> Right-Click to stop <==");
//	int x, y;
//	clicktype t = pGame->getMouseClick(x, y);
//	while (t == LEFT_CLICK)
//	{
//		point clicked;
//		clicked.x = x;
//		clicked.y = y;
//		grid* pGrid = pGame->getGrid(); 
//		pGrid->addBrick(BRK_REM, clicked);
//		//pGrid->deleteBrick(pGrid->getbrickMatrix(), clicked);  // Pass the appropriate 
//		//pGrid->draw();
//		t = pGame->getMouseClick(x, y);
//	}
//	pGame->printMessage("");
//}

////////////////////////////////////////////////////  class iconLoad   //////////////////////////////////////////////
iconLoad::iconLoad(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconLoad::onClick()
{
	pGame->printMessage("Design is loading");
	int x, y;
	clicktype t = pGame->getMouseClick(x, y);
	grid* pGrid = pGame->getGrid();
	brick*** Brick = pGrid->getBrickMatrix();
	BrickType brktype;
	string line;
	ifstream loadfile("save.txt");

	vector<array<int, 3>> data;
	while (getline(loadfile, line)) {
		istringstream iss(line);
		array<int, 3> variables;
		if (iss >> variables[0] >> variables[1] >> variables[2]) {
			// Process the array of three variables
			data.push_back(variables);
			for (const auto& arr : data) {
				BrickType myEnumValue = static_cast<BrickType>(arr[2]);
				pGrid->addSavedBrick(arr[0], arr[1], myEnumValue);
			}
		}

	}

	loadfile.close();
}


////////////////////////////////////////////////////  class iconPlay   //////////////////////////////////////////////
iconPlay::iconPlay(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{}

void iconPlay::onClick()
{
	pGame->printMessage("Click space to start playing ==> Right-Click to stop <==");
	pGame->startPlay(); 
}



////////////////////////////////////////////////////  class iconExit   //////////////////////////////////////////////
iconExit::iconExit(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	toolbarIcon(r_uprleft, r_width, r_height, r_pGame)
{

}

void iconExit::onClick()
{
	//TO DO: add code for cleanup and game exit here
}




////////////////////////////////////////////////////  class toolbar   //////////////////////////////////////////////
toolbar::toolbar(point r_uprleft, int wdth, int hght, game* pG):
	drawable(r_uprleft, wdth, hght, pG)
{	
	
	height = hght;
	pGame = pG;

	//First prepare List of images for each icon
	//To control the order of these images in the menu, reoder them in enum ICONS above	
	iconsImages[ICON_ADD_NORM] = "images\\ToolbarIcons\\NormalBrickIcon.jpg";
	iconsImages[ICON_ADD_Hard] = "images\\ToolbarIcons\\Hardbrick.jpg";
	iconsImages[ICON_ADD_ROCK] = "images\\ToolbarIcons\\LaserBrick.jpg";
	iconsImages[ICON_ADD_LASER] = "images\\ToolbarIcons\\Rockbrick.jpg";
	iconsImages[ICON_ADD_POWER] = "images\\ToolbarIcons\\Powebrick.jpg";
	iconsImages[ICON_ADD_BOMB] = "images\\ToolbarIcons\\BombBrick2.jpg";
	iconsImages[ICON_SAVE] = "images\\ToolbarIcons\\SaveIcon.jpg";
	iconsImages[ICON_LOAD] = "images\\ToolbarIcons\\LoadIcon.jpg";
	iconsImages[ICON_REMOVE] = "images\\ToolbarIcons\\RemoveIcon.jpg";
	iconsImages[ICON_PLAY] = "images\\ToolbarIcons\\PlayIcon.jpg";
	iconsImages[ICON_EXIT] = "images\\ToolbarIcons\\ExitIcon.jpg";
	
	point p;
	p.x = 0;
	p.y = 0;

	iconsList = new toolbarIcon* [ICON_COUNT];

	//For each icon in the tool bar
	//	1- Create an object setting its upper left corner, width and height
	iconsList[ICON_ADD_NORM] = new iconAddNormalBrick(p, config.iconWidth, height, pGame);
	p.x+= config.iconWidth;

	iconsList[ICON_ADD_Hard] = new iconAddHardBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;

	iconsList[ICON_ADD_BOMB] = new iconAddBombBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;

	iconsList[ICON_ADD_ROCK] = new iconAddRockBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;


	iconsList[ICON_ADD_POWER] = new iconAddPowerBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;

	iconsList[ICON_ADD_LASER] = new iconAddLaserBrick(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;

	iconsList[ICON_SAVE] = new iconSave(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;

	iconsList[ICON_LOAD] = new iconLoad(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;

	iconsList[ICON_REMOVE] = new iconRemove(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;

	iconsList[ICON_PLAY] = new iconPlay(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;

	iconsList[ICON_EXIT] = new iconExit(p, config.iconWidth, height, pGame);
	p.x += config.iconWidth;

	

	//	2-Set its image (from the above images list)
	for (int i = 0; i < ICON_COUNT; i++)
	{
		iconsList[i]->setImageName(iconsImages[i]);

	}
}

toolbar::~toolbar()
{
	for (int i = 0; i < ICON_COUNT; i++)
		delete iconsList[i];
	delete iconsList;
}

void toolbar::draw() const
{
	for (int i = 0; i < ICON_COUNT; i++)
		iconsList[i]->draw();
	window* pWind = pGame->getWind();
	pWind->SetPen(LAVENDER,3);
	pWind->DrawLine(0, height, pWind->GetWidth(), height);

}

//handles clicks on toolbar icons, returns true if exit is clicked
bool toolbar::handleClick(int x, int y)
{
	if (x > ICON_COUNT * config.iconWidth)	//click outside toolbar boundaries
		return false;
	
	
	//Check whick icon was clicked
	//==> This assumes that menu icons are lined up horizontally <==
	//Divide x coord of the point clicked by the icon width (int division)
	//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

	int clickedIconIndex = (x / config.iconWidth);
	iconsList[clickedIconIndex]->onClick();	//execute onClick action of clicled icon

	if (clickedIconIndex == ICON_EXIT) return true;	
	
	return false;
}