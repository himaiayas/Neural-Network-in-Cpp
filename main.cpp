#include <iostream>
#include <vector>
#include "implementations/matrix.cpp"
#include "implementations/activation.cpp"
#include "implementations/layer.cpp"
#include "implementations/dense-layer.cpp"

int main(){
    std::vector<double> a = {-1,2,-3,-4,-5,6};
    Matrix obj(6,1,a);
    ReLU::activate(obj);
    obj.print();

    //DenseLayer myLayer(3,5,LayerTypeEnum::DENSE, ActivationTypeEnum::ReLU);
    
}