#include <stdio.h>
#include "Aflevering2.h"

 // input example : 100 5
int aflevering2(void) {
    // variables
    int listLength = 100;
    int checkNum = 5;

    // set an counter for the number
    int count = 0;
    // start with 1 and count to the amount given listLenght
    for (int i = 1; i <= listLength; i++) {
        // use helper funciton to to check if the number is the disired number and if it is we increment the counter
        if (containsDigit(i, checkNum)) {
            count++;
        }
    }
    // print the amount of times the disired number is found.
    printf("%d\n", count);
    return 0;
}

// Helper function: check if number contains digit
bool containsDigit(int num, int digit) {
    // now if the number is greater than 0 we check the number
    while (num > 0) {
        // here we say if the modulus to the number is greater than 10
        // is equal to the number we check for, we set the hasNum boolean to true
        // and break out of the statement
        if (num % 10 == digit) {
            return true;
        }
        num /= 10;
    }
    return false;
}
