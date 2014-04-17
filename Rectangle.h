/*******************************************************************************
 * Author: Matt Arnold                                                         *
 * Description: Defines the Rectangle class to be used for elements of the game*
 *              that involve rectangles                                        *
 * Date Created: 10 April 2014                                                 *
 * Date Last Modified: 10 April 2014                                           *
 ******************************************************************************/
#ifndef __Rectangle__
#define __Rectangle__

#include <iostream>
#include "Point.h"
#include "Shape.h"
#include "Constants.h"

class Rectangle : public Shape
{
    protected:
        Point topLeft, bottomRight;
    public:
        Rectangle(Point tl = Point(0, 0),
                  Point br = Point(50, 50), unsigned int color = WHITE);
        virtual ~Rectangle();
        virtual void draw(GLUT_Plotter* g);
        virtual void erase(GLUT_Plotter* g);
        virtual void setTopLeft(Point a);
        virtual void setBottomRight(Point b);
        virtual Point getTopLeft();
        virtual Point getBottomRight();
        virtual bool isInRange(Point a);
        
};

#endif