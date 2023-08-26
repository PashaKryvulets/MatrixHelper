#include <iostream>
#include <string>
#include <limits>
#include "Header.h"

int main() {
    Matrix matrix1, matrix2;
    int multiplicand = 0;

    while (true) {
        std::cout << "Matrix operations" << std::endl << std::endl;

        std::cout << "Matrix_1" << std::endl;
        int rows1 = getPositiveNumber("Enter the number of rows: ");
        int cols1 = getPositiveNumber("Enter the number of columns: ");
        std::cout << std::endl;

        matrix1 = Matrix(rows1, cols1);
        std::cout << "Enter values for matrix_1:" << std::endl;
        matrix1.fillMatrix();
        std::cout << std::endl;

        
            std::cout << "Select operation:" << std::endl;
            std::cout << "1. Addition (+)" << std::endl;
            std::cout << "2. Subtraction (-)" << std::endl;
            std::cout << "3. Multiplication (*)" << std::endl;
            std::cout << "4. Multiply by a number" << std::endl;
            std::cout << "5. Find determinant" << std::endl;
                std::cout << "Enter choice: ";
            
            int choice;
            while (true) {
                std::cout << "Enter choice: ";
            while (!(std::cin >> choice)) {
                std::cout << "Invalid choice. Try again.\nEnter choice: ";
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
                std::cout << "Matrix multiplication by a number" << std::endl;
                std::cout << "Entered matrix:" << std::endl;
                matrix1.printMatrix();
                std::cout << "Multiplier:" << std::endl;
                while (!(std::cin >> multiplicand)) {
                    std::cout << "Invalid input. Please enter a valid number: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                break;
            }
            else if (choice == 5)
            {
                break;
            }
            else {
                std::cout << "Invalid choice! Try again." << std::endl;
            }
        }


        Matrix result(rows1, cols1);

        switch (choice) {
        case 1:
            try {
                result = matrix1 + matrix2;
                std::cout << "Sum of matrices" << std::endl;
                std::cout << "Matrix_1:" << std::endl;
                matrix1.printMatrix();
                std::cout << "Matrix_2:" << std::endl;
                matrix2.printMatrix();
                std::cout << "Result:" << std::endl;
                result.printMatrix();
            }
            catch (const std::runtime_error& a) {
                std::wcout << "Error: " << a.what() << std::endl;
            }
            break;
        case 2:
            try {
                result = matrix1 - matrix2;
                std::cout << "Subtraction of matrices" << std::endl;
                std::cout << "Matrix_1" << std::endl;
                matrix1.printMatrix();
                std::cout << "Matrix_2" << std::endl;
                matrix2.printMatrix();
                std::cout << "Result:" << std::endl;
                result.printMatrix();
            }
            catch (const std::runtime_error& b) {
                std::wcout << "Error: " << b.what() << std::endl;
            }
            break;
        case 3:
            try {
                result = matrix1 * matrix2;
                std::cout << "Multiplication of matrices" << std::endl;
                std::cout << "Matrix_1:" << std::endl;
                matrix1.printMatrix();
                std::cout << "Matrix_2:" << std::endl;
                matrix2.printMatrix();
                std::cout << "Result:" << std::endl;
                result.printMatrix();
            }
            catch (const std::runtime_error& e) {
                std::wcout << "Error: " << e.what() << std::endl;
            }
            break;
        case 4:
            std::cout << "Result: " << std::endl;
            result = matrix1 * multiplicand;
            result.printMatrix();
            break;
        case 5:
            try {
                std::cout << "Matrix:" << std::endl;
                matrix1.printMatrix();
                double det = matrix1.determinant();
                std::cout << "Determinant: " << det << std::endl;
            }
            catch (const std::runtime_error& e) {
                std::wcout << "Error: " << e.what() << std::endl;
            }
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
