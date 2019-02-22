#pragma once
#include <iostream>
#include <vector>

class Matrix {
 public:
  // Constructor.
  Matrix(size_t rows, size_t cols);

  // Destructor.
  ~Matrix();

  // Print the Matrix.
  void print();

  // Matrixmultiplication, return the product.
  Matrix mult(Matrix m);

  // A Setter Function.
  void setValue(int row, int col, double value);

  // A Getter Function.
  double getValue(int row, int col);

  // Add a Value to every entry in the Matrix. 
  void add(double x);
  
  // Add one Matrix to another. Substract it if plus is false.
  void add(Matrix m, bool plus);

  // Transpose the Matrix.
  Matrix transpose();

  // The Rows of the Matrix.
  size_t _rowNum;

  // The Collums of the Matrix.
  size_t _colNum;

 private:
  // The Entries of the Matrix.
  std::vector<std::vector<double> > _storage;
};