#pragma once
#include "../interfaces/layer.h"
#include "activation.cpp"

Layer::Layer(size_t inputSize, size_t outputSize, LayerTypeEnum type, ActivationTypeEnum activation):
    weight(inputSize, outputSize, 1),
    bias(outputSize, 1,1),
    type(type)
{
    setActivation(activation);
};

Layer::Layer(size_t inputSize, size_t outputSize):
    weight(inputSize, outputSize, 1),
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