# VMatrix
My own Vector implemented Matrix in C++.

This repo is just for learning purposes only and I have no intention on this being a real thing. Feel free to contribute or fork if you are also learning.

Example below is some output of matrices and having them added/subtracted and multiplied.
```
Matrix1: 
R1|    16    89    38 |
R2|     6    30    60 |
R3|    25    73    58 |

Matrix2: 
R1|    18    59    48 |
R2|     7    68    70 |
R3|    71    67    23 |

Matrix1 + Matrix2: 
R1|    34   148    86 |
R2|    13    98   130 |
R3|    96   140    81 |

Matrix1 - Matrix2: 
R1|    -2    30   -10 |
R2|    -1   -38   -10 |
R3|   -46     6    35 |

Matrix1 * Matrix2: 
R1|  3609  9542  7872 |
R2|  4578  6414  3768 |
R3|  5079 10325  7644 |
```

To make things easier for building out a structured matrix I built a Matrix class.
If you want to make a `Matrix` all  you need to do is call:
```
 VMatrix::Matrix m1 = VMatrix::Matrix(3, 3);
```

Once you have initialized your matrix, you can then quickly fill it with random data by calling this method:
```
// first param is a min and the second param is a max for the random values that will be stored.
m1.fillMatrixWithRandNums(1, 99); 
```

Or if you would like to fill up the data just build it like this:
```
    //Create custom 2x2 
    VMatrix::MatrixVector mVec;
    mVec.push_back(std::vector<int>(2)); // row 1
    mVec.push_back(std::vector<int>(2)); // row 2
    mVec[0][0] = 12; mVec[0][1] = 21;
    mVec[1][0] = 10; mVec[1][1] = 11;

    VMatrix::Matrix custMatrix = VMatrix::Matrix(mVec, 2, 2);
    std::cout << "Printing Custom Matrix: " << std::endl;
    custMatrix.printMatrix(); 
```

Please see below for a full example (also in the example.cpp file:
```
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
```

Output:
```
Matrix1: 
R1|    16    89    38 |
R2|     6    30    60 |
R3|    25    73    58 |

Matrix2: 
R1|    18    59    48 |
R2|     7    68    70 |
R3|    71    67    23 |

Matrix1 + Matrix2: 
R1|    34   148    86 |
R2|    13    98   130 |
R3|    96   140    81 |

Matrix1 - Matrix2: 
R1|    -2    30   -10 |
R2|    -1   -38   -10 |
R3|   -46     6    35 |

Matrix1 * Matrix2: 
R1|  3609  9542  7872 |
R2|  4578  6414  3768 |
R3|  5079 10325  7644 |

Printing Custom Matrix: 
R1|    12    21 |
R2|    10    11 |

Printing Custom Matrix2: 
R1|    12    21 |
R2|    10    11 |
```
