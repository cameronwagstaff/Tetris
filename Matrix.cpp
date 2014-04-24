/******************************************************************************
 * Author: John Daniel                                                        *
 * Description: Implementation of Matrix Class                                *
 * Date Created:16 April 2014                                                 *
 * Date Last Modified:22 April 2014 - Matt Arnold                             *
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
    matrix = new Shape**[MAX_ROWS];
    for (int i = MIN_ROWS; i < MAX_ROWS; i++)
    {
        matrix[i] = new Shape*[MAX_COLS];
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
    //Destructer needs to touch all levels of the array
    for(int i = 0; i < MAX_ROWS; i++)
    {
        for(int j = 0; j < MAX_COLS; j++)
        {
            delete [] matrix[i][j];
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
void Matrix::lineCheck()
{
    for (int i = MAX_ROWS - 1; i >= 0; i--)
    {
        if (rowSum(i) == MAX_COLS)
        {
            deleteRow(i);
            shiftDown(i);
        }
    }
}

/******************************************************************************
* Description: Finds the sum of the row                                       *
* Return: INTEGER!!!!!                                                        *
* Pre: Everything exists, valid integer                                       *
* Post: Nothing is changed                                                    *
******************************************************************************/
int Matrix::rowSum(int r)
{
    int count = 0;
    for (int c = MIN_COLS; c < MAX_COLS; c++)
    {
        if (matrix[r][c] != NULL)
        {
            count++;
        }
    }
    return count;
}

/******************************************************************************
* Description: Deletes the entire row!                                        *
* Return: void                                                                *
* Pre: The row is full and ready to be deleted                                *
* Post: The row is deleted and ready to be shifted down                       *
******************************************************************************/
void Matrix::deleteRow(int r)
{
    for(int i = 0; i < MAX_COLS; i++)
    {
        matrix[r][i]->erase(g);
    }
    
    //Shift matrix down
    shiftDown(r);
    
    //Set top row to NULL
    for (int c = MIN_COLS; c < MAX_COLS; c++)
    {
        ///////////////////////////////////////\
        // I think this is a hardcore leak/////\
        ///////////////////////////////////////\
        
        ///////////////////////////////////////\
        // Nah man, I think you're good////////\
        ///////////////////////////////////////\
        
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
void Matrix::shiftDown(int r)
{
    for (int r; r > MIN_ROWS; r--)
    {
        for (int c = MIN_COLS; c < MAX_COLS; c++)
        {
            swap(matrix[r][c], matrix[r-1][c]);
        }
    }
    return;
}

/******************************************************************************
* Description: Puts a shape in the matrix                                     *
* Return: Matrix&                                                             *
* Pre: Valid shape                                                            *
* Post: There is now a shape in row, col                                      *
******************************************************************************/
Matrix& Matrix::addShape(int r, int c, Shape& object)
{
    //If matrix already points to an object, we are trying to add something
    //  where something is already present; throw LocationOccupied
    if(matrix[r][c] != NULL)
    {
        throw(LocationOccupied(r, c));
    }
    
    //Else, add object to the matrix
    matrix[r][c] = &object;
    
    //Commented John's stuff out rather than deleting in case I'm crazy - Matt
    /*//Add Shape if matrix[r][c] is null. else there is already something there
    if (matrix[r][c] == NULL)
    {
        matrix[r][c] = &object;
    }
    // else throw some kind of exception...too tired to think about that*/
    return *this;
}

