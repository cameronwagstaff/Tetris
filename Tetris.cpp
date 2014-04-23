/*******************************************************************************
 * Author: Dr. Booth, Matt Arnold                                              *
 * Description: Does the Tetris                                                *
 * Created on: Mar 31, 2014                                                    *
 * Last Modified: 22 April 2014 - Matt Arnold                                  *
 ******************************************************************************/

#include "Tetris.h"
#include "Rectangle.h"
//Tetris Constructor

Tetris::Tetris(GLUT_Plotter* g) : matrix(g)
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
    static double time = clock();
    
    drawGame();

    if(m)
    {
        m.draw(g);
    }
    else
    {
        if(clock() >= time + .75 * static_cast<double>(CLOCKS_PER_SEC))
           {
               current.erase(g);
               current.fall();
               time = clock();
           }
        current.draw(g);
    }
    

    //Check for Keyboard Hit
	while(g->kbhit())
    {
		int k = g->getKey();
		switch (k)
        {
            case  27: exit(1); break;
            case 164: current.moveLeft(); break;
            case 166: current.moveRight(); break;
            case 167: current.rotateLeft(); break;
            case 165: current.rotateRight(); break;
            case 32 : current.fall(); break;       //Space Bar    
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
}
