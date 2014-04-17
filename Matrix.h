#ifndef TETRIS_MATRIX_H_
#define TETRIS_MATRIX_H_

#include "Constants.h"
#include "Shape.h"

class Matrix
{
    private:
        Shape** matrix;

    public:
        Matrix();
        //Matrix(const Matrix& other);
        ~Matrix();
        bool lineCheck();
        void shiftDown();
        Matrix& addShape(int row, int col);
};

#endif
