#ifndef ENUM_H
#define ENUM_H

enum LayerTypeEnum{
    DENSE,
};
enum ActivationTypeEnum{
    ReLU
};



std::string layerEnumToString(LayerTypeEnum type);
std::string activationEnumToString(ActivationTypeEnum type);

using ActivationFunction = void (*)(Matrix&);
ActivationFunction activationEnumToActivate(ActivationTypeEnum type);


#endif