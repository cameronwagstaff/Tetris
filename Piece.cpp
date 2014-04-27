/*******************************************************************************
 * Author:  Brennan Saul                                                       *
 * File Name:  Piece.cpp                                                       *
 * Description:  Implements the Piece class.                                   *
 * Date Created:  16 April 2014                                                *
 * Date Last Modified:  April 22, 2014 - Matt Arnold                           *
 ******************************************************************************/

#include "Piece.h"

/*******************************************************************************
 * Description:  The Piece class constructor.                                  *
 * Precondition:  None                                                         *
 * Postcondition:  Object Created                                              *
 * Return value:  None                                                         *
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

/*******************************************************************************
 * Description:  The Piece class constructor.                                  *
 * Precondition:  None                                                         *
 * Postcondition:  Object Created                                              *
 * Return value:  None                                                         *
 ******************************************************************************/
Piece::Piece(int pieceType)
{
    orientation = 0;
    rest = false;
    this->pieceType = pieceType;

    //set value for point 2
    //p2.x = MAX_ROWS / 2;
    //p2.y = 1;

    //set value and orientation for all ofther points
    setOrientation(orientation);
    setColor();
}
/*******************************************************************************
 * Description:  Peice destructor                                              *
 * Precondition:  Object must exist.                                           *
 * Postcondition:  Object deleted.                                             *
 * Return value:  None                                                         *
 ******************************************************************************/
Piece::~Piece()
{
    for(int i = 0; i < 4; i++)
    {
        delete squares[i];
    }
}

/*******************************************************************************
 * Description: Copy constructor                                               *
 * Return: nothing                                                             *
 * Pre: other is a valid instance of the Piece class                           *
 * Post: object constructed as copy of other                                   *
 ******************************************************************************/
Piece::Piece(const Piece& other)
{
    *this = other;
}

/*******************************************************************************
 * Description: overloaded assignment operator                                 *
 * Return: a reference to self                                                 *
 * Pre: object exists, other is valid instance of the Piece class              *
 * Post: object becomes an exact copy of other                                 *
 ******************************************************************************/
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

/*******************************************************************************
 * Description:  Rotates the object 90 degrees to the right.                   *
 * Precondition:  Object must exist.                                           *
 * Postcondition:  Object rotated 90 degrees.                                  *
 * Return value:  void                                                         *
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
    for(int i = 0; i < 4; i++)
    {
        if(squares[i]->getCenter().y + (SQUARE_WIDTH) >= GAME_BOTTOM -
           BORDER_WIDTH - SQUARE_WIDTH / 2)
        {
            rest = true;
        }
    }
    
    if(!rest)
    {
        for(int i = 0; i < 4; i++)
        {
            squares[i]->fall();
        }
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
<<<<<<< HEAD
    //Wall not perfect but its a start!
    if(squares[0]->getCenter().x > MIN_COLS + SQUARE_WIDTH + SQUARE_BORDER)
=======
    for(int i = 0; i < 4; i++)
>>>>>>> 46b7923adab16f6a1a9a85fe81f09883cddc853a
    {
        squares[i]->shiftLeft();
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
void Piece::iOrientation(int newOrientation)
{
    switch(newOrientation)
    {
        case 0:
            squares[0]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y
                                        - SQUARE_WIDTH));
            
            squares[2]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y
                                        + SQUARE_WIDTH));

            squares[3]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y
                                        + 2 * SQUARE_WIDTH));

            break;

        case 1:
            
            squares[0]->setCenter(Point(squares[1]->getCenter().x
                                        - SQUARE_WIDTH,
                                        squares[1]->getCenter().y));
            
            squares[2]->setCenter(Point(squares[1]->getCenter().x
                                        + SQUARE_WIDTH,
                                        squares[1]->getCenter().y));
            
            squares[3]->setCenter(Point(squares[1]->getCenter().x + 2
                                        * SQUARE_WIDTH,
                                        squares[1]->getCenter().y));

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
            
            squares[0]->setCenter(Point(squares[1]->getCenter().x
                                        - SQUARE_WIDTH,
                                        squares[1]->getCenter().y
                                        + SQUARE_WIDTH));
            
            squares[2]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y
                                        + SQUARE_WIDTH));

            squares[3]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y
                                        - SQUARE_WIDTH));

            break;

        case 1:
            
            squares[0]->setCenter(Point(squares[1]->getCenter().x
                                        - SQUARE_WIDTH,
                                        squares[1]->getCenter().y
                                        - SQUARE_WIDTH));
            
            squares[2]->setCenter(Point(squares[1]->getCenter().x
                                        - SQUARE_WIDTH,
                                        squares[1]->getCenter().y));

            squares[3]->setCenter(Point(squares[1]->getCenter().x
                                        + SQUARE_WIDTH,
                                        squares[1]->getCenter().y));

            break;

        case 2:
            
            squares[0]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y
                                        + SQUARE_WIDTH));
            
            squares[2]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y
                                        - SQUARE_WIDTH));

            squares[3]->setCenter(Point(squares[1]->getCenter().x
                                        + SQUARE_WIDTH,
                                        squares[1]->getCenter().y
                                        - SQUARE_WIDTH));
            break;
            
        default:
            
            squares[0]->setCenter(Point(squares[1]->getCenter().x
                                        - SQUARE_WIDTH,
                                        squares[1]->getCenter().y));
            
            squares[2]->setCenter(Point(squares[1]->getCenter().x
                                        + SQUARE_WIDTH,
                                        squares[1]->getCenter().y));

            squares[3]->setCenter(Point(squares[1]->getCenter().x
                                        + SQUARE_WIDTH,
                                        squares[1]->getCenter().y
                                        + SQUARE_WIDTH));

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
            
            squares[0]->setCenter(Point(squares[1]->getCenter().x
                                        - SQUARE_WIDTH,
                                        squares[1]->getCenter().y));
            
            squares[2]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y
                                        - SQUARE_WIDTH));

            squares[3]->setCenter(Point(squares[1]->getCenter().x
                                        + SQUARE_WIDTH,
                                        squares[1]->getCenter().y
                                        - SQUARE_WIDTH));

            break;

        case 1:
            
            squares[0]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y -
                                        SQUARE_WIDTH));
            
            squares[2]->setCenter(Point(squares[1]->getCenter().x
                                        + SQUARE_WIDTH,
                                        squares[1]->getCenter().y));

            squares[3]->setCenter(Point(squares[1]->getCenter().x
                                        + SQUARE_WIDTH,
                                        squares[1]->getCenter().y
                                        + SQUARE_WIDTH));

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
            
            squares[0]->setCenter(Point(squares[1]->getCenter().x
                                        - SQUARE_WIDTH,
                                        squares[1]->getCenter().y));
            
            squares[2]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y
                                        + SQUARE_WIDTH));

            squares[3]->setCenter(Point(squares[1]->getCenter().x
                                        + SQUARE_WIDTH,
                                        squares[1]->getCenter().y));

            break;

        case 1:
            
            squares[0]->setCenter(Point(squares[1]->getCenter().x
                                        - SQUARE_WIDTH,
                                        squares[1]->getCenter().y));
            
            squares[2]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y
                                        + SQUARE_WIDTH));

            squares[3]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y
                                        - SQUARE_WIDTH));

            break;

        case 2:
            
            squares[0]->setCenter(Point(squares[1]->getCenter().x
                                        - SQUARE_WIDTH,
                                        squares[1]->getCenter().y));
            
            squares[2]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y
                                        - SQUARE_WIDTH));

            squares[3]->setCenter(Point(squares[1]->getCenter().x
                                        + SQUARE_WIDTH,
                                        squares[1]->getCenter().y));

            break;
            
        default:
            
            squares[0]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y
                                        + SQUARE_WIDTH));
            
            squares[2]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y
                                        - SQUARE_WIDTH));
            
            squares[3]->setCenter(Point(squares[1]->getCenter().x
                                        + SQUARE_WIDTH,
                                        squares[1]->getCenter().y ));
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
            
            squares[0]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y
                                        - SQUARE_WIDTH));
            
            squares[2]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y
                                        + SQUARE_WIDTH));
            
            squares[3]->setCenter(Point(squares[1]->getCenter().x
                                        + SQUARE_WIDTH,
                                        squares[1]->getCenter().y
                                        + SQUARE_WIDTH));

            break;

        case 1:
            
            squares[0]->setCenter(Point(squares[1]->getCenter().x
                                        - SQUARE_WIDTH,
                                        squares[1]->getCenter().y
                                        + SQUARE_WIDTH));
            
            squares[2]->setCenter(Point(squares[1]->getCenter().x
                                        - SQUARE_WIDTH,
                                        squares[1]->getCenter().y));

            squares[3]->setCenter(Point(squares[1]->getCenter().x
                                        + SQUARE_WIDTH,
                                        squares[1]->getCenter().y));
            
            break;

        case 2:
            
            squares[0]->setCenter(Point(squares[1]->getCenter().x
                                        - SQUARE_WIDTH,
                                        squares[1]->getCenter().y
                                        - SQUARE_WIDTH));
            
            squares[2]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y
                                        - SQUARE_WIDTH));
            
            squares[3]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y
                                        + SQUARE_WIDTH));

            break;
            
        default:
            squares[0]->setCenter(Point(squares[1]->getCenter().x
                                        - SQUARE_WIDTH,
                                        squares[1]->getCenter().y));
            
            squares[2]->setCenter(Point(squares[1]->getCenter().x
                                        + SQUARE_WIDTH,
                                        squares[1]->getCenter().y));
            
            squares[3]->setCenter(Point(squares[1]->getCenter().x
                                        + SQUARE_WIDTH,
                                        squares[1]->getCenter().y
                                        - SQUARE_WIDTH));
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
    squares[0]->setCenter(Point(squares[1]->getCenter().x,
                                squares[1]->getCenter().y - SQUARE_WIDTH));
    
    squares[2]->setCenter(Point(squares[1]->getCenter().x + SQUARE_WIDTH,
                                squares[1]->getCenter().y - SQUARE_WIDTH));
    
    squares[3]->setCenter(Point(squares[1]->getCenter().x + SQUARE_WIDTH,
                                squares[1]->getCenter().y));

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
            squares[0]->setCenter(Point(squares[1]->getCenter().x
                                        - SQUARE_WIDTH,
                                        squares[1]->getCenter().y
                                        - SQUARE_WIDTH));
            
            squares[2]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y
                                        - SQUARE_WIDTH));
            
            squares[3]->setCenter(Point(squares[1]->getCenter().x
                                        + SQUARE_WIDTH,
                                        squares[1]->getCenter().y));

            break;

        case 1:
            
            squares[0]->setCenter(Point(squares[1]->getCenter().x
                                        - SQUARE_WIDTH,
                                        squares[1]->getCenter().y
                                        + SQUARE_WIDTH));
            
            squares[2]->setCenter(Point(squares[1]->getCenter().x
                                        - SQUARE_WIDTH,
                                        squares[1]->getCenter().y));
            
            squares[3]->setCenter(Point(squares[1]->getCenter().x,
                                        squares[1]->getCenter().y
                                        - SQUARE_WIDTH));
            break;

        case 2:
            zOrientation(0);

            break;
        default:
            zOrientation(1);
    }
}

/*******************************************************************************
 * Description: setter for pieceType                                           *
 * Return: void                                                                *
 * Pre: object exists                                                          *
 * Post: piceType assigned a new value newType, object's orientation set to 0  *
 ******************************************************************************/
void Piece::setType(int newType)
{
    pieceType = newType;
    setOrientation(0);
}

/*******************************************************************************
 * Description: sets the center Point of the Square at squares[1]              *
 * Return: void                                                                *
 * Pre: object exists                                                          *
 * Post: squares[i]->center is assigned a value newCenter, orientation         *
 *       altered to match the new position                                     *
 ******************************************************************************/
void Piece::setPosition(Point newCenter)
{
    squares[1]->setCenter(newCenter);
    setOrientation(orientation);
}

/*******************************************************************************
 * Description: getter for pieceType                                           *
 * Return: an integer value representing the type of pice the object is        *
 * Pre: object exists                                                          *
 * Post: object unchanged                                                      *
 ******************************************************************************/
int  Piece::getType()
{
    return pieceType;
}

/*******************************************************************************
 * Description: getter for orientation                                         *
 * Return: an integer value representing the object's orientation              *
 * Pre: object exists                                                          *
 * Post: object unchanged                                                      *
 ******************************************************************************/
int Piece::getOrientation()
{
    return orientation;
}

/*******************************************************************************
 * Description: moves a Piece up a distance FALL_LENGTH                        *
 * Return: void                                                                *
 * Pre: object exists                                                          *
 * Post: object shifted up                                                     *
 ******************************************************************************/
void Piece::moveUp()
{
    for(int i = 0; i < 4; i++)
    {
        squares[i]->moveUp();
    }
}


