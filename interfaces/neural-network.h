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
    bool hasOutputLayer = false;

    NeuralNetwork(size_t inputSize, size_t outputSize);

    void print();

    void addLayer(Layer* layer);
    void addHiddenLayer(size_t size, LayerTypeEnum type, ActivationTypeEnum activation,InitializationTypeEnum initialization);
    void addOutputLayer();
    void verifyOutputLayer();

    Matrix forePropagation(const Matrix& input);
};

#endif