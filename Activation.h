//Activation.h
#ifndef ACTIVATION_H
#define ACTIVATION_H

#include "Matrix.h"

/**
 * @enum ActivationType
 * @brief Indicator of activation function.
 */
enum ActivationType
{
    Relu,
    Softmax
};

class Activation{
public:
    ActivationType getActivationType() const;
    Matrix& operator()(const Matrix &mat) const;
    Activation(ActivationType act);
private:
    ActivationType act;
};

#endif //ACTIVATION_H
