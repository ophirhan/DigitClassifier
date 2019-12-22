//
// Created by Ophir's laptop on 21/12/2019.
//

#include <new>
#include <iostream>
#include "MlpNetwork.h"
#include "Activation.h"

#define NUMBER_OF_DIGITS (10)
#define WRONG_MATRIX_SIZE "Error: Wrong matrix size"

MlpNetwork::MlpNetwork(const Matrix *weights, const Matrix *biases) :
        denseOne(weights[0], biases[0], Relu),
        denseTwo(weights[1], biases[1], Relu),
        denseThree(weights[2], biases[2], Relu),
        denseFour(weights[3], biases[3], Softmax)
{
}

Digit MlpNetwork::operator()(const Matrix &mat)
{
    Matrix result = denseFour(denseThree(denseTwo(denseOne(mat))));
    if(result.getRows()*result.getCols() != NUMBER_OF_DIGITS)
    {
        std::cerr << WRONG_MATRIX_SIZE << std::endl;
        exit(EXIT_FAILURE);
    }
    unsigned int value = 0;
    float maxProbability = result[0];
    for(int i = 1; i < NUMBER_OF_DIGITS; i++)
    {
        if(maxProbability < result[i])
        {
            value = i;
            maxProbability = result[i];
        }
    }
    return {value, maxProbability};
}

