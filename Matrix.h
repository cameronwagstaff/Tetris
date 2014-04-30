/******************************************************************************
 * Author: John Daniel                                                        *
 * Description: Matrix Class, all you need in a Matrix 2.0! (2-D)             *
 * Date Created:16 April 2014                                                 *
 * Date Last Modified:29 April 2014 - Matt Arnold                             *
 *****************************************************************************/
#ifndef TETRIS_MATRIX_H_
#define TETRIS_MATRIX_H_

#include <exception>
#include <string>
#include <sstream>
#include "GLUT_Plotter.h"
#include "Constants.h"
#include "Shape.h"
#include "Piece.h"

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

class NotInMatrix : public exception
{
    private:
        int row, col;
    public:
        NotInMatrix(int r, int c)
        {
            row = r;
            col = c;
        }

        const char* what()
        {
            std::stringstream ss;

            ss << "Points " << row << ", " << col << " are not in the Matrix" << endl;

            return ss.str().c_str();
        }

};

Point toMatrix(Point);

class Matrix
{
    private:
        /**
         Yes three pointers. To determine whether a shape is there the
         pointer either points to NULL or a shape. So it's a group of
         pointers that point to pointers that point to NULL or SHAPES!
        **/
         Square*** matrix;
         GLUT_Plotter *g;

    public:
        Matrix(GLUT_Plotter *g);
        //Matrix(const Matrix& other);
        ~Matrix();
        bool lineCheck();
        void shiftDown(int r);
        void draw(GLUT_Plotter *g);
        int  rowSum(int r);
        void deleteRow(int r);
        Matrix& addPiece(Piece object);
        Matrix& addShape(int row, int col, Square& object);
        bool occupied(int r, int c);
        void clear();
};

#endif
