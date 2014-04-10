/*
 * Author: Matt Arnold
 * Assignment Title:
 * Assignment Description:
 * Due Date:
 * Date Created: 01 April 2014
 * Date Last Modified: 08 April 2014 - Matt Arnold
 */


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
    void run(GLUT_Plotter *g);
    Button getStartButton();
    Button getViewScores();
    bool operator !();
};

#endif
