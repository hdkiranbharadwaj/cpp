#include <iostream>

int main() {
    double num1, num2;
    char operation;

    std::cout << "Welcome to the Simple Calculator!" << std::endl;

    // Input two numbers from the user
    std::cout << "Enter the first number: ";
    std::cin >> num1;
    std::cout << "Enter the second number: ";
    std::cin >> num2;

    // Choose the operation
    std::cout << "Enter the operation (+, -, *, /): ";
    std::cin >> operation;

    // Perform the chosen operation
    switch (operation) {
        case '+':
            std::cout << "Result: " << num1 + num2 << std::endl;
            break;
        case '-':
            std::cout << "Result: " << num1 - num2 << std::endl;
            break;
        case '*':
            std::cout << "Result: " << num1 * num2 << std::endl;
            break;
        case '/':
            if (num2 != 0) {
                std::cout << "Result: " << num1 / num2 << std::endl;
            } else {
                std::cout << "Error: Division by zero is undefined." << std::endl;
            }
            break;
        default:
            std::cout << "Error: Invalid operation. Please use +, -, *, or /." << std::endl;
            break;
    }

    return 0;
}
