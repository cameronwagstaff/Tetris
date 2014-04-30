/*******************************************************************************
 * Author: Cameron Wagtaff                                                     *
 * Description: Prints text to the screen at a given point in desired colors   *
 * Date Created: 04 April 2014                                                 *
 * Date Last Modified: 30 April 2014 - Cameron Wagstaff                        *
 ******************************************************************************/

#include "Text.h"

/******************************************************************************
* Description: Default class constructor
* Return: none
* Pre: Function is called
* Post: Text object is created
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
* Description: Overloaded equals operator
* Return: Text by reference
* Pre: there is another text object
* Post: this text object is a copy of the other text object
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
* Description: Sets the location of the text
* Return: void
* Pre: object exists
* Post: object is unchanged
******************************************************************************/
void Text::setLocation(Point o)
{
    origin = o;
}

/******************************************************************************
* Description: Draw function for characters
* Return: void
* Pre: object exists
* Post: object is unchanged
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
* Description: Draw function for the entire text
* Return: void
* Pre: object exists
* Post: object is unchanged
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
* Description: Replaces text with its background color, effectively erasing it
* Return: void
* Pre: object exists
* Post: object is unchanged
******************************************************************************/
void Text::erase(GLUT_Plotter* g)
{
    unsigned int temp = drawColor;
    drawColor = backgroundColor;
    this->draw(g);
    drawColor = temp;
}

/******************************************************************************
* Description: character to font code conversion tool
* Return: int
* Pre: the function is called with a character
* Post: that character's identifier is returned
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

    throw(InvalidChar());
}

/******************************************************************************
* Description: Shorthand string drawing tool
* Return: void
* Pre: function is called
* Post: text appears on screen
******************************************************************************/
void drawString(GLUT_Plotter* g, string s, Point n, unsigned int color)
{
    Text temp(n, s, color, WHITE);

    temp.draw(g);
}

/******************************************************************************
* Description: Shorthand string drawing tool
* Return: void
* Pre: function is called
* Post: text appears on screen
******************************************************************************/
void drawCenteredString(GLUT_Plotter* g, string s, Point n, unsigned int color)
{
    Point refPoint;

    refPoint.x = n.x - s.size() * characterWidth / 2;
    refPoint.y = n.y - characterHeight / 2;

    drawString(g, s, refPoint, color);
}











