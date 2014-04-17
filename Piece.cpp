/******************************************************************************
Author:  Brennan Saul
File Name:  Piece.cpp
Description:  Implements the Piece class.
Date Created:  April 16, 2014
Date Last Modified:  April 16, 2014 - Created - Brennan Saul
******************************************************************************/

#include "Piece.h"

/******************************************************************************
Function name:  Piece()
Description:  The Piece class constructor.
Precondition:  None
Postcondition:  Object Created
Return value:  None
******************************************************************************/
Piece::Piece()
{
    color;
    pieceType;
    Point p1, p2, p3, p4;
    rest;
}

/******************************************************************************
Function name:  Piece(int pieceType)
Description:  The Piece class constructor.
Precondition:  None
Postcondition:  Object Created
Return value:  None
******************************************************************************/
Piece::Piece(int pieceType)
{
    this->pieceType = pieceType;

    switch(pieceType)
    {
        case I:
            p1.x = SCREEN_WIDTH / 2;
            p1.y = 0;

            p2.x = SCREEN_WIDTH / 2;
            p2.y = 1;

            p3.x = SCREEN_WIDTH / 2;
            p3.y = 2;

            p4.x = SCREEN_WIDTH / 2;
            p4.y = 3;

            //need to define colors in constants.h
            break;

        case J:
            p1.x = MAX_ROWS / 2;
            p1.y = 0;

            p2.x = MAX_ROWS / 2;
            p2.y = 1;

            p3.x = MAX_ROWS / 2;
            p3.y = 2;

            p4.x = (MAX_ROWS / 2) - 1;
            p4.y = 3;

            break;

        case S:
            break;

        case T:
            break;

        case L:
            break;

        case O:
            break;

        case Z:
            break;

        default:
          break;
    }
}
/******************************************************************************
Function name:  ~Piece()
Description:  Peice destructor
Precondition:  Object must exist.
Postcondition:  Object deleted.
Return value:  None
******************************************************************************/
Piece::~Piece()
{

}

/******************************************************************************
Function name:  rotateRight()
Description:  Rotates the object 90 degrees to the right.
Precondition:  Object must exist.
Postcondition:  Object rotated 90 degrees.
Return value:  None
******************************************************************************/
void Piece::rotateRight()
{

}

/******************************************************************************
Function name:  rotateLeft()
Description:  Rotates the object 90 degrees to the Left
Precondition:  Object must exist.
Postcondition:  object rotated 90 degrees
Return value:  None
******************************************************************************/
void Piece::rotateLeft()
{

}

/******************************************************************************
Function name:  fall()
Description:  Object falls one space if rest == false
Precondition:  Object must exist.
Postcondition:  object's points y values - 1
Return value:  None
******************************************************************************/
void Piece::fall()
{

}

/******************************************************************************
Function name:  moveRight()
Description:This function moves the piece one spot over right.
Precondition:  Object must exist.
Postcondition:  Object point x values + 1
Return value:  None
******************************************************************************/
void Piece::moveRight()
{

}

/******************************************************************************
Function name:  moveLeft()
Description:  This function moves the piece one spot over left.
Precondition:  Object must exist.
Postcondition:  Points x - 1
Return value:  None
******************************************************************************/
void Piece::moveLeft()
{

}

/******************************************************************************
Function name:  draw()
Description:
Precondition:  Object must exist.
Postcondition:  Object is not changed
Return value:  None
******************************************************************************/
void Piece::draw()
{

}



