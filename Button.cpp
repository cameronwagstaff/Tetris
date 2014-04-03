/*******************************************************************************
 * Author: Matt Arnold                                                         *
 * Description: Implementation for the Button class, graphical objects which   *
 *              function as buttons                                            *
 * Date Created: 01 April 2014                                                 *
 * Date Last Modified: 02 April 2014                                           *
 ******************************************************************************/

#include "Button.h"

/*******************************************************************************
 * Description: Constructor for the Button class                               *
 * Return: none                                                                *
 * Pre: none                                                                   *
 * Post: a Button object is constructed with text s, top left Point tl, bottom *
 *       right Point br, color color and text color textColor                  *
 ******************************************************************************/
Button::Button(string s, Point tl, Point br, int color, int textColor)
{
    this->text = s;
    this->topLeft = tl;
    this->bottomRight = br;
    this->color = color;
    this->textColor = textColor;
}

/*******************************************************************************
 * Description: draws the Button object on the screen                          *
 * Return: void                                                                *
 * Pre: Button object exists                                                   *
 * Post: object is displayed on the screen, remains unchanged                  *
 ******************************************************************************/
void Button::draw(GLUT_Plotter* g)
{
    //Set Color to the color of the button and fill the appropriate area
    g->setColor(color);
    
    for(int i = topLeft.x; i < bottomRight.x; i++)
    {
        for(int j = topLeft.y;
            j < bottomRight.y; j++)
        {
            g->plot(i, j);
        }
    }
}

/*******************************************************************************
 * Description: erases a Button that has been drawn to the screen              *
 * Return: void                                                                *
 * Pre: the object has previously been drawn on the screen                     *
 * Post: the Button is removed from the graphical display, remains unchanged   *
 ******************************************************************************/
void Button::erase(GLUT_Plotter* g)
{
    //Set Color to background color and fill area previously held by button
    g->setColor(BACKGROUND_GRAY);
    
    for(int i = topLeft.x; i < bottomRight.x; i++)
    {
        for(int j = topLeft.y; j < bottomRight.y; j++)
        {
            g->plot(i, j);
        }
    }
    
    //Draw button text

}

/*******************************************************************************
 * Description: Graphically represents the pressing of a button                *
 * Return: void                                                                *
 * Pre: object exists                                                          *
 * Post: object remains unchanged                                              *
 ******************************************************************************/
void Button::press(GLUT_Plotter* g)
{
    //erase existing button and redraw with different color
    erase(g);
    color += 0x777777;
    textColor += 0x777777;
    draw(g);
    
    //will probably add some kind of Sleep here
    
    
    //erase button and redraw with original color
    erase(g);
    color -= 0x777777;
    textColor -= 0x777777;
    draw(g);
}

/*******************************************************************************
 * Description: Setter for color                                               *
 * Return: void                                                                *
 * Pre: object exists                                                          *
 * Post: color is assgned a value newColor                                     *
 ******************************************************************************/
void Button::setColor(unsigned int newColor)
{
    color = newColor;
}

/*******************************************************************************
 * Description: Setter for textColor                                           *
 * Return: void                                                                *
 * Pre: object exists                                                          *
 * Post: textColor is assigned a value newTextColor                            *
 ******************************************************************************/
void Button::setTextColor(unsigned int newTextColor)
{
    textColor = newTextColor;
}

/*******************************************************************************
 * Description: Setter for text (changes the text on the button)               *
 * Return: void                                                                *
 * Pre: object exists                                                          *
 * Post: text is assigned a value newText                                      *
 ******************************************************************************/
void Button::setText(string newText)
{
    text = newText;
}
/*******************************************************************************
 * Description: getter for color                                               *
 * Return: an unsigned integer value representing the color of the object      *
 * Pre: object exists                                                          *
 * Post: object unchanged                                                      *
 ******************************************************************************/
unsigned int Button::getColor()
{
    return color;
}

/*******************************************************************************
 * Description: getter for textColor                                           *
 * Return: an unsigned integer representing the color of the text on the button*
 * Pre: object exists                                                          *
 * Post: object unchanged                                                      *
 ******************************************************************************/
unsigned int Button::getTextColor()
{
    return textColor;
}

/*******************************************************************************
 * Description: getter for text                                                *
 * Return: a string representing the text to be printed on the button          *
 * Pre: object exists                                                          *
 * Post: object unchanged                                                      *
 ******************************************************************************/
string Button::getText()
{
    return text;
}

