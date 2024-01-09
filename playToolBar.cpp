#include "playToolBar.h"
#include "drawable.h"
#include "gameConfig.h"
#include "game.h"
playToolbaricon::playToolbaricon(point r_lwrleft, int r_width, int r_height, game* r_pGame) :
    drawable(r_lwrleft, r_width, r_height, r_pGame)
{}


iconPause::iconPause(point r_lwrleft, int r_width, int r_height, game* r_pGame) :
    playToolbaricon(r_lwrleft, r_width, r_height, r_pGame)
{}

void iconPause::onClick() {
    pGame->printMessage("Click space to start playing ==> Right-Click to a7a <==");
    game* Game;
    Game->pauseicon();
}

iconContinue::iconContinue(point r_lwrleft, int r_width, int r_height, game* r_pGame) :
    playToolbaricon(r_lwrleft, r_width, r_height, r_pGame)
{}

void iconContinue::onClick() {
    game* Game;
    Game->continueicon();
}

iconStop::iconStop(point r_lwrleft, int r_width, int r_height, game* r_pGame) :
    playToolbaricon(r_lwrleft, r_width, r_height, r_pGame)
{}

void iconStop::onClick() {
    game* Game;
    Game->stop();
}





////////////////////////////////////////////////////  class playToolBar   //////////////////////////////////////////////
playToolbar::playToolbar(point r_uprleft, int wdth, int hght, game* pG) :
    drawable(r_uprleft, wdth, hght, pG)
{

    height = hght;
    pGame = pG;

    //First prepare List of images for each icon
    //To control the order of these images in the menu, reoder them in enum ICONS above  


    iconsImages[ICON_PAUSE] = "images\\playToolBar\\pauseicon.jpg";
    iconsImages[ICON_CONTINUE] = "images\\playToolBar\\continuedicon.jpg";
    iconsImages[ICON_STOP] = "images\\playToolBar\\stopicon.jpg";


    point p;
    p.x = config.playToolBarPositionY;
    p.y = config.playToolBarPositionX;

    iconsList = new playToolbaricon * [ICON_COUNT];

    //For each icon in the tool bar
    //  1- Create an object setting its upper left corner, width and height


    iconsList[ICON_PAUSE] = new iconPause(p, config.iconWidth, height, pGame);
    p.x += config.iconWidth;
    iconsList[ICON_CONTINUE] = new iconContinue(p, config.iconWidth, height, pGame);
    p.x += config.iconWidth;
    iconsList[ICON_STOP] = new iconStop(p, config.iconWidth, height, pGame);
    p.x += config.iconWidth;


    //  2-Set its image (from the above images list)
    for (int i = 0; i < ICON_COUNT; i++)
    {
        iconsList[i]->setImageName(iconsImages[i]);

    }
}



void playToolbar::draw() const
{
    for (int i = 0; i < ICON_COUNT; i++)
        iconsList[i]->draw();
    window* pWind = pGame->getWind();


}

//handles clicks on toolbar icons, returns true if exit is clicked
bool playToolbar::handleClick(int x, int y)
{
    if (x > ICON_COUNT * config.iconWidth)  //click outside toolbar boundaries
        return false;





    int clickedIconIndex = (x / config.iconWidth);
    iconsList[clickedIconIndex]->onClick();  //execute onClick action of clicled icon

    /*if (clickedIconIndex == ICON_EXIT) return true;

    return false;*/


}
playToolbar::~playToolbar()
{
    for (int i = 0; i < ICON_COUNT; i++)
        delete iconsList[i];
    delete iconsList;
}