#include <iostream>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <algorithm>
#include <iterator>

using namespace std;




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

char method_types[4] = {'*', '+', '-', '/'};


int main() {

    int left_column[8];
    int right_column[8];
    char method;
    
    method = 0;

    while (true) {
        method = getch();
        bool exists = find(begin(method_types), end(method_types), method) != end(method_types);

        if (exists) {
            cout << method << endl;
        } 
    }


    cout << methodFound(method) << endl;
}
