#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"
#include "project1.h"

void scan_data(double* accumulator);


int Main () {
    double accumulator = 0.0;

    while (1) {
        scan_data(&accumulator);
    }

    return 0;
}


void scan_data(double* accumulator) {
    char input[20];
    char operator;
    double operand;

    printf("Enter operation (e.g., + 5) or 'q' to quit: ");
    scanf(" %19[^\n]", input);  // Read full line

    // Check for 'q'
    if (input[0] == 'q' || input[0] == 'Q') {
        printf("Final result is: %lf", *accumulator);
        exit(0);
    }

    // Parse operator and operand
    if (sscanf(input, "%c %lf", &operator, &operand)) {
      do_next_op(operator, operand, accumulator);
      printf("Output: %.2f\n", *accumulator);
    }
}

