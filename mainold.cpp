#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {
    // Define variables
    double num1 = 0, num2 = 0, result = 0;
    char op = ' ';
    string input = "";
    string method[1];

    while (true) {
        // Clear the console
        system("clear");

        // Print the calculator UI with the current input and result
        cout << "------------------------" << endl;
        cout << "|                      |" << endl;
        cout << "|       Calculator     |" << endl;
        cout << "|                      |" << endl;
        cout << "------------------------" << endl;
        cout << "|                      |" << endl;
        cout << "| " << input << endl;
        cout << "| " << result << endl;
        cout << "|                      |" << endl;
        cout << "|                      |" << endl;
        cout << "|                      |" << endl;
        cout << "|                      |" << endl;
        cout << "|                      |" << endl;
        cout << "|                      |" << endl;
        cout << "|                      |" << endl;
        cout << "|                      |" << endl;
        cout << "|                      |" << endl;
        cout << "------------------------" << endl;

        // Get user input
        char key = std::cin.get();
        cout << key << endl;
//        if (key == "+") {
//            method[0] = "+";
//        } else if (key == "-") {
//            method[0] = "-";
//        }

        if (key == 13) { // Enter key
            // Perform calculation based on operator
            switch (op) {
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
                    result = num1 / num2;
                    break;
                case '^':
                    result = pow(num1, num2);
                    break;
                default:
                    break;
            }

            // Reset variables
            num1 = result;
            num2 = 0;
            op = ' ';
            input = "";
        } else if (key == 27) { // Escape key
            // Clear the console and exit the program
            system("clear");
            return 0;
        } else if (key == '+' || key == '-' || key == '*' || key == '/' || key == '^') {
            // Set the operator
            op = key;
            input += op;
        } else if (key >= '0' && key <= '9') {
            // Add the digit to the current number
            if (op == ' ') {
                num1 = num1 * 10 + (key - '0');
            } else {
                num2 = num2 * 10 + (key - '0');
            }
            input += key;
        }

        // Clear the console
        system("clear");
    }

    return 0;
}
