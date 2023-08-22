//#ifndef MATRIX_H
//#define MATRIX_H

#pragma once

#include <vector>
#include <string>

class Matrix {
private:
    int rows;
    int cols;
    std::vector<std::vector<int>> data;

public:
    Matrix() : rows(0), cols(0) {};
    Matrix(int rows, int cols);
    void fillMatrix();
    void printMatrix() const;
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    Matrix operator*(int multiplicand) const;
};


int getPositiveNumber(const std::string& prompt);
//#endif // MATRIX_H
