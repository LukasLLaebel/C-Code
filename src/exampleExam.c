#include "stdio.h"
#include "stdlib.h"

int task8(void) {
  char str[] = "IMPR";
  char c = 'C';
  int i = 0;
  while ((c = str[++i])) {
    printf("%c", c);
  }
  return 0;
}

// task 11
int f(int x) {
  if (x < 0)
    return x;
  return (x - 1) + (2 * x);
}

// task 12
void load(int *x) {
  printf("x var %d", *x);
  scanf("%d", x);
}

int task12() {
  int x = 0;
  load(&x);
  printf("x er nu %d.", x);
  return 0;
}

// task 13
// task 13
char *get_text() {
  char *s = malloc(100 * sizeof(char));

  scanf("%99s", s);

  return s; // ❗ free(s) må IKKE være her
}

int task13() {
  const int size = 20;
  char *s = NULL;

  char **arr = malloc(size * sizeof(char *));
  //            ↑ malloc → skal matches med free(arr)

  for (int i = 0; i < size; i++) {
    s = get_text(); // malloc inde i get_text
    arr[i] = s;
  }

  for (int i = 0; i < size; i++) {
    s = arr[i];
    printf("%s\n", s);

    free(s); // ✅ MARKØR: frigiv hver streng
  }

  free(arr); // ✅ MARKØR: frigiv arrayet af pointere
  return 0;
}
