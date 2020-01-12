#include "vmatrix.h"

#include <iostream>
#include <vector>

int main() {
    VMatrix::Matrix m1 = VMatrix::Matrix(3, 3);
    m1.fillMatrixWithRandNums(1, 99);
    VMatrix::Matrix m2 = VMatrix::Matrix(3, 3);
    m2.fillMatrixWithRandNums(1, 99);

    std::cout << "Matrix1: " << std::endl;
    m1.printMatrix();
    std::cout << "Matrix2: " << std::endl;
    m2.printMatrix();

    std::cout << "Matrix1 + Matrix2: " << std::endl;
    (m1 + m2).printMatrix();

    std::cout << "Matrix1 - Matrix2: " <<std::endl;
    (m1 - m2).printMatrix();

    std::cout << "Matrix1 * Matrix2: " << std::endl;
    (m1 * m2).printMatrix();

    //Create custom 2x2 
    VMatrix::MatrixVector mVec;
    mVec.push_back(std::vector<int>(2)); // row 1
    mVec.push_back(std::vector<int>(2)); // row 2
    mVec[0][0] = 12; mVec[0][1] = 21;
    mVec[1][0] = 10; mVec[1][1] = 11;

    VMatrix::Matrix custMatrix = VMatrix::Matrix(mVec, 2, 2);
    // or
    VMatrix::Matrix custMatrix2 = VMatrix::Matrix(2, 2);
    custMatrix2.setNewMatrix(mVec);

    std::cout << "Printing Custom Matrix: " << std::endl;
    custMatrix.printMatrix();
    std::cout << "Printing Custom Matrix2: " << std::endl;
    custMatrix2.printMatrix();

    return 0;
}