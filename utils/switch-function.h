#pragma once
#include "enum.h"
#include "../interfaces/layer.h"
#include <memory>
#include "../interfaces/matrix.h"

#ifndef SWITCHFUNC_H
#define SWITCHFUNC_H

std::string layerEnumToString(LayerTypeEnum type);
std::string activationEnumToString(ActivationTypeEnum type);
std::string initializationEnumToString(InitializationTypeEnum type);


using ActivationFunction = void (*)(Matrix&);
ActivationFunction activationEnumToFunctionActivate(ActivationTypeEnum type);
using DerivativeFunction = Matrix (*)(Matrix&);
DerivativeFunction activationEnumToFunctionDifferentiate(ActivationTypeEnum type);


using InitializationFunction= void (*)(Matrix&);
InitializationFunction initializationEnumToFunction(InitializationTypeEnum type);

#endif