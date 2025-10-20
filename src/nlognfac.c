
#include "../lib/nlognfac.h"
#include <stdio.h>
#include <math.h>


int nlogn() {
    double max_operations = 1e9;
    long long low = 1, high = 1e9;
    long long best_n = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;
        double ops = mid * (log2(mid));  // f(n) = n * log2(n)

        if (ops <= max_operations) {
            best_n = mid;
            low = mid + 1;  // try to find a larger valid n
        } else {
            high = mid - 1;  // n is too large
        }
    }

    printf("Largest n such that n*log2(n) <= 1e9 is: %lld\n", best_n);
    return 0;
}


int factorial() {
    long long max_operations = 1000000000;  // 10^9
    long long fact = 1;
    int n = 1;

    while (1) {
        fact *= n;
        if (fact > max_operations) {
            break;
        }
        n++;
    }

    printf("Largest n such that n! <= 1e9 is: %d\n", n - 1);
    return 0;
}

