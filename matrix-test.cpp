#include <iostream>
#include <vector>
#include "implementations/matrix.cpp"
#include <random>


int main(){
    // std::vector<double> v = {1,2,3,4,5,6,7,8};
    // Matrix m(2,4,v);
    // Matrix b = m*2;
    // b-=m;
    // b.print();

    double stddev = sqrt(2.0/4);
    std::mt19937_64 generator(time(0));
    std::normal_distribution<double> dist(0,stddev);
    std::cout<<dist(generator);
}