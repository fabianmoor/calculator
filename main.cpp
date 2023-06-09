#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <termios.h>
#include <unistd.h>
#include <array>
#include <algorithm>

using namespace std;

// Function to read a single character without echoing it to the console
char getch() {

    char buf = 0;
    struct termios oldSettings, newSettings;

    if (tcgetattr(0, &oldSettings) < 0) {
        perror("tcgetattr");
        exit(1);
    }

    newSettings = oldSettings;
    newSettings.c_lflag &= ~ICANON;
    newSettings.c_lflag &= ~ECHO;

    if (tcsetattr(0, TCSANOW, &newSettings) < 0) {
        perror("tcsetattr");
        exit(1);
    }

    if (read(0, &buf, 1) < 0) {
        perror("read");
        exit(1);
    }

    if (tcsetattr(0, TCSANOW, &oldSettings) < 0) {
        perror("tcsetattr");
        exit(1);
    }

    return buf;
}

bool isAllowedChar(char ch) {
    if (isdigit(ch) || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=')
        return true;
    return false;
}

double num1 = 0, num2 = 0, result = 0;
char op = ' ';
char input[13] = "";
char method[1];
char key;
int inputLength = 0;


void printCalculator() {
    cout << "------------------------" << endl;
    cout << "|        Fabians       |" << endl;
    cout << "|       Calculator     |" << endl;
    cout << "|                      |" << endl;
    cout << "|----------------------|" << endl;
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
}

int main() {

    while (true) {
        // Clear Console
        system("clear");

        printCalculator();

        key = getch();  // Capture user input

        if (strlen(input) <= 12) {
            if (inputLength > 0 && key == '\b') {
                input[--inputLength] = '\0';  // Remove the last character
                printCalculator();
            } else {
                if (isAllowedChar(key) && inputLength < 12) {
                    input[inputLength++] = key;  // Append the input to the array
                    input[inputLength] = '\0';  // Add null character at the end
                }
            }
        } else {
            sleep(2);
            if (inputLength > 0 && key == '\b') {
                input[--inputLength] = '\0';  // Remove the last character
                printCalculator();
            }
            continue;
        }
    }
}
