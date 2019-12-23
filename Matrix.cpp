//
// Created by Ophir's laptop on 17/12/2019.
//
#include "Matrix.h"

#define MATRIX_OPERATOR_ERROR "dashjk"


Matrix::Matrix(const int &rows,const int &cols):
dims({rows, cols})
{
    if(rows < 1 || cols < 1)
    {
        std::cerr << MATRIX_OPERATOR_ERROR << std::endl;
        exit(EXIT_FAILURE);
    }
    matrix = new(std::nothrow) float[rows*cols];
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
matrix(new(std::nothrow) float[other.length()]), dims({other.getRows(), other.getCols()})
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
    for(int i = 0; i < getRows(); i++)
    {
        for(int j = 0; j < getCols(); j++)
        {
            std::cout << (*this)(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

Matrix& Matrix::operator=(const Matrix &other)
{
    if(other.length() != length())
    {
        delete [] matrix;
        matrix = new(std::nothrow) float[other.length()];
    }
    dims = other.dims;
    for(int i = 0; i< other.length();i++)
    {
        (*this)[i] = other[i];
    }

    return *this;
}

Matrix Matrix::operator*(const Matrix &right) const
{
    if(getCols() != right.getRows())
    {
        std::cerr << MATRIX_OPERATOR_ERROR << std::endl;
        exit(EXIT_FAILURE);
    }
    Matrix result(getRows(), right.getCols());
    for(int row = 0; row < result.getRows(); row++)
    {
        for(int col = 0; col < result.getCols(); col++)
        {
            for(int i = 0; i < getCols(); i++)
            {
                result(row, col) += (*this)(row, i) * right(i, col);
            }
        }
    }
    return result;
}

Matrix Matrix::operator*(const float &scalar) const
{
    Matrix result(*this);
    for(int i = 0; i < length(); i++)
    {
        result[i] *= scalar;
    }
    return result;
}

Matrix operator*(const float &scalar, const Matrix &mat)
{
    return mat*scalar;
}

Matrix Matrix::operator+(const Matrix &other) const
{
    Matrix result(*this);
    result += other;
    return result;
}

float& Matrix::operator()(const int row,const int col)
{
    int index = row*getCols() + col;
    if(row < 0 || col < 0 || col >= getCols() || row >= getRows())
    {
        std::cerr << "6855675587" << std::endl;
        exit(EXIT_FAILURE);
    }
    return (*this)[index];
}

float& Matrix::operator[](const int i)
{
    if(i < 0 || i >= length())
    {
        std::cerr << "9" << std::endl;
        exit(EXIT_FAILURE);
    }
    return matrix[i];
}

const float& Matrix::operator()(const int row,const int col) const
{
    int index = row*getCols() + col;
    if(row < 0 || col < 0 || col >= getCols() || row >= getRows())
    {
        std::cerr << "2" << std::endl;
        exit(EXIT_FAILURE);
    }
    return (*this)[index];
}

const float& Matrix::operator[](const int i) const
{
    if(i < 0 || i >= length())
    {
        std::cerr << MATRIX_OPERATOR_ERROR << std::endl;
        exit(EXIT_FAILURE);
    }
    return matrix[i];
}

Matrix& Matrix::operator+=(const Matrix &other)
{
    if((*this).getRows() != other.getRows() || (*this).getCols() != other.getCols())
    {
        std::cerr << MATRIX_OPERATOR_ERROR << std::endl;
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < length(); i++)
    {
        (*this)[i] += other[i];
    }
    return *this;
}

std::istream& operator>>(std::istream &in, Matrix &mat)
{
    if(in)
    {
        in.read((char*) mat.matrix, mat.getCols()*mat.getRows()* sizeof(float));
        if(!in.good())
        {
            std::cerr << MATRIX_OPERATOR_ERROR << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, Matrix &mat)
{
    for(int i = 0; i < mat.getRows(); i++)
    {
        for(int j = 0; j < mat.getCols(); j++)
        {
            if(mat(i,j) <= DRAWING_THRESHOLD)
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