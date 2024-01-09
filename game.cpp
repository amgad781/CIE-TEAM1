#include "game.h"
#include "gameConfig.h"
#include "Ball.h"
#include "Paddle.h"
#include "Functions.h"
#include "CMUgraphicsLib/CMUgraphics.h"
#include "CMUgraphicsLib/auxil.h"
#include "string"
#include "Collectables.h"


game::game()
{
	//Initialize playgrond parameters

	////2 - create and draw  playToolBar
	point playToolBarUpperleft;
	playToolBarUpperleft.x = 0;
	playToolBarUpperleft.y = 0;
	PlayToolBar = new playToolbar(playToolBarUpperleft, 0, config.playToolBarhieght, this);

	gameMode = MODE_DSIGN;
	startTime = high_resolution_clock::now();
	pGame = this;

	//1 - Create the main window
	pWind = CreateWind(config.windWidth, config.windHeight, config.wx, config.wy);

	//2 - create and draw the toolbar
	point toolbarUpperleft;
	toolbarUpperleft.x = 0;
	toolbarUpperleft.y = 0;

	gameToolbar = new toolbar(toolbarUpperleft, 0, config.toolBarHeight, this);
	gameToolbar->draw();



	//3 - create and draw the grid
	point gridUpperleft;
	gridUpperleft.x = 0;
	gridUpperleft.y = config.toolBarHeight;
	bricksGrid = new grid(gridUpperleft, config.windWidth, config.gridHeight, this);
	bricksGrid->draw();

	//4- Create the Paddle
	point PaddleUpperleft;
	PaddleUpperleft.x = config.paddleInitialX;
	PaddleUpperleft.y = config.paddleInitialY;
	gamePaddle = new Paddle(PaddleUpperleft, config.paddleWidth, config.paddleHeight, this);


	//5- Create the ball
	point ballUpperleft;
	ballUpperleft.x = config.ballintialX;
	ballUpperleft.y = config.ballintialY;
	ballptr = new ball(ballUpperleft, config.ballSide, config.ballSide, this);


	//6- Create and clear the status bar
	clearStatusBar();
}

void game::Score()
{
	pWind->SetPen(BLACK);
	pWind->SetFont(40, BOLD, BY_NAME, "Arial");
	pWind->DrawString(config.scoreUprLftX, config.scoreUprLftY, "Score:");

	for (int i = 0; i < bricksGrid->getRows(); i++)
	{
		for (int j = 0; j < bricksGrid->getCols(); j++)
		{
			if (bricksGrid->getBrickMatrix()[i][j]->isColliding())
			{
				score++;
				pWind->DrawInteger(config.scoreUprLftX + 100, config.scoreUprLftY, score);
				pWind->SetPen(LAVENDER);
				pWind->SetBrush(LAVENDER);
				pWind->DrawRectangle(config.scoreUprLftX + 100, config.scoreUprLftY, config.timerUprLftX, config.toolBarHeight);
				pWind->UpdateBuffer();
			}
		}
	}
}

game::~game()
{
	delete pWind;
	delete gameToolbar;
	delete PlayToolBar;
	delete bricksGrid;
	delete ballptr;
	delete gamePaddle;
}


clicktype game::getMouseClick(int& x, int& y) const
{
	return pWind->WaitMouseClick(x, y);	//Wait for mouse click
}
//////////////////////////////////////////////////////////////////////////////////////////
window* game::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(config.bkGrndColor);
	pW->SetPen(config.bkGrndColor, 1);
	pW->DrawRectangle(0, 0, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void game::clearStatusBar() const
{
	//Clear Status bar by drawing a filled rectangle
	pWind->SetPen(config.statusBarColor, 1);
	pWind->SetBrush(config.statusBarColor);
	pWind->DrawRectangle(0, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
}

void game::startPlay()
{
	gameMode = MODE_PLAY;
}

void game::stopPlay()
{

	gameMode = MODE_DSIGN;
	delete PlayToolBar;
	PlayToolBar = nullptr;
}


//////////////////////////////////////////////////////////////////////////////////////////

void game::printMessage(string msg) const	//Prints a message on status bar
{
	clearStatusBar();	//First clear the status bar

	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, config.windHeight - (int)(0.85 * config.statusBarHeight), msg);
}



window* game::getWind() const		//returns a pointer to the graphics window
{
	return pWind;
}



void game::ActivateTimer(window* pWind, std::chrono::steady_clock::time_point startTime)
{
	pWind->SetPen(BLACK);
	pWind->SetFont(40, BOLD, BY_NAME, "Arial");

	auto currentTime = std::chrono::steady_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime);

	auto minutes = std::chrono::duration_cast<std::chrono::minutes>(duration);
	int minutesInt = static_cast<int>(minutes.count());
	duration -= minutes;

	auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration);
	int secondsInt = static_cast<int>(seconds.count());

	pWind->DrawInteger(config.timerUprLftX, config.timerUprLftY, minutesInt);
	pWind->DrawInteger(config.timerUprLftX + 35, config.timerUprLftY, secondsInt);
	pWind->DrawString(config.timerUprLftX + 25, config.timerUprLftY, ":  ");
	Pause(1000);
	pWind->DrawRectangle(config.timerUprLftX, config.timerUprLftY, config.windWidth, config.toolBarHeight);
}



string game::getSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if (Label.size() > 0)
				Label.resize(Label.size() - 1);
			else
				Key = '\0';
		else
			Label += Key;
		printMessage(Label);
	}
}

grid* game::getGrid() const
{
	// TODO: Add your implementation code here.
	return bricksGrid;
}

ball* game::getBall() const
{

	return ballptr;
}

brick* game::getbrick() const
{

	return brickptr ;
}


Paddle* game::getPaddle() const
{
	return gamePaddle;
}




void game::pauseicon()
{
	isPause = true;
}

void game::setgameMode(MODE g)
{
	gameMode = g;
}

void game::stop()
{
	pauseicon();
	stopPlay();
}

void game::continueicon()
{
	isPause = false;
}




void game::drawLives(window* pWind)
{
	imageName = "images\\playToolBar\\lives.jpg";
	int lives = 3;
	//for (int i = 0; i < lives; i++)

	pWind->DrawImage(imageName, config.livesiconPositionX, config.playToolBarPositionX, config.liveIconWidth, config.playToolBarhieght);
	
	pWind->DrawImage(imageName, config.livesiconPositionX+config.liveIconWidth, config.playToolBarPositionX, config.liveIconWidth, config.playToolBarhieght);
	
	pWind->DrawImage(imageName, config.livesiconPositionX+2*config.liveIconWidth, config.playToolBarPositionX, config.liveIconWidth, config.playToolBarhieght);
	

}

void game::resetLives(window* pWind)
{
	imageName = "images\\playToolBar\\livesremover.jpg";
	if ((ballptr->getPointy() + config.ballSide) >= config.windHeight - config.statusBarHeight)
	{
		if (lives > 0) {
			if (lives == 3) {

				imageName = "images\\playToolBar\\livesremover.jpg";
				pWind->DrawImage(imageName, config.livesiconPositionX + 2 * config.liveIconWidth, config.playToolBarPositionX, 50, config.playToolBarhieght);
				lives--;
				ballptr->setInitial(pWind);
			}
			else if (lives == 2) {
				imageName = "images\\playToolBar\\livesremover.jpg";
				pWind->DrawImage(imageName, config.livesiconPositionX + config.liveIconWidth, config.playToolBarPositionX, 50, config.playToolBarhieght);
				lives--;
				ballptr->setInitial(pWind);
				//printMessage("Lives = 1");
			}
			else if (lives == 1) {
				imageName = "images\\playToolBar\\livesremover.jpg";
				pWind->DrawImage(imageName, config.livesiconPositionX, config.playToolBarPositionX, 50, config.playToolBarhieght);
				lives--;
				string myscore = "Gameover, Score:"+to_string(this->getScore());
				printMessage(myscore);

				stop();

			}
		}

	}

}


void game::setlives(int L)
{
	lives = L;
}

int game::getlives()
{
	return lives;
}




void game::setBall(ball* newBall) {
	ballptr = newBall;
}




void game::multipleBalls()
{
	ball** ballList = new ball * [5];

	for (int i = 0; i < 5; i++)
	{
		point ballUpperleft;
		ballUpperleft.x = config.ballintialX;

		// Generate a random offset in the range -60 to +60
		int randomOffset = rand() % 121 - 60;
		int speedsXrandom = rand() % 20 + 1; // Generates a random number in the range [1, 20]
		int speedsYrandom = rand() % 30 + 1; // Generates a random number in the range [1, 30]

		ballUpperleft.y = config.ballintialY + randomOffset;

		ballList[i] = new ball(ballUpperleft, config.ballSide, config.ballSide, this);
		ballList[i]->Ball_Movement(this->getWind());
		ballList[i]->setXinc(speedsXrandom);
		ballList[i]->setYinc(speedsYrandom);
	}
}


int game::getScore() const {
	return score;
}

// Setter for score
void game::setScore(int newScore) {
	score = newScore;
}

bool game::endGame()
{
	grid* Grid = getGrid();
	brick*** brickMatrix = Grid->getBrickMatrix();
	int rows = Grid->getRows();
	int cols = Grid->getCols();
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (brickMatrix[i][j] != nullptr) {
				return false;
				break;
			}
		}
	}
	stopPlay();
	return true;
}


////////////////////////////////////////////////////////////////////////
void game::go()
{
	//This function reads the position where the user clicks to determine the desired operation
	int x, y;
	bool isExit = false;
	bool ExitPlay = false;

	char cKeyData = NULL; {}
	keytype kType = NO_KEYPRESS; {}
	keytype kType2;
	keytype kType3;

	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - Brick Breaker (CIE202-project) - - - - - - - - - -");

	
	do
	{
		printMessage("Ready...");
		pWind->GetMouseClick(x, y);
		//getMouseClick(x, y); //Get the coordinates of the user click

		char cKeyData;
		keytype kType;

		if (gameMode == MODE_DSIGN)		//Game is in the Desgin mode
		{

			//[1] If user clicks on the Toolbar
			if (y >= 0 && y < config.toolBarHeight)
			{
				isExit = gameToolbar->handleClick(x, y);
			}
		}
		else if (gameMode == MODE_PLAY)
		{
			PlayToolBar->draw();
			drawLives(pWind);
			kType = pWind->GetKeyPress(cKeyData); //Try waitKeyPress
			pWind->GetMouseClick(x, y);
			gamePaddle->draw();
			ballptr->draw();
			if (kType == ASCII && cKeyData == ' ')
			{
				startTime = std::chrono::steady_clock::now();

				do
				{
					resetLives(pWind);
					gamePaddle->move(pWind);
					ActivateTimer(pWind, startTime);
					ballptr->Ball_Movement(pWind);
					for (Collectables* collec : pGame->getGrid()->getCollecVector())
					{
						if (collec != nullptr)
						collec->move();
					}
					if (y >= 0 && y < config.playToolBarhieght)
					{
						ExitPlay = PlayToolBar -> handleClick(x, y);
					} 
					if (endGame() == true) {
						stopPlay();
						delete ballptr;
						ballptr = nullptr;
						pWind->DrawRectangle(0, 0, config.windWidth, config.windHeight, FILLED);
						pWind->SetPen(RED);
						pWind->SetFont(70, BOLD, BY_NAME, "Arial");
						pWind->DrawString(450, 200, "You win");
						pWind->SetFont(50, BOLD, BY_NAME, "Arial");
						string Score = to_string(this->getScore());
						pWind->DrawString(450, 285, "Score is:");
						pWind->DrawString(630, 285, Score);

					}
					
					kType2 = pWind->GetKeyPress(cKeyData);

					if (kType2 == ASCII && cKeyData == 'b')
					{kType2 = pWind->GetKeyPress(cKeyData);

					if (kType2 == ASCII && cKeyData == 'b')
					{
						// Get the initial position of the ball
						point ballUpperleft = pGame->getBall()->getUpperLeft();

						// Reset the ball's initial state
						pGame->getBall()->setInitial(pGame->getWind());

						// Delete the existing ball
						delete pGame->getBall();

						// Create a new ball instance at the original position with the same parameters
						ballptr = new ball(ballUpperleft, config.ballSide, config.ballSide, pGame);

						// Draw and move the new ball
						ballptr->draw();
						ballptr->Ball_Movement(pGame->getWind());
						// Set initial velocity for the new ball


						kType3 = pWind->GetKeyPress(cKeyData);

						if (kType3 == ASCII && cKeyData == ' ')
						{
							ballptr->setXinc(1);
							ballptr->setYinc(config.ballSide/3);
						}
						pGame->setBall(ballptr);
					}
						ballptr->setInitial(pWind);
						char cKeyData;
						keytype kType3;
						kType3 = pWind->GetKeyPress(cKeyData);

						if (kType3 == ASCII && cKeyData == ' ')
						{
							ballptr->Sapce(pWind);
						}

					}
					gamePaddle->move(pWind);

					pWind->GetMouseClick(x, y);
					if (y >= 0 && y < config.playToolBarhieght)
					{
						ExitPlay = PlayToolBar->handleClick(x, y);
					}
					gamePaddle->checkCollision(ballptr);
					gamePaddle->collisionAction();
				} while (!isPause);
			}
		}
	} while (!isExit);

}
