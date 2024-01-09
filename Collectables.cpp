#include "Collectables.h"

Collectables::Collectables(point r_uprleft, int r_width, int r_height, game* r_pGame) :collidable(r_uprleft, r_width, r_height, r_pGame), duration(60)
{
    startTime = std::chrono::system_clock::now();
}

bool Collectables::isActive() const
{
    auto currentTime = std::chrono::system_clock::now();
    auto elapsedTime = currentTime - startTime;
    return elapsedTime < duration;
}

void Collectables::move()
{
    draw();
    uprLft.y += speed;
}

WindGlide::WindGlide(point r_uprleft, int r_width, int r_height, game* r_pGame) : Collectables(r_uprleft, r_width, r_height, r_pGame)
{
    imageName = "images\\Powers\\SpeedUp.jpg";
    pGame = r_pGame;
}

void WindGlide::collisionAction()
{
    if (isActive())
    {
        pGame->getPaddle()->setspeed(20);
    }
    else
    {
        resetAction();
    }
}

void WindGlide::resetAction()
{
    pGame->getPaddle()->setspeed(10);
}

// ReversePaddle constructor
void ReversePaddle::collisionAction()
{
    if (RisActive())
    {
        pGame->getPaddle()->setspeed(-10);
    }
    else
    {
        resetAction();
    }
}


ReversePaddle::ReversePaddle(point r_uprleft, int r_width, int r_height, game* r_pGame) : Collectables(r_uprleft, r_width, r_height, r_pGame), duration2(120)
{
    imageName = "images\\Powers\\ReverseDirection.jpg";
    pGame = r_pGame;
}

bool ReversePaddle::RisActive() const
{
    auto currentTime = std::chrono::system_clock::now();
    auto elapsedTime = currentTime - startTime2;
    return elapsedTime < duration2;
}

void ReversePaddle::resetAction()
{
    pGame->getPaddle()->setspeed(10);
}


// WidePaddle constructor
WidePaddle::WidePaddle(point r_uprleft, int r_width, int r_height, game* r_pGame) : Collectables(r_uprleft, r_width, r_height, r_pGame)
{
    imageName = "images\\Powers\\ExpandPaddle.jpg";
    pGame = r_pGame;
}

void WidePaddle::collisionAction()
{
    if (isActive())
    {
        pGame->getPaddle()->setWidth(2.0);
    }
    else
    {
        resetAction();
    }
}

void WidePaddle::resetAction()
{
    pGame->getPaddle()->setWidth(1.0);
}


// NarrowPaddle constructor
NarrowPaddle::NarrowPaddle(point r_uprleft, int r_width, int r_height, game* r_pGame) : Collectables(r_uprleft, r_width, r_height, r_pGame)
{
    imageName = "images\\Powers\\NarrowPaddle.jpg";
    pGame = r_pGame;
}

void NarrowPaddle::collisionAction()
{
    if (isActive())
    {
        pGame->getPaddle()->setWidth(0.5);
    }
    else
    {
        resetAction();
    }
}

void NarrowPaddle::resetAction()
{
    pGame->getPaddle()->setWidth(1.0);
}

// Magnet constructor
Magnet::Magnet(point r_uprleft, int r_width, int r_height, game* r_pGame) : Collectables(r_uprleft, r_width, r_height, r_pGame)
{
    imageName = "images\\Powers\\magnet.jpg";
    pGame = r_pGame;
}

void Magnet::collisionAction()
{
    // Get the initial position of the ball
        point ballUpperleft = pGame->getBall()->getUpperLeft();

        // Reset the ball's initial state
        pGame->getBall()->setInitial(pGame->getWind());

        // Delete the existing ball
        delete pGame->getBall();

        // Create a new ball instance at the original position with the same parameters
        ball* ballptr0 = new ball(ballUpperleft, config.ballSide, config.ballSide, pGame);

        // Draw and move the new ball
        ballptr0->draw();
        window* pWind;
        char cKeyData;
        keytype kType;
        kType = pWind->GetKeyPress(cKeyData);

        if (kType == ASCII && cKeyData == ' ')
        {
            ballptr0->Ball_Movement(pGame->getWind());
            // Set initial velocity for the new ball
            ballptr0->setXinc(0);
            ballptr0->setYinc(0);
        }
        // Update the game's ball pointer to the new ball instance
        pGame->setBall(ballptr0);

}

void Magnet::resetAction()
{
}

// MultipleBall constructor
MultipleBall::MultipleBall(point r_uprleft, int r_width, int r_height, game* r_pGame) : Collectables(r_uprleft, r_width, r_height, r_pGame)
{
    imageName = "images\\Powers\\MultipleBalls.jpg";
    pGame = r_pGame;
}

void MultipleBall::collisionAction()
{
    pGame->multipleBalls();
}

void MultipleBall::resetAction()
{
}


// FireBall constructor
FireBall::FireBall(point r_uprleft, int r_width, int r_height, game* r_pGame) : Collectables(r_uprleft, r_width, r_height, r_pGame)
{
    imageName = "images\\Powers\\FireBall.jpg";
    pGame = r_pGame;
}

void FireBall::collisionAction()
{
    if (isActive())
    {
        pGame->getBall()->setIsFireBall(true);
    }
    else
    {
        resetAction();
    }
}

void FireBall::resetAction()
{
    pGame->getBall()->setIsFireBall(false);
}

// FasterBall constructor
FasterBall::FasterBall(point r_uprleft, int r_width, int r_height, game* r_pGame) : Collectables(r_uprleft, r_width, r_height, r_pGame)
{
    imageName = "images\\Powers\\FastBall.jpg";
    pGame = r_pGame;
}

void FasterBall::collisionAction()
{
    if (isActive())
    {
        pGame->getBall()->setpeed(2.0);
    }
    else
    {
        resetAction();
    }
}

void FasterBall::resetAction()
{
    pGame->getBall()->setpeed(1.0);
}

// SlowerBall constructor
SlowerBall::SlowerBall(point r_uprleft, int r_width, int r_height, game* r_pGame) : Collectables(r_uprleft, r_width, r_height, r_pGame)
{
    imageName = "images\\Powers\\SlowBall.jpg";
    pGame = r_pGame;
}

void SlowerBall::collisionAction()
{
    if (isActive())
    {
        pGame->getBall()->setpeed(0.5);
    }
    else
    {
        resetAction();
    }
}

void SlowerBall::resetAction()
{
    pGame->getBall()->setpeed(1.0);
}

// Quicksand constructor
Quicksand::Quicksand(point r_uprleft, int r_width, int r_height, game* r_pGame) : Collectables(r_uprleft, r_width, r_height, r_pGame)
{
    imageName = "images\\Powers\\SlowDown.jpg";
    pGame = r_pGame;
}

void Quicksand::collisionAction()
{
    if (isActive())
    {
        pGame->getPaddle()->setspeed(10);
    }
    else
    {
        resetAction();
    }
}

void Quicksand::resetAction()
{
    pGame->getPaddle()->setspeed(1.0);
}
