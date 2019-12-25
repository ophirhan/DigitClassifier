//
// Created by Ophir's laptop on 19/12/2019.
//

#include <iostream>
#include "Matrix.h"
#include "Dense.h"
#include "Activation.h"

/**
 * @brief Creates new Dense object.
 * @param weights Matrix object.
 * @param bias Matrix object.
 * @param act Activation function.
 */
Dense::Dense(const Matrix &weights, const Matrix &bias, ActivationType act):
weights(weights), bias(bias), act(act)
{
}

/**
 * @return Matrix weights.
 */
const Matrix& Dense::getWeights() const
{
    return weights;
}

/**
 * @return Matrix bias.
 */
const Matrix& Dense::getBias() const
{
    return bias;
}

/**
 * @return Activation object.
 */
const Activation& Dense::getActivation() const
{
    return act;
}

/**
 * performs all actions on a given matrix and returns result
 * @param matrix to perform on.
 * @return matrix result after all actions.
 */
Matrix Dense::operator()(const Matrix &mat) const
{
    Matrix result = weights*mat;
    result += bias;
    return act(result);
}
