/******************************************************************************
 * Author: John Daniel                                                        *
 * Description: Implementation of Matrix Class                                *
 * Date Created:16 April 2014                                                 *
 * Date Last Modified:30 April 2014 - Matt Arnold                             *
 *****************************************************************************/

#include "Matrix.h"


/******************************************************************************
* Description: Default Constructor                                            *
* Return: Nothing                                                             *
* Pre: Everything is Happy                                                    *
* Post: Matrix is initiated with default shapes in it                         *
******************************************************************************/
Matrix::Matrix(GLUT_Plotter *g)
{
    matrix = new Square** [MAX_ROWS];

    for (int i = MIN_ROWS; i < MAX_ROWS; i++)
    {
        matrix[i] = new Square* [MAX_COLS];

        for (int j = 0; j < MAX_COLS; j++)
        {
            matrix[i][j] = NULL;
        }
    }

    this->g = g;
}

/******************************************************************************
* Description: Destructor                                                     *
* Return: Nothing                                                             *
* Pre: There is something to delete                                           *
* Post: It is deleted                                                         *
******************************************************************************/
Matrix::~Matrix()
{
    for(int i = 0; i < MAX_ROWS; i++)
    {
        delete [] matrix[i];
    }

    delete [] matrix;
}

/******************************************************************************
* Description: Calls rowSum(int r) to check if a row is full; if full then    *
*              calls deleteRow(int r) and shiftDown(int r)                    *
* Return: an integer value representing the number of rows cleared            *
* Pre: The Matrix exists, nothing is bad                                      *
* Post: if there are full lines they are removed and matrix shifted down      *
******************************************************************************/
int Matrix::lineCheck()
{
    int count = 0;

    for (int i = MAX_ROWS - 1; i >= 0; i--)
    {
        if (rowSum(i) == MAX_COLS)
        {
            deleteRow(i);
            count += 1;
        }
    }

    return count;
}

/******************************************************************************
* Description: Draws the matrix of squares with plotter
* Return: void
* Pre: object exists
* Post: object is unchanged
******************************************************************************/
void Matrix::draw(GLUT_Plotter *g)
{
    for(int i = 0; i < MAX_ROWS; i++)
    {
        for(int j = 0; j < MAX_COLS; j++)
        {
            if(matrix[i][j] != NULL)
            {
                matrix[i][j]->draw(g);
            }
        }
    }
}

/******************************************************************************
* Description: Finds the sum of the row                                       *
* Return: integer                                                             *
* Pre: Everything exists, valid integer                                       *
* Post: Nothing is changed                                                    *
******************************************************************************/
int Matrix::rowSum(int r)
{
    bool full = true;
    for(int i = MIN_COLS; i < MAX_COLS && full; i ++)
    {
        if(matrix[r][i] == NULL)
            full = false;
    }

    if(full)
        return MAX_COLS;
    else
        return MIN_COLS;
}

/******************************************************************************
* Description: Deletes the entire row!                                        *
* Return: void                                                                *
* Pre: The row is full and ready to be deleted                                *
* Post: The row is deleted and the squares above it have moved down a unit    *
******************************************************************************/
void Matrix::deleteRow(int r)
{
    for(int i = MIN_COLS; i < MAX_COLS; i ++)
    {
        if(matrix[r][i])
        {
            matrix[r][i]->erase(g);
             matrix[r][i] = NULL;
        }
    }

    //Shift matrix down
    shiftDown(r);

    //Set top row to NULL
    for (int c = MIN_COLS; c < MAX_COLS; c ++)
    {
        matrix[MIN_ROWS][c] = NULL;
    }
    return;
}

/******************************************************************************
* Description: Shifts down everything in the matrix to the correct line       *
* Return: void                                                                *
* Pre: The line is hopefully deleted                                          *
* Post: Well it's gone now                                                    *
******************************************************************************/
void Matrix::shiftDown(int r)
{
    for(int row = r; row > MIN_ROWS; row--)
    {
        for(int c = MIN_COLS; c < MAX_COLS; c++)
        {
            if(matrix[row][c])
            {
                matrix[row][c]->erase(g);
                matrix[row][c]->setCenter(matrix[row][c]->getCenter() +
                                          Point(0, SQUARE_WIDTH));
            }

            matrix[row][c] = matrix[row-1][c];
        }
    }

    draw(g);
    return;
}

/******************************************************************************
* Description: Adds a piece to the matrix
* Return: Matrix by reference
* Pre: object exists
* Post: given piece is added to the matrix
******************************************************************************/
Matrix& Matrix::addPiece(Piece object)
{
    for(int i = 0; i < 4; i++)
    {
        int row = 0, col = 0;

        col = (object.getSquares()[i]->getTopLeft().x - BORDER_WIDTH)
                / SQUARE_WIDTH; //maths
        row = (object.getSquares()[i]->getTopLeft().y - BORDER_WIDTH)
                / SQUARE_WIDTH; //maths

        addShape(row, col, *object.getSquares()[i]);
    }

    return *this;
}

/******************************************************************************
* Description: Puts a shape in the matrix                                     *
* Return: Matrix by reference                                                 *
* Pre: Valid shape                                                            *
* Post: There is now a shape in row, col                                      *
******************************************************************************/
Matrix& Matrix::addShape(int r, int c, Square& object)
{
    if(matrix[r][c] != NULL)
    {
        throw(LocationOccupied(r, c));
    }

    matrix[r][c] = new Square(object);

    return *this;
}

/******************************************************************************
* Description: Checks if Matrix[r][c] is occupied                            *
* Return: bool                                                                *
* Pre: none                                                                   *
* Post: Nothing is changed                                                    *
******************************************************************************/
bool Matrix::occupied(int r, int c)
{
    if (r > MAX_ROWS || c >= MAX_COLS || r < MIN_ROWS || c < MIN_COLS)
    {
        throw(NotInMatrix(r,c));
    }
    return matrix[r][c] != NULL;
}

/******************************************************************************
* Description: Converts the topLeft of a square to its supposed matrix position
* Return: Point
* Pre: none
* Post: Nothing is changed
******************************************************************************/
Point toMatrix(Point convert)
{
    int row, col;
    col = (convert.x - BORDER_WIDTH) / SQUARE_WIDTH; //maths
    row = (convert.y - BORDER_WIDTH) / SQUARE_WIDTH; //maths

    return Point(row, col);
}

/*******************************************************************************
 * Description: Removes all elements from the Matrix                           *
 * Return: void                                                                *
 * Pre: object exists                                                          *
 * Post: all elements removed from Matrix                                      *
 ******************************************************************************/
void Matrix::clear()
{
    for(int i = 0; i < MAX_ROWS; i++)
    {
        deleteRow(i);
    }
}


