/*******************************************************************************
 * Author: Matt Arnold                                                         *
 * Description: class definition for Squares                                   *
 * Date Created: 22 April 2014                                                 *
 * Date Last Modified: 22 April 2014 - Matt Arnold                             *
 ******************************************************************************/

#ifndef __Square__
#define __Square__

#include "Shape.h"
#include "Point.h"
#include "Constants.h"
#include "GLUT_Plotter.h"

class Square : public Shape
{
    private:
        Point center;
    
    public:
        Square(Point center = Point(100, 100), unsigned int color = WHITE);
        Square(const Square & other);
        Square& operator = (const Square& other);
        Point getCenter();
        void draw(GLUT_Plotter *g);
        void erase(GLUT_Plotter *g);
        void setCenter(Point newCenter);
        void fall();
        void moveUp();
        void shiftRight();
        void shiftLeft();
    
};

#endif