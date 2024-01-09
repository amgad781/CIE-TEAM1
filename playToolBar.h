#pragma once
#include "drawable.h"

class playToolbaricon :public drawable
{
public:
    playToolbaricon(point r_uprleft, int r_width, int r_height, game* r_pGame);
    virtual void onClick() = 0;   //The action that should be taken when this icon is clicked
};

class iconPause : public playToolbaricon
{
public:
    iconPause(point r_lwrleft, int r_width, int r_height, game* r_pGame);
    void onClick();
};
class iconContinue : public playToolbaricon
{
public:
    iconContinue(point r_lwrleft, int r_width, int r_height, game* r_pGame);
    void onClick();
};


class iconStop : public playToolbaricon
{
public:
    iconStop(point r_lwrleft, int r_width, int r_height, game* r_pGame);
    void onClick();
};


////////////////////////////////////////////////////  class playToolBar   //////////////////////////////////////////////
class playToolbar :public drawable
{

    enum ICONS //The icons of the toolbar (you should add more icons)
    {
        //Note: Icons are ordered here as they appear in menu
        //If you want to change the menu icons order, change the order here
        ICON_PAUSE,
        ICON_CONTINUE,
        ICON_STOP,
        //Exit icon

        ICON_COUNT    //no. of menu icons ==> This should be the last line in this enum

    };

private:
    playToolbaricon** iconsList; //an array of toolbarIcon pointers
    string iconsImages[ICON_COUNT];
    game* pGame;

public:
    playToolbar(point r_uprleft, int r_width, int r_height, game* r_pGame);
    ~playToolbar();
    void draw() const;
    bool handleClick(int x, int y);  //handles clicks on toolbar icons, returns true if exit is clicked
};