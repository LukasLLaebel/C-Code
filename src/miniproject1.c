#include <stdio.h>
#include <stdlib.h>

int calc(char operator, int number_1, int number_2);

int miniproject1(void) {
    int num1 = 0, num2 = 0;
    char operator;
    int result = 0;
    char input[20];

    printf("Enter first calculation (e.g., 1 + 2): ");
    scanf("%d %c %d", &num1, &operator, &num2);

    result = calc(operator, num1, num2);
    printf("Output: %d\n", result);

    while (1) {
        printf("Enter next operation (e.g., + 5) or 'q' to quit: ");
        scanf(" %19[^\n]", input);  // Read 19 characters while an new line is encounted. 19 is used because the char input is 20

        // Check for 'q'
        if (input[0] == 'q' || input[0] == 'Q') {
            break;
        }

        // Parse operator and number
        if (sscanf(input, "%c %d", &operator, &num2) == 2) {
            result = calc(operator, result, num2);
            printf("Output: %d\n", result);
        } else {
            printf("Invalid input. Please enter something like '+ 5' or 'q'\n");
        }
    }

    return 0;
}

int calc(char operator, int number_1, int number_2) {
    int result = 0;

    switch (operator) {
        case '+': result = number_1 + number_2; break;
        case '-': result = number_1 - number_2; break;
        case '*': result = number_1 * number_2; break;
        case '/':
            if (number_2 == 0) {
                printf("Error: Division by zero\n");
                return number_1;  // Return current result unchanged
            }
            result = number_1 / number_2;
            break;
        default:
            printf("Unsupported operator: %c\n", operator);
            return number_1;  // Return current result unchanged
    }

    return result;
}

