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
    pieceType = I;
    Point p1, p2, p3, p4;
    rest = false;
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

    //set value for point 2
    p2.x = MAX_ROWS / 2;
    p2.y = 1;

    //set value and orientation for all ofther points
    setOrientation(orientation);
    setColor();
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

    setOrientation(orientation);
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
    setOrientation(orientation);
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

/******************************************************************************
Function name:  setColor()
Description:
Precondition:  Object must exist.
Postcondition:  Object is not changed
Return value:  None
******************************************************************************/
void Piece::setColor()
{
    switch(pieceType)
    {

        case I:
            color = CYAN;
            break;

        case J:
            color = BLUE;
            break;

        case S:
            color = GREEN;
            break;

        case T:
            color = PURPLE;
            break;

        case L:
            color = ORANGE;
            break;

        case O:
            color = YELLOW;
            break;

        default:
            color = RED;
    }
}
/******************************************************************************
Function name:  setOrientation()
Description:  Sets correct orientation depending upon which pieceType.
Precondition:  Object must exist.
Postcondition:  Orientation of object is changed.
Return value:  None
******************************************************************************/
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

/******************************************************************************
Function name:  iOrientation()
Description:  Orientation options for the I piece.
Precondition:  Object must exist.
Postcondition:  Orientation of object is changed.
Return value:  None
******************************************************************************/
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

/******************************************************************************
Function name:  jOrientation()
Description:  Orientation options for the J piece.
Precondition:  Object must exist.
Postcondition:  Orientation of object is changed.
Return value:  None
******************************************************************************/
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

/******************************************************************************
Function name:  sOrientation()
Description:  Orientation options for the S piece.
Precondition:  Object must exist.
Postcondition:  Orientation of object is changed.
Return value:  None
******************************************************************************/
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

/******************************************************************************
Function name:  tOrientation()
Description:  Orientation options for the T piece.
Precondition:  Object must exist.
Postcondition:  Orientation of object is changed.
Return value:  None
******************************************************************************/
void Piece::tOrientation(int newOrientation)
{
    switch(newOrientation)
    {
        case 0:
            p1.x = p2.x - 1;
            p1.y = p2.y;

            p3.x = p2.x;
            p3.y = p2.y + 1;

            p4.x = p2.x + 1;
            p4.y = p2.y;

            break;

        case 1:
            p1.y = p2.y;
            p1.x = p2.x - 1;

            p3.y = p2.y + 1;
            p3.x = p2.x;

            p4.y = p2.y - 1;
            p4.x = p2.x;

            break;

        case 2:
            p1.y = p2.y;
            p1.x = p2.x - 1;

            p3.y = p2.y + 1;
            p3.x = p2.x;

            p4.y = p2.y - 1;
            p4.x = p2.x;

            break;
        default:
            p1.y = p2.y - 1;
            p1.x = p2.x;

            p3.y = p2.y - 1;
            p3.x = p2.x;

            p4.y = p2.y;
            p4.x = p2.x + 1;
    }
}

/******************************************************************************
Function name:  lOrientation()
Description:  Orientation options for the L piece.
Precondition:  Object must exist.
Postcondition:  Orientation of object is changed.
Return value:  None
******************************************************************************/
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

/******************************************************************************
Function name:  oOrientation()
Description:  Orientation options for the O piece.
Precondition:  Object must exist.
Postcondition:  Orientation of object is changed.
Return value:  None
******************************************************************************/
void Piece::oOrientation(int newOrientation)
{

    p1.x = p2.x;
    p1.y = p2.y - 1;

    p3.x = p2.x + 1;
    p3.y = p2.y - 1;

    p4.x = p2.x + 1;
    p4.y = p2.y;

}

/******************************************************************************
Function name:  zOrientation()
Description:  Orientation options for the Z piece.
Precondition:  Object must exist.
Postcondition:  Orientation of object is changed.
Return value:  None
******************************************************************************/
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


