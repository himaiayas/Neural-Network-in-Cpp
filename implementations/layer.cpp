#pragma once
#include "../interfaces/layer.h"
#include "activation.cpp"
#include "../utils/enum.cpp"

Layer::Layer(size_t inputSize, size_t outputSize, LayerTypeEnum type, ActivationTypeEnum activation):
    weight(outputSize, inputSize, 1),
    bias(outputSize, 1,1),
    type(type)
{
    setActivation(activation);
};

Layer::Layer(size_t inputSize, size_t outputSize):
    weight(outputSize, inputSize, 1),
    bias(outputSize, 1,1),
    type(LayerTypeEnum::DENSE),
    activate(ReLU::activate)
{};

void Layer::setActivation(ActivationTypeEnum activation){
    switch(activation){
        case ActivationTypeEnum::ReLU:
            this->activate = ReLU::activate;
            break;
    };
};

size_t Layer::getSize(){
    return weight.numRows();
};

void Layer::print(){
    std::cout<< layerEnumToString(type) << "," << getSize() << std::endl;
}
