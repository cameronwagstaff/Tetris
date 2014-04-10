<<<<<<< HEAD
/*******************************************************************************
=======
/*
>>>>>>> FETCH_HEAD
 * Author: Matt Arnold
 * Assignment Title:
 * Assignment Description:
 * Due Date:
 * Date Created: 01 April 2014
<<<<<<< HEAD
 * Date Last Modified: 08 April 2014 - Matt Arnold
 ******************************************************************************/
=======
 * Date Last Modified: 02 April 2014 - Matt Arnold
 */
>>>>>>> FETCH_HEAD

#include "Menu.h"

/*******************************************************************************
 * Description:
 * Return:
 * Pre:
 * Post:
 ******************************************************************************/
Menu::Menu()
//use initialization list to invoke constructors for Buttons with arguments
<<<<<<< HEAD
: startButton("Start Game", Point(95, 320), Point(95 + BUTTON_LENGTH, 320 + BUTTON_WIDTH), BLACK),
  viewScores("View High Scores",Point(95, 420), Point(95 + BUTTON_LENGTH, 420 + BUTTON_WIDTH))
=======

: startButton("Start Game", Point(235, 220), Point(395, 300)), viewScores("View High Scores",
                                                          Point(235, 420), Point(395, 500))
>>>>>>> FETCH_HEAD
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
<<<<<<< HEAD
    g->setColor(MENU_BLUE);
    
    for(int i = BORDER_WIDTH; i < GAME_RIGHT - BORDER_WIDTH; i++)
    {
        for(int j = BORDER_WIDTH; j < GAME_BOTTOM - BORDER_WIDTH; j++)
        {
            g->plot(i, j);
        }
    }
    
=======
    g->setColor(0x12547C);

    for(int i = 0; i < SCREEN_WIDTH; i++)
    {
        for(int j = 0; j < SCREEN_HEIGHT; j++)
        {
            g->plot(i,j);
        }
    }

>>>>>>> FETCH_HEAD
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
<<<<<<< HEAD
    
    
=======


>>>>>>> FETCH_HEAD
    //Erase Buttons
    startButton.erase(g);
    viewScores.erase(g);
}
<<<<<<< HEAD

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

=======
>>>>>>> FETCH_HEAD
