/*******************************************************************************
 * Author: Matt Arnold                                                         *
 * Description: Implementation for the Square class                            *
 * Date Created: 22 April 2014                                                 *
 * Date Last Modified: 23 April 2014 - Matt Arnold                             *
 ******************************************************************************/

#include "Square.h"

/*******************************************************************************
 * Description: constructor for the Square class                               *
 * Return: nothing                                                             *
 * Pre: none                                                                   *
 * Post: object constructed with color color and center at Point center        *
 ******************************************************************************/
Square::Square(Point center, unsigned int color)
: Shape(color)
{
    this->center = center;
}

/*******************************************************************************
 * Description: copy constructor for Square class                              *
 * Return: nothing                                                             *
 * Pre: other is valid Square object                                           *
 * Post: object constructed as copy of other                                   *
 ******************************************************************************/
Square::Square(const Square & other)
{
    *this = other;
}

/*******************************************************************************
 * Description: overloaded assignment operator                                 *
 * Return: a reference to this                                                 *
 * Pre: object exists, other exists                                            *
 * Post: *this becomes a copy of other                                         *
 ******************************************************************************/
Square& Square::operator= (const Square &other)
{
    if(this != &other)
    {
        setColor(other.color);
        center = other.center;
    }

    return *this;
}

/*******************************************************************************
 * Description: Draws a Square object to the screen                            *
 * Return: void                                                                *
 * Pre: object exists                                                          *
 * Post: Square drawn on screen. Object unchanged                              *
 ******************************************************************************/
void Square::draw(GLUT_Plotter *g)
{
    try
    {
        //Draw border
        g->setColor(BLACK);

        Point topLeft(center.x - (SQUARE_WIDTH / 2), center.y +
                                                     (SQUARE_WIDTH / 2));

        for(int i = topLeft.x; i < topLeft.x + SQUARE_WIDTH; i++)
        {
            for(int j = topLeft.y; j < topLeft.y + SQUARE_WIDTH; j++)
            {
                g->plot(i, SCREEN_HEIGHT - j);
            }
        }

        //Draw Square
        g->setColor(this->color);

        for(int i = topLeft.x + SQUARE_BORDER; i < topLeft.x + SQUARE_WIDTH
                                                        - SQUARE_BORDER; i++)
        {
            for(int j = topLeft.y + SQUARE_BORDER; j < topLeft.y + SQUARE_WIDTH
                                                        - SQUARE_BORDER; j++)
            {
                g->plot(i, SCREEN_HEIGHT - j);
            }
        }
    }

    //Handle OffScreen exceptions
    catch(OffScreen &a)
    {
        cerr << "Square Point out of range: Attempted to create point at: "
             << endl;
        cerr << center.x - (SQUARE_WIDTH / 2) << '\t'
             << center.y + (SQUARE_WIDTH / 2) << endl;
        exit(15);
    }

}

/*******************************************************************************
 * Description: removes a Square from the screen                               *
 * Return: void                                                                *
 * Pre: object exists                                                          *
 * Post: object erased from screen. Object unchanged otherwise                 *
 ******************************************************************************/
void Square::erase(GLUT_Plotter *g)
{
    //Note: erase assumes we are only drawing Squares over white areas of screen
    g->setColor(BACKGROUND_WHITE);

    try
    {
        Point topLeft(center.x - (SQUARE_WIDTH / 2), center.y +
                                  (SQUARE_WIDTH / 2));

        for(int i = topLeft.x; i < topLeft.x + SQUARE_WIDTH; i++)
        {
            for(int j = topLeft.y; j < topLeft.y + SQUARE_WIDTH; j++)
            {
                g->plot(i, SCREEN_HEIGHT - j);
            }
        }

    }
    catch(OffScreen &a)
    {
        cerr << "Square Point out of range: Attempted to create point at: "
        << endl;
        cerr << center.x - (SQUARE_WIDTH / 2) << '\t'
        << center.y + (SQUARE_WIDTH / 2) << endl;
        exit(15);
    }

}

/*******************************************************************************
 * Description: returns the Point center                                       *
 * Return: a copy of the center Point                                          *
 * Pre: object exists                                                          *
 * Post: Object unchanged                                                      *
 ******************************************************************************/
Point Square::getCenter()
{
    return center;
}

/*******************************************************************************
 * Description: setter for center                                              *
 * Return: void                                                                *
 * Pre: object exists                                                          *
 * Post: center is assigned a value newCenter                                  *
 ******************************************************************************/
void Square::setCenter(Point newCenter)
{
    this->center = newCenter;
}

/*******************************************************************************
 * Description: causes the Square object to fall                               *
 * Return: void                                                                *
 * Pre: object exists                                                          *
 * Post: center moved down by a value of FALL_LENGTH                           *
 ******************************************************************************/
void Square::fall()
{
    center.y += FALL_LENGTH;
}

/*******************************************************************************
 * Description: shifts the Square to the right                                 *
 * Return: void                                                                *
 * Pre: object exists                                                          *
 * Post: object's center moved to the right                                    *
 ******************************************************************************/
void Square::shiftRight()
{
    center.x += SHIFT_LENGTH;
}

/*******************************************************************************
 * Description: shifts the Square to the left                                  *
 * Return: void                                                                *
 * Pre: object exists                                                          *
 * Post: object's center moved to the left                                     *
 ******************************************************************************/
void Square::shiftLeft()
{
    center.x -= SHIFT_LENGTH;
}

/*******************************************************************************
 * Description: moves the object up                                            *
 * Return: void                                                                *
 * Pre: object exists                                                          *
 * Post: object's center shifted up a distance FALL_LENGTH                     *
 ******************************************************************************/
void Square::moveUp()
{

    center.y -= FALL_LENGTH;
}

/*******************************************************************************
 * Description: calculates the top left Point in a Square                      *
 * Return: a Point by value representing the top left Point                    *
 * Pre: object exists                                                          *
 * Post: object unchanged                                                      *
 ******************************************************************************/
Point Square::getTopLeft()
{
    return Point(center.x - (SQUARE_WIDTH / 2), center.y +
                 (SQUARE_WIDTH / 2));
}
