/*******************************************************************************
 * Author: Matt Arnold                                                         *
 * Description: Defines and implements the abstract Shape class                *
 * Date Created: 16 April 2014                                                 *
 * Date Last Modified: 16 April 2014 - Matt Arnold                             *
 ******************************************************************************/
#ifndef __Shape__
#define __Shape__

#include <iostream>
#include "GLUT_Plotter.h"
#include "Constants.h"

class Shape
{
    protected:
        unsigned int color;
    
    public:
    
        /***********************************************************************
         * Description: Shape class constructor                                *
         * Return: nothing                                                     *
         * Pre: none                                                           *
         * Post: Shape created with color color                                *
         **********************************************************************/
        Shape(unsigned int color = BLACK)
        {
            this->color = color;
        }
    
        /***********************************************************************
         * Description: virtual destructor for Shape                           *
         * Return: nothing                                                     *
         * Pre: object exists                                                  *
         * Post: object destructed                                             *
         **********************************************************************/
        virtual ~Shape()
        {
            
        }
    
       /************************************************************************
        * Description: changes the value of color                              *
        * Return: void                                                         *
        * Pre: object exists                                                   *
        * Post: color assigned value newColor                                  *
        ***********************************************************************/
        virtual void setColor(unsigned int newColor)
        {
            color = newColor;
        }
    
       /************************************************************************
        * Description: getter for color                                        *
        * Return: an unsigned int representing the color of the Shape          *
        * Pre: object exists                                                   *
        * Post: object unchanged                                               *
        ***********************************************************************/
        virtual unsigned int getColor()
        {
            return color;
        }
    
       /************************************************************************
        * Description: draws a shape to the screen                             *
        * Return: void                                                         *
        * Pre: object exists                                                   *
        * Post: object unchanged                                               *
        ***********************************************************************/
        virtual void draw(GLUT_Plotter *g)              =0;
    
       /************************************************************************
        * Description: Erases shape object from screen                         *
        * Return: void                                                         *
        * Pre: object exists                                                   *
        * Post: object unchanged                                               *
        ***********************************************************************/
        virtual void erase(GLUT_Plotter *g)             =0;
};


#endif