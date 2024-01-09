#pragma once
#include "collidable.h"
#include "game.h"
#include <chrono>

class game;

class Collectables : public collidable
{
protected:
    std::chrono::time_point<std::chrono::system_clock> startTime;
    std::chrono::seconds duration;
    int speed = 5;
private:
    bool iscollectable = true;
public:
    Collectables(point r_uprleft, int r_width, int r_height, game* r_pGame);
    bool isActive() const;
    void move();
    virtual void collisionAction() override = 0;
    virtual void resetAction() = 0;
};

class WindGlide : public Collectables
{
public:
    WindGlide(point r_uprleft, int r_width, int r_height, game* r_pGame);
    virtual void collisionAction() override;
    virtual void resetAction() override;
};

class Quicksand : public Collectables
{
public:
    Quicksand(point r_uprleft, int r_width, int r_height, game* r_pGame);
    virtual void collisionAction() override;
    virtual void resetAction() override;
};

class ReversePaddle : public Collectables
{
    std::chrono::time_point<std::chrono::system_clock> startTime2;
    std::chrono::seconds duration2;

public:
    ReversePaddle(point r_uprleft, int r_width, int r_height, game* r_pGame);
    bool RisActive() const;
    virtual void collisionAction() override;
    virtual void resetAction() override;
};

class WidePaddle : public Collectables
{
public:
    WidePaddle(point r_uprleft, int r_width, int r_height, game* r_pGame);
    virtual void collisionAction() override;
    virtual void resetAction() override;
};

class NarrowPaddle : public Collectables
{
public:
    NarrowPaddle(point r_uprleft, int r_width, int r_height, game* r_pGame);
    virtual void collisionAction() override;
    virtual void resetAction() override;
};

class FasterBall : public Collectables
{
public:
    FasterBall(point r_uprleft, int r_width, int r_height, game* r_pGame);
    virtual void collisionAction() override;
    virtual void resetAction() override;
};

class SlowerBall : public Collectables
{
public:
    SlowerBall(point r_uprleft, int r_width, int r_height, game* r_pGame);
    virtual void collisionAction() override;
    virtual void resetAction() override;
};

class FireBall : public Collectables
{
public:
    FireBall(point r_uprleft, int r_width, int r_height, game* r_pGame);
    virtual void collisionAction() override;
    virtual void resetAction() override;
};

class Magnet : public Collectables
{
public:
    Magnet(point r_uprleft, int r_width, int r_height, game* r_pGame);
    virtual void collisionAction() override;
    virtual void resetAction() override;

};

class MultipleBall : public Collectables
{
public:
    MultipleBall(point r_uprleft, int r_width, int r_height, game* r_pGame);
    virtual void collisionAction() override;
    virtual void resetAction() override;

};
