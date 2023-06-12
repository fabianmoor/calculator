#include <iostream>



using namespace std;

float firstarray[] = {5, 4, 2, 5};
float secondarray[] = {5, 2, 4, 1};

float firstnumb;
float secondnumb;

char x = '+';
int main() {

    if (sizeof(firstarray) == 4) { // 1000
        firstnumb = firstarray[0] * 1000 + firstarray[1] * 100 + firstarray[2] * 10 + firstarray[3];
    } else if (sizeof(firstarray) == 3) {
        firstnumb = firstarray[0] * 100 + firstarray[1] * 10 + firstarray[2];
    } else if (sizeof(firstarray) == 2) {
        firstnumb = firstarray[0] * 10 + firstarray[1];
    } else if (sizeof(firstarray) == 1) {
        firstnumb = firstarray[0];
    }

    if (sizeof(secondarray) == 4) { // 1000
        secondnumb = secondarray[0] * 1000 + secondarray[1] * 100 + secondarray[2] * 10 + secondarray[3];
    } else if (sizeof(secondarray) == 3) {
        secondnumb = secondarray[0] * 100 + secondarray[1] * 10 + secondarray[2];
    } else if (sizeof(secondarray) == 2) {
        secondnumb = secondarray[0] * 10 + secondarray[1];
    } else if (sizeof(secondarray) == 1) {
        secondnumb = secondarray[0];
    }
    

    cout << firstnumb << " " << secondnumb << endl;
}

