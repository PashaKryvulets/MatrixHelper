#include <iostream>
#include "Header.h"



int main() {
    int multiplicand = 0;

    while (true) {
        std::cout << "Matrix operations" << std::endl << std::endl;

        std::cout << "Matrix_1" << std::endl;
        int rows = getPositiveNumber("Enter the number of rows: ");
        int cols = getPositiveNumber("Enter the number of columns: ");
        std::cout << std::endl;

        Matrix matrix1(rows, cols);
        std::cout << "Enter values for matrix_1:" << std::endl;
        matrix1.fillMatrix();
        std::cout << std::endl;

        std::cout << "Matrix_2" << std::endl;
        rows = getPositiveNumber("Enter the number of rows: ");
        cols = getPositiveNumber("Enter the number of columns: ");
        std::cout << std::endl;

        Matrix matrix2(rows, cols);
        std::cout << "Enter values for matrix_2:" << std::endl;
        matrix2.fillMatrix();
        std::cout << std::endl;

        int choice;
        while (true) {
            std::cout << "Select operation:" << std::endl;
            std::cout << "1. Addition (+)" << std::endl;
            std::cout << "2. Subtraction (-)" << std::endl;
            std::cout << "3. Multiplication (*)" << std::endl;
            std::cout << "4. Multiply by a number" << std::endl;
            std::cout << "Enter choice: ";
            std::cin >> choice;
            std::cout << std::endl << std::endl;

            if (choice >= 1 && choice <= 3)
            {
                std::cout << "Matrix_2" << std::endl;
                rows = getPositiveNumber("Enter the number of rows: ");
                cols = getPositiveNumber("Enter the number of columns: ");
                std::cout << std::endl;

                Matrix matrix2(rows, cols);
                std::cout << "Enter values for matrix_2:" << std::endl;
                matrix2.fillMatrix();
                std::cout << std::endl;
                break; // выйти из цикла, если выбор верный
            }
            else if (choice == 4)
            {
               // int multiplicand;
                std::cout << "Enter multiplicand: ";
                while (!(std::cin >> multiplicand)) {
                    std::cout << "Invalid input. Please enter a valid number: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
            else
            {
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
                result = matrix1 * matrix2;
                std::cout << "Multiplication of matrices:" << std::endl;
                result.printMatrix();
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
                // Break the loop and continue with the rest of the program
            }
            else {
                std::cout << "Invalid input. Try again." << std::endl;
            }
        }
        std::cout << std::endl << std::endl;
    }

    return 0;
}