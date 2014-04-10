<<<<<<< HEAD
/*******************************************************************************
=======
/*
>>>>>>> FETCH_HEAD
 * Author: Matt Arnold
 * Assignment Title:
 * Assignment Description:
 * Due Date:
 * Date Created: 01 April 2014
 * Date Last Modified: 02 April 2014 - Matt Arnold
<<<<<<< HEAD
 ******************************************************************************/
=======
 */
>>>>>>> FETCH_HEAD


#ifndef Tetris_Button_h
#define Tetris_Button_h

#include <string>
<<<<<<< HEAD
#include <ctime>
=======
>>>>>>> FETCH_HEAD
#include "GLUT_Plotter.h"
#include "Point.h"
#include "Constants.h"

using namespace std;

<<<<<<< HEAD
const int BUTTON_LENGTH = 310;
const int BUTTON_WIDTH = 50;
=======
const int BUTTON_LENGTH = 160;
const int BUTTON_WIDTH = 80;
>>>>>>> FETCH_HEAD

class Button
{
    private:
        unsigned int color, textColor;
        Point topLeft, bottomRight;
        string text;
    public:
<<<<<<< HEAD
        Button(string s = "TEXT", Point tl = Point(0,0),
               Point br = Point(BUTTON_LENGTH, BUTTON_WIDTH),
=======
        Button(string s = "TEXT", Point tl = Point(0,0), Point br = Point(0, 0),
>>>>>>> FETCH_HEAD
               int color = WHITE,int textColor = BLACK);
        void draw(GLUT_Plotter* g);
        void erase(GLUT_Plotter* g);
        void press(GLUT_Plotter* g);
        void setColor(unsigned int newColor);
        void setTextColor(unsigned int newTextColor);
        void setText(string newText);
<<<<<<< HEAD
        void setTopLeft(Point a);
        void setBottomRight(Point b);
        unsigned int getColor();
        unsigned int getTextColor();
        string getText();
        Point getTopLeft();
        Point getBottomRight();
        bool isInRange(Point a);
    
=======
        unsigned int getColor();
        unsigned int getTextColor();
        string getText();
>>>>>>> FETCH_HEAD
};

#endif
