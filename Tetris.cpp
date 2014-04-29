/*******************************************************************************
 * Author: Dr. Booth, Matt Arnold, Cameron Wagstaff                            *
 * Description: Does the Tetris                                                *
 * Created on: Mar 31, 2014                                                    *
 * Last Modified: 28 April 2014 - Cameron Wagstaff                             *
 ******************************************************************************/

#include "Tetris.h"

using namespace std;

//Tetris Constructor
Tetris::Tetris(GLUT_Plotter* g)
: matrix(g),
nextBox(Point(GAME_RIGHT + 40, 70),
        Point(SCREEN_WIDTH - 40, 170), BACKGROUND_WHITE),
enterName("Enter Your Name")

{
    end = false;

    currentScore = 0;

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
}


//Tetris Main Game Loop
void Tetris::Play(void)
{
    matrix.lineCheck();

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
    else if(end)
    {
        enterName.erase(g);
        enterName.draw(g);
    }
    else
    {
        if(clock() >= time + .75 * static_cast<double>(CLOCKS_PER_SEC))
        {
            current.erase(g);

            //this mimics pressing space every time the piece needs to move
            // down, so stopping this function alone would be a pause game
            tryMoveDown(current, matrix);

            time = clock();
        }

        current.draw(g);
        drawNextBox();

        matrix.draw(g);

        if(current.getRest())
        {
            matrix.addPiece(current);

            current = next;
            current.setPosition(PIECE_START);

            srand(clock());//more randomness
            next.setType(rand() % 6);
            next.setColor();
        }

    }


    //Check for Keyboard Hit
	while(g->kbhit())
    {
		int k = g->getKey();

        //Escape key always exits game
        if(k == 27)
        {
            this->~Tetris();
            exit(1);
        }


        if(end)
        {
            switch(k)
            {
                case 127://Backspace

                {
                    enterName.setAlNumErr(false);

                    if(static_cast<int>(enterName.getData().length()) <= MAX_LEN)
                    {
                        enterName.setExcedesLength(false);
                    }

                    if(enterName.getData().length() > 0)
                    {
                        enterName.getData().erase(enterName.getData().size() - 1, 1);
                    }

                    break;
                }
                default:
                {
                    if((isalnum(static_cast<char>(k)) ||
                        static_cast<char>(k) == ' ')
                       && static_cast<int>(enterName.getData().length()) <= MAX_LEN)
                    {
                        enterName.getData() += toupper(static_cast<char>(k));
                        enterName.setAlNumErr(false);

                    }
                    else
                    {
                        if(!(isalnum(static_cast<char>(k)) || static_cast<char>(k) == ' '))
                        {
                            enterName.setAlNumErr(true);
                        }

                        if(static_cast<int>(enterName.getData().length()) >= MAX_LEN)
                        {
                            enterName.setExcedesLength(true);
                        }
                    }

                    break;
                }
            }
        }

        else
        {
            switch (k)
            {
                case 164: //Left Arrow
                    tryMoveLeft(current, matrix);
                break;

                case 166: //Right Arrow
                    tryMoveRight(current, matrix);
                break;

                case 167: //Down Arrow
                    tryRotateLeft(current, matrix);
                break;

                case 165: //Up Arrow
                    tryRotateRight(current, matrix);
                break;

                case 32 : //Space Bar
                    tryMoveDown(current, matrix);
                break;

                case 112: //P
                    //this will pause the game in the future
                break;

                ///THESE ARE CHEATS, REMOVE THEM OR MAKE THEM EASTER EGGS
                case 's': current.setType((current.getType() + 1) % 6); break; //s - Change type
                case 'u': current.moveUp(); break; //u - move up ya know, in case we want that

                default: cout << k << endl;
            }
        }
	}


	//Check for mouse click
	while(g->click())
    {

		Click c;
		c = g->getClick();
        cout << c.x << " " << c.y << endl;

        if(end && enterName.getEnter().isInRange(c))
        {
            enterName.getEnter().press(g);
            scores[scores.search(enterName.getData())].addGame(currentScore);
            scores.save();
            enterName.getData().clear();
            enterName.setExcedesLength(false);
            enterName.setAlNumErr(false);
            end = false;
            scores.setRun(true);
            break;
        }

        if(end && enterName.getCancel().isInRange(c))
        {
            enterName.getCancel().press(g);
            end = false;
            m.setRun(true);
            enterName.getData().clear();
            enterName.setExcedesLength(false);
            enterName.setAlNumErr(false);
            break;
        }


        if(m && m.getStartButton().isInRange(Point(c)))
        {
            currentScore = 0;
            m.getStartButton().press(g);
            m.setRun(false);
            //end = true;   //This was here for testing
        }
        if(m && m.getViewScores().isInRange(Point(c)))
        {
            m.getViewScores().press(g);
            m.setRun(false);
            scores.setRun(true);
            scores.sort();
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

/******************************************************************************
THIS IS AN INPUT GUARD AND I AM TOO LAZY TO DOCUMENT IT RN
******************************************************************************/
void Tetris::tryMoveDown(Piece &current, Matrix &matrix)
{
    try
    {
        bool shouldFall = true;

        for(int i = 0; i < 4 && shouldFall; i ++)
        {
            int r = toMatrix(((current.getSquares())[i]->getTopLeft())).x + 1;
            int c = toMatrix(((current.getSquares())[i]->getTopLeft())).y;

            if(r >= MAX_ROWS || matrix.occupied(r, c))
            {
                shouldFall = false;
            }
        }

        if(shouldFall)
        {
            current.fall();
        }
        else
        {
            current.setRest(true);
        }
    }
    catch(LocationOccupied &e)
    {
        cout << e.what() << endl;
    }
    catch(NotInMatrix e)
    {
        cout << e.what() << endl;
    }
    catch(...)
    {
        cout << "SOMETHING HAS GONE WRONG IN TRYMOVEDOWN" << endl;
    }
}

/******************************************************************************
THIS IS AN INPUT GUARD AND I AM TOO LAZY TO DOCUMENT IT RN
******************************************************************************/
void Tetris::tryMoveLeft(Piece &current, Matrix &matrix)
{
    try
    {
        bool canMoveLeft = true;

        for(int i = 0; i < 4; i ++)
        {
            //I an an idiot
            int row = toMatrix((current.getSquares())[i]->getTopLeft()).x;
            int col = toMatrix((current.getSquares())[i]->getTopLeft()).y - 1;

            if(matrix.occupied(row, col))
            {
                canMoveLeft = false;
            }
        }

        if(canMoveLeft)
        {
            current.moveLeft();
        }
    }
    catch(NotInMatrix &e)
    {
        cout << e.what() << endl;
    }
    catch(LocationOccupied &e)
    {
        cout << e.what() << endl;
    }
    catch(...)
    {
        cout << "SOMETHING HAS GONE WRONG IN TRYMOVELEFT" << endl;
    }
}

/******************************************************************************
THIS IS AN INPUT GUARD AND I AM TOO LAZY TO DOCUMENT IT RN
******************************************************************************/
void Tetris::tryMoveRight(Piece &current, Matrix &matrix)
{
    try
    {
        bool canMoveRight = true;

        for(int i = 0; i < 4; i ++)
        {
            //I an an idiot
            int row = toMatrix((current.getSquares())[i]->getTopLeft()).x;
            int col = toMatrix((current.getSquares())[i]->getTopLeft()).y + 1;

            if(matrix.occupied(row, col))
            {
                canMoveRight = false;
            }
        }

        if(canMoveRight)
        {
            current.moveRight();
        }
    }
    catch(NotInMatrix &e)
    {
        cout << e.what() << endl;
    }
    catch(LocationOccupied &e)
    {
        cout << e.what() << endl;
    }
    catch(...)
    {
        cout << "SOMETHING HAS GONE WRONG IN TRYMOVERIGHT" << endl;
    }
}

/******************************************************************************
THIS IS AN INPUT GUARD AND I AM TOO LAZY TO DOCUMENT IT RN
******************************************************************************/
void Tetris::tryRotateLeft(Piece &current, Matrix &matrix)
{
    Piece p = current;

    try
    {
        bool canRotate = true;

        p.rotateLeft();

        for(int i = 0; i < 4; i ++)
        {
            int row = toMatrix((p.getSquares())[i]->getTopLeft()).x;
            int col = toMatrix((p.getSquares())[i]->getTopLeft()).y;

            if(matrix.occupied(row, col))
            {
                canRotate = false;
            }

            if(row < 0 || row >= MAX_ROWS || col < 0 || col >= MAX_COLS)
            {
                canRotate = false;
            }
        }

        if(canRotate)
        {
            current.rotateLeft();
        }
    }
    catch(NotInMatrix &e)
    {
        cout << e.what() << endl;
    }
    catch(OffScreen &e)
    {
        cout << "YOU CAN'T DO THAT" << endl;
    }
    catch(...)
    {
        cout << "SOMETHING HAS GONE WRONG IN TRYROTATELEFT" << endl;
    }
}

/******************************************************************************
THIS IS AN INPUT GUARD AND I AM TOO LAZY TO DOCUMENT IT RN
******************************************************************************/
void Tetris::tryRotateRight(Piece &current, Matrix &matrix)
{
    Piece p = current;

    try
    {
        bool canRotate = true;

        p.rotateRight();

        for(int i = 0; i < 4; i ++)
        {
            int row = toMatrix((p.getSquares())[i]->getTopLeft()).x;
            int col = toMatrix((p.getSquares())[i]->getTopLeft()).y;

            if(matrix.occupied(row, col))
            {
                canRotate = false;
            }

            if(row < 0 || row >= MAX_ROWS || col < 0 || col >= MAX_COLS)
            {
                canRotate = false;
            }
        }

        if(canRotate)
        {
            current.rotateRight();
        }
    }
    catch(NotInMatrix &e)
    {
        cout << e.what() << endl;
    }
    catch(OffScreen &e)
    {
        cout << "YOU CAN'T DO THAT" << endl;
    }
    catch(...)
    {
        cout << "SOMETHING HAS GONE WRONG IN TRYROTATERIGHT" << endl;
    }
}






