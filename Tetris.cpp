/*
 * Tetris.cpp
 *
 *  Created on: Mar 31, 2014
 *  Modified on: Mar 31, 2014
 *  Author: D. Booth
 */

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
<<<<<<< HEAD
    drawGame();
    m.draw(g);
    
=======

>>>>>>> FETCH_HEAD
	//Check for Keyboard Hit
	while(g->kbhit())
    {
		int k = g->getKey();
		switch (k)
<<<<<<< HEAD
        {
            case 27: exit(1); //ESC key
                break;
            default: cout << k << endl;
=======
		{
		     case 27://ESC key
		         exit(1);
             break;
>>>>>>> FETCH_HEAD
		}
	}
    
    
	//Check for mouse click
	while(g->click())
    {
<<<<<<< HEAD
        
=======
>>>>>>> FETCH_HEAD
		Click c;
		c = g->getClick();
        cout << c.x << " " << c.y << endl;
        
        if(m.getStartButton().isInRange(Point(c)))
        {
            m.getStartButton().press(g);
        }
        if(m.getViewScores().isInRange(Point(c)))
            m.getViewScores().press(g);
    }
    
    
	// Update screen - draw game
	g->Draw();
}

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
