#include <iostream>
#include <vector>
#include "implementations/matrix.cpp"

int main(){
    std::vector<double> a = {1,2,3,4,5,6,7,8,9};
    Matrix obj(3,3,a);
    obj.print();
}