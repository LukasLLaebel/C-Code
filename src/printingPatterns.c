#include <stdio.h>
#include "printingPatterns.h"


void diamond(int n) {
    int size = 2 * n - 1;  // total rows
    for (int i = 0; i < size; i++) {
        int dist = i < n ? i : size - 1 - i;  // distance from middle row
        for (int j = 0; j < size; j++) {
            if (j == n - 1 - dist || j == n - 1 + dist) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}


void reverseHalfPyramid(int n) {
    for (int i = 1; i <= n; i++) {
        // print leading spaces
        for (int j = 0; j < n - i; j++) {
            printf("  ");
        }
        // print stars with a trailing space
        for (int j = 0; j < i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void halfPyramid(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i+1; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void pyramid(int n) {
    for (int i = 1; i <= n; i++) {
        // print spaces
        for (int j = 0; j < n - i; j++) {
            printf(" ");
        }
        // print stars
        for (int j = 0; j < 2*i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void firkant(int n , int m) {
    // erklæring af variable
    // og intialisere dem selvom de bliver overskrevet senere

    // lav firkant
    // for-loop for rows
    for (int i = 0; i < n; i++) {
        // udskriv numre
        printf("%d", i);
        // for loop coloumns (af stjerner)
        for (int j = 0; j <= m; j++) {
            printf("*");
        }
        printf("\n");
    }
}