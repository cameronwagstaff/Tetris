/*******************************************************************************
 * Author: Dr. Booth, Matt Arnold                                              *
 * Description: Tetris game class header                                       *
 * Created on: Mar 28, 2014                                                    *
 * Last Modified: 29 April 2014 - Matt Arnold                                  *
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
#include "InputBox.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>

using namespace std;

class Tetris
{
private:
    GLUT_Plotter *g;
    Menu m;
    ScoreTable scores;
    Matrix matrix;
    Piece current,  next;
    stdRect::Rectangle nextBox;
    InputBox enterName;
    bool end;
    int currentScore;
    int rowsCleared;
    int consecRC;

public:
    //constructor
    Tetris(GLUT_Plotter* g);

    //Main GAIM FUNCTION
    void Play(void);
    void drawGame();
    void drawNextBox();
    void drawScore();
    double fallSpeed();

    //Input guards
    void tryMoveDown(Piece&, Matrix&);
    void tryRotateRight(Piece&, Matrix&);
    void tryRotateLeft(Piece&, Matrix&);
    void tryMoveLeft(Piece&, Matrix&);
    void tryMoveRight(Piece&, Matrix&);
};

#endif /* TETRIS_H_ */
