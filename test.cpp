#include <iostream>

using namespace std;

float firstarray[] = {0, 0, 0, 0, 1};
float secondarray[] = {0, 0, 0, 0, 1};

float firstnumb;
float secondnumb;

char method;

int firstarraysize = sizeof(firstarray) / sizeof(firstarray[0]);
int secondarraysize = sizeof(secondarray) / sizeof(secondarray[0]);

void calculate_arrays(){
    if (firstarraysize == 1) {
        firstnumb = firstarray[0];
    } else if (firstarraysize == 2) {
        firstnumb = firstarray[0] * 10 + firstarray[1];
    } else if (firstarraysize == 3) {
        firstnumb = firstarray[0] * 100 + firstarray[1] * 10 + firstarray[2];
    } else if (firstarraysize== 4) {
        firstnumb = firstarray[0] * 1000 + firstarray[1] * 100 + firstarray[2] * 10 + firstarray[3];
    } else if (firstarraysize == 5) {
        firstnumb = firstarray[0] * 10000 + firstarray[1] * 1000 + firstarray[2] * 100 + firstarray[3] * 10 + firstarray[4];
    }
    

    if (secondarraysize == 1) {
        secondnumb = secondarray[0];
    } else if (secondarraysize == 2) {
        secondnumb = secondarray[0] * 10 + secondarray[1];
    } else if (secondarraysize == 3) {
        secondnumb = secondarray[0] * 100 + secondarray[1] * 10 + secondarray[2];
    } else if (secondarraysize == 4) { // 1000
        secondnumb = secondarray[0] * 1000 + secondarray[1] * 100 + secondarray[2] * 10 + secondarray[3];
    } else if (secondarraysize == 5) { // 10000
        secondnumb = secondarray[0] * 10000 + secondarray[1] * 1000 + secondarray[2] * 100 + secondarray[3] * 10 + secondarray[4];
    }
}

float calculation(float x, float y, char z){

    float result;

    if (z == '+') {
        result = x+y;
    } else if (z == '-') {
        result = x-y;
    } else if (z == '*') {
        result = x*y;
    } else if (z == '/') {
        result = x/y;
    }
    return result;
}

    

//    calculate_arrays();
//    cout << firstnumb << endl;
//    firstarray[4] = 2;
//    calculate_arrays();
//    cout << firstnumb << endl;
