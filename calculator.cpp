#include <iostream>

int main() {
    char operation;
    double num1, num2, result;

    // Input the first number
    std::cout << "Enter the first number: ";
    std::cin >> num1;

    // Input the operation (+, -, *, /)
    std::cout << "Enter the operation (+, -, *, /): ";
    std::cin >> operation;

    // Input the second number
    std::cout << "Enter the second number: ";
    std::cin >> num2;

    // Perform the selected operation
    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
                return 1; // Exit with an error code
            }
            result = num1 / num2;
            break;
        default:
            std::cout << "Invalid operation. Please use +, -, *, or /." << std::endl;
            return 1; // Exit with an error code
    }

    // Display the result
    std::cout << "Result: " << num1 << " " << operation << " " << num2 << " = " << result << std::endl;

    return 0;
}
