// Matrix.h
#include<iostream>

#ifndef MATRIX_H
#define MATRIX_H


#define DRAWING_THRESHOLD (0.1f)
/**
 * @struct MatrixDims
 * @brief Matrix dimensions container
 */
typedef struct MatrixDims
{
    int rows, cols;
} MatrixDims;

/**
 * Matrix class for neural network project.
 */
class Matrix
{
public:
    /**
     * Creates new matrix object.
     * @param rows how many rows in the matrix.
     * @param cols how many cols in the matrix.
     */
    Matrix(const int &rows, const int &cols);

    /**
     * Creates new matrix object with dims 1 by 1.
     */
    Matrix();

    /**
     * Copy constructor for matrix object.
     * @param other
     */
    Matrix(const Matrix &other);

    /**
     * Destructor for Matrix object.
     */
    ~Matrix();

    /**
     * Getter for dims.rows.
     * @return number of rows in the matrix.
     */
    int getRows() const;

    /**
     * Getter for dims.cols.
     * @return number of cols in the matrix.
     */
    int getCols() const;

    /**
     * Turns a given matrix in vector shape.
     * @return given matrix as vector.
     */
    Matrix& vectorize();

    /**
     * Prints matrix elements, no return value.
     */
    void plainPrint() const;

    /**
     * Sets the matrix to be same as given matrix
     * @return a reference to the matrix.
     */
    Matrix& operator=(const Matrix &);

    /**
     * Matrix multiplication.
     * @return a matrix which is the result of matrix multiplication.
     */
    Matrix operator*(const Matrix &) const;

    /**
     * Matrix scalar multiplication.
     * @return the matrix multiplied by given scalar.
     */
    Matrix operator*(const float &) const;

    /**
     * Matrix scalar multiplication.
     * @return the matrix multiplied by given scalar.
     */
    friend Matrix operator*(const float &, const Matrix &);

    /**
     * Matrix addition.
     * @return the result of addition between this matrix and a given matrix.
     */
    Matrix operator+(const Matrix &) const;

    /**
     * Sets the matrix to be the result of addition between it and a given matrix.
     * @return the matrix.
     */
    Matrix& operator+=(const Matrix &);

    /**
     * Returns the float in the corresponding cell of the matrix.
     * @return
     */
    float& operator()(int, int);

    float& operator[](int);

    const float& operator()(int, int) const;

    const float& operator[](int) const;

    friend std::istream& operator>>(std::istream &in, Matrix &mat);

    friend std::ostream& operator<<(std::ostream &out, Matrix &mat);


private:
    int length() const;
    float *matrix;
    MatrixDims dims;
};

#endif //MATRIX_H
