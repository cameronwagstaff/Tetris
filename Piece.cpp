/******************************************************************************
Author:  Brennan Saul
File Name:  Piece.cpp
Description:  Implements the Piece class.
Date Created:  April 16, 2014
Date Last Modified:  April 19, 2014 - Created - Brennan Saul
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
    orientation = 0;
    rest = false;
    this->pieceType = pieceType;

    switch(pieceType)
    {

        case I:
            p2.x = MAX_ROWS / 2;
            p2.y = 1;

            iOrientation(orientation);
            //need to define colors in constants.h
            break;

        case J:

            p2.x = MAX_ROWS / 2;
            p2.y = 1;

            jOrientation(orientation);


            break;

        case S:
            p2.x = MAX_ROWS / 2;
            p2.y = 1;

            sOrientation(orientation);
            break;

        case T:
            p2.x = MAX_ROWS / 2;
            p2.y = 1;

            tOrientation(orientation);

            break;

        case L:
            p2.x = MAX_ROWS / 2;
            p2.y = 1;

            lOrientation(orientation);
            break;

        case O:
            p2.x = MAX_ROWS / 2;
            p2.y = 1;

            oOrientation(orientation);

            break;

        default:
            p2.x = MAX_ROWS / 2;
            p2.y = 1;

            zOrientation(orientation);

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
    if(orientation == 3)
    {
        orientation = 0;
    }
    else
    {
        orientation++;
    }
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
    if(orientation == 0)
    {
        orientation = 3;
    }
    else
    {
        orientation--;
    }
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
    if(!rest)
    {
        p1.y -= 1;
        p2.y -= 1;
        p3.y -= 1;
        p4.y -= 1;
    }
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
    //in orientaion file may want to always put p1 te the far right block and p4 to the far right block to test movability simply
    p1.x += 1;
    p2.x += 1;
    p3.x += 1;
    p4.x += 1;
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
    p1.x -= 1;
    p2.x -= 1;
    p3.x -= 1;
    p4.x -= 1;
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

void Piece::setOrientation(int newOrientation)
{
    switch(this->pieceType)
    {

        case I:
            iOrientation(newOrientation);
            break;

        case J:
            jOrientation(newOrientation);
            break;

        case S:
            sOrientation(newOrientation);
            break;

        case T:
            tOrientation(newOrientation);
            break;

        case L:
            lOrientation(newOrientation);
            break;

        case O:
            oOrientation(newOrientation);
            break;

        case Z:
            zOrientation(newOrientation);
            break;

        default:
          break;
    }
}

void Piece::iOrientation(int newOrientation)
{
    switch(newOrientation)
    {
        case 0:
            p1.x = p2.x;
            p1.y = p2.y - 1;

            p3.x = p2.x;
            p3.y = p2.y + 1;

            p4.x = p2.x;
            p4.y = p2.y + 2;

            break;

        case 1:
            p1.y = p2.y;
            p1.x = p2.x - 1;

            p3.y = p2.y;
            p3.x = p2.x + 1;

            p4.y = p2.y;
            p4.x = p2.x + 2;

            break;

        case 2:
            iOrientation(0);
            break;
        default:
            iOrientation(1);
    }
}

void Piece::jOrientation(int newOrientation)
{
    switch(newOrientation)
    {
        case 0:
            p1.x = p2.x - 1;
            p1.y = p2.y + 1;

            p3.x = p2.x;
            p3.y = p2.y + 1;

            p4.x = p2.x;
            p4.y = p2.y -1;

            break;

        case 1:
            p1.y = p2.y - 1;
            p1.x = p2.x - 1;

            p3.y = p2.y;
            p3.x = p2.x - 1;

            p4.y = p2.y;
            p4.x = p2.x + 1;

            break;

        case 2:
            p1.y = p2.y + 1;
            p1.x = p2.x;

            p3.y = p2.y - 1;
            p3.x = p2.x;

            p4.y = p2.y - 1;
            p4.x = p2.x + 1;

            break;
        default:
            p1.y = p2.y;
            p1.x = p2.x - 1;

            p3.y = p2.y;
            p3.x = p2.x + 1;

            p4.y = p2.y + 1;
            p4.x = p2.x + 1;
    }
}

void Piece::sOrientation(int newOrientation)
{
    switch(newOrientation)
    {
        case 0:
            p1.x = p2.x - 1;
            p1.y = p2.y;

            p3.x = p2.x;
            p3.y = p2.y - 1;

            p4.x = p2.x + 1;
            p4.y = p2.y -1;

            break;

        case 1:
            p1.y = p2.y - 1;
            p1.x = p2.x;

            p3.y = p2.y;
            p3.x = p2.x + 1;

            p4.y = p2.y - 1;
            p4.x = p2.x + 1;

            break;

        case 2:
            sOrientation(0);

            break;
        default:
            sOrientation(1);
    }
}

void Piece::tOrientation(int newOrientation)
{

}

void Piece::lOrientation(int newOrientation)
{
    switch(newOrientation)
    {
        case 0:
            p1.x = p2.x;
            p1.y = p2.y - 1;

            p3.x = p2.x;
            p3.y = p2.y + 1;

            p4.x = p2.x + 1;
            p4.y = p2.y + 1;

            break;

        case 1:
            p1.y = p2.y + 1;
            p1.x = p2.x - 1;

            p3.y = p2.y;
            p3.x = p2.x - 1;

            p4.y = p2.y;
            p4.x = p2.x + 1;

            break;

        case 2:
            p1.y = p2.y - 1;
            p1.x = p2.x - 1;

            p3.y = p2.y - 1;
            p3.x = p2.x;

            p4.y = p2.y + 1;
            p4.x = p2.x;

            break;
        default:
            p1.y = p2.y;
            p1.x = p2.x - 1;

            p3.y = p2.y;
            p3.x = p2.x + 1;

            p4.y = p2.y - 1;
            p4.x = p2.x + 1;
    }
}

void Piece::oOrientation(int newOrientation)
{

    p1.x = p2.x;
    p1.y = p2.y - 1;

    p3.x = p2.x + 1;
    p3.y = p2.y - 1;

    p4.x = p2.x + 1;
    p4.y = p2.y;

}

void Piece::zOrientation(int newOrientation)
{
    switch(newOrientation)
    {
        case 0:
            p1.x = p2.x - 1;
            p1.y = p2.y - 1;

            p3.x = p2.x;
            p3.y = p2.y - 1;

            p4.x = p2.x + 1;
            p4.y = p2.y;

            break;

        case 1:
            p1.y = p2.y + 1;
            p1.x = p2.x - 1;

            p3.y = p2.y;
            p3.x = p2.x - 1;

            p4.y = p2.y - 1;
            p4.x = p2.x;

            break;

        case 2:
            sOrientation(0);

            break;
        default:
            sOrientation(1);
    }
}


