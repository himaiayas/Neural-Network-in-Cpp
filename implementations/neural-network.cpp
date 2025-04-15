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
        cur->printFull();
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

void NeuralNetwork::addHiddenLayer(size_t size, LayerTypeEnum type, ActivationTypeEnum activation,InitializationTypeEnum initialization){
    size_t layerInputSize;
    if (first==nullptr) {
        layerInputSize = inputSize;
    } else {
        layerInputSize = last->getSize();
    }

    Layer* layer;
    switch(type){
        case LayerTypeEnum::DENSE:
            layer = new DenseLayer(layerInputSize, size, type, activation, initialization);
            break;
    };

    addLayer(layer);
}


void NeuralNetwork::addOutputLayer(){
    addHiddenLayer(outputSize, LayerTypeEnum::DENSE, ActivationTypeEnum::SoftMax, InitializationTypeEnum::Xavier);
}

void NeuralNetwork::verifyOutputLayer(){
    if (!hasOutputLayer) throw std::exception();
}

Matrix NeuralNetwork::forePropagation(const Matrix& input){
    return this->first->forePropagation(input);
}
