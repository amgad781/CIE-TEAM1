#pragma once

//This file contains all classes related to toolbar (toolbar icon classes & toolbar class itself)
#include "drawable.h"

////////////////////////////////////////////////////  class toolbarIcon   ////////////////////////////////////////////////////
//Base class for all toolbar icons 
class toolbarIcon :public drawable
{
public:
	toolbarIcon(point r_uprleft, int r_width, int r_height, game* r_pGame);
    virtual void onClick()=0;   //The action that should be taken when this icon is clicked
};

////////////////////////////////////////////////////  class iconAddNormalBrick   //////////////////////////////////////////////
class iconAddNormalBrick :public toolbarIcon
{
public:
	iconAddNormalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void onClick();
};


////////////////////////////////////////////////////  class iconAddPowerBrick   //////////////////////////////////////////////
class iconAddPowerBrick :public toolbarIcon
{
public:
	iconAddPowerBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void onClick();
};


////////////////////////////////////////////////////  class iconAddHardBrick   //////////////////////////////////////////////
class iconAddHardBrick :public toolbarIcon
{
public:
	iconAddHardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void onClick();
};

////////////////////////////////////////////////////  class iconAddLaserBrick   //////////////////////////////////////////////
class iconAddLaserBrick :public toolbarIcon
{
public:
	iconAddLaserBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void onClick();
};

////////////////////////////////////////////////////  class iconAddRockBrick   //////////////////////////////////////////////

class iconAddRockBrick :public toolbarIcon
{
public:
	iconAddRockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void onClick();
};

class iconAddBombBrick :public toolbarIcon
{
public:
	iconAddBombBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void onClick();
};

////////////////////////////////////////////////////  class iconESave   //////////////////////////////////////////////
class iconSave :public toolbarIcon
{
public:
	iconSave(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void onClick();
};

////////////////////////////////////////////////////  class iconRemove  //////////////////////////////////////////////
class iconRemove :public toolbarIcon
{
public:
	iconRemove(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void onClick();
};

////////////////////////////////////////////////////  class iconLoad  //////////////////////////////////////////////
class iconLoad :public toolbarIcon
{
public:
	iconLoad(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void onClick();
};

////////////////////////////////////////////////////  class iconPlay  //////////////////////////////////////////////
class iconPlay :public toolbarIcon
{
public:
	iconPlay(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void onClick();
};


////////////////////////////////////////////////////  class iconExit   //////////////////////////////////////////////
class iconExit :public toolbarIcon
{
public:
	iconExit(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void onClick();
};


////////////////////////////////////////////////////  class toolbar   //////////////////////////////////////////////
class toolbar:public drawable
{

	enum ICONS //The icons of the toolbar (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here
		ICON_ADD_NORM,		//add normal brick

		ICON_ADD_Hard,		//add Hard brick

		ICON_ADD_BOMB,		//add Bomb brick

		ICON_ADD_LASER,		//add Laser brick


		ICON_ADD_POWER,		//add POWER brick

		ICON_ADD_ROCK,		//add Rock brick

		ICON_SAVE,			//Save design

		ICON_LOAD,			//Load design

		ICON_REMOVE,		//add remove button

		ICON_PLAY,			//play icon

		ICON_EXIT,			//Exit icon


		ICON_COUNT			//no. of menu icons ==> This should be the last line in this enum

	};

private:
    toolbarIcon** iconsList; //an array of toolbarIcon pointers
	string iconsImages[ICON_COUNT];
	game* pGame;

public:
	toolbar(point r_uprleft, int r_width, int r_height, game* r_pGame);
	~toolbar();
    void draw() const;
	bool handleClick(int x, int y);	//handles clicks on toolbar icons, returns true if exit is clicked
};

