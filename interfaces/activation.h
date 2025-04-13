#pragma once
#include "matrix.h"

#ifndef ACTIVATION_H
#define ACTIVATION_H

class Activation{
public:
    Matrix static activate(const Matrix& logits);
}

#endif