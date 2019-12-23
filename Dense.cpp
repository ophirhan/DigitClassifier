//
// Created by Ophir's laptop on 19/12/2019.
//

#include <iostream>
#include "Matrix.h"
#include "Dense.h"
#include "Activation.h"

Dense::Dense(const Matrix &weights, const Matrix &bias, ActivationType act):
weights(weights), bias(bias), act(act)
{
}

const Matrix& Dense::getWeights() const
{
    return weights;
}

const Matrix& Dense::getBias() const
{
    return bias;
}

const Activation& Dense::getActivation() const
{
    return act;
}

const Matrix& Dense::operator()(const Matrix &mat) const
{
    Matrix result = weights*mat;
    result += bias;
    return act(result);
}
