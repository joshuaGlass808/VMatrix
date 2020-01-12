#ifndef VMATRIX_H
#define VMATRIX_H

#include <vector>

namespace VMatrix {
    typedef std::vector<std::vector<int>> MatrixVector;

    class Matrix {

        int colCount, rowCount;
        MatrixVector matrix;

    public:
        Matrix(const unsigned int, const unsigned int);
        Matrix(MatrixVector&, int, int);
        ~Matrix() { return; }

        bool fillMatrixWithRandNums(const unsigned int, const unsigned int);
        void printMatrix();
        void setNewMatrix(MatrixVector const & mVec) { this->matrix = mVec; }
        int getColumnCount() const { return this->colCount; }
        int getRowCount() const { return this->rowCount; }
        MatrixVector getRawMatrixVector() const { return this->matrix; }

        friend Matrix operator + (Matrix const&, Matrix const&);
        friend Matrix operator - (Matrix const&, Matrix const&);
        friend Matrix operator * (Matrix const&, Matrix const&);
    };
}

#endif