/*******************************************************************************
 * Author: Matt Arnold                                                         *
 * Description: Implementation for the InputBox class                          *
 * Date Created: 26 April 2014                                                 *
 * Last Modified: 29 April 2014 - Matt Arnold                                  *
 ******************************************************************************/

#include "InputBox.h"

/*******************************************************************************
 * Description: class constructor                                              *
 * Return: nothing                                                             *
 * Pre: none                                                                   *
 * Post: InputBox constructed                                                  *
 ******************************************************************************/
InputBox::InputBox(string prompt, unsigned int backgroundColor,
                   unsigned int buttonColor, string data)

//initialization list
: background(Point(80, 175), Point(430, 360), backgroundColor),
  dataBox(Point(100, 250)
          , Point( 400, 285), WHITE),
  enter("OK", Point(260, 300), Point(400, 345), buttonColor),
  cancel("Cancel", Point(100, 300), Point(240, 345), buttonColor)
{
    this->data = data;
    this->prompt = prompt;
    this->alNumErr = false;
    this->exceedsLength = false;
}

/*******************************************************************************
 * Description: class destructor                                               *
 * Return: nothing                                                             *
 * Pre: none                                                                   *
 * Post: object destructed                                                     *
 ******************************************************************************/
InputBox::~InputBox()
{

}

/*******************************************************************************
 * Description: copy constructor                                               *
 * Return: nothing                                                             *
 * Pre: other is a valid object                                                *
 * Post: object constructed as a copy of other                                 *
 ******************************************************************************/
InputBox::InputBox(const InputBox& other)
{
    *this = other;
}

/*******************************************************************************
 * Description: overloaded assignment operator                                 *
 * Return: a reference to self                                                 *
 * Pre: object exists, other is valid object                                   *
 * Post: *this becomes a copy of other                                         *
 ******************************************************************************/
InputBox& InputBox::operator = (const InputBox& other)
{
    if(this != &other)
    {
        this->background = other.background;
        this->dataBox = other.dataBox;
        this->enter = other.enter;
        this->cancel = other.cancel;
        this->data = other.data;
        this->prompt = other.prompt;
    }

    return *this;
}

/*******************************************************************************
 * Description: getter for background                                          *
 * Return: a reference to the Rectangle background                             *
 * Pre: object exists                                                          *
 * Post: object unchanged                                                      *
 ******************************************************************************/
stdRect::Rectangle& InputBox::getBackground()
{
    return background;
}

/*******************************************************************************
 * Description: getter for dataBox                                             *
 * Return: a reference to the Rectangle dataBox                                *
 * Pre: object exists                                                          *
 * Post: object unchanged                                                      *
 ******************************************************************************/
stdRect::Rectangle& InputBox::getDataBox()
{
    return dataBox;
}

/*******************************************************************************
 * Description: getter for enter                                               *
 * Return: a reference to the Button enter                                     *
 * Pre: object exists                                                          *
 * Post: object unchanged                                                      *
 ******************************************************************************/
Button& InputBox::getEnter()
{
    return enter;
}

/*******************************************************************************
 * Description: getter for cancel                                              *
 * Return: a reference to the Button cancel                                    *
 * Pre: object exists                                                          *
 * Post: object unchanged                                                      *
 ******************************************************************************/
Button& InputBox::getCancel()
{
    return cancel;
}

/*******************************************************************************
 * Description: getter for data                                                *
 * Return: a reference to the string representing data                         *
 * Pre: object exists                                                          *
 * Post: object unchanged                                                      *
 ******************************************************************************/
string& InputBox::getData()
{
    return data;
}

/*******************************************************************************
 * Description: setter for data                                                *
 * Return: void                                                                *
 * Pre: object exists, d is a valid string                                     *
 * Post: data is assigned a value d                                            *
 ******************************************************************************/
void InputBox::setData(string d)
{
    data = d;
}

/*******************************************************************************
 * Description: draws the InputBox to the screen                               *
 * Return: void                                                                *
 * Pre: object exists                                                          *
 * Post: InputBox drawn to screen, object unchanged                            *
 ******************************************************************************/
void InputBox::draw(GLUT_Plotter *g)
{
    background.draw(g);
    dataBox.draw(g);
    enter.draw(g);
    cancel.draw(g);

    drawCenteredString(g, prompt, Point(250, 220), BLACK);
    drawString(g, data, dataBox.getTopLeft(), BLACK);

    if(alNumErr)
    {
        drawCenteredString(g, "Alphanumeric Characters and Spaces Only!!!",
                           Point(255, 125), RED);
    }

    if(exceedsLength)
    {
        drawCenteredString(g, "Input must be smaller than 10 characters!!!",
                           Point(255, 140), RED);
    }
}

/*******************************************************************************
 * Description: erases InputBox from screen                                    *
 * Return: void                                                                *
 * Pre: object exists                                                          *
 * Post: InputBox erased from screen, object unchanged                         *
 ******************************************************************************/
void InputBox::erase(GLUT_Plotter *g)
{
    background.erase(g);
    dataBox.erase(g);
    enter.erase(g);
    cancel.erase(g);
}

/*******************************************************************************
 * Description: setter for alNumError - should be true when the user           *
 *              attempts to input a non-alphanumeric character                 *
 * Return: void                                                                *
 * Pre: object exists                                                          *
 * Post: alNumErr is assigned a value val                                      *
 ******************************************************************************/
void InputBox::setAlNumErr(bool val)
{
    alNumErr = val;
}

/*******************************************************************************
 * Description: setter for exceedsLength - true when the user attempts to enter*
 *              a string of characters longer than one we want to print        *
 * Return: void                                                                *
 * Pre: object exists                                                          *
 * Post: exceedsLength is assigned a value val                                 *
 ******************************************************************************/
void InputBox::setExcedesLength(bool val)
{
    exceedsLength = val;
}
