#include "Ball.h"
#include "gameConfig.h"
#include "game.h"
#include "Bricks.h"
#include <cmath>
#include "CMUgraphicsLib/CMUgraphics.h"
#include "CMUgraphicsLib/auxil.h"

ball::ball(point r_uprleft, int r_width, int r_height, game* r_pGame) :
    collidable(r_uprleft, r_width, r_height, r_pGame), isBall(true), isFireBall(false)
{
    imageName = "images\\Ball.jpg";
    pGame = r_pGame;
    bricksgrid = r_pGame->getGrid();
    // Initialize prevUprLft with the initial position
    prevUprLft = r_uprleft;
    Xinc = 0;
    Yinc = (config.ballSide / 3);
}

void ball::collisionAction()
{
    if (this->getPointx() == collisionInfo.collisionPoint.x || (this->getPointx() + config.ballSide) == collisionInfo.collisionPoint.x)
    setXinc(Xinc);
    if (this->getPointy() == collisionInfo.collisionPoint.y || (this->getPointy() + config.ballSide) == collisionInfo.collisionPoint.y)
    setYinc(Yinc);
    if (pGame->getbrick()->isThisBrick() && pGame->getBall()->isThisFireBall())
    {
        int rows = bricksgrid->getRows();
        int cols = bricksgrid->getCols();
        brick*** BRICKSMATRIX = bricksgrid->getBrickMatrix();
        for (int i = 10; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (checkCollision(BRICKSMATRIX[i][j])) {
                    this->collisionAction();
                    BRICKSMATRIX[i][j]->collisionAction();
                    delete BRICKSMATRIX[i][j];
                }
            }
        }
    }
}

bool ball::checkCollision(collidable* other)
{
    collisionInfo.isColliding = false;
    collided->setcollidableobj(other);;
    if (other != nullptr) {

        // Calculate the bounding boxes of the objects

        int otherLeft = other->getUprLftX();
        int otherRight = otherLeft + other->getWidth();
        int otherTop = other->getUprLftY();
        int otherBottom = otherTop + other->getHeight();

        int thisleft = this->uprLft.x;
        int thisright = this->uprLft.x + this->width;
        int thistop = this->uprLft.y;
        int thisbottom = this->uprLft.y + this->height;

        // Check if the bounding boxes overlap for left or right sides
        // calculating the collision point(x,y) 

        if (otherRight == thisleft) {
            if (otherTop <= thistop && otherTop >= thisbottom)
            {
                collisionInfo.isColliding = true;
                collisionInfo.collisionPoint.x = otherRight;
                collisionInfo.collisionPoint.y = otherTop + ((thisbottom - otherTop) / 2);
            }
            else if (otherBottom >= thistop && otherBottom <= thisbottom)
            {
                collisionInfo.isColliding = true;
                collisionInfo.collisionPoint.x = otherRight;
                collisionInfo.collisionPoint.y = thistop + ((otherBottom - thistop) / 2);
            }
            else if (thistop <= otherTop && thisbottom >= otherBottom)

            {
                collisionInfo.isColliding = true;
                collisionInfo.collisionPoint.x = otherRight;
                collisionInfo.collisionPoint.y = thistop + (thisbottom - thistop) / 2;
            }
        }
        if (thisright == otherLeft) {
            if (otherTop <= thistop && otherTop >= thisbottom)
            {
                collisionInfo.isColliding = true;
                collisionInfo.collisionPoint.x = otherLeft;
                collisionInfo.collisionPoint.y = otherTop + ((thisbottom - otherTop) / 2);
            }
            else if (otherBottom >= thistop && otherBottom <= thisbottom)
            {
                collisionInfo.isColliding = true;
                collisionInfo.collisionPoint.x = otherLeft;
                collisionInfo.collisionPoint.y = thistop + ((otherBottom - thistop) / 2);
            }
            else if (thistop <= otherTop && thisbottom >= otherBottom)

            {
                collisionInfo.isColliding = true;
                collisionInfo.collisionPoint.x = otherLeft;
                collisionInfo.collisionPoint.y = thistop + (thisbottom - thistop) / 2;
            }
        }
        //check if the bounding boxes overlap for top or bottom sides
        //calculating the collision point(x, y)
        if (otherTop == thisbottom) {
            if (otherRight >= thisleft && otherRight <= thisright)
            {
                collisionInfo.isColliding = true;
                collisionInfo.collisionPoint.x = otherLeft + (otherRight - thisleft) / 2;
                collisionInfo.collisionPoint.y = otherTop;
            }
            else  if (thisleft <= otherLeft && thisright >= otherLeft)
            {
                collisionInfo.isColliding = true;
                collisionInfo.collisionPoint.x = thisleft + (otherLeft - thisleft) / 2;
                collisionInfo.collisionPoint.y = otherTop;
            }
            else if (thisleft >= otherLeft && thisright <= otherRight)

            {
                collisionInfo.isColliding = true;
                collisionInfo.collisionPoint.x = thisleft + (thisright - thisleft) / 2;
                collisionInfo.collisionPoint.y = otherTop;
            }
        }
        if (thistop == otherBottom) {
            if (otherRight >= thisleft && otherRight <= thisright)
            {
                collisionInfo.isColliding = true;
                collisionInfo.collisionPoint.x = otherLeft + (otherRight - thisleft) / 2;
                collisionInfo.collisionPoint.y = otherBottom;
            }
            else  if (thisleft <= otherLeft && thisright >= otherLeft)
            {
                collisionInfo.isColliding = true;
                collisionInfo.collisionPoint.x = thisleft + (otherLeft - thisleft) / 2;
                collisionInfo.collisionPoint.y = otherBottom;
            }
            else if (thisleft >= otherLeft && thisright <= otherRight)

            {
                collisionInfo.isColliding = true;
                collisionInfo.collisionPoint.x = thisleft + (thisright - thisleft) / 2;
                collisionInfo.collisionPoint.y = otherBottom;
            }
        }
    }

    return collisionInfo.isColliding;
}



void ball::Ball_Movement(window* pWind)
{
    //Pause(200);
    pGame->getWind();
    pWind->SetPen(config.bkGrndColor);
    pWind->SetBrush(config.bkGrndColor);

    // Save the current position as the previous position for the next iteration
    prevUprLft.x = this->uprLft.x - Xinc;
    prevUprLft.y = this->uprLft.y + Yinc;

    // Erase the previous frame of the ball
    pWind->DrawRectangle(prevUprLft.x, prevUprLft.y, prevUprLft.x + config.ballSide + 1, prevUprLft.y + config.ballSide + 1, FILLED);

    // Update the ball's position
    this->uprLft.x += (Xinc);
    this->uprLft.y -= (Yinc);

    if (uprLft.y <= config.gridHeight + config.brickHeight)
    {
        int rows = bricksgrid->getRows();
        int cols = bricksgrid->getCols();
        brick*** BRICKSMATRIX = bricksgrid->getBrickMatrix();
        for (int i = 10; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (checkCollision(BRICKSMATRIX[i][j])) {
                    this->collisionAction();
                    BRICKSMATRIX[i][j]->collisionAction();  
                }
            }
        }
    }

    // Wrap the ball around to the top if it reaches the toolbar height
    if ((this->uprLft.x) + config.ballSide >= config.windWidth - 5 || this->uprLft.x <= 0)
    {
        setXinc(Xinc);
    }

    if (this->uprLft.y <= config.toolBarHeight)
    {
        setYinc(Yinc);
    }
    if ((this->uprLft.y + config.ballSide) >= config.windHeight - config.statusBarHeight)
    {
        setYinc(Yinc);
    }
    // Draw the ball in its new position
    this->draw();


    // Redraw the game grid
    grid* gameGrid = pGame->getGrid();
    gameGrid->draw();
}
void ball::setXinc(double newIncrease)
{
    Xinc = - newIncrease;
}

void ball::setYinc(double newIncrease)
{
    Yinc = newIncrease;
}

point ball::getUpperLeft() const
{
    return this->r_uprleft;
}

bool ball::isThisBall()
{
    this->setIsFireBall(!(this->getIsBall()));
    return this->getIsBall();
}

bool ball::isThisFireBall()
{
    this->setIsBall(!(this->getIsFireBall()));
    return this->getIsFireBall();
}

bool ball::getIsBall() const
{
    return isBall;
}

void ball::setIsBall(bool value)
{
    isBall = value;
}

bool ball::getIsFireBall() const
{
    return isFireBall;
}

void ball::setIsFireBall(bool value)
{
    isFireBall = value;
}

void ball::SetPoint()
{
    this->r_uprleft = r_uprleft;
}

//void ball::setBall(ball* newBall)
//{
//    ballptr = newBall;
//}
//
//int ball::getBall(ball* newBall)
//{
//      return ballptr ;
//}

double ball::getuprLft() const
{
    return this->uprLft.x;
}

double ball::getXinc() const
{
    return Xinc;
}
double ball::getYinc() const
{
    return Yinc;
}



void ball::setInitial(window* pWind)
{
    this->setBallIntial();
    pWind->SetPen(WHITE);
    pWind->SetBrush(WHITE);
    pWind->DrawRectangle(uprLft.x, uprLft.y, uprLft.x + config.ballSide , uprLft.y + 30, FILLED);
    this->draw();
    this->setXinc(0);
    this->setYinc(0);
}

void ball::Sapce(window* pWind)
{
    this->setXinc(0);
    this->setYinc(10);
    this->Ball_Movement(pWind);
}


int ball::getPointx() const
{
    return uprLft.x;
}

int ball::getPointy() const
{
    return uprLft.y;
}

void ball::setpeed(double Factor)
{
    this->setXinc(this->getXinc() * Factor);
    this->setYinc(this->getYinc() * Factor);
}

    /*
    char cKeyData;
    keytype kType3;
    kType3 = pWind->GetKeyPress(cKeyData);

    if (kType3 == ASCII && cKeyData == ' ')
    {
        this->setXinc(0);
        this->setYinc(10);
        this->Ball_Movement(pWind);
    }*/
    /*void ball::multipleBalls()
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

            ballList[i] = new ball(ballUpperleft, config.ballSide, config.ballSide, pGame);
            ballList[i]->setXinc(speedsXrandom);
            ballList[i]->setYinc(speedsYrandom);
        }
    }*/
    /*void ball::ResetBall(window* pWind)
    {


        // Reset the ball's position to the initial position
        uprLft.x = r_uprleft.x;
        uprLft.y = r_uprleft.y;

        // Reset the previous position
        prevUprLft = uprLft;

        // Reset the ball's movement increments
        Xinc = 0;
        Yinc = -(config.ballSide / 6);

        // Draw the reset ball
        draw();

        // Redraw the game grid
        grid* gameGrid = bricksgrid;
        gameGrid->draw();

        // Pause to make the reset visible
        Pause(500);
    }
    */
    /*pWind->DrawRectangle(r_uprleft.x, r_uprleft.y, r_uprleft.x + config.ballSide + 1, r_uprleft.y + config.ballSide + 1, FILLED);
        this->setBallIntial();
        this->setXinc(0);
        this->setYinc(0);
        char cKeyData = NULL; {}
        keytype kType = NO_KEYPRESS; {}
        kType = pWind->GetKeyPress(cKeyData);
        if (kType == ASCII && cKeyData == ' ')
        {
           this->setXinc(0);
           this->setYinc((config.ballSide / 3));
        }
        //pGame->~game();*/
