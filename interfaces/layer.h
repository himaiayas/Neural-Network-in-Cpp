#pragma once
#include "matrix.h"
#include "activation.h"
#include "../utils/enum.h"

#ifndef LAYER_H
#define LAYER_H





class Layer{
public:
    Matrix weight;
    Matrix bias;
    LayerTypeEnum type;
    ActivationTypeEnum activation;
    Layer* next = nullptr;
    Layer* prev = nullptr;

    Layer(size_t inputSize, size_t outputSize, LayerTypeEnum type, ActivationTypeEnum activation);
    Layer(size_t inputSize, size_t outputSize);

    size_t getSize();
    void print();

    virtual Matrix forePropagation(const Matrix& input) = 0;


};


class DenseLayer : public Layer{
public:
    DenseLayer(size_t inputSize, size_t outputSize, LayerTypeEnum type, ActivationTypeEnum activation);
    DenseLayer(size_t inputSize, size_t outputSize);

    Matrix forePropagation(const Matrix& input) override;    
};


#endif