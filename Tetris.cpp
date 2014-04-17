/*******************************************************************************
 * Author: Dr. Booth, Matt Arnold                                              *
 * Description: Does the Tetris                                                *
 * Created on: Mar 31, 2014                                                    *
 * Last Modified: 10 April 2014 - Matt Arnold                                  *
 ******************************************************************************/

#include "Tetris.h"

//Tetris Constructor

Tetris::Tetris(GLUT_Plotter* g)
{
	this->g = g;
    
    //Load player score data from file. If file does not exist, it is created
    try
    {
        scores.get();
    }
    catch(NoScores a)
    {
        cerr << "Scores data not found: creating file" << endl;
        ofstream data;
        data.open("scores.bin");
        data.close();
    }
}


//Tetris Main Game Loop
void Tetris::Play(void)
{
    drawGame();
    
    if(m)
    {
        m.draw(g);
    }
    
    //Check for Keyboard Hit
	while(g->kbhit())
    {
		int k = g->getKey();
		switch (k)
        {
            case 27: exit(1); //ESC key
                break;
            default: cout << k << endl;
		}
	}
    
    
	//Check for mouse click
	while(g->click())
    {
        
		Click c;
		c = g->getClick();
        cout << c.x << " " << c.y << endl;
        
        if(m && m.getStartButton().isInRange(Point(c)))
        {
            m.getStartButton().press(g);
            m.setRun(false);
        }
        if(m && m.getViewScores().isInRange(Point(c)))
            m.getViewScores().press(g);
    }
    
    
	// Update screen - draw game
	g->Draw();
}

/*******************************************************************************
 * Description: Draws the basic gameplay screen                                *
 * Return: void                                                                *
 * Pre: Tetris exists, God transcends us                                       *
 * Post: game drawn to screen                                                  *
 ******************************************************************************/
void Tetris::drawGame()
{
    g->setColor(BACKGROUND_GRAY);
    for(int i = 0; i < SCREEN_WIDTH; i++)
    {
        for(int j = 0; j < SCREEN_HEIGHT; j++)
        {
            g->plot(i, j);
        }
    }
    
    g->setColor(BLACK);
    
    for(int i = 0; i < GAME_BOTTOM; i++)
    {
        g->plot(GAME_RIGHT, i);
    }
    
    g->setColor(BACKGROUND_WHITE);
    
    for(int i = BORDER_WIDTH; i < GAME_RIGHT - BORDER_WIDTH; i++)
    {
        for(int j = BORDER_WIDTH; j < GAME_BOTTOM - BORDER_WIDTH; j++)
        {
            g->plot(i, j);
        }
    }
    
    Rectangle b(Point(537, 75),Point(537+225, 75 + 100),(m)? MENU_BLUE :
                                                              BACKGROUND_WHITE);
    b.draw(g);
    
}