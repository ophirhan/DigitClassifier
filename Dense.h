//
// Created by Ophir's laptop on 19/12/2019.
//

#ifndef EX1_DENSE_H
#define EX1_DENSE_H

#include "Activation.h"

/**
 * @brief Dense object for neural network project.
 */
class Dense
{
public:
    /**
     * @brief Creates new Dense object.
     * @param weights Matrix object.
     * @param bias Matrix object.
     * @param act Activation function.
     */
    Dense(const Matrix &weights, const Matrix &bias, ActivationType act);

    /**
     * @return Matrix weights.
     */
    const Matrix& getWeights() const;

    /**
     * @return Matrix bias.
     */
    const Matrix& getBias() const;

    /**
     * @return Activation object.
     */
    const Activation& getActivation() const;

    /**
     * performs all actions on a given matrix and returns result
     * @param matrix to perform on.
     * @return matrix result after all actions.
     */
    Matrix operator()(const Matrix &matrix) const;
private:

    /**
     * Matrix weights.
     */
    Matrix weights;


    /**
     * Matrix bias.
     */
    Matrix bias;

    /**
     * Activation object.
     */
    Activation act;
};

#endif //EX1_DENSE_H
