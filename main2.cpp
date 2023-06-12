#include <iostream>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <algorithm>
#include <iterator>
#include "test.cpp"
#include <cstdlib>

using namespace std;

char getch();
bool methodFound(char x);
void printCalculator(); 

// Programbeskrivning: 
// Kalkylatorn ska fungera genom att live uppdateras
// och visa resultatet av det som är inskrivet för
// stunden. Detta skall genomföras genom användning
// av 3 olika listor. 2 int och 1 char. 
//
// Tanken är att 
//
// if (char array empty()) {
//    fyll int array 2.
// } else {
//    fyll int array 1.
// }
//
// På så vis kan vi separera de tal som skall användas
// för uträkningen. 
//
// Exempel: Vi har tryckt in 4, 5 och 6. Dessa lagras i
// int array 1. Efter det trycker vi på "*". Eftersom 
// "*" är av typ char så ska den lagras i char arrayn. 
// 
// Eftersom char arrayn numera inte är == empty() så ska
// nästa siffra lagras i int array 2. Det blir då enkelt
// för oss att genomföra önskvärda matematiska beräkning
// på de 2 arrays som innehåller int med hjälp av metoden
// som finns på index 0 i char arrayn.
//
//
// Det som behövs.
// 
// Function som kollar ifall array char är tom.
//
// Function som slår ihop alla talen i en array och bildar ett nytt
// tal och inte summerar talen. Om man skriver 456 så det inte bli
// 4+5+6 etc etc.
//
// Skriv ut Calculatorns "spelfält", snygga till den helt enkelt.
//
//


// Definerar lite variablar
char method_types[4] = {'*', '+', '-', '/'};
char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
// Definerar key variablen
char key;

// Definerar arrays som används för att 
// slå ihop de olika tal man skriver.
float leftcolumn[5];
float rightcolumn[5];

float input;
float result;

bool looped;

int main() {
    // Sätter key = 0 för att undvika errors
    key = 0;

    // Programmets while loop
    while (true) {

        printCalculator();
        // true och false variablar som lagrar 
        // om senaste knapptryck är en symbol
        // eller om det är en siffra.
        bool methodexists = find(begin(method_types), end(method_types), key) != end(method_types);
        bool numbexists = find(begin(numbers), end(numbers), key) != end(numbers);

        // Lagra varje key-press
        key = getch();

        // Om *, -, / eller + används
        // lagra värdet i method-variabeln.
        if (methodexists) {
            method = key;

        // Om siffra blev tryckt på
        // lagra siffran i värdet.
        } else if (numbexists) {
            int numbcount = 0;
            if (!methodexists) {
                firstarray[numbcount] = key;
                numbcount++;
            } else {
                looped = true;
                if (!looped) {
                    numbcount = 0;
                }
                secondarray[numbcount] = key;
                numbcount++;
            }
            numbcount++;
        }

        calculate_arrays();

        result = calculation(firstnumb, secondnumb, method);


    }


    return 0;
}




void printCalculator() {
    system("clear");
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

bool methodFound(char x) {
    // Kollar ifall vi har ett tecken
    // som vi bör räckna ihop de 2 listorna med.
    if (x != 0) {
        return true;
    } else {
        return false;
    }
}

