#pragma once
#include "../interfaces/layer.h"
#include "activation.cpp"
#include "../utils/enum.cpp"

Layer::Layer(size_t inputSize, size_t outputSize, LayerTypeEnum type, ActivationTypeEnum activation,InitializationTypeEnum initialization):
    weight(outputSize, inputSize, 0),
    bias(outputSize, 1,0),
    weightGradient(outputSize, inputSize, 0),
    biasGradient(outputSize, 1,0),
    type(type),
    activation(activation),
    initialization(initialization)
{};

Layer::Layer(size_t inputSize, size_t outputSize):
    Layer(inputSize, outputSize, LayerTypeEnum::DENSE, ActivationTypeEnum::ReLU,InitializationTypeEnum::He)
{};

size_t Layer::getSize(){
    return weight.numRows();
};

void Layer::print(){
    std::cout<< layerEnumToString(type) << "," << getSize() << std::endl;
}
void Layer::printFull(){
    std::cout<< layerEnumToString(type) << "," << getSize() << std::endl;
    this->weight.print();
    this->bias.print();
}

