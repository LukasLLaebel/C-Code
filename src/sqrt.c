#include <math.h>
#include <stdbool.h>
#include "../lib/sqrt.h"

// inverse of a sqrt
int inverseSQRT(float number) {
    //float y = 1 / sqrt(x);

    // using Quake 3 algorithm
    long i;                             // using a long so we have 32 bits to go though
    float x2,y;                         // Then we declare a 32 bit decimal number (x2 and y)
    const float threehalf = 1.5F;       // store a 1.5 into threehalf variable (also 32 bits)

    x2 = number * 0.5F;                 // then we copy half of the input into x2
    y = number;                         // then the hole input into y
    i = *(long *)(&y);                  // now we use an C code trick.
                                            // we make C think the number living at the float address is now a long
                                            // in that way we can iterate though the float as if it was a long.
    i = 0x5f3759df - (i >> 1);          // because bit-shifting the number to the left doubles the number
                                            // when bit shifting to right we can half the number (i >> 1)
                                            // if we do this to an exponent we can see it like this:
                                            // double an exponent x^1 gives us x^2 while halfing an exponent gives us x^1/2
                                            // witch equals to the sqrt, while if we are negating the exponent we get (1/sqrt(x))
    y = *(float *)(&i);

    y = y * (threehalf - (x2 * y * y));     // newtons 1st iteration
    // y = y * (threehalf - (x2 * y * y));  // newtons 2nd iteration

    // https://www.youtube.com/watch?v=p8u_k2LIZyo
}


float for_float_sqrt(float number) {
    float stored = 0;

    for (float f = 0; f < number; f += 0.000001f) {
        if (number - (f*f) <= 0) {
            return stored;
        }
        stored = f;
    }
    return 0;
}

float binary_search_sqrt(float number) {
    float low = 0;
    float high = number;
    float mid;
    float epsilon = number * 1e-9f;

    int i = 0;
    while (true) {
        mid = (low + high) / 2;
        float square = mid * mid;
        float error = fabs(square - number);

        if (error < epsilon) {
            break;
        }

        if (square > number) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return mid;
}

float herons_method(float number) {
    float initial_estimate = number / 2;
    float current_step = initial_estimate;
    float epsilon = number * 1e-9f;

    while (true) {
        float next_step = ((float)1/2) * (current_step + (number / current_step));

        if (fabs(next_step - current_step) < epsilon) {
            break;
        }
        current_step = next_step;
    }
    return current_step;
}

float quake_sqrt(float number) {
    float half = 0.5f * number;
    // Type-punning
    union {
        float number;
        int i;
    }u; // reinterpret the bits of a float as an integer

    u.number = number;
    // using IEEE 754 floating-point numbers are represented
    u.i = 0x5f375a86 - (u.i >> 1);  // instead of dividing

    // Newton–Raphson iteration
    u.number = u.number * (1.5f - half * u.number * u.number);  // Newtons method: 1st iteration
    u.number = u.number * (1.5f - half * u.number * u.number);  // Newtons method: 2nd iteration
    u.number = u.number * (1.5f - half * u.number * u.number);  // Newtons method: 3rd iteration

    // make it a normal sqrt instead of inverse sqrt
    return number * u.number;
}
