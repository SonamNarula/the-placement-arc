#include <iostream>
using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        cout << "Error! Division by zero is not allowed." << endl;
        return 0;
    }
    return a / b;
}

int main() {
    double num1, num2;
    int choice;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << "\nCalculator Menu:\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
        case 1:
            cout << "Result = " << add(num1, num2);
            break;
        case 2:
            cout << "Result = " << subtract(num1, num2);
            break;
        case 3:
            cout << "Result = " << multiply(num1, num2);
            break;
        case 4:
            cout << "Result = " << divide(num1, num2);
            break;
        default:
            cout << "Invalid choice!";
    }

    return 0;
}