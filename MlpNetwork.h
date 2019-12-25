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

/**
 * MlpNetwork object for neural network project.
 */
class MlpNetwork
{
public:
    /**
     * Creates new MlpNetwork object.
     * @param weights array of matrices for Dense objects within the object.
     * @param biases array of matrices for Dense objects within the object.
     */
    MlpNetwork(const Matrix weights[], const Matrix biases[]);

    /**
     * puts a given matrix through the network.
     * @return result of network operation.
     */
    Digit operator()(const Matrix &) const;

private:

    /**
     * Dense one of the network.
     */
    const Dense denseOne;
    /**
     * Dense two of the network.
     */
    const Dense denseTwo;
    /**
     * Dense three of the network.
     */
    const Dense denseThree;
    /**
     * Dense four of the network.
     */
    const Dense denseFour;
};

#endif // MLPNETWORK_H

