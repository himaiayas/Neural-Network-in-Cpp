#pragma once
#include "../interfaces/activation.h"
#include <cmath>


struct NoneActivation : Activation{
public:
    static void activate(Matrix& logits){}
};

struct ReLU : Activation {
public:
    static void activate(Matrix& logits){
        for (size_t i=0; i<logits.numRows(); i++){
            logits(i,0)=std::max(0.0,logits(i,0));
        }
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