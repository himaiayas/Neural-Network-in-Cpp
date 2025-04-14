#pragma once
#include "layer.cpp"
#include "dense-layer.cpp"
#include "../interfaces/neural-network.h"

NeuralNetwork::NeuralNetwork(size_t inputSize, size_t outputSize):
    inputSize(inputSize),
    outputSize(outputSize)
{};

void NeuralNetwork::print(){
    std::cout<<"Input "<<inputSize<<std::endl;

    Layer* cur = first;
    while(cur!=nullptr){
        cur->print();
        cur = cur->next;
    }

    if (outputSize!=last->getSize()){
        std::cout<<"Output size not match with lastest output layer"<<std::endl;
    }
};

void NeuralNetwork::addLayer(Layer* layer){
    if (first==nullptr){
        first = layer;
        last = layer;
    }
    else{
        layer->prev = last;
        last->next = layer;
        last = layer;
    }
};

void NeuralNetwork::addLayer(size_t size, LayerTypeEnum type, ActivationTypeEnum activation){
    size_t layerInputSize;
    if (first==nullptr) {
        layerInputSize = inputSize;
    } else {
        layerInputSize = last->getSize();
    }

    Layer* layer;
    switch(type){
        case LayerTypeEnum::DENSE:
            layer = new DenseLayer(layerInputSize, size, type, activation);
            break;
    };

    addLayer(layer);
}
