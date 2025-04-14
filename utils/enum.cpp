#include "enum.h"

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