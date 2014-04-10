/*******************************************************************************
 * Author: Matt Arnold                                                         *
 * Description: Defines a Point struct to represent a point on the screen with *
 *              x and y coordinates                                            *
 * Date Created: 02 April 2014                                                 *
<<<<<<< HEAD
 * Date Last Modified: 03 April 2014 - Matt Arnold                             *
=======
 * Date Last Modified: 02 April 2014 - Matt Arnold                             *
>>>>>>> FETCH_HEAD
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
<<<<<<< HEAD
    
=======

>>>>>>> FETCH_HEAD
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
<<<<<<< HEAD
        
        this->x = x;
        this->y = y;
    }
    
    /***************************************************************************
     * Description: Constructs a Point object from a Click
     * Return: none
     * Pre: Click object exists, x and y are within screen range
     * Post: Point object is created with x c.x and y c.y
     **************************************************************************/
    Point(Click c)
    {
        this->x = c.x;
        this->y = c.y;
    }
=======

        this->x = x;
        this->y = y;
    }
>>>>>>> FETCH_HEAD
};

#endif