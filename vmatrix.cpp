#include "vmatrix.h"

#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include <iomanip>

VMatrix::Matrix::Matrix(VMatrix::MatrixVector& hopefulMatrixShape, int rows, int columns) {
    this->colCount = columns;
    this->rowCount = rows;
    this->matrix   = hopefulMatrixShape;
}

VMatrix::Matrix::Matrix(const unsigned int rows, const unsigned int columns) {
    this->colCount = columns;
    this->rowCount = rows;

    for (int i = 0; i < rows; i++) {
        this->matrix.push_back(std::vector<int>(columns));
    }
}

void VMatrix::Matrix::printMatrix() {
    if (this->rowCount <= 0) {
        std::cout << "Nothing to print" << std::endl;
        return;
    }

    for (int i = 0; i < this->rowCount; i++) {
        for (int c = 0; c < this->colCount; c++) {
            if (c == 0) {
                std::cout << "R" << i + 1 << "|";
            }
            std::cout <<std::right << std::setw(6) << this->matrix[i][c];
        }
        std::cout << " |\n";
    }
    std::cout << "\n";
}

bool VMatrix::Matrix::fillMatrixWithRandNums(const unsigned int lowNum, const unsigned int highNum) {
    if (this->rowCount <= 0) {
        throw "Matrix is too small.";
    }

    if (lowNum > highNum) {
        throw "lowNum must be lower than highNum when doing random fill.";
    }

    try {
        for (int i = 0; i < this->rowCount; i++) {
            for (int k = 0; k < this->colCount; k++) {
                this->matrix[i][k] = rand() % (highNum - lowNum) + lowNum;
            }
        }
    } catch (const std::exception _) {
        return false;
    }

    return true;
}

namespace VMatrix {
    Matrix operator + (VMatrix::Matrix const& m1, VMatrix::Matrix const& m2) {
        if (
            m1.rowCount != m2.rowCount
            || m1.colCount != m2.colCount
        ) {
            throw "Row x Col needs to be the same for both Matrices to be added.";
        }

        VMatrix::MatrixVector newMatrix;
   
        for (int r = 0; r < m1.rowCount; r++) {
            newMatrix.push_back(std::vector<int>(m1.colCount));
            for (int c = 0; c < m1.colCount; c++) {
               newMatrix[r][c] = (m1.matrix[r][c] + m2.matrix[r][c]);
            }
        }
    
        return VMatrix::Matrix(newMatrix, m1.rowCount, m1.colCount);
    }

    VMatrix::Matrix operator - (VMatrix::Matrix const& m1, VMatrix::Matrix const& m2) {
        if (
            m1.rowCount != m2.rowCount
            || m1.colCount != m2.colCount
        ) {
            throw "Row x Col needs to be the same for both Matrices to be added.";
        }

        VMatrix::MatrixVector newMatrix;
   
        for (int r = 0; r < m1.rowCount; r++) {
            newMatrix.push_back(std::vector<int>(m1.colCount));
            for (int c = 0; c < m1.colCount; c++) {
               newMatrix[r][c] = (m1.matrix[r][c] - m2.matrix[r][c]);
            }
        }
    
        return Matrix(newMatrix, m1.rowCount, m1.colCount);
    }

    Matrix operator * (VMatrix::Matrix const& ma1, VMatrix::Matrix const& ma2) {
    // in case we want to change the order of the matrix.
        auto m1 = ma1;
        auto m2 = ma2;
        if (m1.colCount != m2.rowCount) {
            if (m2.colCount != m1.rowCount) {
                throw "Cannot multiply these matrices.";
            }

            // we can multiply them, but we need to switch them around.
            // Example: 3x2 * 2x3 is legal, but 2x3 * 2x3 is not.
            // m1 col size needs to equal m2 row size.
            auto tmp = m1;
            m1 = m2;
            m2 = tmp;
        }

        // Now we have validated our matrix sizes, we are ready to multiply.
        VMatrix::MatrixVector mulMatrix;
        int multiplier;

        for (int col = 0; col < m2.colCount; col++) {
            for (int r = 0; r < m1.rowCount; r++) {
                mulMatrix.push_back(std::vector<int>(m1.colCount));
                multiplier = 0;
                for (int c = 0; c < m1.colCount; c++) {
                    multiplier += (m1.matrix[r][c] * m2.matrix[c][col]);       
                }
                mulMatrix[r][col] = multiplier;
            }
        }

        return VMatrix::Matrix(mulMatrix, m1.rowCount, m2.colCount);
    }
}