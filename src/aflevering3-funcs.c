#include <stdio.h>
#include "../lib/Aflevering3.h"
#include "../lib/aflevering3-funcs.h"

/**
 * Funktion: map
 * ---------------------
 * Anvender funktionen f på hvert element i arrayet
 * og opdaterer elementet til resultatet.
 */

void map(double f(double), double arr[], const int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = f(arr[i]);
    }
}

/**
 * Funktion: all
 * ---------------------
 * Returnerer 1 (true), hvis ALLE elementer opfylder betingelsen f.
 * Returnerer 0 (false), hvis mindst ét element IKKE gør.
 */

int all(int f(double), const double arr[], const int size) {
    for (int i = 0; i < size; i++) {
        if (!f(arr[i])) {
            return 0; // Hvis ét element fejler betingelsen
        }
    }
    return 1; // Alle elementer opfylder betingelsen
}

/**
 * Funktion: any
 * ---------------------
 * Returnerer 1 (true), hvis MINDST ÉT element opfylder betingelsen f.
 * Returnerer 0 (false), hvis INGEN gør.
 */

int any(int f(double), const double arr[], const int size) {
    for (int i = 0; i < size; i++) {
        if (f(arr[i])) {
            return 1; // Hvis ét element opfylder betingelsen
        }
    }
    return 0; // Ingen elementer opfylder betingelsen
}

