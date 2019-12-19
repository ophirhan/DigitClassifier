//
// Created by Ophir's laptop on 19/12/2019.
//

#include <cmath>
#include "Activation.h"
#include "Matrix.h"

ActivationType Activation::getActivationType() const
{
    return act;
}

Activation::Activation(ActivationType act):
act(act)
{
}

Matrix& Activation::operator()(const Matrix &mat) const
{
    auto* result  = new Matrix(mat);
    if(act == Relu)
    {
        for(int i = 0; i < mat.length(); i++)
        {
            if(mat[i] < 0)
            {
                (*result)[i] = 0;
            }
        }
        return *result;
    }
    else
    {
        float sum = 0;
        for(int i = 0; i < mat.length(); i++)
        {
            mat[i] = std::exp(mat[i]);
            sum += mat[i];
        }
        float scalar = 1/sum;
        *result = scalar*mat;
    }
}
