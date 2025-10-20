#include <stdio.h>
#include "../lib/lecture1.h"

int exercise1_1(void) {
    double radius;

    printf("This program computes the area of a circle.\n\n");

    printf("Input the radius:   ");
    scanf("%lf", &radius);

    printf("\nArea = PI * radius * radius\n");
    printf("     = %.2f * %.2f * %.2f\n", PI, radius, radius);
    printf("     = %.5f\n", PI * radius * radius );

    return 0;
}

int exercise1_2(void) {
    float
        first_number,
        second_number,
        last_number;

    printf("Give me three numbers: \n");

    printf("first number: ");
    scanf("%f",&first_number);
    printf("You choose: %.2f\n", first_number);

    printf("second number: ");
    scanf("%f",&second_number);
    printf("You choose: %.2f\n", second_number);

    printf("Last number: ");
    scanf("%f",&last_number);
    printf("You choose: %.2f\n", last_number);

    printf("Result: %.2f\n", (first_number + second_number + last_number) / 3.0);
    return 0;
}
