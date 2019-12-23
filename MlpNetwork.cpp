//
// Created by Ophir's laptop on 21/12/2019.
//
#include "MlpNetwork.h"
#include "Activation.h"


MlpNetwork::MlpNetwork(const Matrix *weights, const Matrix *biases) :
        denseOne(weights[0], biases[0], Relu),
        denseTwo(weights[1], biases[1], Relu),
        denseThree(weights[2], biases[2], Relu),
        denseFour(weights[3], biases[3], Softmax)
{
}

Digit MlpNetwork::operator()(const Matrix &mat) const
{
    Matrix result = denseFour(denseThree(denseTwo(denseOne(mat))));
    unsigned int value = 0;
    float maxProbability = result[0];
    for(int i = 1; i < result.getRows(); i++)
    {
        if(maxProbability < result[i])
        {
            value = i;
            maxProbability = result[i];
        }
    }
    return {value, maxProbability};
}

