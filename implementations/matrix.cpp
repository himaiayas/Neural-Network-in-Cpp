#pragma once
#include <iostream>
#include <vector>
#include "../interfaces/matrix.h"


Matrix::Matrix(size_t rows, size_t cols, std::vector<double>& data):
        rows(rows), 
        cols(cols),
        data(data)
    {
        if (data.size()!=rows*cols){
            throw std::length_error("Length of vector does not match matrix");
        } 
    }

Matrix::Matrix(size_t rows, size_t cols, double init_value):
        rows(rows),
        cols(cols),
        data(rows*cols, init_value)
    {}


double Matrix::operator()(size_t row, size_t col) const {
        if (rows<row || cols<col){
            throw std::length_error("() Operation: Out of range");
        }
        return data[row*cols + col];
    }

double& Matrix::operator()(size_t row, size_t col) {
        if (rows<row || cols<col){
            throw std::length_error("() Operation: Out of range");
        }
        return data[row*cols + col];
    }

Matrix Matrix::operator+(const Matrix& other) const {
        if (rows!=other.numRows() || cols!=other.numCols() ){
            throw std::length_error("+ Operation: Size not match");
        }
        Matrix result(rows,cols,0);
        for (size_t i=0; i<rows; i++){
            for (size_t j=0; j<cols; j++){
                result(i,j) = (*this)(i,j) + other(i,j);
            }
        }
        return result;
    }
Matrix Matrix::operator-(const Matrix& other) const{
        if (rows!=other.numRows() || cols!=other.numCols() ){
            throw std::length_error("- Operation: Size not match");
        }
        Matrix result(rows,cols,0);
        for (size_t i=0; i<rows; i++){
            for (size_t j=0; j<cols; j++){
                result(i,j) = (*this)(i,j) - other(i,j);
            }
        }
        return result;
    }

Matrix Matrix::operator*(const Matrix& other) const{
        if (cols!=other.numRows()){
            throw std::length_error("* Operation: Size not match");
        }
        Matrix result(rows,other.numCols(),0);
        for (size_t i=0; i<rows; i++){
            for (size_t j=0; j<other.numCols(); j++){
                double sum = 0;
                for (size_t k=0; k<cols; k++){
                    sum+=(*this)(i,k) * other(k,j);
                }
                result(i,j) = sum;
            }
        }
        return result;
    }

size_t Matrix::numRows() const {
        return this->rows;
    }
size_t Matrix::numCols() const{
        return this->cols;
    }

void Matrix::print(){
        for (size_t i=0; i<rows; i++){
            for (size_t j=0; j<cols; j++){
                std::cout<<(*this)(i,j)<<" ";
            }
            std::cout<<std::endl;
        }
    }

Matrix Matrix::T(){
        Matrix result(cols,rows,0);
        for (size_t i=0; i<rows; i++){
            for (size_t j=0; j<cols; j++){
                result(j,i)=(*this)(i,j);
            }
        }
        return result;
    }
