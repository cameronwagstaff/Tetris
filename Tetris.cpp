/*******************************************************************************
 * Author: Dr. Booth, Matt Arnold, Cameron Wagstaff                            *
 * Description: Does the Tetris                                                *
 * Created on: Mar 31, 2014                                                    *
 * Last Modified: 29 April 2014 - Matt Arnold                                  *
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
    srand(clock());

    end = false;

    currentScore = 0;
    rowsCleared = 0;
    consecTetris = 0;

    this->g = g;

    next.setPosition(Point((GAME_RIGHT + SCREEN_WIDTH) / 2, 95));

    //Load player score data from file. If file does not exist, it is created
    try
    {
        scores.get();
        cerr << "Successfully got scores" << endl;
    }
    catch(NoScores a)
    {
        cerr << "Scores data not found: creating file" << endl;
        ofstream data;
        data.open("scores.bin");
        data.close();
        scores.get();
    }

    //scores.getPlayers().push_back(Player("Tim"));
}


//Tetris Main Game Loop
void Tetris::Play(void)
{
    //matrix.lineCheck();

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
        matrix.draw(g);
        drawCenteredString(g, "GAME OVER", Point(245, 40), BLACK);
        enterName.erase(g);
        enterName.draw(g);
    }
    else
    {
        if(clock() >= time + fallSpeed() * static_cast<double>(CLOCKS_PER_SEC))
        {
            current.erase(g);

            tryMoveDown(current, matrix);

            time = clock();
        }

        current.draw(g);

        drawNextBox();
        drawScore();

        matrix.draw(g);

        if(current.getRest())
        {
            try
            {
                matrix.addPiece(current);

                current = next;
                current.setPosition(PIECE_START);

                //srand(clock());//more randomness
                next.setType(rand() % 6);
                next.setColor();
            }
            catch(LocationOccupied &l)
            {
                end = true;
            }

        }

    }


    //Check for Keyboard Hit
	while(g->kbhit())
    {
		int k = g->getKey();

		//cout << k << endl;

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
                //Ignore shift keys
                case LSHIFT: break;
                case RSHIFT: break;
                case BACKSPACE://Backspace - see Constants.h

                {
                    enterName.setAlNumErr(false);

                    if(static_cast<int>(enterName.getData().length())
                       <= MAX_LEN)
                    {
                        enterName.setExcedesLength(false);
                    }

                    if(enterName.getData().length() > 0)
                    {
                        enterName.getData().erase(enterName.getData().size()
                                                  - 1, 1);
                    }

                    break;
                }
                default:
                {
                    if((isalnum(static_cast<char>(k)) ||
                        static_cast<char>(k) == ' ')
                       && static_cast<int>(enterName.getData().length())
                       <= MAX_LEN)
                    {
                        enterName.getData() += toupper(static_cast<char>(k));
                        enterName.setAlNumErr(false);

                    }
                    else
                    {
                        if(!(isalnum(static_cast<char>(k)) ||
                             static_cast<char>(k) == ' '))
                        {
                            enterName.setAlNumErr(true);
                        }

                        if(static_cast<int>(enterName.getData().length())
                           >= MAX_LEN)
                        {
                            enterName.setExcedesLength(true);
                        }
                    }

                    break;
                }
            }
             cout << enterName.getData() << '\t'
                  << enterName.getData().length() << endl;
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
                case 's': current.setType((current.getType() + 1) % 7); break; //s - Change type
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
        //cout << c.x << " " << c.y << endl;

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

        if(end && enterName.getEnter().isInRange(c))
        {
            enterName.getEnter().press(g);
            scores[scores.search(enterName.getData())].addGame(currentScore);
            scores.save();
            scores.sort();
            scores.save();
            enterName.getData().clear();
            enterName.setExcedesLength(false);
            enterName.setAlNumErr(false);
            scores.setRun(true);
            resetGame();
        }

        if(end && enterName.getCancel().isInRange(c))
        {
            enterName.getCancel().press(g);
            m.setRun(true);
            enterName.setExcedesLength(false);
            enterName.setAlNumErr(false);
            resetGame();
        }
    }
    
        int rows = matrix.lineCheck();
    
        if(rows == 4)
        {
            currentScore += consecTetris * 400;
            consecTetris += 1;
        }
        else
        {
            consecTetris = 0;
        }

        currentScore += 100 * rows;
        rowsCleared += rows;

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

/*******************************************************************************
 * Description: draws the box holding the next piece                           *
 * Return: void                                                                *
 * Pre: object exists, nothing is broken                                       *
 * Post: nextBox drawn to screen with next Piece inside, nothing changed       *
 ******************************************************************************/
void Tetris::drawNextBox()
{
    nextBox.draw(g);

    next.draw(g);

    drawString(g, "Next Piece:", nextBox.getTopLeft(), BLACK);
}

/*******************************************************************************
 * Description: Draws the user's current score to the screen                   *
 * Return: void                                                                *
 * Pre: object exists, score is valid                                          *
 * Post: player score drawn to screen, object unchanged                        *
 ******************************************************************************/
void Tetris::drawScore()
{
    stringstream stream;

    stream << "Score: " << currentScore;

    drawString(g, stream.str(), Point(nextBox.getTopLeft().x,
                                      nextBox.getTopLeft().y + 200), BLACK);
    //Temporarily row cleared data is drawn here. will either change location of
    //this block or name && description of function
    stringstream stream2;
    stream2 << "Rows Cleared: " << rowsCleared;
    drawString(g, stream2.str(), Point(nextBox.getTopLeft().x,
                                      nextBox.getTopLeft().y + 300), BLACK);
}

/*******************************************************************************
 * Description: returns the number of seconds to wait between falls based on   *
 *              number of rows cleared (level)                                 *
 * Return: a double representing the number of seconds between falls           *
 * Pre: object exists, nothing is broken                                       *
 * Post: object unchanged                                                      *
 ******************************************************************************/
double Tetris::fallSpeed()
{
    static bool canChange = false;
    static double time = 0.75;

    if(!canChange && rowsCleared % 7 != 0)
    {
        canChange = true;
    }

    if(canChange && rowsCleared %7 == 7)
    {
        time -= FALL_TIME_PER_LEVEL;
    }

    return time;
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

/*******************************************************************************
 * Description: Resets the game to allow replayability                         *
 * Return: void                                                                *
 * Pre: object exists                                                          *
 * Post: game is reset                                                         *
 ******************************************************************************/
void Tetris::resetGame()
{
    end = false;
    matrix.clear();

    enterName.getData().clear();

    currentScore = 0;
    rowsCleared = 0;
    consecTetris = 0;

    current = Piece();
    next = Piece();

    next.setPosition(Point((GAME_RIGHT + SCREEN_WIDTH) / 2, 95));
    current.setPosition(PIECE_START);
}






