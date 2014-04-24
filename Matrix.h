/******************************************************************************
 * Author: John Daniel                                                        *
 * Description: Matrix Class, all you need in a Matrix 2.0! (2-D)             *
 * Date Created:16 April 2014                                                 *
 * Date Last Modified:22 April 2014 - Matt Arnold                             *
 *****************************************************************************/
#ifndef TETRIS_MATRIX_H_
#define TETRIS_MATRIX_H_

#include <exception>
#include <string>
#include <sstream>
#include "GLUT_Plotter.h"
#include "Constants.h"
#include "Shape.h"

//Exception class thrown if the user tries to add a shape to the matrix in
//  a location that is already occupied
//Note: I tried way too hard on this - Matt
class LocationOccupied : public exception
{
    private:
        int row, col;
    public:
        LocationOccupied(int r, int c)
        {
            row = r;
            col = c;
        }
    
        const char* what()
        {
            std::stringstream ss;
            
            ss << "LocationOccupied: row " << row << " column " << col << endl;
            
            return ss.str().c_str();
        }
    
};

class Matrix
{
    private:
        /**
         Yes three pointers. To determine whether a shape is there the
         pointer either points to NULL or a shape. So it's a group of
         pointers that point to pointers that point to NULL or SHAPES!
        **/
        Shape*** matrix;
         GLUT_Plotter *g;

    public:
        Matrix(GLUT_Plotter *g);
        //Matrix(const Matrix& other);
        ~Matrix();
        void lineCheck();
        void shiftDown(int r);
        int  rowSum(int r);
        void deleteRow(int r);
        Matrix& addShape(int row, int col, Shape& object);
};

#endif
