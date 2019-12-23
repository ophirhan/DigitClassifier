// Matrix.h
#include<iostream>

#ifndef MATRIX_H
#define MATRIX_H


#define DRAWING_THRESHOLD 0.1
/**
 * @struct MatrixDims
 * @brief Matrix dimensions container
 */
typedef struct MatrixDims
{
    int rows, cols;
} MatrixDims;

class Matrix
{
public:
    Matrix(const int &rows, const int &cols);
    Matrix();
    Matrix(const Matrix &other);
    ~Matrix();
    int getRows() const;
    int getCols() const;
    Matrix& vectorize();
    void plainPrint() const;
    Matrix& operator=(const Matrix &);
    Matrix operator*(const Matrix &) const;
    Matrix operator*(const float &) const;
    friend Matrix operator*(const float &, const Matrix &);
    Matrix operator+(const Matrix &) const;
    Matrix& operator+=(const Matrix &);
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
