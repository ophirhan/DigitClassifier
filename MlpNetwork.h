//MlpNetwork.h

#ifndef MLPNETWORK_H
#define MLPNETWORK_H

#include "Matrix.h"
#include "Digit.h"
#include "Dense.h"

#define MLP_SIZE 4

const MatrixDims imgDims = {28, 28};
const MatrixDims weightsDims[] = {{128, 784}, {64, 128}, {20, 64}, {10, 20}};
const MatrixDims biasDims[]    = {{128, 1}, {64, 1}, {20, 1},  {10, 1}};

class MlpNetwork
{
public:
    MlpNetwork(const Matrix weights[], const Matrix biases[]);
    Digit operator()(const Matrix &);

private:
    const Dense denseOne;
    const Dense denseTwo;
    const Dense denseThree;
    const Dense denseFour;
};

#endif // MLPNETWORK_H

