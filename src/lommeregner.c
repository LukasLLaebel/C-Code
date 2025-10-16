#include "lommeregner.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>



// beskrivelse af operators:
// + for addition af akkumulatoren
// - for subtraktion af akkumulatoren
// * for multiplikation af akkumulatoren
// / for division af akkumulatoren
// ^ for potensopløftning af akkumulatoren
//
// # for kvadratroden
// % for at vende fortegnet af akkumulatoren
// ! for at dividere 1 med akkumulatoren
// q for at afslutte regnemaskinen


// IMPROVEMENTS
// 1. ranking of operators "(), *, /" is before "+, -"
// 2. be able to make real equesitons like solve for x and so on.
// 3. be able to regonize terms like log, sin, cos, tan, and so on


// function prototypes
int calculation(char operator, int number_1, int number_2);

int lommeregner(void) {
    const char operators[5] = {'+', '-', '/', '*','^'};
    //const char Special_operators[3] = {'#', '%','!'};
    char input[100];
    char storedOperator = '\0';
    char numberBuff[100];
    int bufferIndex = 0;
    char stored_num1[100] = "";
    char stored_num2[100] = "";
    int result = 0;
    int num1 = 0, num2 = 0;

    // input
    printf("Enter expression: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // remove newline

    for (int i = 0; i <= strlen(input); i++) {
        if (isdigit(input[i])) {
            numberBuff[bufferIndex++] = input[i];
        } else if (input[i] == ' ' || input[i] == '\0') {
            continue; // skip spaces and null terminator
        } else {
            numberBuff[bufferIndex] = '\0'; // terminate number
            if (stored_num1[0] == '\0') {
                strcpy(stored_num1, numberBuff);
                storedOperator = input[i];
            } else {
                strcpy(stored_num2, numberBuff); 
                num1 = atoi(stored_num1);
                num2 = atoi(stored_num2);

                result = calculation(storedOperator,num1,num2);

                sprintf(stored_num1, "%d", result); // store result as next operand
                stored_num2[0] = '\0';
            }
            bufferIndex = 0;
            storedOperator = input[i]; // update operator
        }
    }

    // Final number after the last operator
    if (bufferIndex > 0) {
        numberBuff[bufferIndex] = '\0';
        strcpy(stored_num2, numberBuff);
        num1 = atoi(stored_num1);
        num2 = atoi(stored_num2);
        
        result = calculation(storedOperator,num1,num2);
    }

    printf("Result: %d\n", result);
    return 0;
}


int calculation(char operator, int number_1, int number_2) {
  int result = 0;

  switch (operator) {
    case '+': result = number_1 + number_2; break;
    case '-': result = number_1 - number_2; break;
    case '*': result = number_1 * number_2; break;
    case '/':
      if (number_2 == 0) {
        printf("Error: Division by zero\n");
        return 1;
      }
      result = number_1 / number_2;
    break;
    default:
      printf("Unsupported operator: %c\n", operator);
      return 1;
  }




  return result;
}


//unsigned int binary_divide(unsigned int dividend, unsigned int divisor) {
//    unsigned int quotient = 0;
//    unsigned int temp = 0;
//
//    for (int i = 31; i >= 0; i--) {
//        // Shift temp left and bring in the next bit of dividend
//        temp = (temp << 1) | ((dividend >> i) & 1);
//
//        if (temp >= divisor) {
//            temp -= divisor;
//            quotient |= (1U << i);
//        }
//    }
//
//    return quotient;
//}


