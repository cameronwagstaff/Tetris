/******************************************************************************
Author:  Brennan Saul
File Name:  Piece.h
Description:  Defines the Piece class. Includes prototypes of functions
              and private fields.
Date Created:  April 16, 2014
Date Last Modified:  April 23, 2014 - Cameron Wagstaff
******************************************************************************/

#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED

#include "Square.h"
#include "GLUT_Plotter.h"
#include <cstdlib>
#include <ctime>

using namespace std;

const Point PIECE_START             = Point((GAME_RIGHT - BORDER_WIDTH) / 2,
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
<<<<<<< HEAD
        void draw();
<<<<<<< HEAD
=======
=======
>>>>>>> 73b5a12792a91007b2ddc752109a08b2651599df
        void draw(GLUT_Plotter *g);
        void erase(GLUT_Plotter *g);
        void setOrientation(int);
>>>>>>> 5e853c804c482acf6d8882c0b8dc7a096f368259
        void setColor();
        void setType(int newType);
        void setPosition(Point newCenter);
        int  getType();
        int  getOrientation();
        void moveUp();

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
<<<<<<< HEAD
        //moved setOrientation in to the private function becuase it is only
        //used within functions such as constructors and turns
        //void setOrientation(int);
=======
<<<<<<< HEAD
        //moved setOrientation in to the private function becuase it is only
        //used within functions such as constructors and turns
        void setOrientation(int);

=======
>>>>>>> 5e853c804c482acf6d8882c0b8dc7a096f368259
>>>>>>> 73b5a12792a91007b2ddc752109a08b2651599df
};


#endif // PIECE_H_INCLUDED
