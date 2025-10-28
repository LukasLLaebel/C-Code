#include <stdio.h>
#include "../lib/aflevering3-funcs.h"
#include "../lib/Aflevering3.h"

/* Eksempler på funktioner, som kan kaldes på et enkelt element af typen double */
void print(double x) { printf("%.2lf, ", x); }
double add_one(double x) { return x + 1; }
double square(double x) { return x * x; }
int is_zero(double x) { return x == 0; }
int positive(double x) { return x > 0; }

void print_array(const double arr[], int size);
void apply(void f(double), const double arr[], int size);


int Aflevering3(void) {
    double arr[] = {3.4, 0.0, 1.5, -2.1, 14.0, -4.5, 6.7, 8.5, 9.6, -0.1};
    const int size = sizeof(arr)/sizeof(arr[0]);
    printf("Initial array:\n");
    print_array(arr, size);

    /*
     * Det følgende kode kan du bruge til at afprøve din implementering af `map`, `all` og `any`.
     */
    if (all(positive, arr, size)) printf("All numbers are positive.\n");
    else if (any(positive, arr, size)) printf("There is a positive number.\n");
    if (any(is_zero, arr, size)) printf("There is a zero.\n");
    printf("\nIncrementing each number:\n");
    
    map(add_one, arr, size);
    print_array(arr, size);
    if (all(positive, arr, size)) printf("All numbers are positive.\n");
    else if (any(positive, arr, size)) printf("There is a positive number.\n");
    if (any(is_zero, arr, size)) printf("There is a zero.\n");
    printf("\nSquaring each number:\n");
    
    map(square, arr, size);
    print_array(arr, size);
    if (all(positive, arr, size)) printf("All numbers are positive.\n");
    else if (any(positive, arr, size)) printf("There is a positive number.\n");
    if (any(is_zero, arr, size)) printf("There is a zero.\n");

    return 0;
}

void print_array(const double arr[], const int size) {
    apply(print, arr, size); // print each element
    printf("\n");            // end with a line break
}
void apply(void f(double), const double arr[], const int size) {
    for (int i = 0; i < size; i++) {
        f(arr[i]);
    }
}
