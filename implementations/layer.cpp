#pragma once
#include "../interfaces/layer.h"
#include "activation.cpp"
#include "../utils/enum.cpp"

Layer::Layer(size_t inputSize, size_t outputSize, LayerTypeEnum type, ActivationTypeEnum activation):
    weight(outputSize, inputSize, 1),
    bias(outputSize, 1,1),
    type(type),
    activation(activation)
{};

Layer::Layer(size_t inputSize, size_t outputSize):
    weight(outputSize, inputSize, 1),
    bias(outputSize, 1,1),
    type(LayerTypeEnum::DENSE),
    activation(ActivationTypeEnum::ReLU)
{};

size_t Layer::getSize(){
    return weight.numRows();
};

void Layer::print(){
    std::cout<< layerEnumToString(type) << "," << getSize() << std::endl;
}
