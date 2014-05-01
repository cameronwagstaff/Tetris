/*******************************************************************************
 * Author: Dr. Booth, Matt Arnold, Cameron Wagstaff                            *
 * Description: Does the Tetris                                                *
 * Created on: Mar 31, 2014                                                    *
 * Last Modified: 30 April 2014 - Cameron Wagstaff                             *
 ******************************************************************************/

#include "Tetris.h"

using namespace std;

//Tetris Constructor
Tetris::Tetris(GLUT_Plotter* g)
: matrix(g),
nextBox(Point(GAME_RIGHT + 40, 70),
        Point(SCREEN_WIDTH - 40, 170), BACKGROUND_WHITE),
enterName("Enter Your Name"),
endGame("End Game", Point(nextBox.getTopLeft().x, nextBox.getTopLeft().y + 400),
        Point(nextBox.getTopLeft().x + 200, nextBox.getTopLeft().y + 500), MENU_BLUE)
{
    srand(clock());

    end = false;
    pause = false;

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

            if(!pause)
            {
                tryMoveDown(current, matrix);
            }

            time = clock();
        }

        current.draw(g);

        drawNextBox();
        drawScore();

        matrix.draw(g);

        if(pause)
        {
            drawCenteredString(g, "PAUSED", Point((GAME_RIGHT - BORDER_WIDTH)
                    / 2 + BORDER_WIDTH, (GAME_BOTTOM - BORDER_WIDTH * 2) / 2 +
                    BORDER_WIDTH), RED);
        }

        if(current.getRest())
        {
            try
            {
                matrix.addPiece(current);

                current = next;
                current.setPosition(PIECE_START);

                next.setType(rand() % 7);
                next.setColor();
            }
            catch(LocationOccupied &l)
            {
                end = true;
            }

        }

        endGame.draw(g);
    }

    //Check for Keyboard Hit
	while(g->kbhit())
    {
		int k = g->getKey();

        //Escape key
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
                    if(enterName.getData().empty() &&
                       static_cast<char>(k) == ' ')
                    {
                        break;
                    }

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
        }

        else
        {
            switch (k)
            {
                case 164: //Left Arrow
                    if(!pause)
                    {
                        tryMoveLeft(current, matrix);
                    }
                break;

                case 166: //Right Arrow
                    if(!pause)
                    {
                        tryMoveRight(current, matrix);
                    }
                break;

                case 167: //Down Arrow
                    if(!pause)
                    {
                        tryRotateLeft(current, matrix);
                    }
                break;

                case 165: //Up Arrow
                    if(!pause)
                    {
                        tryRotateRight(current, matrix);
                    }
                break;

                case 32 : //Space Bar
                    if(!pause)
                    {
                        tryMoveDown(current, matrix);
                    }
                break;

                case 112: //P
                    togglePause();
                break;

                default:
                break;
            }
        }
	}

	//Check for mouse click
	while(g->click())
    {

		Click c;
		c = g->getClick();

        if(m && m.getStartButton().isInRange(Point(c)))
        {
            currentScore = 0;
            m.getStartButton().press(g);
            m.setRun(false);
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

        if(!m && !scores && endGame.isInRange(c))
        {
            endGame.press(g);
            end = true;
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
    static double warp = .05;
    static int lastRowsCleared = rowsCleared;
    int level = (500 + currentScore / 700.0) * .001;

    if(!canChange && lastRowsCleared != rowsCleared)
    {
        canChange = true;
    }

    if(canChange)
    {
        canChange = false;

        time -= warp;

        warp = level / rowsCleared;

        if(time <= 0)
        {
            time = .000001;
        }
    }

    lastRowsCleared = rowsCleared;

    return time;
}

/******************************************************************************
* Description: Attempts to move the current piece down
* Return: void
* Pre: object exists
* Post: object is unchanged
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
        cerr << e.what() << endl;
    }
    catch(NotInMatrix e)
    {
        cerr << e.what() << endl;
    }
    catch(...)
    {

    }
}

/******************************************************************************
* Description: Attempts to move the current piece to the left
* Return: void
* Pre: object exists
* Post: object is unchanged
******************************************************************************/
void Tetris::tryMoveLeft(Piece &current, Matrix &matrix)
{
    try
    {
        bool canMoveLeft = true;

        for(int i = 0; i < 4; i ++)
        {
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
        cerr << e.what() << endl;
    }
    catch(LocationOccupied &e)
    {
        cerr << e.what() << endl;
    }
    catch(...)
    {

    }
}

/******************************************************************************
* Description: Attempts to move the piece to the right
* Return: void
* Pre: object exists
* Post: object is unchanged
******************************************************************************/
void Tetris::tryMoveRight(Piece &current, Matrix &matrix)
{
    try
    {
        bool canMoveRight = true;

        for(int i = 0; i < 4; i ++)
        {
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
        cerr << e.what() << endl;
    }
    catch(LocationOccupied &e)
    {
        cerr << e.what() << endl;
    }
    catch(...)
    {

    }
}

/******************************************************************************
* Description: Attempts to rotate the current piece to the left
* Return: void
* Pre: object exists
* Post: Object is unchanged
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
        cerr << e.what() << endl;
    }
    catch(OffScreen &e)
    {

    }
    catch(...)
    {

    }
}

/******************************************************************************
* Description: Attempts to rotate the current piece to the right
* Return: void
* Pre: object exists
* Post: object is unchanged
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
        cerr << e.what() << endl;
    }
    catch(OffScreen &e)
    {

    }
    catch(...)
    {

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

/******************************************************************************
* Description: Function to pause the game
* Return: void
* Pre: object exists
* Post: pause is toggled
******************************************************************************/
void Tetris::togglePause()
{
    pause = !pause;
}




