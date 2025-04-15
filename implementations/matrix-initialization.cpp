#pragma once
#include "../interfaces/matrix-initialization.h"
#include "layer.cpp"
#include <random>
#include <cmath>

struct HeInitialization : MatrixInitialization{
public:
    static void initializeWeight(Matrix& weight){
        double stddev = sqrt(2.0/weight.numCols());
        std::default_random_engine generator;
        std::normal_distribution<double> dist(0,stddev);

        for (size_t i=0; i<weight.numRows(); i++){
            for (size_t j=0; j<weight.numCols(); j++){
                weight(i,j) = dist(generator);
            }
        }
    }
};

struct XavierInitialization : MatrixInitialization{
public:
    static void initializeWeight(Matrix& weight){
        double stddev = sqrt(2.0/(weight.numCols()+(weight.numRows())));
        std::default_random_engine generator;
        std::normal_distribution<double> dist(0,stddev);

        for (size_t i=0; i<weight.numRows(); i++){
            for (size_t j=0; j<weight.numCols(); j++){
                weight(i,j) = dist(generator);
            }
        }
    }
};