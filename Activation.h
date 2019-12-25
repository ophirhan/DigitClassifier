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

/**
 * @brief Activation object performs activation function on matrix.
 */
class Activation{
public:
    /**
     * @return ActivationType of the object.
     */
    ActivationType getActivationType() const;

    /**
     * @brief Performs the function on a given matrix
     * @param mat matrix to perform function on.
     * @return result of function.
     */
    Matrix operator()(const Matrix &mat) const;

    /**
     * Creates new Activation object.
     * @param act ActivationType of the wanted object.
     */
    Activation(ActivationType act);
private:
    /**
     * ActivationType of the object.
     */
    ActivationType act;
};

#endif //ACTIVATION_H
