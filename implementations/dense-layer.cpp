#pragma once
#include "../interfaces/layer.h"
#include "activation.cpp"
#include "layer.cpp"
#include "../utils/enum.h"
#include "../utils/switch-function.h"

DenseLayer::DenseLayer(size_t inputSize, size_t outputSize, LayerTypeEnum type, ActivationTypeEnum activation,InitializationTypeEnum initialization):
    Layer(inputSize, outputSize, type, activation,initialization)
{
    this->initializeWeight();
};
DenseLayer::DenseLayer(size_t inputSize, size_t outputSize):
    DenseLayer(inputSize, outputSize,LayerTypeEnum::DENSE, ActivationTypeEnum::ReLU,InitializationTypeEnum::He)
{};

void DenseLayer::initializeWeight(){
    InitializationFunction initialize = initializationEnumToFunction(initializationType);
    initialize(weight);
}

Matrix DenseLayer::forePropagation(const Matrix& input){
    ActivationFunction activate = activationEnumToFunctionActivate(activationType);
    Matrix output = weight*input + bias;
    activate(output);
    this->activation = output;
    
    if (this->next==nullptr) return output;
    else return this->next->forePropagation(output);
};

void DenseLayer::backPropagation(const Matrix& dC_by_dh){
    DerivativeFunction differentiate = activationEnumToFunctionDifferentiate(activationType);
    Matrix dC_by_dZ = dC_by_dh.dot(differentiate(this->activation));
}