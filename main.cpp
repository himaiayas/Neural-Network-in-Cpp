#include <iostream>
#include <vector>
#include "implementations/matrix.cpp"
#include "implementations/activation.cpp"
#include "implementations/layer.cpp"
#include "implementations/dense-layer.cpp"
#include "implementations/neural-network.cpp"

int main(){
    NeuralNetwork network(10,4);
    network.addLayer(6,LayerTypeEnum::DENSE,ActivationTypeEnum::ReLU);
    network.addLayer(4,LayerTypeEnum::DENSE,ActivationTypeEnum::ReLU);
    network.print();
    
}