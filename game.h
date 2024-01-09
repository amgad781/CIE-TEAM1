#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "toolbar.h"
#include "playToolBar.h"
#include "grid.h"
#include "Ball.h"
#include "paddle.h"
#include <chrono>
#include <thread>
using namespace chrono;
using namespace std;


//Main class that coordinates the game operation
class game
{
	int score;
	int lives = 3;
	enum MODE	//Game mode
	{
		MODE_DSIGN,	//Desing mode (startup mode)
		MODE_PLAY	//Playing mode
	};

	MODE gameMode;

	/// Add more members if needed

	
	bool isPause = false;
	window* pWind;			//Pointer to the CMU graphics window
	toolbar* gameToolbar;
	grid* bricksGrid;
	ball* ballptr;
	brick* brickptr;
	game* pGame;
	brick*** BricksGrid;
	playToolbar* PlayToolBar;
	Paddle* gamePaddle;
	std::chrono::steady_clock::time_point startTime;
	
public:
	game();
	~game();

	clicktype getMouseClick(int& x, int& y) const;//Get coordinate where user clicks and returns click type (left/right)
	string getSrting() const;	 //Returns a string entered by the user


	window* CreateWind(int, int, int, int) const; //creates the game window


	void clearStatusBar() const;	//Clears the status bar
	void startPlay();
	void stopPlay();

	void printMessage(string msg) const;	//Print a message on Status bar

	void go();
	void setBall(ball* newBall);
	void Score();

	string imageName;
	window* getWind() const;		//returns a pointer to the graphics window
	
	Paddle* getPaddle() const;

	void ActivateTimer(window* pWind, std::chrono::steady_clock::time_point startTime);
	grid* getGrid() const;
	ball* getBall() const;
	brick* getbrick() const;


	void resetLives(window* pWind);
	void pauseicon();
	void setgameMode(MODE g);
	void stop();
	void continueicon();
	void drawLives(window* pWind);
	void setlives(int L);
	int getlives();
	void multipleBalls();
	bool endGame();
	int getScore() const;


	void setScore(int newScore);
	//void resetBallPosition(game* pGame);
};

