#pragma once
#include "../interfaces/layer.h"
#include "dense-layer.cpp"
#include "activation.cpp"
#include "layer.cpp"
#include "../utils/enum.h"


OutputLayer::OutputLayer(size_t inputSize, size_t outputSize, LayerTypeEnum type, ActivationTypeEnum activation,InitializationTypeEnum initialization):
    DenseLayer(inputSize, outputSize, type, activation,initialization)
{};

OutputLayer::OutputLayer(size_t inputSize, size_t outputSize):
    OutputLayer(inputSize, outputSize,LayerTypeEnum::DENSE, ActivationTypeEnum::ReLU,InitializationTypeEnum::He)
{};

void OutputLayer::backPropagation(const Matrix& target){
    Matrix dC_by_dz = (this->activation-target).T();
    //if (this->prev!=nullptr);
};