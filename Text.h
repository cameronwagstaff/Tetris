/*******************************************************************************
 * Author: Cameron Wagtaff                                                     *
 * Description: Prints text to the screen at a given point in desired colors   *
 * Date Created: 04 April 2014                                                 *
 * Date Last Modified:  April 23 2014 by Cameron Wagstaff                      *
 ******************************************************************************/

#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

#include "Font.h"
#include "Constants.h"
#include "GLUT_Plotter.h"
#include "Point.h"
#include <string>

using namespace std;

class InvalidChar{};;


/******************************************************************************
ATTENTION LAZY PEOPLE:
    THIS IS A SINGLE FUNCTION WRAPPER FOR THE TEXT CLASS. USE IT
******************************************************************************/
void drawString(GLUT_Plotter* g, string s, Point n, unsigned int color/*, unsigned int backgroundColor*/);

/******************************************************************************
ATTENTION LAZY PEOPLE:
    THIS CENTERS TEXT ABOUT A POINT YOU GIVE IT. IT MIGHT HELP YOU AVOID WORK
******************************************************************************/
void drawCenteredString(GLUT_Plotter* g, string s, Point n, unsigned int color);

class Text
{
    private:
        Point origin;
        string text;
        int charWidth, charHeight;
        unsigned int drawColor, backgroundColor;

        //draws a character you want, this function is public for debugging,
        //do not write dependencies on it
        void drawChar(GLUT_Plotter* g, int x, int y, int val);

        int charToInt(char);

    public:
        //constructor
        Text(Point o = Point(0,0), string n = "test", unsigned int c = BLACK,
             unsigned int bc = BACKGROUND_WHITE);

        //you know what this does, but the location is defined by the top left
        //of the text
        void setLocation(Point o);

        //the soon to be implemented function that will draw the string
        //contained in text<string> at origin<Point>
        void draw(GLUT_Plotter* g);

        //do not expect this function to do anything as it uses the draw
        //function to erase
        void erase(GLUT_Plotter* g);

        //just your friendly neighborhood equals operator
        Text& operator=(Text*);
};

#endif // TEXT_H_INCLUDED
