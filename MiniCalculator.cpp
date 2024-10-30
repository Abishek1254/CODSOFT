#include <iostream>
using namespace std;

// Function to perform the chosen operation
void calculate(int num1, int num2, int op) {
    switch (op) {
        case 1:
            cout << "Result: " << num1 << " + " << num2 << " = " << num1 + num2 << endl;
            break;
        case 2:
            cout << "Result: " << num1 << " - " << num2 << " = " << num1 - num2 << endl;
            break;
        case 3:
            cout << "Result: " << num1 << " * " << num2 << " = " << num1 * num2 << endl;
            break;
        case 4:
            if (num2 != 0)
                cout << "Result: " << num1 << " / " << num2 << " = " << static_cast<float>(num1) / num2 << endl;
            else
                cout << "Error: Division by zero is undefined." << endl;
            break;
        default:
            cout << "Invalid choice of operation. Please try again." << endl;
    }
}

int main() {
    bool choice = true;

    cout << "==== Welcome to MiniCalculator ====" << endl;

    while (choice) {
        int num1, num2, op;

        cout << "\nEnter two integers: ";
        cin >> num1 >> num2;

        cout << "Choose an operation to perform: " << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> op;

        calculate(num1, num2, op); // Call function to calculate and display the result

        cout << "\nWould you like to perform another calculation? Enter 1 for yes or 0 for no: ";
        cin >> choice;
    }

    cout << "\nThank you for using MiniCalculator! Goodbye!" << endl;
    return 0;
}
