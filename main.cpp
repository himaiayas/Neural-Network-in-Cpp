#include <iostream>
#include <vector>
#include "implementations/matrix.cpp"
#include "implementations/activation.cpp"
#include "implementations/layer.cpp"
#include "implementations/dense-layer.cpp"
#include "implementations/neural-network.cpp"

#include <random>
#include <cmath>

int main(){
    NeuralNetwork network(10,4);
    network.addHiddenLayer(6,LayerTypeEnum::DENSE,ActivationTypeEnum::ReLU,InitializationTypeEnum::He);
    network.addHiddenLayer(6,LayerTypeEnum::DENSE,ActivationTypeEnum::ReLU,InitializationTypeEnum::He);
    network.addOutputLayer();
    network.print();
    
}