/*
 * Author: Matt Arnold
 * Assignment Title:
 * Assignment Description:
 * Due Date:
 * Date Created: 01 April 2014
<<<<<<< HEAD
 * Date Last Modified: 08 April 2014 - Matt Arnold
=======
 * Date Last Modified: 02 April 2014 - Matt Arnold
>>>>>>> FETCH_HEAD
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
<<<<<<< HEAD
    bool running;
    
=======

>>>>>>> FETCH_HEAD
public:
    Menu();
    void draw(GLUT_Plotter *g);
    void erase(GLUT_Plotter *g);
<<<<<<< HEAD
    void run(GLUT_Plotter *g);
    Button getStartButton();
    Button getViewScores();
    bool operator !();
=======
>>>>>>> FETCH_HEAD
};

#endif
