/*******************************************************************************
 * Author: Dr. Booth, Matt Arnold                                              *
 * Description: Tetris game class header                                       *
 * Created on: Mar 28, 2014                                                    *
 * Last Modified: 23 April 2014 by Matt Arnold                                 *
 ******************************************************************************/

#ifndef TETRIS_H_
#define TETRIS_H_
#include "GLUT_Plotter.h"
#include "Text.h"
#include "Menu.h"
#include "Matrix.h"
#include "ScoreTable.h"
#include "Square.h"
#include "Constants.h"
#include "Piece.h"
#include "Rectangle.h"
#include <cstdlib>
#include <ctime>

using namespace std;


class Tetris
{
private:
    GLUT_Plotter *g;
    Menu m;
    ScoreTable scores;
    Matrix matrix;
    Piece current,  next;
    Rectangle nextBox;

public:
    //constructor
    Tetris(GLUT_Plotter* g);

    //Main GAIM FUNCTION
    void Play(void);
    void drawGame();
    void drawNextBox();
};

#endif /* TETRIS_H_ */
