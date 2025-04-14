#pragma once
#include "../interfaces/layer.h"
#include "activation.cpp"
#include "layer.cpp"

DenseLayer::DenseLayer(size_t inputSize, size_t outputSize, LayerTypeEnum type, ActivationTypeEnum activation):
    Layer(inputSize, outputSize, type, activation)
{};
DenseLayer::DenseLayer(size_t inputSize, size_t outputSize):
    Layer(inputSize, outputSize)
{};

Matrix DenseLayer::forePropagation(const Matrix& input){
    Matrix output = weight*input;
    return output;
};