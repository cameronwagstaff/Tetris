/******************************************************************************
 * Author: John Daniel                                                        *
 * Description: Matrix Class, all you need in a Matrix 2.0! (2-D)             *
 * Date Created:16 April 2014                                                 *
 * Date Last Modified:16 April 2014 - John Daniel                             *
 *****************************************************************************/
#ifndef TETRIS_MATRIX_H_
#define TETRIS_MATRIX_H_

#include "Constants.h"
#include "Shape.h"

class Matrix
{
    private:
        /**
         Yes three pointers. To determine whether a shape is there the
         pointer either points to NULL or a shape. So it's a group of
         pointers that point to pointers that point to NULL or SHAPES!
        **/
        Shape*** matrix;

    public:
        Matrix();
        //Matrix(const Matrix& other);
        ~Matrix();
        void lineCheck();
        void shiftDown(int r);
        int  rowSum(int r);
        void deleteRow(int r);
        Matrix& addShape(int row, int col, Shape& object);
};

#endif
