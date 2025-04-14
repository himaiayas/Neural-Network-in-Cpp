#pragma once
#include "layer.h"


#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H



class NeuralNetwork{
public:

    size_t inputSize;
    size_t outputSize;
    Layer* first = nullptr;
    Layer* last = nullptr;

    NeuralNetwork(size_t inputSize, size_t outputSize);

    void print();

    void addLayer(Layer* layer);
    void addLayer(size_t size, LayerTypeEnum type, ActivationTypeEnum activation);
};

#endif