#include "Header.h"
#include <iostream>
#include <limits>
#include <cmath>

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    data.resize(rows, std::vector<int>(cols, 0));
}

int getPositiveNumber(const std::string& prompt) {
    int number;
    while (true) {
        std::cout << prompt;
        if (std::cin >> number && number > 0) {
            break;
        }
        else {
            std::cout << "Please enter a positive integer." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return number;
}

void Matrix::fillMatrix() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Enter element at position (" << i << ", " << j << "): ";

            while (!(std::cin >> data[i][j])) {
                std::cout << "Invalid input. Please enter a valid number: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
}

void Matrix::printMatrix() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

double Matrix::determinant() const {
    if (rows != cols) {
        throw std::runtime_error("Matrix must be square to find the determinant.");
    }

    if (rows == 2) {
        return data[0][0] * data[1][1] - data[0][1] * data[1][0];
    }

    double det = 0;
    for (int j = 0; j < cols; ++j) {
        Matrix submatrix(rows - 1, cols - 1);
        for (int i = 1; i < rows; ++i) {
            for (int k = 0; k < cols; ++k) {
                if (k < j) {
                    submatrix.data[i - 1][k] = data[i][k];
                }
                else if (k > j) {
                    submatrix.data[i - 1][k - 1] = data[i][k];
                }
            }
        }
        det += (j % 2 == 0 ? 1 : -1) * data[0][j] * submatrix.determinant();
    }

    return det;
}

Matrix Matrix::operator*(int multiplicand) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] * multiplicand;
        }
    }
    return result;
}

Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::runtime_error("Matrix dimensions must be the same for addition.");
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }

    return result;

}
Matrix Matrix::operator-(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::runtime_error("Matrix dimensions must be the same for subtraction.");
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }

    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows) {
        throw std::runtime_error("Number of columns in the first matrix must be equal to the number of rows\n in the second matrix for multiplication.");
    }

    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            int sum = 0;
            for (int k = 0; k < cols; ++k) {
                sum += data[i][k] * other.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }

    return result;
}

