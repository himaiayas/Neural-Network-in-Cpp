#pragma once
#include "matrix.h"
#include "activation.h"

#ifndef LAYER_H
#define LAYER_H

enum LayerTypeEnum{
    DENSE,
};
enum ActivationTypeEnum{
    ReLU
};



class Layer{
public:
    using ActivationFunction = void (*)(Matrix&);

    Matrix weight;
    Matrix bias;
    enum LayerTypeEnum type;
    ActivationFunction activate;

    Layer(size_t inputSize, size_t outputSize, LayerTypeEnum type, ActivationTypeEnum activation);
    Layer(size_t inputSize, size_t outputSize);

    void setActivation(ActivationTypeEnum activation);

    virtual Matrix forePropagation(const Matrix& input) = 0;


};


class DenseLayer : public Layer{
public:
    DenseLayer(size_t inputSize, size_t outputSize, LayerTypeEnum type, ActivationTypeEnum activation);
    DenseLayer(size_t inputSize, size_t outputSize);

    Matrix forePropagation(const Matrix& input) override;    
};


#endif