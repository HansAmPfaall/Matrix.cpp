#include "./Matrix.h"

// _____________________________________________________________________________
Matrix::Matrix(size_t rows, size_t cols) {
    _rowNum = rows;
    _colNum = cols;
    _storage.resize(rows);
    for (size_t i = 0; i < rows; i++) {
        _storage[i].resize(rows);
        for (size_t j = 0; j < cols; j++) {
            _storage[i][j] = 0.0;
        }
    }
}

// _____________________________________________________________________________
Matrix::~Matrix() {}

// _____________________________________________________________________________
void Matrix::setValue(int row, int col, double value) {
    if (row < _rowNum && col < _colNum) {
        _storage[row][col] = value;
    }
}

// _____________________________________________________________________________
Matrix Matrix::transpose() {
    Matrix temp(_colNum, _rowNum);
    // for (size_t i = 0; i < temp._rowNum; i++) {
    //     for (size_t j = 0; j < temp._colNum; j++) {
    //         temp.setValue(i, j, _storage[j][i]);
    //     }
    // }
    return temp;
}

// _____________________________________________________________________________
Matrix Matrix::mult(Matrix m)
{
    Matrix temp(_rowNum, _colNum);
    return temp;
}


// _____________________________________________________________________________
void Matrix::print()
{
    for (size_t i = 0; i < _rowNum; i++)
    {
        for (size_t j = 0; j < _colNum; j++)
        {
            std::cout << _storage[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
