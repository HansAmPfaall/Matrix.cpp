#pragma once
#include "./Matrix.h"
#include <cstdlib>


// _____________________________________________________________________________
Matrix::Matrix(size_t rows, size_t cols) {
  _rowNum = rows;
  _colNum = cols;
  _storage.resize(rows);
  for (size_t i = 0; i < rows; i++) {
    _storage[i].resize(cols);
    for (size_t j = 0; j < cols; j++) {
      _storage[i][j] = ((double)rand() / RAND_MAX);
    }
  }
}

// _____________________________________________________________________________
Matrix::~Matrix() {
}

// _____________________________________________________________________________
inline void Matrix::setValue(int row, int col, double value) {
  if (row < _rowNum && col < _colNum) {
    _storage[row][col] = value;
  }
}

// _____________________________________________________________________________
inline double Matrix::getValue(int row, int col) {
  if (row < _rowNum && col < _colNum) {
    return _storage[row][col];
  }
}

// _____________________________________________________________________________
void Matrix::add(double x) {
  for (size_t i = 0; i < _rowNum; i++) {
    for (size_t j = 0; j < _colNum; j++) {
      _storage[i][j] += x;
    }
  }
}

// _____________________________________________________________________________
void Matrix::add(Matrix m, bool plus = true) {
  int s = plus ? 1:-1;
  if (_rowNum == m._rowNum and _colNum == m._colNum) { 
  for (size_t i = 0; i < _rowNum; i++) {
    for (size_t j = 0; j < _colNum; j++) {
      _storage[i][j] += m.getValue(i, j) * s;
    }
  }
  }
}

// _____________________________________________________________________________
Matrix Matrix::transpose() {
  Matrix temp(_colNum, _rowNum);
  for (size_t i = 0; i < temp._rowNum; i++) {
      for (size_t j = 0; j < temp._colNum; j++) {
          temp.setValue(i, j, _storage[j][i]);
      }
  }
  return temp;
}

// _____________________________________________________________________________
Matrix Matrix::mult(Matrix m) {
  Matrix temp(_rowNum, m._colNum);
  if (_rowNum != m._colNum) {
    return temp;
  }
  for (size_t i = 0; i < _rowNum; i++) {
    for (size_t k = 0; k < m._colNum; k++) {
      for (size_t j = 0; j < _colNum; j++) {
        temp.setValue(i, k, temp.getValue(i, k) + _storage[i][j] * m.getValue(j, k));
      }
    }
  }
  return temp;
}

// _____________________________________________________________________________
void Matrix::print() {
  for (size_t i = 0; i < _rowNum; i++) {
    for (size_t j = 0; j < _colNum; j++) {
      std::cout << _storage[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
