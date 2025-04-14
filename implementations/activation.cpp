#pragma once
#include "../interfaces/activation.h"


struct ReLU : Activation {
public:
    static void activate(Matrix& logits){
        for (size_t i=0; i<logits.numRows(); i++){
            logits(i,0)=std::max(0.0,logits(i,0));
        }
    }
};