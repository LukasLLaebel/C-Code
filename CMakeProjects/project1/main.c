#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"
#include "project1.h"

void scan_data(double* accumulator);


int Main () {
    double accumulator = 0.0;
    // We want to make sure that the user gets promted until they are done
    while (1) {
      // use the scan_data() with the parameter &accumylator because its an pointer we need to address it.
      scan_data(&accumulator);
    }

    return 0;
}


void scan_data(double* accumulator) {
    // Variables
    char input[20];
    char operator;
    double operand;

    printf("Enter operation (e.g., + 5) or 'q' to quit: ");
    // we want to read the full line first we do this by setting the format specifier to 19[^\n]
    // in short terms this just tells the program that it needs to read the first 19 characters.
    // the reason for 19 is becuase the array input have an size of 20
    scanf(" %19[^\n]", input);  

    // Check if the input includes an q or Q if it does we want to exit the program
    // the reason for not adding it into the switch is because its not an calculation
    // and we want that to happen as the first thing.
    if (input[0] == 'q' || input[0] == 'Q') {
        // print end result
        printf("Final result is: %lf", *accumulator);
        // close program
        exit(0);
    }

    // Use sscanf so we can parse the operator and operand from the array
    // if it wasent becuase of the !, # i could have made an validater easy with this setup
    // Just check if sscanf size is 2, that means operator and operand is present. 
    // sscanf(...) == 2. But because we need at least 1 i can just make it go though anyway.
    if (sscanf(input, "%c %lf", &operator, &operand)) {
      do_next_op(operator, operand, accumulator);
      // Print output with 2 decimals becuase that is more userfriendly, END RESULT IS WITH ALL DECIMALS :)
      printf("Output: %.2f\n", *accumulator);
    }
}

