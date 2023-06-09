#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;


//jag behöver en array som lagrar de 
//sifforna jag har skrivit in. Jag kan
//sedan lagra vilken uträkning jag ska
//göra utifrån vad som lagras i list_method
//Utifrån vad som är i list_method avgör
//vilken typ av matematisk uträkning
//som skall göras.


//ex num1 list_method[0] num2
//   num1 + num2

int main(){


    double list_int[2];
    string method[1];

    double num1;
    double num2;
    double result;
    num1 = 1;
    num2 = 1;
    

    if (method[0] == "+") {
        result = num1 + num2;
    } else if (method[0] == "-") {
        result = num1 - num2;
    } else if (method[0] == "*") {
        result = num1 * num2;
    } else if (method[0] == "/") {
        result = num1 / num2;
    } else {
        cout << "Invalid method." << endl;
        return 0;
    }

    //list_int = []
    //list_method = []

    // for each *, /, +, - or ^:
        //append previous int or float.
        //list_method[0] = i
    //


    
}