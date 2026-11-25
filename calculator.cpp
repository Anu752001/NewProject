#include <iostream>
#include <limits>
#include <stdexcept>

double add(double left, double right) {
    return left + right;
}

double subtract(double left, double right) {
    return left - right;
}

double multiply(double left, double right) {
    return left * right;
}

double divide(double left, double right) {
    if (right == 0.0) {
        throw std::invalid_argument("Cannot divide by zero");
    }
    return left / right;
}

int main() {
    std::cout << "A Simple C++ Calculator\n";
    std::cout << "Operators Supported: +  -  *  /\n";

    double left;
    char operation;
    double right;

    std::cout << "Enter an expression (for example: 12 + 3): ";

    while (std::cin >> left >> operation >> right) {
        try {
            double result;

            switch (operation) {
                case '+':
                    result = add(left, right);
                    break;
                case '-':
                    result = subtract(left, right);
                    break;
                case '*':
                    result = multiply(left, right);
                    break;
                case '/':
                    result = divide(left, right);
                    break;
                default:
                    throw std::invalid_argument("Invalid operator");
            }

            std::cout << "Result: " << result << '\n';
        } catch (const std::invalid_argument& error) {
            std::cout << "Error: " << error.what() << '\n';
        }

        std::cout << "\nEnter another expression (Ctrl+C to exit): ";
    }

    if (!std::cin.eof()) {
        std::cout << "Invalid input.\n";
    }

    return 0;
}
