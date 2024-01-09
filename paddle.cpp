#include "Paddle.h"
#include "game.h"
#include "Ball.h"

Paddle::Paddle(point p_uprleft, int p_width, int p_height, game* pG) : collidable(p_uprleft, p_width, p_height, pG)
{
    imageName = "images\\Paddle\\Paddle.jpg";
    this->speed = 10;
}

bool Paddle::checkCollision(collidable* other)
{
    collisionInfo.isColliding = false;

    int otherLeft = other->getUprLftX();
    int otherRight = otherLeft + other->getWidth();
    int otherTop = other->getUprLftY();
    int otherBottom = otherTop + other->getHeight();

    int thisLeft = this->uprLft.x;
    int thisRight = thisLeft + this->width;
    int thisTop = this->uprLft.y;
    int thisBottom = thisTop + this->height;

    // Check if the bounding boxes overlap for left or right sides
    if (thisRight >= otherLeft && thisLeft <= otherRight) {
        if (thisTop <= otherBottom && thisBottom >= otherTop) {
            collisionInfo.isColliding = true;
            collisionInfo.collisionPoint.x = (thisRight + otherLeft) / 2;
            collisionInfo.collisionPoint.y = (thisTop + thisBottom) / 2;
        }
    }

    // Check if the bounding boxes overlap for top or bottom sides
    if (thisBottom >= otherTop && thisTop <= otherBottom) {
        if (thisLeft <= otherRight && thisRight >= otherLeft) {
            collisionInfo.isColliding = true;
            collisionInfo.collisionPoint.x = (thisLeft + thisRight) / 2;
            collisionInfo.collisionPoint.y = (thisBottom + otherTop) / 2;
        }
    }
    return colliding();
}


bool Paddle::colliding()
{
    return collisionInfo.isColliding;
}

bool Paddle::checkCollision_powerup(collidable* other)
{
    return false;
}



void Paddle::collisionAction()
{
    /*if (this->colliding())
    {
        if (pGame->getBall()->isThisBall())
        {
            double Ballcenter = ((double)(pGame->getBall()->getuprLft()) + 15.0);
            double Paddlecenter = (double)this->getWidth() / 2.0 + (double)this->uprLft.x;
            double diff = (Ballcenter - Paddlecenter) / ((double)this->getWidth());
            double theta = (3.141592653589793238462643383279 / 2.0) + atan(diff);
            double Rinc = pow(pow(pGame->getBall()->getXinc(), 2) + pow(pGame->getBall()->getYinc(), 2), 0.5);

            pGame->getBall()->setXinc(Rinc * cos(theta));
            pGame->getBall()->setYinc(Rinc * sin(theta));
        }
    }*/
}


void Paddle::move(window* pWind)
{

    char cKeyData;
    keytype kType;

    kType = pWind->GetKeyPress(cKeyData);

    if (kType == ARROW)
    {
        pWind->SetPen(LAVENDER);
        pWind->SetBrush(LAVENDER);
        pWind->DrawRectangle(0, config.paddleInitialY, config.windWidth, config.paddleInitialY + config.paddleHeight, FILLED);

        switch (cKeyData)
        {
        case 4:	//left Arrow
            if (uprLft.x > 15) {
                this->uprLft.x -= 10;
                pWind->DrawRectangle(0, config.paddleInitialY, config.windWidth, config.paddleInitialY + config.paddleHeight, FILLED);
                pWind->UpdateBuffer();
                break;
            }
        case 6:	//right Arrow
            if (uprLft.x + config.paddleWidth < config.windWidth - 25)
            {
                this->uprLft.x += 10;
                pWind->DrawRectangle(0, config.paddleInitialY, config.windWidth, config.paddleInitialY + config.paddleHeight, FILLED);
                pWind->UpdateBuffer();

                break;
            }
            pWind->UpdateBuffer();
        }
    }
    this->draw();
    //for (Collectables* collec : pGame->getGrid()->getCollecVector()) {
    //    if (collec != nullptr) {
    //        if (checkCollision(collec))
    //        {
    //            collec->collisionAction();
    //        }
    //    }
    //}
}


int Paddle::getspeed() const
{
    return speed;
}

void Paddle::setspeed(int speed)
{
    this->speed = speed;
}