/*******************************************************************************
 * Author: Dr. Booth, Matt Arnold                                              *
 * Description: Does the Tetris                                                *
 * Created on: Mar 31, 2014                                                    *
 * Last Modified: 23 April 2014 - Matt Arnold                                  *
 ******************************************************************************/

#include "Tetris.h"
#include "Rectangle.h"
//Tetris Constructor

Tetris::Tetris(GLUT_Plotter* g) : matrix(g), nextBox(Point(GAME_RIGHT + 40, 70),
                                                     Point(SCREEN_WIDTH - 40, 170), BACKGROUND_WHITE)
{
    current.setType(Z);
    current.setOrientation(0);
    current.setColor();

	this->g = g;

    next.setPosition(Point((GAME_RIGHT + SCREEN_WIDTH) / 2, 95));

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
        scores.get();
    }
    
    scores.search(Player("Jeff"));
    scores.search("Tim");
    scores.search("Marsha");
    scores.search("Tom");
    scores.search("Dick");
    scores.search("Harry");
    scores.search("Paul");
    scores.search("Paula");
    scores.search("Latasha");
    scores.search("Cheyenne");

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
    else if(scores)
    {
        scores.draw(g);
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
        drawNextBox();
    }


    //Check for Keyboard Hit
	while(g->kbhit())
    {
		int k = g->getKey();
		switch (k)
        {
            case  27: exit(1); break;
            case 164: current.moveLeft(); break; //Left Arrow
            case 166: current.moveRight(); break; //Right Arrow
            case 167: current.rotateLeft(); break; //Down Arrow
            case 165: current.rotateRight(); break; //Up Arrow
            case 32 : current.fall(); break;       //Space Bar
            case 's': current.setType((current.getType() + 1) % 6); break; //s - Change type
            case 'u': current.moveUp(); break; //u - move up ya know, in case we want that
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
        {
            m.getViewScores().press(g);
            m.setRun(false);
            scores.setRun(true);
        }
        
        if(scores && scores.getMenuButton().isInRange(c))
        {
            scores.getMenuButton().press(g);
            scores.setRun(false);
            m.setRun(true);
        }
        
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

void Tetris::drawNextBox()
{
    nextBox.draw(g);

    next.draw(g);

    drawString(g, "Next Piece:", nextBox.getTopLeft(), BLACK);
}
