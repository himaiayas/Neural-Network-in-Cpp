#include "enum.h"
#include "../implementations/activation.cpp"

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
        default:
            return "Other";
    };
}

ActivationFunction activationEnumToActivate(ActivationTypeEnum type){
    switch(type){
        case ActivationTypeEnum::ReLU:
            return ReLU::activate;
        default:
            throw std::bad_typeid();
    };
}