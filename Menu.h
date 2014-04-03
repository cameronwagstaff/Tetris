/*
 * Author: Matt Arnold
 * Assignment Title:
 * Assignment Description:
 * Due Date:
 * Date Created: 01 April 2014
 * Date Last Modified: 02 April 2014 - Matt Arnold
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
    
public:
    Menu();
    void draw(GLUT_Plotter *g);
    void erase(GLUT_Plotter *g);
};

#endif
