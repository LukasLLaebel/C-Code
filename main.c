#include <math.h>
#include <stdio.h>

#include "lib/Aflevering1.h"
#include "lib/Aflevering2.h"
#include "lib/Aflevering3.h"
// #include "lib/EC_hashtables.h"
#include "lib/cashier.h"
// #include "lib/hashtable.h"
#include "lib/exampleExam.h"
#include "lib/lecture1.h"
#include "lib/lecture12.h"
#include "lib/lecture13.h"
#include "lib/lecture2.h"
#include "lib/lecture3.h"
#include "lib/lecture4.h"
#include "lib/lecture7.h"
#include "lib/lecture9.h"
#include "lib/leetcode.h"
#include "lib/lommeregner.h"
#include "lib/mergesort.h"
#include "lib/nlognfac.h"
#include "lib/printingPatterns.h"
#include "lib/qsort.h"
#include "lib/searchCompare.h"
#include "lib/sqrt.h"
#include "lib/stensakspapir.h"
#include "lib/sudoSolver.h"
#include "lib/swapNum.h"
#include "miniproject2.h"
#include "miniproject3.h"
#include "project1.h"

#define LAMBDA(return_type, function_body)                                     \
  ({                                                                           \
    return_type __fn__ function_body;                                          \
    __fn__;                                                                    \
  })

int main(/*int argc, char *argv[]*/) {
  // NOTE: ---------------------EXAM EXAMPLES ----------------------
  // task8();
  // printf("%d", f(1)); // first -1 = -1, 1 = 1, 2 = 5
  // task12();
  // task13();
  //  ---------------------------------------------------------------

  // PERF: --------------------- printingPatterns.c ---------------------
  //  int n = 10;
  //  int m = 10;
  //  halfPyramid(n);
  //  reverseHalfPyramid(n);
  //  pyramid(n);
  //  diamond(n);
  //  firkant(n, m);
  //  ---------------------------------------------------------------

  // NOTE: --------------------------- DTG -----------------------------
  // searchCompare();
  // nlogn();
  // factorial();
  // workshop3();
  // --------------------------------------------------------------

  // PERF: ----------------------------HASH TABLE ---------------------------
  // hashtableExample();
  // EC_hashtableExample();
  // -----------------------------------------------------------------------

  // NOTE: ------------------------SUDOKU Solver-------------------------------
  // SudokuSolver();
  // --------------------------------------------------------------------

  // PERF: --------------------- sqrt.c ---------------------
  // float number = 10;
  // float SQRT = sqrt(number);
  // float inSqrt = inverseSQRT(number);
  // float anothersqrt = for_float_sqrt(number);
  // float anothersqrt = binary_search_sqrt(number);
  // float anothersqrt = herons_method(number);
  // float anothersqrt = quake_sqrt(number);
  // printf("%f\n%f", SQRT , anothersqrt);
  //  --------------------------------------------------

  // NOTE: --------------------- qsort ---------------------
  // char *colors[] = {"B", "D", "A", "W", "Z", "X", "M", "O"};
  // Size of the array
  // int size = sizeof(colors) / sizeof(colors[0]);
  // qsortingInt();
  // qsortingChar(colors, size);
  // qsortingStr();
  // printf("\n===== MyOwnQsort =====\n");
  // test_int_sorting();
  // test_string_sorting();
  // test_char_array_sorting();
  //  --------------------------------------------------

  // PERF: ---------------- SWAP NUMBERS ----------------------
  // tempVar();
  // withoutTemp();
  // xorSwap();
  // ----------------------------------------------------

  // NOTE: --------------- LAMBDA FUNCTIONS --------------------
  //  Create lambda
  // int (*add)(int, int) = LAMBDA(int, (int a, int b) { return a + b; });
  // printf("Result: %d\n", add(5, 3));
  // return 0;
  //  ------------------------------------------------------

  // PERF: --------------------- Lecture1.c --------------------- INTRODUCTION
  // TO C exercise1_1(); exercise1_2();
  // ------------------------------------------------------

  // NOTE: --------------------- Lecture2.c --------------------- INTRODUKTION
  // TIL C exercise2_1(); exercise2_5();
  // ------------------------------------------------------

  // PERF: --------------------- Lecture3.c --------------------- KONTROL
  // STRUKTURER
  // exercise3_1();
  // exercise3_2();
  // exercise3_4();
  // bouncer();
  // ------------------------------------------------------

  // NOTE: <==== Lecture4.c Iterative KONTROLSTRUKTURER ====>
  // exercise4_1(); unsigned int m = 5, n = -13, k = 3;
  // exercise4_2(m, n, k);
  // printf("%d", exercise4_3(n));
  // exercise4_4();
  // exercise4_5();
  // exercise4_5V2();
  // exercise4_6();
  // ------------------------------------------------------

  // PERF: --------------------- Lecture5.c --------------------- FUNCTTIONS
  // ------------------------------------------------------

  // NOTE: --------------------- Lecture6.c --------------------- FLERE
  // FUNCTIONS
  // ------------------------------------------------------

  // PERF:--------------------- lecture7 ----------------------- ARRAYS AND
  // POINTERS cashier(); exercise9_2(); exercise9_3();
  //  -------------------------------------------------------

  // NOTE:---------------------- lecture9 ----------------------- TEGN OG TEKST
  // STRENGE exercise10_1(); exercise10_2(); exercise10_3(); exercise10_4();
  // -------------------------------------------------------

  // ------------------------------------------------------------- REKUSION
  // -------------------------------------------------------------
  //
  // -------------------------------------------------------------
  //
  // -------------------------------------------------------------

  // PERF: ---------------------- lecture12 -----------------------
  // exercise13_1();
  // exercise13_2(argc, argv);
  // -------------------------------------------------------

  // NOTE:---------------------- lecture13 -----------------------
  // exercise12_7_and_12_8();
  // -------------------------------------------------------

  // PERF: --------------------- StenSaksPapir.c ---------------------
  // stensakspapir_game();
  // -----------------------------------------------------------

  // NOTE: --------------------- Aflevering1.c ---------------------
  // aflevering1();
  // ---------------------------------------------------------

  // PERF: --------------------- Aflevering2.c ---------------------
  // int checkNum = 5;
  // int listLength = 100;
  // aflevering2(listLength, checkNum);
  // --------------------------------------------------------

  // NOTE: ---------------------- Aflevering3 ----------------------
  // Aflevering3();
  // ---------------------------------------------------------

  // PERF: --------------------- Mini project1.c --------------------
  // lommeregner();
  // miniproject1();
  // Main();
  //  ---------------------------------------------------------

  // NOTE: --------------------- Mini project2.c --------------------
  // miniproject2();
  //  ---------------------------------------------------------

  // PERF: --------------------- Mini project3.c --------------------
  // miniproject3();
  //   ---------------------------------------------------------

  // NOTE: ----------------------- LEETCODE --------------------------
  // int number = romanToInt("IVV");
  // printf("%d", number);
  // ---Max subarray---
  int numSize = 9;
  int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  printf("%d", maxSubArray(nums, numSize));
  //  -----------------------------------------------------------

  return 0;
}
