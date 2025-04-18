#pragma once
#include "matrix.h"
#include "layer.h"
#include <ctime>
#include <random>

#ifndef MATRIXINIT_H
#define MATRIXINIT_H

struct InitGenerator{
public:
    static std::mt19937_64 generator;
};

struct MatrixInitialization{
public:
    static void initializeWeight(Layer* layer);
};

#endif