#pragma once
#include <iostream>
#include <vector>

#ifndef MATRIX_H
#define MATRIX_H

class Matrix{
private:
    const size_t rows,cols;
    std::vector<double> data;
public:
    Matrix(size_t rows, size_t cols, std::vector<double>& data);
    Matrix(size_t rows, size_t cols, double init_value);

    size_t numRows() const;
    size_t numCols() const;
    void print();

    double operator()(size_t row, size_t col) const;
    double& operator()(size_t row, size_t col);
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;

    Matrix T();
};

#endif