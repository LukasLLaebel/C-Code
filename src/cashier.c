#include <stdio.h>
#include "../lib/cashier.h"

#define NUMBER_OF_GOODS 10

void print_prices(int* p, double* d, int number_of_items);

int cashier(void) {
    int i;
    int price;
    int prices[NUMBER_OF_GOODS];
    double discounts[NUMBER_OF_GOODS];

    // Prompt for prices and store in an array
    for (i = 0; i < NUMBER_OF_GOODS; ++i) {
        printf("Input price of item number %d: ", i);
        scanf(" %d", &price);
        prices[i] = price;

        printf("Input discount of item number %d: ", i);
        scanf(" %lf", &discounts[i]);
    }

    print_prices(prices, discounts, NUMBER_OF_GOODS);

    // Calculate total price with discounts
    double total_price = 0;
    for (i = 0; i < NUMBER_OF_GOODS; ++i) {
        total_price += prices[i] * (1.0 - discounts[i]);;
    }
    printf("Total price is: %lf\n", total_price);

    return 0;
}

void print_prices(int* p, double* d, int number_of_items) {
    for (int i = 0; i < number_of_items; ++i) {
        printf("Item number %d: ", i);
        printf("%d", p[i]);
        printf(" with discount of %lf", d[i]);
        printf(" is: %lf", p[i] * (1.0 - d[i]));
    }
}
