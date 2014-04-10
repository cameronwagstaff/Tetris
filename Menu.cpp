/*******************************************************************************
 * Author: Matt Arnold
 * Assignment Title:
 * Assignment Description:
 * Due Date:
 * Date Created: 01 April 2014
 * Date Last Modified: 08 April 2014 - Matt Arnold
 ******************************************************************************/

#include "Menu.h"

/*******************************************************************************
 * Description:
 * Return:
 * Pre:
 * Post:
 ******************************************************************************/
Menu::Menu()
//use initialization list to invoke constructors for Buttons with arguments
: startButton("Start Game", Point(95, 320), Point(95 + BUTTON_LENGTH, 320 + BUTTON_WIDTH), BLACK),
  viewScores("View High Scores",Point(95, 420), Point(95 + BUTTON_LENGTH, 420 + BUTTON_WIDTH))
{
    //Empty block
}

/*******************************************************************************
 * Description:
 * Return:
 * Pre:
 * Post:
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
}

/*******************************************************************************
 * Description:
 * Return:
 * Pre:
 * Post:
 ******************************************************************************/
void Menu::erase(GLUT_Plotter *g)
{
    
    
    //Erase Buttons
    startButton.erase(g);
    viewScores.erase(g);
}

Button Menu::getStartButton()
{
    return startButton;
}

Button Menu::getViewScores()
{
    return viewScores;
}

bool Menu::operator!()
{
    return !running;
}

