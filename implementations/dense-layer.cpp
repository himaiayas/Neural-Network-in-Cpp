#pragma once
#include "../interfaces/layer.h"
#include "activation.cpp"
#include "layer.cpp"
#include "../utils/enum.cpp"

DenseLayer::DenseLayer(size_t inputSize, size_t outputSize, LayerTypeEnum type, ActivationTypeEnum activation,InitializationTypeEnum initialization):
    Layer(inputSize, outputSize, type, activation,initialization)
{
    this->initializeWeight();
};
DenseLayer::DenseLayer(size_t inputSize, size_t outputSize):
    DenseLayer(inputSize, outputSize,LayerTypeEnum::DENSE, ActivationTypeEnum::ReLU,InitializationTypeEnum::He)
{};

void DenseLayer::initializeWeight(){
    InitializationFunction initialize = initializationEnumToFunction(initialization);
    initialize(weight);
}

Matrix DenseLayer::forePropagation(const Matrix& input){
    ActivationFunction activate = activationEnumToFunction(activation);
    Matrix output = weight*input + bias;
    activate(output);

    if (this->next==nullptr) return output;
    else return this->next->forePropagation(output);
};