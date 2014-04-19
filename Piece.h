/******************************************************************************
Author:  Brennan Saul
File Name:  Piece.h
Description:  Defines the Piece class. Includes prototypes of functions
              and private fields.
Date Created:  April 16, 2014
Date Last Modified:  April 19, 2014 - Created - Brennan Saul
******************************************************************************/

#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED

#include "Point.h"


class Piece
{
    public:
             Piece();
             Piece(int);
            ~Piece();
        void rotateRight();
        void rotateLeft();
        void fall();
        void moveRight();
        void moveLeft();
        void draw();
        void setOrientation(int);
        void setColor();

    private:

        //private fields
        int          orientation;
        unsigned int color;
        int          pieceType;
        Point        p1, p2, p3, p4;
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
