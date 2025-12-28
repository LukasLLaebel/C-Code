
#include <stdio.h>

int tempVar(void) {
  int a = 5, b = 10, temp;
  printf("-------------\n");
  printf("a = %d, b = %d\n", a, b);

  // Swapping values of a and  b
  temp = a;
  a = b;
  b = temp;
  printf("a = %d, b = %d\n", a, b);
  return 0;
}

int withoutTemp() {
  int a = 5, b = 10;
  printf("-------------\n");
  printf("a = %d, b = %d\n", a, b);

  // Arithmetic operations to swap values
  a = a + b;
  b = a - b;
  a = a - b;
  printf("a = %d, b = %d\n", a, b);
  return 0;
}

// bitwise operator XOR
int xorSwap() {
  int a = 5, b = 10;
  printf("-------------\n");
  printf("a = %d, b = %d\n", a, b);

  // Apply XOR operations in the given order
  // to swap values
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
  printf("a = %d, b = %d\n", a, b);
  return 0;
}
