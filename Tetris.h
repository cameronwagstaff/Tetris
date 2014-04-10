/*
 * Tetris.h - Tetris game class header
 *
 *  Created on: Mar 28, 2014
 *  Created on: Mar 28, 2014
 *      Author: Dr. Booth
 *
 *  Last Modified: 07 April 2014 - Matt Arnold
 */

#ifndef TETRIS_H_
#define TETRIS_H_
#include "GLUT_Plotter.h"
#include "Menu.h"
#include "ScoreTable.h"
#include "Constants.h"


class Tetris
{
private:
    GLUT_Plotter *g;
    Menu m;
    ScoreTable scores;
    
public:
    //constructor
    Tetris(GLUT_Plotter* g);
    
    //Main GAIM FUNCTION
    void Play(void);
    void drawGame();
};

#endif /* TETRIS_H_ */
