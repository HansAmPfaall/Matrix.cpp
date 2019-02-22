#pragma once
#include <iostream>
#include <vector>
#include "./Matrix.cpp"

class Matrix
{
  public:
    // Construct a new instance.
    Matrix(size_t rows, size_t cols);

    // Destructor.
    ~Matrix();

    void print();

    Matrix mult(Matrix m);

    void setValue(int row, int col, double value);

    Matrix transpose();

  private:
    // Size of the storage field.
    size_t _rowNum;
    size_t _colNum;
    std::vector<std::vector<double> > _storage;
};