#pragma once
#include "CMUgraphicsLib/CMUgraphics.h"

__declspec(selectany) //This line to prevent "redefinition error"
struct 		//contains all game configurations (MAY be loaded from a configuration file later)
{
	int	windWidth=1200, windHeight=600,	//Window width and height
		wx=5, wy=5,			//Window starting coordinates

		//The window is divded into 4 areas: toolbar, bricks grid area, paddle area, statusbar
		toolBarHeight=40,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		statusBarHeight=50;	//Status Bar Height
		
	int remainingHeight = windHeight - toolBarHeight - statusBarHeight;

	int gridHeight = int(remainingHeight * (2 / 3.0)); 		//The grid is where bricks can be drawn
	int paddleAreaHeight = remainingHeight - gridHeight;	//The area dedicated for paddle

	color	penColor = BLUE,			//color used to draw lines/write messages
			bkGrndColor= LAVENDER,		//Background color
			statusBarColor = LAVENDER;	//background color of the status
	int penWidth=3;			//width of the pen that draws shapes


	int scoreWidth = 200;
	int scoreUprLftX = 850;
	int scoreUprLftY = 0;

	int brickWidth = 60;
	int brickHeight = 30;
	int normalBrickStrength = 1;
	int bombBrickStrength = 1;
	int hardBrickStrength = 3;
	int RockBrickStrength = 1;
	int LaserBrickStrength = 1;
	int PowerBrickStrength = 1;

	int collectableSide = 20;

	int powerUpsWidth = 20;
	int powerUpsHeight = 20;



	int ballSide = 30;		//length of the ball as a square
	
	color gridLinesColor = WHITE;

	int timerUprLftX = 1050;
	int timerUprLftY = 0;
	int digitWidth = 15;
	int paddleWidth = 200, paddleHeight = 30;
	int paddleInitialX = 500, paddleInitialY = 500;
	//int fixx = 70 , fixy = 70;
	int ballintialX = 580, ballintialY = 470;
	
	int playToolBarhieght = 30;
	int var_2 = 140;
	int playToolBarPositionY = 980;
	int playToolBarPositionX = 550;
	
	int liveIconWidth = 50;
	int livesiconPositionX=825;
	int var = 70;

	int	iconWidth = 70; 	//Width of each icon in toolbar 
}config;
