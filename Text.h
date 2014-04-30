/*******************************************************************************
 * Author: Cameron Wagtaff                                                     *
 * Description: Prints text to the screen at a given point in desired colors   *
 * Date Created: 04 April 2014                                                 *
 * Date Last Modified: April 30 2014 - Cameron Wagstaff                        *
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
* Description: Shorthand string drawing tool
* Return: void
* Pre: function is called
* Post: given string is drawn
******************************************************************************/
void drawString(GLUT_Plotter* g, string s, Point n, unsigned int color);

/******************************************************************************
* Description: Shorthand string drawing tool
* Return: void
* Pre: function is called
* Post: given string is drawn
******************************************************************************/
void drawCenteredString(GLUT_Plotter* g, string s, Point n, unsigned int color);

class Text
{
    private:
        Point origin;
        string text;
        int charWidth, charHeight;
        unsigned int drawColor, backgroundColor;

        void drawChar(GLUT_Plotter* g, int x, int y, int val);
        int charToInt(char);

    public:
        Text(Point o = Point(0,0), string n = "test", unsigned int c = BLACK,
             unsigned int bc = BACKGROUND_WHITE);
        void setLocation(Point o);
        void draw(GLUT_Plotter* g);
        void erase(GLUT_Plotter* g);
        Text& operator=(Text*);
};

#endif // TEXT_H_INCLUDED
