/*******************************************************************************
 * Author: Matt Arnold                                                         *
 * Description: Defines the Rectangle class to be used for elements of the game*
 *              that involve rectangles                                        *
 * Date Created: 10 April 2014                                                 *
 * Date Last Modified: 23 April 2014 - Matt Arnold                             *
 ******************************************************************************/
#ifndef __Rectangle__
#define __Rectangle__

#include <iostream>
#include "GLUT_Plotter.h"
#include "Point.h"
#include "Shape.h"
#include "Constants.h"

using namespace std;

//Wow. Like, this is actually a thing. Wow.
//Such namespace. many rect. wow. so computer. much magic.
namespace stdRect
{
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
            virtual Point getCenter();
            virtual bool isInRange(Point a);
    };

}



#endif
