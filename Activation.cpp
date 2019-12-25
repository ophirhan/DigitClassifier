//
// Created by Ophir's laptop on 19/12/2019.
//

#include <cmath>
#include "Activation.h"
#include "Matrix.h"

/**
 * @return ActivationType of the object.
 */
ActivationType Activation::getActivationType() const
{
    return act;
}


/**
 * Creates new Activation object.
 * @param act ActivationType of the wanted object.
 */
Activation::Activation(ActivationType act):
act(act)
{
}


/**
 * @brief Performs the function on a given matrix
 * @param mat matrix to perform function on.
 * @return result of function.
 */
Matrix Activation::operator()(const Matrix &mat) const
{
    Matrix result(mat);
    if(act == Relu)
    {
        for(int i = 0; i < mat.getCols()*mat.getRows(); i++)
        {
            if(mat[i] < 0)
            {
                result[i] = 0;
            }
        }
        return result;
    }
    else
    {
        float sum = 0;
        for(int i = 0; i < mat.getRows()*mat.getCols(); i++)
        {
            result[i] = std::exp(mat[i]);
            sum += result[i];
        }
        float scalar = 1/sum;
        return scalar*result;
    }
}
