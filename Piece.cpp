/******************************************************************************
Author:  Brennan Saul
File Name:  Piece.cpp
Description:  Implements the Piece class.
Date Created:  April 16, 2014
Date Last Modified:  April 16, 2014 - Created - Brennan Saul
Date Last Modified:  April 22, 2014 - Matt Arnold
Date LAst Modified:  April 24, 2014 - Brennan Saul
******************************************************************************/
#include "Piece.h"
#include "Square.h"

/******************************************************************************
Function name:  Piece()
Description:  The Piece class constructor.
Precondition:  None
Postcondition:  Object Created
Return value:  None
******************************************************************************/
Piece::Piece()
{
    pieceType = rand() % 6;

    for(int i = 0; i < 4; i++)
    {
        squares[i] = new Square;
    }

    squares[1]->setCenter(PIECE_START);

    setColor();

    setOrientation(0);

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
    // 0 is the default orientation for all Pieces
    orientation     = 0;
    rest            = false;
    this->pieceType = pieceType;

    //set value for point 2 which all other point are dependent on.
    //p2.x = MAX_ROWS / 2;
    //p2.y = 1;

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
    for(int i = 0; i < 4; i++)
    {
        delete squares[i];
    }
}

Piece::Piece(const Piece& other)
{
    *this = other;
}

Piece& Piece::operator=(const Piece &other)
{
    if(this != &other)
    {
        for(int i = 0; i < 4; i++)
        {
            delete squares[i];
            squares[i] = new Square(*(other.squares[i]));
        }

        this->pieceType = other.pieceType;
        this->orientation = other.orientation;
        this->color = other.color;
        this->rest = other.rest;

        setOrientation(orientation);
        setColor();
    }
    return *this;
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
        orientation += 1;
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
        orientation -= 1;
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
    //need to check for peices under and check if at the bottem

    bool canFall = true;

    for(int i = 0; i < 4; i++)
    {
        if(squares[i]->getCenter().y + (SQUARE_WIDTH) >= GAME_BOTTOM -
           BORDER_WIDTH - SQUARE_WIDTH / 2)
        {
            canFall = false;
            rest = true;
        }
    }

    if(canFall)
    {
        for(int i = 0; i < 4; i++)
        {
            squares[i]->fall();
        }
    }
}

/******************************************************************************
Function name:  moveRight()
Description:  This function moves the piece one spot over right.
Precondition:  Object must exist.
Postcondition:  Object point x values + 1
Return value:  None
******************************************************************************/
void Piece::moveRight()
{
    //point p1 is always farthest to the left and p4 is always farthest to the right
    //if(p4.x < MAX_COLS)
    //p1.x += 1;
    //p2.x += 1;
    //p3.x += 1;
    //p4.x += 1;

    for(int i = 0; i < 4; i++)
    {
        squares[i]->shiftRight();
    }
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
    //Wall not perfect but its a start!
    if(squares[0]->getCenter().x > MIN_COLS + SQUARE_WIDTH + SQUARE_BORDER)
    {
        for(int i = 0; i < 4; i++)
        {
            squares[i]->shiftLeft();
        }
   }
}

/******************************************************************************
Function name:  draw()
Description:
Precondition:  Object must exist.
Postcondition:  Object is not changed
Return value:  None
******************************************************************************/
void Piece::draw(GLUT_Plotter *g)
{
    for(int i = 0; i < 4; i++)
    {
        squares[i]->draw(g);
    }
}

void Piece::erase(GLUT_Plotter *g)
{
    for(int i = 0; i < 4; i++)
    {
        squares[i]->erase(g);
    }
}

/******************************************************************************
Function name:  setColor()
Description: Sets the piece's color dependent on t\piece type.
Precondition:  Object must exist.
Postcondition:  Object color added
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

    for(int i = 0; i < 4; i++)
    {
        squares[i]->setColor(color);
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
    orientation = newOrientation;

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
void Piece::iOrientation(int newOrientation)    //Flawless
{
    switch(newOrientation)
    {
        case 0:
            squares[0]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y - SQUARE_WIDTH));

            squares[2]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y + SQUARE_WIDTH));
            /*p3.x = p2.x;
            p3.y = p2.y + 1;*/

            squares[3]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y + 2 * SQUARE_WIDTH));

            /*p4.x = p2.x;
            p4.y = p2.y + 2;*/

            break;

        case 1:

            squares[0]->setCenter(Point(squares[1]->getCenter().x - SQUARE_WIDTH,
                                        squares[1]->getCenter().y));
            // p1.y = p2.y;
            //p1.x = p2.x - 1;

            squares[2]->setCenter(Point(squares[1]->getCenter().x + SQUARE_WIDTH,
                                        squares[1]->getCenter().y));
            //p3.y = p2.y;
            //p3.x = p2.x + 1;

            squares[3]->setCenter(Point(squares[1]->getCenter().x + 2 * SQUARE_WIDTH,
                                        squares[1]->getCenter().y));

            //p4.y = p2.y;
            //p4.x = p2.x + 2;

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
void Piece::jOrientation(int newOrientation)    //Flawless
{
    switch(newOrientation)
    {
        case 0:
            squares[0]->setCenter(Point(squares[1]->getCenter().x - SQUARE_WIDTH,
                                        squares[1]->getCenter().y + SQUARE_WIDTH));

            //p1.x = p2.x - 1;
            //p1.y = p2.y + 1;

            squares[0]->setCenter(Point(squares[1]->getCenter().x - SQUARE_WIDTH,
                                        squares[1]->getCenter().y + SQUARE_WIDTH));

            //p1.x = p2.x - 1;
            //p1.y = p2.y + 1;

            squares[2]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y + SQUARE_WIDTH));

            //p3.x = p2.x;
            //p3.y = p2.y + 1;

            squares[3]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y - SQUARE_WIDTH));

            //p4.x = p2.x;
            //p4.y = p2.y -1;

            break;

        case 1:
            squares[0]->setCenter(Point(squares[1]->getCenter().x - SQUARE_WIDTH,
                                        squares[1]->getCenter().y - SQUARE_WIDTH));

            //p1.y = p2.y - 1;
            //p1.x = p2.x - 1;

            squares[0]->setCenter(Point(squares[1]->getCenter().x - SQUARE_WIDTH,
                                        squares[1]->getCenter().y - SQUARE_WIDTH));

            //p1.y = p2.y - 1;
            //p1.x = p2.x - 1;

            squares[2]->setCenter(Point(squares[1]->getCenter().x - SQUARE_WIDTH,
                                        squares[1]->getCenter().y));

            //p3.y = p2.y;
            //p3.x = p2.x - 1;

            squares[3]->setCenter(Point(squares[1]->getCenter().x + SQUARE_WIDTH,
                                        squares[1]->getCenter().y));

            //p4.y = p2.y;
            //p4.x = p2.x + 1;

            break;

        case 2:
            squares[0]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y + SQUARE_WIDTH));

            //p1.y = p2.y + 1;
            //p1.x = p2.x;

            squares[0]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y + SQUARE_WIDTH));

            //p1.y = p2.y + 1;
            //p1.x = p2.x;

            squares[2]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y - SQUARE_WIDTH));

            //p3.y = p2.y - 1;
            //p3.x = p2.x;

            squares[3]->setCenter(Point(squares[1]->getCenter().x + SQUARE_WIDTH,
                                        squares[1]->getCenter().y - SQUARE_WIDTH));
            //p4.y = p2.y - 1;
            //p4.x = p2.x + 1;

            break;
        default:

            squares[0]->setCenter(Point(squares[1]->getCenter().x - SQUARE_WIDTH,
                                        squares[1]->getCenter().y));

            //p1.y = p2.y;
            //p1.x = p2.x - 1;

            squares[0]->setCenter(Point(squares[1]->getCenter().x - SQUARE_WIDTH,
                                        squares[1]->getCenter().y));

            //p1.y = p2.y;
            //p1.x = p2.x - 1;

            squares[2]->setCenter(Point(squares[1]->getCenter().x + SQUARE_WIDTH,
                                        squares[1]->getCenter().y));

            //p3.y = p2.y;
            //p3.x = p2.x + 1;

            squares[3]->setCenter(Point(squares[1]->getCenter().x + SQUARE_WIDTH,
                                        squares[1]->getCenter().y + SQUARE_WIDTH));

            //p4.y = p2.y + 1;
            //p4.x = p2.x + 1;
    }
}

/******************************************************************************
Function name:  sOrientation()
Description:  Orientation options for the S piece.
Precondition:  Object must exist.
Postcondition:  Orientation of object is changed.
Return value:  None
******************************************************************************/
void Piece::sOrientation(int newOrientation)    //Flawlessish
{
    switch(newOrientation)
    {
        case 0:

            squares[0]->setCenter(Point(squares[1]->getCenter().x - SQUARE_WIDTH,
                                        squares[1]->getCenter().y));

            //p1.x = p2.x - 1;
            //p1.y = p2.y;

            squares[0]->setCenter(Point(squares[1]->getCenter().x - SQUARE_WIDTH,
                                        squares[1]->getCenter().y));

            //p1.x = p2.x - 1;
            //p1.y = p2.y;

            squares[2]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y - SQUARE_WIDTH));

            //p3.x = p2.x;
            //p3.y = p2.y - 1;

            squares[3]->setCenter(Point(squares[1]->getCenter().x + SQUARE_WIDTH,
                                        squares[1]->getCenter().y - SQUARE_WIDTH));

            //p4.x = p2.x + 1;
            //p4.y = p2.y -1;

            break;

        case 1:

            squares[0]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y -
                                        SQUARE_WIDTH));

            //p1.y = p2.y - 1;
            //p1.x = p2.x;

            squares[0]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y -
                                        SQUARE_WIDTH));

            //p1.y = p2.y - 1;
            //p1.x = p2.x;

            squares[2]->setCenter(Point(squares[1]->getCenter().x + SQUARE_WIDTH,
                                        squares[1]->getCenter().y));

            //p3.y = p2.y;
            //p3.x = p2.x + 1;

            squares[3]->setCenter(Point(squares[1]->getCenter().x + SQUARE_WIDTH,
                                        squares[1]->getCenter().y + SQUARE_WIDTH));

            //p4.y = p2.y - 1;
            //p4.x = p2.x + 1;

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
void Piece::tOrientation(int newOrientation)    //Flawless
{
    switch(newOrientation)
    {
        case 0:

            squares[0]->setCenter(Point(squares[1]->getCenter().x - SQUARE_WIDTH,
                                        squares[1]->getCenter().y));

            //p1.x = p2.x - 1;
            //p1.y = p2.y;

            squares[0]->setCenter(Point(squares[1]->getCenter().x - SQUARE_WIDTH,
                                        squares[1]->getCenter().y));

            //p1.x = p2.x - 1;
            //p1.y = p2.y;

            squares[2]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y + SQUARE_WIDTH));

            //p3.x = p2.x;
            //p3.y = p2.y + 1;

            squares[3]->setCenter(Point(squares[1]->getCenter().x + SQUARE_WIDTH,
                                        squares[1]->getCenter().y));

            //p4.x = p2.x + 1;
            //p4.y = p2.y;

            break;

        case 1:
            squares[0]->setCenter(Point(squares[1]->getCenter().x - SQUARE_WIDTH,
                                        squares[1]->getCenter().y));

            //p1.y = p2.y;
            //p1.x = p2.x - 1;

            squares[0]->setCenter(Point(squares[1]->getCenter().x - SQUARE_WIDTH,
                                        squares[1]->getCenter().y));

            //p1.y = p2.y;
            //p1.x = p2.x - 1;

            squares[2]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y + SQUARE_WIDTH));

            //p3.y = p2.y + 1;
            //p3.x = p2.x;

            squares[3]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y - SQUARE_WIDTH));

            //p4.y = p2.y - 1;
            //p4.x = p2.x;

            break;

        case 2:
            squares[0]->setCenter(Point(squares[1]->getCenter().x - SQUARE_WIDTH,
                                        squares[1]->getCenter().y));

            //p1.y = p2.y;
            //p1.x = p2.x - 1;

            squares[0]->setCenter(Point(squares[1]->getCenter().x - SQUARE_WIDTH,
                                        squares[1]->getCenter().y));

            //p1.y = p2.y;
            //p1.x = p2.x - 1;

            squares[2]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y - SQUARE_WIDTH));

            //p3.y = p2.y + 1;
            //p3.x = p2.x;

            squares[3]->setCenter(Point(squares[1]->getCenter().x + SQUARE_WIDTH,
                                        squares[1]->getCenter().y));

            //p4.y = p2.y - 1;
            //p4.x = p2.x;

            break;
        default:

            squares[0]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y + SQUARE_WIDTH));

            //p1.y = p2.y - 1;
            //p1.x = p2.x;

            squares[0]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y + SQUARE_WIDTH));

            //p1.y = p2.y - 1;
            //p1.x = p2.x;

            squares[2]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y - SQUARE_WIDTH));

            //p3.y = p2.y - 1;
            //p3.x = p2.x;

            squares[3]->setCenter(Point(squares[1]->getCenter().x + SQUARE_WIDTH,
                                        squares[1]->getCenter().y ));

            //p4.y = p2.y;
            //p4.x = p2.x + 1;
    }
}

/******************************************************************************
Function name:  lOrientation()
Description:  Orientation options for the L piece.
Precondition:  Object must exist.
Postcondition:  Orientation of object is changed.
Return value:  None
******************************************************************************/
void Piece::lOrientation(int newOrientation)    //Flawless
{
    switch(newOrientation)
    {
        case 0:
            squares[0]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y - SQUARE_WIDTH));

            //p1.x = p2.x;
            //p1.y = p2.y - 1;

            squares[0]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y - SQUARE_WIDTH));

            //p1.x = p2.x;
            //p1.y = p2.y - 1;

            squares[2]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y + SQUARE_WIDTH));

            //p3.x = p2.x;
            //p3.y = p2.y + 1;

            squares[3]->setCenter(Point(squares[1]->getCenter().x + SQUARE_WIDTH,
                                        squares[1]->getCenter().y + SQUARE_WIDTH));

            //p4.x = p2.x + 1;
            //p4.y = p2.y + 1;

            break;

        case 1:
            squares[0]->setCenter(Point(squares[1]->getCenter().x - SQUARE_WIDTH,
                                        squares[1]->getCenter().y + SQUARE_WIDTH));

            //p1.y = p2.y + 1;
            //p1.x = p2.x - 1;

            squares[0]->setCenter(Point(squares[1]->getCenter().x - SQUARE_WIDTH,
                                        squares[1]->getCenter().y + SQUARE_WIDTH));

            //p1.y = p2.y + 1;
            //p1.x = p2.x - 1;

            squares[2]->setCenter(Point(squares[1]->getCenter().x - SQUARE_WIDTH,
                                        squares[1]->getCenter().y));

            //p3.y = p2.y;
            //p3.x = p2.x - 1;

            squares[3]->setCenter(Point(squares[1]->getCenter().x + SQUARE_WIDTH,
                                        squares[1]->getCenter().y));

            //p4.y = p2.y;
            //p4.x = p2.x + 1;

            break;

        case 2:
            squares[0]->setCenter(Point(squares[1]->getCenter().x - SQUARE_WIDTH,
                                        squares[1]->getCenter().y - SQUARE_WIDTH));

            //p1.y = p2.y - 1;
            //p1.x = p2.x - 1;

            squares[0]->setCenter(Point(squares[1]->getCenter().x - SQUARE_WIDTH,
                                        squares[1]->getCenter().y - SQUARE_WIDTH));

            //p1.y = p2.y - 1;
            //p1.x = p2.x - 1;

            squares[2]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y - SQUARE_WIDTH));

            //p3.y = p2.y - 1;
            //p3.x = p2.x;

            squares[3]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y + SQUARE_WIDTH));

            //p4.y = p2.y + 1;
            //p4.x = p2.x;

            break;
        default:
            squares[0]->setCenter(Point(squares[1]->getCenter().x - SQUARE_WIDTH,
                                        squares[1]->getCenter().y));
            //p1.y = p2.y;
            //p1.x = p2.x - 1;

            squares[2]->setCenter(Point(squares[1]->getCenter().x + SQUARE_WIDTH,
                                        squares[1]->getCenter().y));

            //p3.y = p2.y;
            //p3.x = p2.x + 1;

            squares[3]->setCenter(Point(squares[1]->getCenter().x + SQUARE_WIDTH,
                                        squares[1]->getCenter().y - SQUARE_WIDTH));

            //p4.y = p2.y - 1;
            //p4.x = p2.x + 1;
    }
}

/******************************************************************************
Function name:  oOrientation()
Description:  Orientation options for the O piece.
Precondition:  Object must exist.
Postcondition:  Orientation of object is changed.
Return value:  None
******************************************************************************/
void Piece::oOrientation(int newOrientation)    //Flawless
{
    squares[0]->setCenter(Point(squares[1]->getCenter().x,
                                squares[1]->getCenter().y - SQUARE_WIDTH));
    //p1.x = p2.x;
    //p1.y = p2.y - 1;

    squares[2]->setCenter(Point(squares[1]->getCenter().x + SQUARE_WIDTH,
                                squares[1]->getCenter().y - SQUARE_WIDTH));

    //p3.x = p2.x + 1;
    //p3.y = p2.y - 1;

    squares[3]->setCenter(Point(squares[1]->getCenter().x + SQUARE_WIDTH,
                                squares[1]->getCenter().y));

    //p4.x = p2.x + 1;
    //p4.y = p2.y;*/

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
            squares[0]->setCenter(Point(squares[1]->getCenter().x - SQUARE_WIDTH,
                                        squares[1]->getCenter().y - SQUARE_WIDTH));
            //p1.x = p2.x - 1;
            //p1.y = p2.y - 1;

            squares[2]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y - SQUARE_WIDTH));

            //p3.x = p2.x;
            //p3.y = p2.y - 1;

            squares[3]->setCenter(Point(squares[1]->getCenter().x + SQUARE_WIDTH,
                                        squares[1]->getCenter().y));

            //p4.x = p2.x + 1;
            //p4.y = p2.y;

            break;

        case 1:

            squares[0]->setCenter(Point(squares[1]->getCenter().x - SQUARE_WIDTH,
                                        squares[1]->getCenter().y + SQUARE_WIDTH));

            //p1.y = p2.y + 1;
            //p1.x = p2.x - 1;

            squares[0]->setCenter(Point(squares[1]->getCenter().x - SQUARE_WIDTH,
                                        squares[1]->getCenter().y + SQUARE_WIDTH));

            //p1.y = p2.y + 1;
            //p1.x = p2.x - 1;

            squares[2]->setCenter(Point(squares[1]->getCenter().x - SQUARE_WIDTH,
                                        squares[1]->getCenter().y));

            //p3.y = p2.y;
            //p3.x = p2.x - 1;

            squares[3]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y - SQUARE_WIDTH));

            //p4.y = p2.y - 1;
            //p4.x = p2.x;

            break;

        case 2:
            zOrientation(0);

            break;
        default:
            zOrientation(1);
    }
}

void Piece::setType(int newType)
{
    pieceType = newType;
    setOrientation(0);
}

void Piece::setPosition(Point newCenter)
{
    squares[1]->setCenter(newCenter);
    setOrientation(orientation);
}

int  Piece::getType()
{
    return pieceType;
}

int Piece::getOrientation()
{
    return orientation;
}

void Piece::moveUp()
{
    for(int i = 0; i < 4; i++)
    {
        squares[i]->moveUp();
    }
}


