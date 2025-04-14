#pragma once
#include "matrix.h"

#ifndef ACTIVATION_H
#define ACTIVATION_H

struct Activation{
public:
    static void activate(Matrix& logits);
};

#endif


