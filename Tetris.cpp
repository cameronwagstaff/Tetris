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
}


//Tetris Main Game Loop
void Tetris::Play(void)
{

	//Check for Keyboard Hit
	while(g->kbhit())
    {
		int k = g->getKey();
		switch (k)
		{
		     case 27://ESC key
		         exit(1);
             break;
		}
	}


	//Check for mouse click
	while(g->click())
    {
		Click c;
		c = g->getClick();
	}

	// Update screen - draw game
	g->Draw();
}
