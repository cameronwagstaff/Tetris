/*******************************************************************************
 * Author: Matt Arnold                                                         *
 * Description: Defines a Point struct to represent a point on the screen with *
 *              x and y coordinates                                            *
 * Date Created: 02 April 2014                                                 *
 * Date Last Modified: 02 April 2014 - Matt Arnold                             *
 ******************************************************************************/


#ifndef Tetris_Point_h
#define Tetris_Point_h

#include "Constants.h"

//OffScreen is an exception class to be thrown when a Point is made that is
//outside the boudaries of the display window
class OffScreen{};

struct Point
{
    int x, y;

    /***************************************************************************
     * Description: Point object constructor                                   *
     * Return: none                                                            *
     * Pre: None                                                               *
     * Post: Point object is created with x and y                              *
     **************************************************************************/
    Point(int x = 0, int y = 0) throw(OffScreen)
    {
        //Throw OffScreen exception if the Point is outside the display
        //window boundaries
        if (y > SCREEN_HEIGHT || y < 0 || x < 0 || x > SCREEN_WIDTH)
        {
            throw(OffScreen());
        }

        this->x = x;
        this->y = y;
    }
};

#endif
