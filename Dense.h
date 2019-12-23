//
// Created by Ophir's laptop on 19/12/2019.
//

#ifndef EX1_DENSE_H
#define EX1_DENSE_H

#include "Activation.h"

class Dense
{
public:
    Dense(const Matrix &weights, const Matrix &bias, ActivationType act);
    const Matrix& getWeights() const;
    const Matrix& getBias() const;
    const Activation& getActivation() const;
    const Matrix& operator()(const Matrix &matrix) const;
private:
    Matrix weights;
    Matrix bias;
    Activation act;
};

#endif //EX1_DENSE_H
