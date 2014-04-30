/*******************************************************************************
 * Author: Matt Arnold                                                         *
 * Description: Defines the Menu class to represent the game menu              *
 * Date Created: 01 April 2014                                                 *
 * Date Last Modified: 10 April 2014 - Matt Arnold                             *
 ******************************************************************************/


#ifndef Tetris_Menu_h
#define Tetris_Menu_h

#include "GLUT_Plotter.h"
#include "Button.h"
#include "Constants.h"

class Menu
{
private:
    Button startButton, viewScores;
    bool running;

public:
    Menu();
    void draw(GLUT_Plotter *g);
    void erase(GLUT_Plotter *g);
    Button& getStartButton();
    Button& getViewScores();
    operator bool();
    void setRun(bool a);
};

#endif
