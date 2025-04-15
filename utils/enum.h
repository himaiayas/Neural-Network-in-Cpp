#pragma once
#include "../interfaces/layer.h"
#include "../interfaces/matrix.h"

#ifndef ENUM_H
#define ENUM_H

enum LayerTypeEnum{
    DENSE,
};
enum ActivationTypeEnum{
    ReLU,
    SoftMax
};
enum InitializationTypeEnum{
    He,
    Xavier
};



std::string layerEnumToString(LayerTypeEnum type);
std::string activationEnumToString(ActivationTypeEnum type);
std::string initializationEnumToString(InitializationTypeEnum type);

using ActivationFunction = void (*)(Matrix&);
ActivationFunction activationEnumToFunction(ActivationTypeEnum type);

using InitializationFunction= void (*)(Matrix&);
InitializationFunction initializationEnumToFunction(InitializationTypeEnum type);


#endif