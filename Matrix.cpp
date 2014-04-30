/******************************************************************************
 * Author: John Daniel                                                        *
 * Description: Implementation of Matrix Class                                *
 * Date Created:16 April 2014                                                 *
 * Date Last Modified:29 April 2014 - Matt Arnold                             *
 *****************************************************************************/

#include "Matrix.h"


/******************************************************************************
* Description: Default Constructor                                            *
* Return: Nothing                                                             *
* Pre: Everything is Happy                                                    *
* Post: Matrix is initiated with default shapes in it                         *
******************************************************************************/
Matrix::Matrix(GLUT_Plotter *g)//works the way we think it does
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
    //Destructor needs to touch all levels of the array
    for(int i = 0; i < MAX_ROWS; i++)
    {
        for(int j = 0; j < MAX_COLS; j++)
        {
            //delete matrix[i][j];
        }

        delete [] matrix[i];
    }

    delete [] matrix;
}

/******************************************************************************
* Description: Calls rowSum(int r) to check if a row is full; if full then    *
*              calls deleteRow(int r) and shiftDown(int r)                    *
* Return: void                                                                *
* Pre: The Matrix exists, nothing is bad                                      *
* Post: if there are full lines they are removed and matrix shifted down      *
******************************************************************************/
bool Matrix::lineCheck()//works the way we think it does
{
    bool flag = false;

    for (int i = MAX_ROWS - 1; i >= 0; i--)
    {
        if (rowSum(i) == MAX_COLS)
        {
            deleteRow(i);
            flag = true;
        }
    }

    return flag;
}

//document this you fool
void Matrix::draw(GLUT_Plotter *g)//works the way we think it does
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
* Return: INTEGER!!!!!                                                        *
* Pre: Everything exists, valid integer                                       *
* Post: Nothing is changed                                                    *
******************************************************************************/
int Matrix::rowSum(int r)//works the way we think it does
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
        //delete matrix[r][c];
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
void Matrix::shiftDown(int r)//this does what we think it does
{
    cout << "shifting" << endl;
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

            matrix[row][c] = matrix[row-1][c];//needs to work
        }
    }

    draw(g);
    return;
}

//document this you fool
Matrix& Matrix::addPiece(Piece object)//this function has questionable maths
{
    //cout << "try" << endl;
    for(int i = 0; i < 4; i++)
    {
        int row = 0, col = 0;

        col = (object.getSquares()[i]->getTopLeft().x - BORDER_WIDTH)
                / SQUARE_WIDTH; //maths
        row = (object.getSquares()[i]->getTopLeft().y - BORDER_WIDTH)
                / SQUARE_WIDTH; //maths
        //cout << row << " " << col << endl;
        addShape(row, col, *object.getSquares()[i]);
    }

    return *this;
}

/******************************************************************************
* Description: Puts a shape in the matrix                                     *
* Return: Matrix&                                                             *
* Pre: Valid shape                                                            *
* Post: There is now a shape in row, col                                      *
******************************************************************************/
Matrix& Matrix::addShape(int r, int c, Square& object)
{
    //If matrix already points to an object, we are trying to add something
    //  where something is already present; throw LocationOccupied
    if(matrix[r][c] != NULL)
    {
        throw(LocationOccupied(r, c));
    }

    //Else, add object to the matrix
    matrix[r][c] = new Square(object);

    return *this;
}

/******************************************************************************
* Description: Checks if Matrix[r][c] is occutpied                            *
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


