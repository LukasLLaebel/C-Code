#include "lommeregner.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// function prototypes
int calculation(char operator, int number_1, int number_2);


int lommeregner(void) {
    const char operators[4] = {'+', '-', '/', '*'};
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


