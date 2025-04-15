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
    Matrix weightGradient;
    Matrix biasGradient;
    LayerTypeEnum type;
    ActivationTypeEnum activation;
    InitializationTypeEnum initialization;
    Layer* next = nullptr;
    Layer* prev = nullptr;


    Layer(size_t inputSize, size_t outputSize, LayerTypeEnum type, ActivationTypeEnum activation, InitializationTypeEnum initialization);
    Layer(size_t inputSize, size_t outputSize);

    size_t getSize();
    void print();
    void printFull();

    virtual void initializeWeight()=0;
    virtual Matrix forePropagation(const Matrix& input) = 0;



};


class DenseLayer : public Layer{
public:
    DenseLayer(size_t inputSize, size_t outputSize, LayerTypeEnum type, ActivationTypeEnum activation,InitializationTypeEnum initialization);
    DenseLayer(size_t inputSize, size_t outputSize);

    void initializeWeight() override;
    Matrix forePropagation(const Matrix& input) override;    
};


#endif