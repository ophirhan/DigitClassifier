//
// Created by Ophir's laptop on 17/12/2019.
//
#include "Matrix.h"

#define ERROR "Error: "
#define INVALID_DIMS "Invalid matrix dimensions"
#define OUT_OF_BOUNDS "Index out of bounds"

/**
 * @breif Creates new matrix object.
 * @param rows how many rows in the matrix.
 * @param cols how many cols in the matrix.
 */
Matrix::Matrix(const int &rows, const int &cols) :
        dims({rows, cols})
{
    if (rows < 1 || cols < 1)
    {
        std::cerr << ERROR << INVALID_DIMS << std::endl;
        exit(EXIT_FAILURE);
    }
    matrix = new(std::nothrow) float[rows * cols];
    for (int i = 0; i < length(); i++)
    {
        matrix[i] = 0;
    }
}

int Matrix::length() const
{
    return getRows() * getCols();
}

/**
 * @breif Creates new matrix object with dims 1 by 1.
 */
Matrix::Matrix() :
        Matrix(1, 1)
{
}

/**
 * @breif Copy constructor for matrix object.
 * @param other
 */
Matrix::Matrix(const Matrix &other) :
        matrix(new(std::nothrow) float[other.length()]), dims({other.getRows(), other.getCols()})
{
    for (int i = 0; i < other.length(); i++)
    {
        matrix[i] = other.matrix[i];
    }
}

/**
 * @breif Destructor for Matrix object.
 */
Matrix::~Matrix()
{
    delete[] (matrix);
}

/**
 * @breif Getter for dims.rows.
 * @return number of rows in the matrix.
 */
int Matrix::getRows() const
{
    return dims.rows;
}

/**
 * @breif Getter for dims.cols.
 * @return number of cols in the matrix.
 */
int Matrix::getCols() const
{
    return dims.cols;
}

/**
 * @breif Turns a given matrix in vector shape.
 * @return given matrix as vector.
 */
Matrix &Matrix::vectorize()
{
    dims = {length(), 1};
    return *this;
}

/**
 * @breif Prints matrix elements, no return value.
 */
void Matrix::plainPrint() const
{
    for (int i = 0; i < getRows(); i++)
    {
        for (int j = 0; j < getCols(); j++)
        {
            std::cout << (*this)(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

/**
 * @breif Sets the matrix to be same as given matrix
 * @return a reference to the matrix.
 */
Matrix &Matrix::operator=(const Matrix &other)
{
    if (other.length() != length())
    {
        delete[] matrix;
        matrix = new(std::nothrow) float[other.length()];
    }
    dims = other.dims;
    for (int i = 0; i < other.length(); i++)
    {
        (*this)[i] = other[i];
    }
    return *this;
}

/**
 * @breif Matrix multiplication.
 * @return a matrix which is the result of matrix multiplication.
 */
Matrix Matrix::operator*(const Matrix &right) const
{
    if (getCols() != right.getRows())
    {
        std::cerr << ERROR << "Matrix multiplication not defined for these dimensions" << std::endl;
        exit(EXIT_FAILURE);
    }
    Matrix result(getRows(), right.getCols());
    for (int row = 0; row < result.getRows(); row++)
    {
        for (int col = 0; col < result.getCols(); col++)
        {
            for (int i = 0; i < getCols(); i++)
            {
                result(row, col) += (*this)(row, i) * right(i, col);
            }
        }
    }
    return result;
}

/**
 * @breif Matrix scalar multiplication.
 * @return the matrix multiplied by given scalar.
 */
Matrix Matrix::operator*(const float &scalar) const
{
    Matrix result(*this);
    for (int i = 0; i < length(); i++)
    {
        result[i] *= scalar;
    }
    return result;
}

/**
 * @breif Matrix scalar multiplication.
 * @return the matrix multiplied by given scalar.
 */
Matrix operator*(const float &scalar, const Matrix &mat)
{
    return mat * scalar;
}

/**
 * @breif Matrix addition.
 * @return the result of addition between this matrix and a given matrix.
 */
Matrix Matrix::operator+(const Matrix &other) const
{
    Matrix result(*this);
    result += other;
    return result;
}

/**
 * @return reference to cell in given indexes
 */
float &Matrix::operator()(const int row, const int col)
{
    if (row < 0 || col < 0 || col >= getCols() || row >= getRows())
    {
        std::cerr << ERROR << OUT_OF_BOUNDS << std::endl;
        exit(EXIT_FAILURE);
    }
    return (*this)[row * getCols() + col];
}

/**
 * @return reference to cell in given index
 */
float &Matrix::operator[](const int i)
{
    if (i < 0 || i >= length())
    {
        std::cerr << ERROR << OUT_OF_BOUNDS << std::endl;
        exit(EXIT_FAILURE);
    }
    return matrix[i];
}

/**
 * @return const reference to cell in given indexes
 */
const float &Matrix::operator()(const int row, const int col) const
{
    int index = row * getCols() + col;
    if (row < 0 || col < 0 || col >= getCols() || row >= getRows())
    {
        std::cerr << ERROR << OUT_OF_BOUNDS << std::endl;
        exit(EXIT_FAILURE);
    }
    return (*this)[index];
}

/**
 * @return const reference to cell in given index
 */
const float &Matrix::operator[](const int i) const
{
    if (i < 0 || i >= length())
    {
        std::cerr << ERROR << OUT_OF_BOUNDS << std::endl;
        exit(EXIT_FAILURE);
    }
    return matrix[i];
}

/**
 * @breif Sets the matrix to be the result of addition between it and a given matrix.
 * @return the matrix.
 */
Matrix &Matrix::operator+=(const Matrix &other)
{
    if ((*this).getRows() != other.getRows() || (*this).getCols() != other.getCols())
    {
        std::cerr << ERROR << INVALID_DIMS << std::endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < length(); i++)
    {
        (*this)[i] += other[i];
    }
    return *this;
}

/**
 * @brief reads a stream to a given matrix.
 * @param in stream to read
 * @param mat matrix to fill
 * @return given stream
 */
std::istream &operator>>(std::istream &in, Matrix &mat)
{
    if (in)
    {
        in.read((char *) mat.matrix, mat.getCols() * mat.getRows() * sizeof(float));
        if (!in.good())
        {
            std::cerr << ERROR << "stream length does not match matrix" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    return in;
}

/**
 * @brief outputs matrix content into a given output stream
 * @param out output stream
 * @param mat matrix to read
 * @return the given stream
 */
std::ostream &operator<<(std::ostream &out, Matrix &mat)
{
    for (int i = 0; i < mat.getRows(); i++)
    {
        for (int j = 0; j < mat.getCols(); j++)
        {
            if (mat(i, j) <= DRAWING_THRESHOLD)
            {
                out << "  ";
            }
            else
            {
                out << "**";
            }
        }
        out << std::endl;
    }
    return out;
}