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
 * @breif Matrix class for neural network project.
 */
class Matrix
{
public:
    /**
     * @breif Creates new matrix object.
     * @param rows how many rows in the matrix.
     * @param cols how many cols in the matrix.
     */
    Matrix(const int &rows, const int &cols);

    /**
     * @breif Creates new matrix object with dims 1 by 1.
     */
    Matrix();

    /**
     * @breif Copy constructor for matrix object.
     * @param other
     */
    Matrix(const Matrix &other);

    /**
     * @breif Destructor for Matrix object.
     */
    ~Matrix();

    /**
     * @breif Getter for dims.rows.
     * @return number of rows in the matrix.
     */
    int getRows() const;

    /**
     * @breif Getter for dims.cols.
     * @return number of cols in the matrix.
     */
    int getCols() const;

    /**
     * @breif Turns a given matrix in vector shape.
     * @return given matrix as vector.
     */
    Matrix &vectorize();

    /**
     * @breif Prints matrix elements, no return value.
     */
    void plainPrint() const;

    /**
     * @breif Sets the matrix to be same as given matrix
     * @return a reference to the matrix.
     */
    Matrix &operator=(const Matrix &);

    /**
     * @breif Matrix multiplication.
     * @return a matrix which is the result of matrix multiplication.
     */
    Matrix operator*(const Matrix &) const;

    /**
     * @breif Matrix scalar multiplication.
     * @return the matrix multiplied by given scalar.
     */
    Matrix operator*(const float &) const;

    /**
     * @breif Matrix scalar multiplication.
     * @return the matrix multiplied by given scalar.
     */
    friend Matrix operator*(const float &, const Matrix &);

    /**
     * @breif Matrix addition.
     * @return the result of addition between this matrix and a given matrix.
     */
    Matrix operator+(const Matrix &) const;

    /**
     * @breif Sets the matrix to be the result of addition between it and a given matrix.
     * @return the matrix.
     */
    Matrix &operator+=(const Matrix &);

    /**
     * @breif Returns the float in the corresponding cell of the matrix.
     * @return float
     */
    float &operator()(int, int);


    /**
     * @breif Returns the float in the corresponding cell of the matrix.
     * @return float
     */
    float &operator[](int);


    /**
     * @breif Returns the float in the corresponding cell of the matrix.
     * @return float
     */
    const float &operator()(int, int) const;

    /**
     * @breif Returns the float in the corresponding cell of the matrix.
     * @return float
     */
    const float &operator[](int) const;

    /**
     * @breif Reads an input stream into a matrix.
     * @param in the stream.
     * @param mat the matrix.
     * @return the stream.
     */
    friend std::istream &operator>>(std::istream &in, Matrix &mat);

    /**
     * @breif Outputs the content of a matrix to a given stream.
     * @param out the stream.
     * @param mat the matrix to output
     * @return the stream.
     */
    friend std::ostream &operator<<(std::ostream &out, Matrix &mat);


private:
    /**
     * @return the amount of cells in the matrix.
     */
    int length() const;

    /**
     * @breif pointer to the first cell in the matrix.
     */
    float *matrix;

    /**
     * @breif Struct with how many rows and columns in the matrix.
     */
    MatrixDims dims;
};

#endif //MATRIX_H
