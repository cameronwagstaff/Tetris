/******************************************************************************
Author:  Brennan Saul
File Name:  Piece.h
Description:  Defines the Piece class. Includes prototypes of functions
              and private fields.
Date Created:  April 16, 2014
Date Last Modified:  April 22, 2014 - Matt Arnold
******************************************************************************/

#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED

#include "Square.h"
#include "GLUT_Plotter.h"

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
        int  getType();
        int  getOrientation();

    private:
        //private fields
        int          orientation;
        unsigned int color;
        int          pieceType;
        Square*      squares[4];
        bool         rest;

        //private functions
        void iOrientation(int);
        void jOrientation(int);
        void sOrientation(int);
        void tOrientation(int);
        void lOrientation(int);
        void oOrientation(int);
        void zOrientation(int);
        void moveUp();

};


#endif // PIECE_H_INCLUDED
