/*******************************************************************************
 * Author: Cameron Wagtaff                                                     *
 * Description: Prints text to the screen at a given point in desired colors   *
 * Date Created: 04 April 2014                                                 *
 * Date Last Modified: 26 April 2014 - Matt Arnold                             *
 ******************************************************************************/

#include "Text.h"

/******************************************************************************
Default constructor for text object
******************************************************************************/
Text::Text(Point o, string n, unsigned int c, unsigned int bc)
{
    origin = o;
    text = n;
    drawColor = c;
    backgroundColor = bc;
    charWidth = characterWidth;
    charHeight = characterHeight;
}

/******************************************************************************
Overloaded assignment operator, if the arguments/returns are off, patch it.
I don't know why my compiler was mad at 'const Text& o' as a parameter
******************************************************************************/
Text& Text::operator=(Text* o)
{
    if(this != o)
    {
        origin = o->origin;
        text = o->text;
        drawColor = o->drawColor;
        backgroundColor = o->backgroundColor;
        charWidth = o->charWidth;
        charHeight = o->charHeight;
    }

    return *this;
}

/******************************************************************************
This function sets the origin to a point. The origin defines the top left
corner of the text
******************************************************************************/
void Text::setLocation(Point o)
{
    origin = o;
}

/******************************************************************************
Draws a character given at any coordinate you specify at a color you specify.
    ***THIS FUNCTION WILL GO PRIVATE WHEN Text::draw(GLUT_Plotter*) IS***
                ***IMPLEMENTED, SO DON'T DEPEND ON IT***
******************************************************************************/
void Text::drawChar(GLUT_Plotter* g, int x, int y, int val)
{
    for(int i = charHeight; i > 0; i --)
    {
        for(int j = 0; j < charWidth; j ++)
        {
            if(characters16[val][i][j] == 1)
            {
                if(val != 36)
                {
                    g->plot(x + j, y - i);
                }
            }
        }
    }
}

/******************************************************************************
Draws the contents of text<string> to the screen from origin<Point> down
and rightwards
******************************************************************************/
void Text::draw(GLUT_Plotter* g)
{
    g->setColor(drawColor);

    for(int i = 0; i < static_cast<int>(text.size()); i ++)
    {
        drawChar(g, origin.x + 10 * i, SCREEN_HEIGHT - origin.y, charToInt(text[i]));
    }
}

/******************************************************************************
Calls Text::draw(GLUT_Plotter*) with the backgroundColor<int> given
******************************************************************************/
void Text::erase(GLUT_Plotter* g)
{
    unsigned int temp = drawColor;
    drawColor = backgroundColor;
    this->draw(g);
    drawColor = temp;
}

/******************************************************************************
Converts given character to the index in the font array that its bitmap is in.
This is hard code, but it maps characters to values well
******************************************************************************/
int Text::charToInt(char c)
{
    if('0' <= c && c <= '9')
    {
        return static_cast<int>(c - '0');
    }
    if('A' <= c && c <= 'Z')
    {
        return static_cast<int>(c - 'A') + 10;
    }
    if('a' <= c && c <= 'z')
    {
        return static_cast<int>(c - 'a') + 10;
    }

    switch(c)
    {
        case ':':
            return 38;
        break;

        case '.':
            return 37;
        break;

        case ' ':
            return 36;
        break;

        case ',':
            return 39;
        break;

        case '\'':
            
        case '!':
            return 40;

        break;
    }

    //mind the gap
    throw(InvalidChar());
}

void drawString(GLUT_Plotter* g, string s, Point n, unsigned int color/*, unsigned int backgroundColor*/)
{
    Text temp(n, s, color, WHITE);

    temp.draw(g);
}

void drawCenteredString(GLUT_Plotter* g, string s, Point n, unsigned int color)
{
    Point refPoint;

    refPoint.x = n.x - s.size() * characterWidth / 2;
    refPoint.y = n.y - characterHeight / 2;

    drawString(g, s, refPoint, color);
}











