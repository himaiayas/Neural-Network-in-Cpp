#include <iostream>
#include <vector>
#include "implementations/matrix.cpp"
#include "implementations/activation.cpp"
#include "implementations/layer.cpp"
#include "implementations/dense-layer.cpp"
#include "implementations/output-layer.cpp"
#include "implementations/neural-network.cpp"
#include "utils/switch-function.cpp"

#include <random>
#include <cmath>

int main(){
    NeuralNetwork network(10,4);
    network.addHiddenLayer(6,LayerTypeEnum::DENSE,ActivationTypeEnum::ReLU,InitializationTypeEnum::He);
    network.addHiddenLayer(6,LayerTypeEnum::DENSE,ActivationTypeEnum::ReLU,InitializationTypeEnum::He);
    network.addOutputLayer();

    std::vector<double> v = {1,1,2,3,0,1,2,5,3,2};
    Matrix input(10,1,v);
    Matrix output = network.forePropagation(input);
    network.print();
    std::cout<<"output\n";
    output.print();

    std::vector<double> y = {1,0,0,0};
    Matrix Y(4,1,y);

    std::cout<<"last activation\n";
    network.last->printFull();

    std::cout<<"Y\n";
    Y.print();

    network.last->backPropagation(Y);
    
    
    
}