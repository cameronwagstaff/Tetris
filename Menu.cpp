/*
 * Author: Matt Arnold
 * Assignment Title:
 * Assignment Description:
 * Due Date:
 * Date Created: 01 April 2014
 * Date Last Modified: 02 April 2014 - Matt Arnold
 */

#include "Menu.h"

/*******************************************************************************
 * Description:
 * Return:
 * Pre:
 * Post:
 ******************************************************************************/
Menu::Menu()
//use initialization list to invoke constructors for Buttons with arguments

: startButton("Start Game", Point(235, 220), Point(395, 300)), viewScores("View High Scores",
                                                          Point(235, 420), Point(395, 500))
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
    g->setColor(0x12547C);
    
    for(int i = 0; i < SCREEN_WIDTH; i++)
    {
        for(int j = 0; j < SCREEN_HEIGHT; j++)
        {
            g->plot(i,j);
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
