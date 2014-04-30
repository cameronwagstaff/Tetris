/*******************************************************************************
 * Author: Matt Arnold                                                         *
 * Description: Implements the Menu class, which handles the game menu         *
 * Date Created: 01 April 2014                                                 *
 * Date Last Modified: 10 April 2014 - Matt Arnold                             *
 ******************************************************************************/

#include "Menu.h"

/*******************************************************************************
 * Description: Constructor for the Menu class, initializes buttons            *
 * Return: nothing                                                             *
 * Pre: Object exists                                                          *
 * Post: Object unchanged                                                      *
 ******************************************************************************/
Menu::Menu()
//use initialization list to invoke constructors for Buttons with arguments
: startButton("Start Game", Point(95, 320),
              Point(95 + BUTTON_LENGTH, 320 + BUTTON_WIDTH), MENU_BUTTON_COLOR),
  viewScores("View High Scores",Point(95, 420),
             Point(95 + BUTTON_LENGTH, 420 + BUTTON_WIDTH), MENU_BUTTON_COLOR)
{
    running = true;
}

/*******************************************************************************
 * Description: Draws the menu to the screen                                   *
 * Return: void                                                                *
 * Pre: Object exists                                                          *
 * Post: Object unchanged                                                      *
 ******************************************************************************/
void Menu::draw(GLUT_Plotter *g)
{
    g->setColor(MENU_BLUE);

    for(int i = BORDER_WIDTH; i < GAME_RIGHT - BORDER_WIDTH; i++)
    {
        for(int j = BORDER_WIDTH; j < GAME_BOTTOM - BORDER_WIDTH; j++)
        {
            g->plot(i, j);
        }
    }

    //Draw Buttons
    startButton.draw(g);
    viewScores.draw(g);

    //Draw Title
    drawCenteredString(g, "TETRIS", Point(255, 135), 0x00FF33);
}

/*******************************************************************************
 * Description: erases the menu                                                *
 * Return: void                                                                *
 * Pre: object exists                                                          *
 * Post: object unchanged                                                      *
 ******************************************************************************/
void Menu::erase(GLUT_Plotter *g)
{
    //Erase Buttons
    startButton.erase(g);
    viewScores.erase(g);
}

/*******************************************************************************
 * Description: accessor for startButton Button                                *
 * Return: a reference to startButton                                          *
 * Pre: object exists                                                          *
 * Post: object unchanged                                                      *
 ******************************************************************************/
Button& Menu::getStartButton()
{
    return startButton;
}

/*******************************************************************************
 * Description: accessor for viewScores Button                                 *
 * Return: a reference to viewScores                                           *
 * Pre: object exists                                                          *
 * Post: object unchanged                                                      *
 ******************************************************************************/
Button& Menu::getViewScores()
{
    return viewScores;
}

/*******************************************************************************
 * Description: allows Menu object to be treated as a boolean variable         *
 * Return: true if menu should be running, false otherwise                     *
 * Pre: object exists                                                          *
 * Post: object unchaged                                                       *
 ******************************************************************************/
Menu::operator bool()
{
    return running;
}

/*******************************************************************************
 * Description: Sets the boolean variable running                              *
 * Return: void                                                                *
 * Pre: object exists                                                          *
 * Post: the value of running is assigned the value of a                       *
 ******************************************************************************/
void Menu::setRun(bool a)
{
    running = a;
}

