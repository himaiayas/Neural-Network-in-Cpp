#pragma once
#include "../interfaces/activation.h"
#include <cmath>


void Activation::activate(Matrix& logits){};
Matrix Activation::differentiate(Matrix& activation){
    return activation;
};

struct ReLU : Activation {
public:
    static void activate(Matrix& logits){
        for (size_t i=0; i<logits.numRows(); i++){
            logits(i,0)=std::max(0.0,logits(i,0));
        }
    }

    static Matrix differentiate(Matrix& activation){
        Matrix result(1, activation.numRows(),0);
        for (size_t i=0; i<activation.numRows(); i++){
            if (activation(i,0)>0) result(0,i)=1;
        }
        return result;
    }
};

struct SoftMax : Activation {
public :
    static void activate(Matrix& logits){
        double sumExp=0;
        for (size_t i=0; i<logits.numRows(); i++){
            sumExp+=exp(logits(i,0));
        }
        for (size_t i=0; i<logits.numRows(); i++){
            logits(i,0) = exp(logits(i,0))/sumExp;
        }
    }
};