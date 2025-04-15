#pragma once
#include "enum.h"
#include "../implementations/activation.cpp"
#include "../implementations/matrix-initialization.cpp"

std::string layerEnumToString(LayerTypeEnum type){
    switch(type){
        case LayerTypeEnum::DENSE:
            return "Dense";
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

ActivationFunction activationEnumToFunction(ActivationTypeEnum type){
    switch(type){
        case ActivationTypeEnum::ReLU:
            return ReLU::activate;
        case ActivationTypeEnum::SoftMax:
            return SoftMax::activate;
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