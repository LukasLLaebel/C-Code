#include <stdio.h>
#include <stdlib.h>
#include "../lib/lecture7.h"

// function prototypes for 9.2
void get_polynomium(double coeff[], int* degreep);
double eval_polynomium(const double coeff[], int degree, double x);


// <======== Polynomier ========>
int exercise9_2() {
    double coeff[9];  // plads til grader op til 8
    int degree;

    get_polynomium(coeff, &degree);

    double x;
    while (1) {
        printf("\nIndtast en x-værdi (eller 'q' for at afslutte): ");
        if (scanf("%lf", &x) != 1) {
            break; // brugeren skrev ikke et tal, fx 'q'
        }

        double result = eval_polynomium(coeff, degree, x);
        printf("p(%.2f) = %.4f\n", x, result);
    }

    printf("Program afsluttet.\n");
    return 0;
}


void get_polynomium(double coeff[], int* degreep) {
    int degree;
    printf("Indtast graden af polynomiet (maks 8): ");
    scanf("%d", &degree);

    while (degree < 0 || degree > 8) {
        printf("Graden skal være mellem 0 og 8. Prøv igen: ");
        scanf("%d", &degree);
    }

    *degreep = degree;

    for (int i = 0; i <= degree; i++) {
        printf("Indtast koefficient a[%d]: ", i);
        scanf("%lf", &coeff[i]);
    }
}

double eval_polynomium(const double coeff[], int degree, double x) {
    double result = 0.0;
    double x_power = 1.0;  // x^0 = 1

    for (int i = 0; i <= degree; i++) {
        result += coeff[i] * x_power;
        x_power *= x;  // x^i
    }

    return result;
}

// funciton prototypes for 9.3
double combine_right(double a[], int n, double (*combiner)(double,double));
double combine_left(double a[], int n, double (*combiner)(double,double));
double combiner(double num1, double num2);

// <======== Reductions of Array ========>
int exercise9_3() {
  // define the lenght
  int n;
  printf("Set the size of array (max 20):");
  scanf("%d", &n);


  // put the length into the array
  double arr[n] = {};
  
  // scan for numbers
  for (int i = 0; i < n; i++) {
    scanf("%lf", &arr[i]);
  }
  
  // find end result with the combine (left || right) function
  double end = combine_right(arr, n, combiner);
  //double end = combine_left(arr, n, combiner);
  // print the return of the function
  printf("result: %lf", end);
}

double combine_right (double a[], int n, double (*combiner)(double, double)) {
  // validate number. if number is only 1 then just return that number
  if (n == 1) {
    return a[0];
  } else {
    return combiner(combine_right(a + 1, n - 1, combiner), a[0]);
  }
}

double combine_left (double a[], int n,double (*combiner)(double, double)) {
  if (n == 1) {
    return a[0];
  } else {
    return combiner(a[0], combine_left(a + 1, n - 1, combiner));
  }
}

double combiner(double num1, double num2) {
  return num1 - num2;
}
















// <======== ========>
int exercise9_4() {

}


// <======== ========>
int exercise9_5() {

}





// <======== ========>
int exercise9_8() {

}
