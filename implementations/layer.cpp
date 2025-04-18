#pragma once
#include "../interfaces/layer.h"
#include "activation.cpp"
#include "../utils/enum.h"
#include "../utils/switch-function.h"

Layer::Layer(size_t inputSize, size_t outputSize, LayerTypeEnum type, ActivationTypeEnum activation,InitializationTypeEnum initialization):
    weight(outputSize, inputSize, 0),
    bias(outputSize, 1,0),
    weightGradient(outputSize, inputSize, 0),
    biasGradient(outputSize, 1,0),
    activation(outputSize,1,0),
    layerType(type),
    activationType(activation),
    initializationType(initialization)
{};

Layer::Layer(size_t inputSize, size_t outputSize):
    Layer(inputSize, outputSize, LayerTypeEnum::DENSE, ActivationTypeEnum::ReLU,InitializationTypeEnum::He)
{};

size_t Layer::getSize(){
    return weight.numRows();
};

void Layer::print(){
    std::cout<< layerEnumToString(layerType) << "," << getSize() << std::endl;
}
void Layer::printFull(){
    std::cout<< layerEnumToString(layerType) << "," << getSize() << std::endl;
    this->weight.print();
    this->bias.print();
}

