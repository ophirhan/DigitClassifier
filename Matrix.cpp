//
// Created by Ophir's laptop on 17/12/2019.
//
#include <iostream>
#include <cstring>
#include "Matrix.h"

#define NEW_MATRIX_ERROR ""
#define MATRIX_OPERATOR_ERROR ""



float* newMatrix(const int &length)
{
    auto* result = new(std::nothrow) float[length];
    if(result == nullptr)
    {
        std::cerr << NEW_MATRIX_ERROR << std::endl;
        exit(1);
    }
    return result;
}

Matrix::Matrix(const int &rows,const int &cols):
dims({rows, cols})
{
    matrix = newMatrix(length());
    for(int i = 0; i < length();i++)
    {
        matrix[i] = 0;
    }
}

int Matrix::length() const
{
    return getRows()*getCols();
}


Matrix::Matrix():
Matrix(1,1)
{
}

Matrix::Matrix(const Matrix &other):
matrix(newMatrix(other.length())), dims({other.getRows(), other.getCols()})
{
    for(int i = 0; i < other.length();i++)
    {
        matrix[i] = other.matrix[i];
    }
}

Matrix::~Matrix()
{
    delete [] (matrix);
}

int Matrix::getRows() const
{
    return dims.rows;
}

int Matrix::getCols() const
{
    return dims.cols;
}

Matrix& Matrix::vectorize()
{
    dims = {length(), 1};
    return *this;
}

void Matrix::plainPrint() const
{
    for(int i = 0; i < getCols(); i++)
    {
        for(int j = 0; j < getRows(); j++)
        {
            std::cout << (*this)(i, j) << " ";
        }
        std::cout << "\n";
    }
}

Matrix& Matrix::operator=(const Matrix &other)
{
    if(&other == this)
    {
        return *this;
    }
    if(other.length() != length())
    {
        delete [] matrix;
        matrix = newMatrix(other.length());
    }
    for(int i = 0; i< other.length();i++)
    {
        (*this)[i] = other[i];
    }
    dims = other.dims;
    return *this;
}

Matrix& Matrix::operator*(const Matrix &right) const
{
    if(getRows()!=right.getCols())
    {
        std::cerr << MATRIX_OPERATOR_ERROR << std::endl;
        exit(1);
    }
    auto* result = new Matrix(getRows(),right.getCols());
    for(int row = 0; row < result->getRows(); row++)
    {
        for(int col = 0; col < result->getCols(); col++)
        {
            for(int i = 0; i < getCols(); i++)
            {
                (*result)(row, col) += (*this)(row, i) * right(i, col);
            }
        }
    }
    return *result;
}

Matrix& Matrix::operator*(const float &scalar) const
{
    auto* result = new Matrix(*this);
    for(int i = 0; i < length(); i++)
    {
        (*result)[i] *= scalar;
    }
    return *result;
}

Matrix& operator*(const float &scalar, const Matrix &mat)
{
    return mat*scalar;
}

void printErrorAndExit(const std::string &msg)
{
    std::cerr << msg << std::endl;
    exit(1);
}

void checkSameDim(const Matrix &left, const Matrix &right)
{
    if(left.getRows() != right.getRows() || left.getCols() != right.getCols())
    {
        printErrorAndExit(MATRIX_OPERATOR_ERROR);
    }
}

Matrix& Matrix::operator+(const Matrix &other) const
{
    checkSameDim((*this), other);
    auto* result = new Matrix(*this);
    *result += other;
    return *result;
}

float& Matrix::operator()(int row, int col) const
{
    return (*this)[row*getCols() + col];
}

float& Matrix::operator[](int i) const
{
    return matrix[i];
}

Matrix& Matrix::operator+=(const Matrix &other)
{
    checkSameDim(*this, other);
    for(int i = 0; i < length(); i++)
    {
        (*this)[i] += other[i];
    }
    return *this;
}

std::istream& operator>>(std::istream& in, Matrix &mat)
{
    float inFloat;
    for (int i = 0; in.good(); i++)
    {
        if(i > mat.getCols()*mat.getRows())
        {
            printErrorAndExit(MATRIX_OPERATOR_ERROR);
        }
        in.read((char*) &inFloat, sizeof(float));
        mat[i] = inFloat;
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, Matrix &mat)
{
    out << "Image processed:" << "\n" << std::endl;
    for(int i = 0; i < mat.getCols(); i++)
    {
        for(int j = 0; j < mat.getRows(); j++)
        {
            if(mat(i,j) <= 0.1)
            {
                out << "  " << std::endl;
            }
            else
            {
                out << "**" << std::endl;
            }
        }
        out << "\n" << std::endl;
    }
    return out;
}