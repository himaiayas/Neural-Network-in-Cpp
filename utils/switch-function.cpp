#pragma once
#include "enum.h"
#include "switch-function.h"
#include "../implementations/activation.cpp"
#include "../implementations/matrix-initialization.cpp"
#include <memory>

std::string layerEnumToString(LayerTypeEnum type){
    switch(type){
        case LayerTypeEnum::DENSE:
            return "Dense";
        case LayerTypeEnum::OUTPUT:
            return "Output";
        default:
            return "Other";
    };
}
std::string activationEnumToString(ActivationTypeEnum type){
    switch(type){
        case ActivationTypeEnum::ReLU:
            return "ReLU";
        case ActivationTypeEnum::SoftMax:
            return "SoftMax";
        default:
            return "Other";
    };
}
std::string initializationEnumToString(InitializationTypeEnum type){
    switch(type){
        case InitializationTypeEnum::He:
            return "He";
        default:
            return "Other";
    };
}



ActivationFunction activationEnumToFunctionActivate(ActivationTypeEnum type){
    switch(type){
        case ActivationTypeEnum::ReLU:
            return ReLU::activate;
        case ActivationTypeEnum::SoftMax:
            return SoftMax::activate;
        default:
            throw std::bad_typeid();
    };
}

DerivativeFunction activationEnumToFunctionDifferentiate(ActivationTypeEnum type){
    switch(type){
        case ActivationTypeEnum::ReLU:
            return ReLU::differentiate;
        case ActivationTypeEnum::SoftMax:
            return SoftMax::differentiate;
        default:
            throw std::bad_typeid();
    };
}

InitializationFunction initializationEnumToFunction(InitializationTypeEnum type){
    switch(type){
        case InitializationTypeEnum::He:
            return HeInitialization::initializeWeight;
        case InitializationTypeEnum::Xavier:
            return XavierInitialization::initializeWeight;
        default:
            throw std::bad_typeid();
    };
}