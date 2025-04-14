#pragma once
#include "matrix.h"
#include "activation.h"
#include "../utils/enum.h"

#ifndef LAYER_H
#define LAYER_H





class Layer{
public:
    using ActivationFunction = void (*)(Matrix&);

    Matrix weight;
    Matrix bias;
    enum LayerTypeEnum type;
    ActivationFunction activate;
    Layer* next = nullptr;
    Layer* prev = nullptr;

    Layer(size_t inputSize, size_t outputSize, LayerTypeEnum type, ActivationTypeEnum activation);
    Layer(size_t inputSize, size_t outputSize);

    void setActivation(ActivationTypeEnum activation);
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