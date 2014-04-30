/*******************************************************************************
 * Author: Matt Arnold                                                         *
 * Description: Implementation of the Rectangle class                          *
 * Date Created: 10 April 2014                                                 *
 * Date Last Modified: 24 April 2014 - Matt Arnold                             *
 ******************************************************************************/
#include "Rectangle.h"

using namespace stdRect;

/*******************************************************************************
 * Description: Constructor for the Rectangle class                            *
 * Return: nothing                                                             *
 * Pre: none                                                                   *
 * Post: Rectangle object created with topLeft = tl, bottomRight = br, color   *
 *       assigned color                                                        *
 ******************************************************************************/
Rectangle::Rectangle(Point tl, Point br, unsigned int color) : Shape(color)
{
    this->topLeft = tl;
    this->bottomRight = br;
    //this->color = color;
}

/*******************************************************************************
 * Description: Destructor for Rectangles - does nothing                       *
 * Return: nothing                                                             *
 * Pre: object exists                                                          *
 * Post: object destructed                                                     *
 ******************************************************************************/
Rectangle::~Rectangle()
{
    //empty
}

/*******************************************************************************
 * Description: draws a Rectangle to the screen                                *
 * Return: void                                                                *
 * Pre: object exists                                                          *
 * Post: Rectangle drawn to screen. Object unchanged                           *
 ******************************************************************************/
void Rectangle::draw(GLUT_Plotter* g)
{
    //Set Color to the color of the button and fill the appropriate area
    g->setColor(color);

    for(int i = topLeft.x; i < bottomRight.x; i++)
    {
        for(int j = topLeft.y; j < bottomRight.y; j++)
        {
            g->plot(i, SCREEN_HEIGHT - j);
        }
    }

}

/*******************************************************************************
 * Description: erases a Rectangle object from the screen                      *
 * Return: void                                                                *
 * Pre: object exists                                                          *
 * Post: Rectangle erased from the screen. Object unchanged                    *
 ******************************************************************************/
void Rectangle::erase(GLUT_Plotter* g)
{
    //Set Color to background color and fill area previously held by button
    g->setColor(BACKGROUND_GRAY);

    for(int i = topLeft.x; i < bottomRight.x; i++)
    {
        for(int j = topLeft.y; j < bottomRight.y; j++)
        {
            g->plot(i, SCREEN_HEIGHT - j);
        }
    }

}

/*******************************************************************************
 * Description: setter for topLeft Point                                       *
 * Return: void                                                                *
 * Pre: object exists, Point a valid                                           *
 * Post: topLeft assigned a value of a                                         *
 ******************************************************************************/
void Rectangle::setTopLeft(Point a)
{
    topLeft = a;
}

/*******************************************************************************
 * Description: setter for bottomRight Point                                   *
 * Return: void                                                                *
 * Pre: object exists, Point b valid                                           *
 * Post: bottomRight assigned a value of b                                     *
 ******************************************************************************/
void Rectangle::setBottomRight(Point b)
{
    bottomRight = b;
}

/*******************************************************************************
 * Description: Getter for color                                               *
 * Return: an unsigned integer representing the object's color                 *
 * Pre: object exists                                                          *
 * Post: object unchanged                                                      *
 ******************************************************************************/
//unsigned int Rectangle::getColor()
//{
//  return color;
//}

/*******************************************************************************
 * Description: Getter for topLeft Point                                       *
 * Return: a Point representing the top left corner of the Rectangle           *
 * Pre: object exists                                                          *
 * Post: object unchanged                                                      *
 ******************************************************************************/
Point Rectangle::getTopLeft()
{
    return topLeft;
}

/*******************************************************************************
 * Description: Getter for bottomRight Point                                   *
 * Return: a Point representing the bottom right corner of the Rectangle       *
 * Pre: object exists                                                          *
 * Post: object unchanged                                                      *
 ******************************************************************************/
Point Rectangle::getBottomRight()
{
    return bottomRight;
}

/*******************************************************************************
 * Description: Getter for center point                                        *
 * Return: a point representing the center of the Rectangle                    *
 * Pre: object exists                                                          *
 * Post: object unchanged                                                      *
 ******************************************************************************/
Point Rectangle::getCenter()
{
    Point center;
    center.x = topLeft.x + (bottomRight.x - topLeft.x) / 2;
    center.y = topLeft.y + (bottomRight.y - topLeft.y) / 2;

    return center;
}

/*******************************************************************************
 * Description: Checks wheter a Point is within the space occupied by a        *
 *              Rectangle                                                      *
 * Return: true if the Point is inside the Rectangle's area, false otherwise   *
 * Pre: object exists                                                          *
 * Post: object unchanged                                                      *
 ******************************************************************************/
bool Rectangle::isInRange(Point a)
{
    return a.x > topLeft.x && a.y > topLeft.y &&
           a.x < bottomRight.x && a.y < bottomRight.y;
}
