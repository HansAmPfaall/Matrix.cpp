#pragma once
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

class Matrix {
 public:
  // ___________________________________________________________________________
  // Constructor for Matriux with random values.
  Matrix(size_t rows, size_t cols) {
    _rowNum = rows;
    _colNum = cols;
    _storage.resize(rows * cols);
    for (size_t i = 0; i < rows * cols; i++) {
      _storage[i] = ((double)rand() / RAND_MAX);
    }
  }

  // ___________________________________________________________________________
  // Constructor.
  Matrix(size_t rows, size_t cols, float value) {
    _rowNum = rows;
    _colNum = cols;
    _storage.resize(rows * cols);
    for (size_t i = 0; i < rows * cols; i++) {
      _storage[i] = value;
    }
  }

  // ___________________________________________________________________________
  // Destructor.
  ~Matrix() {}

  // ___________________________________________________________________________
  // Print the Matrix.
  void print() {
    for (size_t i = 0; i < _rowNum * _colNum; i++) {
      if (i % _colNum == 0 and i > 0) {
        std::cout << std::endl;
      }
      std::cout << _storage[i] << " ";
    }
    std::cout << std::endl;
  }

  // ___________________________________________________________________________
  // Matrixmultiplication, return the product.
  Matrix mult(Matrix m) {
    assert(_colNum == m._rowNum);
    Matrix temp(_rowNum, m._colNum, 0);
    for (size_t i = 0; i < _rowNum; i++) {
      for (size_t k = 0; k < m._colNum; k++) {
        for (size_t j = 0; j < _colNum; j++) {
          temp._storage[i * temp._colNum + k] +=
              _storage[i * _colNum + j] * m._storage[j * m._colNum + k];
        }
      }
    }
    return temp;
  }

  // ___________________________________________________________________________
  Matrix operator*(Matrix m) {
    // TODO: implement this function.
  }

  // ___________________________________________________________________________
  // A Setter Function.
  void setValue(int row, int col, float value) {
    assert(row < _rowNum && col < _colNum);
    _storage[_colNum * row + col] = value;
  }

  // ___________________________________________________________________________
  // A Getter Function.
  float getValue(int row, int col) {
    assert(row < _rowNum && col < _colNum);
    return _storage[_colNum * row + col];
  }

  // ___________________________________________________________________________
  // Add a Value to every entry in the Matrix.
  void add(float x) {
    for (size_t i = 0; i < _rowNum * _colNum; i++) {
      _storage[i] += x;
    }
  }

  // ___________________________________________________________________________
  // Add one Matrix to another.
  void add(Matrix m) {
    assert(_rowNum == m._rowNum and _colNum == m._colNum);
    for (size_t i = 0; i < _rowNum * _colNum; i++) {
      _storage[i] += m._storage[i];
    }
  }

  // ___________________________________________________________________________
  void operator+(float value) {
    for (size_t i = 0; i < _rowNum * _colNum; i++) {
      _storage[i] += value;
    }
  }

  // ___________________________________________________________________________
  // Transpose the Matrix.
  Matrix t() {
    Matrix temp(_colNum, _rowNum, 0);
    for (size_t i = 0; i < _colNum * _rowNum; i++) {
      temp.setValue(i % _colNum, i / _colNum, _storage[i]);
    }
    return temp;
  }

  // ___________________________________________________________________________
  // Applies the sigmoid function.
  void sigmoid() {
    for (size_t i = 0; i < _rowNum * _colNum; i++) {
      _storage[i] = 1 / (1 + exp(-_storage[i]));
    }
  }

  // ___________________________________________________________________________
  // Applies the Derivative of the sigmoid function.
  void d_sigmoid() {
    for (size_t i = 0; i < _rowNum * _colNum; i++) {
      _storage[i] = pow(exp(-_storage[i]) / (1 + exp(-_storage[i])), 2);
    }
  }

  // The Rows of the Matrix.
  size_t _rowNum;

  // The Collums of the Matrix.
  size_t _colNum;
  // The Entries of the Matrix.
  std::vector<float> _storage;
};