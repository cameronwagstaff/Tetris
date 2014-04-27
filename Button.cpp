/*******************************************************************************
 * Author: Matt Arnold                                                         *
 * Description: Implementation for the Button class, graphical objects which   *
 *              function as buttons                                            *
 * Date Created: 01 April 2014                                                 *
 * Date Last Modified: 23 April 2014 - Cameron Wagstaff                        *
 ******************************************************************************/

#include "Button.h"

/*******************************************************************************
 * Description: Constructor for the Button class                               *
 * Return: none                                                                *
 * Pre: none                                                                   *
 * Post: a Button object is constructed with text s, top left Point tl, bottom *
 *       right Point br, color color and text color textColor                  *
 ******************************************************************************/
Button::Button(string s, Point tl, Point br, unsigned int color,
               unsigned int textColor)
: Rectangle(tl, br, color)
{
    this->text = s;
    this->textColor = textColor;
}

Button::~Button()
{
    //empty
}

/*******************************************************************************
 * Description: draws the Button object on the screen                          *
 * Return: void                                                                *
 * Pre: Button object exists                                                   *
 * Post: object is displayed on the screen, remains unchanged                  *
 ******************************************************************************/
void Button::draw(GLUT_Plotter* g)
{
    //Draw Rectangle
    Rectangle::draw(g);

    //Draw Text
    drawCenteredString(g, text, getCenter(), textColor);
}

/*******************************************************************************
 * Description: erases a Button that has been drawn to the screen              *
 * Return: void                                                                *
 * Pre: the object has previously been drawn on the screen                     *
 * Post: the Button is removed from the graphical display, remains unchanged   *
 ******************************************************************************/
void Button::erase(GLUT_Plotter* g)
{
    //Erase Button Text
    //HAHA I DON'T NEED THIS TO ERASE TEXT

    //Erase Rectangle
    Rectangle::erase(g);


}

/*******************************************************************************
 * Description: Graphically represents the pressing of a button                *
 * Return: void                                                                *
 * Pre: object exists                                                          *
 * Post: object remains unchanged                                              *
 ******************************************************************************/
void Button::press(GLUT_Plotter* g)
{
    float pressTime = .22;
    int times = clock();
    //erase existing button and redraw with different color
    erase(g);
    color += 0x555555;
    textColor += 0x555555;
    draw(g);
    
    g->Draw();

    //Wait for pressTime seconds

    while(clock() < times + pressTime * CLOCKS_PER_SEC);

    //erase button and redraw with original color
    erase(g);
    color -= 0x555555;
    textColor -= 0x555555;
    draw(g);

    //g->Draw();
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
