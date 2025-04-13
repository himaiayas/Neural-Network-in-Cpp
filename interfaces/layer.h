#pragma once
#include "matrix.h"

#ifndef LAYER_H
#define LAYER_H

enum LayerTypeEnum{
    DENSE,
}



class Layer{
public:
    Matrix weight;
    Matrix bias;
    enum LayerTypeEnum type = LayerTypeEnum::DENSE;
    

    
}

#endif