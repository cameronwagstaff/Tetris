/*******************************************************************************
 * Author: Matt Arnold                                                         *
 * Description: defines the Button class for buttons used in menus, etc        *
 * Date Created: 01 April 2014                                                 *
 * Date Last Modified: 10 April 2014 - Matt Arnold                             *
 ******************************************************************************/

#ifndef Tetris_Button_h
#define Tetris_Button_h

#include <string>
#include <ctime>
#include "GLUT_Plotter.h"
#include "Point.h"
#include "Constants.h"
#include "Text.h"
#include "Rectangle.h"

using namespace std;

const int BUTTON_LENGTH = 310;
const int BUTTON_WIDTH = 50;

class Button : public stdRect::Rectangle
{
    private:
        unsigned int textColor;
        string text;
    public:
        Button(string s = "TEXT", Point tl = Point(0,0),
               Point br = Point(BUTTON_LENGTH, BUTTON_WIDTH),
               unsigned int color = WHITE, unsigned int textColor = BLACK);
        ~Button();
        void draw(GLUT_Plotter* g);
        void erase(GLUT_Plotter* g);
        void press(GLUT_Plotter* g);
        void setTextColor(unsigned int newTextColor);
        void setText(string newText);
        unsigned int getTextColor();
        string getText();

};

#endif
