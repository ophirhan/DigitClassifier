//
// Created by Ophir's laptop on 21/12/2019.
//
#include "MlpNetwork.h"
#include "Activation.h"


/**
 * Creates new MlpNetwork object.
 * @param weights array of matrices for Dense objects within the object.
 * @param biases array of matrices for Dense objects within the object.
 */
MlpNetwork::MlpNetwork(const Matrix *weights, const Matrix *biases) :
        denseOne(weights[0], biases[0], Relu),
        denseTwo(weights[1], biases[1], Relu),
        denseThree(weights[2], biases[2], Relu),
        denseFour(weights[3], biases[3], Softmax)
{
}

/**
 * puts a given matrix through the network.
 * @return result of network operation.
 */
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

