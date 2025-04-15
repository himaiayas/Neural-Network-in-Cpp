#pragma once
#include "matrix.h"
#include "layer.h"

#ifndef MATRIXINIT_H
#define MATRIXINIT_H

struct MatrixInitialization{
public:
    static void initializeWeight(Layer* layer);
};

#endif