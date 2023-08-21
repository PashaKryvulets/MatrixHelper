#include <iostream>
#include <string>
#include "Header.h"

int main() {
    Matrix matrix1, matrix2;
    int multiplicand;

    while (true) {
        std::cout << "Matrix operations" << std::endl << std::endl;

        std::cout << "Matrix_1" << std::endl;
        int rows = getPositiveNumber("Enter the number of rows: ");
        int cols = getPositiveNumber("Enter the number of columns: ");
        std::cout << std::endl;

        matrix1 = Matrix(rows, cols);
        std::cout << "Enter values for matrix_1:" << std::endl;
        matrix1.fillMatrix();
        std::cout << std::endl;

        int choice;
        while (true) {
            std::cout << "Select operation:" << std::endl;
            std::cout << "1. Addition (+)" << std::endl;
            std::cout << "2. Subtraction (-)" << std::endl;
            std::cout << "3. Multiplication (*)" << std::endl;
            std::cout << "4. Multiply by a number" << std::endl;
            std::cout << "Enter choice: ";

            while (!(std::cin >> choice)) {
                std::cout << "Invalid input. Please enter a valid number: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            std::cout << std::endl << std::endl;

            if (choice >= 1 && choice <= 3) {
                std::cout << "Matrix_2" << std::endl;
                int rows2 = getPositiveNumber("Enter the number of rows: ");
                int cols2 = getPositiveNumber("Enter the number of columns: ");
                std::cout << std::endl;

                matrix2 = Matrix(rows2, cols2);
                std::cout << "Enter values for matrix_2:" << std::endl;
                matrix2.fillMatrix();
                std::cout << std::endl;
                break;
            }
            else if (choice == 4) {
                std::cout << "Enter multiplicand: ";
                while (!(std::cin >> multiplicand)) {
                    std::cout << "Invalid input. Please enter a valid number: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                break;
            }
            else {
                std::cout << "Invalid choice! Try again." << std::endl;
            }
        }

        std::cout << "Entered matrices:" << std::endl;
        std::cout << "Matrix_1:" << std::endl;
        matrix1.printMatrix();

        std::cout << "Matrix_2:" << std::endl;
        matrix2.printMatrix();
        std::cout << std::endl;

        Matrix result(rows, cols);

        switch (choice) {
        case 1:
            result = matrix1 + matrix2;
            std::cout << "Sum of matrices" << std::endl;
            result.printMatrix();
            break;
        case 2:
            result = matrix1 - matrix2;
            std::cout << "Subtraction of matrices:" << std::endl;
            result.printMatrix();
            break;
        case 3:
            try {
                result = matrix1 * matrix2;
                std::cout << "Multiplication of matrices:" << std::endl;
                result.printMatrix();
            }
            catch (const std::runtime_error& e) {
                std::wcout << "Error: " << e.what() << std::endl;
            }
            break;
        case 4:
            result = matrix1 * multiplicand;
            std::cout << "Multiplication of the matrix by " << multiplicand << ":" << std::endl;
            result.printMatrix();
            break;
        }
        std::cout << std::endl;

        std::string continuechoice;
        while (true) {
            std::cout << "Do you want to continue? ('Yes' or 'No'): ";
            std::cin >> continuechoice;

            if (continuechoice == "No") {
                std::cout << "Exiting." << std::endl;

                return 0;
            }
            else if (continuechoice == "Yes") {
                break;
            }
            else {
                std::cout << "Invalid input. Try again." << std::endl;
            }
        }
        std::cout << std::endl << std::endl;
    }

    return 0;
}