/*******************************************************************************
* Author:  Brennan Saul                                                        *
* File Name:  Piece.h                                                          *
* Description:  Defines the Piece class. Includes prototypes of functions      *
*               and private fields.                                            *
* Date Created:  16 April 2014                                                 *
* Date Last Modified:  27 April 2014 - Cameron Wagstaff                        *
*******************************************************************************/

#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED

#include "Square.h"
#include "GLUT_Plotter.h"
#include <cstdlib>
#include <ctime>

using namespace std;

const Point PIECE_START           = Point((GAME_RIGHT - BORDER_WIDTH) / 2 - 5,
                                           SQUARE_WIDTH + BORDER_WIDTH * 2 + 1);

class Piece
{
    public:
             Piece();
             Piece(int);
             Piece(const Piece &other);
            ~Piece();
        Piece& operator =(const Piece& other);
        void rotateRight();
        void rotateLeft();
        void fall();
        void moveRight();
        void moveLeft();
        void draw(GLUT_Plotter *g);
        void erase(GLUT_Plotter *g);
        void setOrientation(int);
        void setColor();
        void setType(int newType);
        void setPosition(Point newCenter);
        void setRest(bool);
        int  getType();
        int  getOrientation();
        void moveUp();
        Square**& getSquares();
        bool getRest();

    private:
        //private fields
        int          orientation;
        unsigned int color;
        int          pieceType;
        Square**     squares;
        bool         rest;

        //private functions
        void iOrientation(int);
        void jOrientation(int);
        void sOrientation(int);
        void tOrientation(int);
        void lOrientation(int);
        void oOrientation(int);
        void zOrientation(int);
};


#endif // PIECE_H_INCLUDED
