#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparison function
int compare_int(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
}

int qsortingInt() {
  int arr[] = {10, 5, 4, 6, 9};
  int n = sizeof(arr) / sizeof(arr[0]);

  qsort(arr, n, sizeof(int), compare_int);

  printf("Following is the sorted array: ");

  int i;
  for (i = 0; i < n; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}

// Comparison function
int compare_str(const void *arg1, const void *arg2) {
  return strcasecmp(*(const char **)arg1, *(const char **)arg2);
}

int qsortingChar(char *arr[], int size) {
  // char *colors[]  = {"B", "D", "A", "W", "Z", "X", "M", "O"};
  int i;

  printf("Original array elements:\n");
  for (i = 0; i < size; i++) {
    printf("%s ", arr[i]);
  }

  printf("\n\n");

  // Use qsort to sort
  qsort(arr, size, sizeof(char *), compare_str);
  printf("Following is the sorted array: ");

  for (i = 0; i < size; ++i) {
    printf("%s ", arr[i]);
  }
  return 0;
}

int qsortingStr(void) {
  char *colors[] = {"Vivek", "Aman", "Shriansh", "Tapas"};
  int i;
  // Size of the array
  int size = sizeof(colors) / sizeof(colors[0]);

  printf("Original array elements:\n");
  for (i = 0; i < size; i++) {
    printf("%s ", colors[i]);
  }

  printf("\n");

  // Use qsort to sort
  qsort(colors, size, sizeof(char *), compare_str);
  printf("Following is the sorted array: ");

  for (i = 0; i < size; ++i) {
    printf("%s ", colors[i]);
  }
  return 0;
}

// Helper function to swap two elements
static void swap(void *a, void *b, size_t size) {
  unsigned char *p1 = (unsigned char *)a;
  unsigned char *p2 = (unsigned char *)b;
  unsigned char temp;

  for (size_t i = 0; i < size; i++) {
    temp = p1[i];
    p1[i] = p2[i];
    p2[i] = temp;
  }
}

// Helper function to get pointer to element at index
static void *get_element(void *base, size_t index, size_t size) {
  return (unsigned char *)base + (index * size);
}

// Partition function for quicksort
static size_t partition(void *base, size_t low, size_t high, size_t size,
                        int (*compar)(const void *, const void *)) {
  // Choose the rightmost element as pivot
  void *pivot = get_element(base, high, size);
  size_t i = low;

  for (size_t j = low; j < high; j++) {
    void *current = get_element(base, j, size);
    // If current element is smaller than or equal to pivot
    if (compar(current, pivot) <= 0) {
      swap(get_element(base, i, size), get_element(base, j, size), size);
      i++;
    }
  }

  // Swap pivot to its correct position
  swap(get_element(base, i, size), get_element(base, high, size), size);
  return i;
}

// Recursive quicksort implementation
static void quicksort_recursive(void *base, size_t low, size_t high,
                                size_t size,
                                int (*compar)(const void *, const void *)) {
  if (low < high) {
    // Partition the array and get pivot index
    size_t pi = partition(base, low, high, size, compar);

    // Recursively sort elements before and after partition
    if (pi > 0) {
      quicksort_recursive(base, low, pi - 1, size, compar);
    }
    quicksort_recursive(base, pi + 1, high, size, compar);
  }
}

// Main qsort implementation
void my_qsort(void *base, size_t nitems, size_t size,
              int (*compar)(const void *, const void *)) {
  if (nitems <= 1 || base == NULL || compar == NULL) {
    return; // Nothing to sort
  }

  quicksort_recursive(base, 0, nitems - 1, size, compar);
}

// ============== TEST FUNCTIONS ==============

int test_int_sorting() {
  int arr[] = {10, 5, 4, 6, 9};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Original integer array:  ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  my_qsort(arr, n, sizeof(int), compare_int);

  printf("Sorted integer array:    ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n\n");
  return 0;
}

int test_string_sorting() {
  char *colors[] = {"Vivek", "Aman", "Shriansh", "Tapas"};
  int size = sizeof(colors) / sizeof(colors[0]);

  printf("Original string array: ");
  for (int i = 0; i < size; i++) {
    printf("%s ", colors[i]);
  }
  printf("\n");

  my_qsort(colors, size, sizeof(char *), compare_str);

  printf("Sorted string array:   ");
  for (int i = 0; i < size; i++) {
    printf("%s ", colors[i]);
  }
  printf("\n\n");
  return 0;
}

int test_char_array_sorting() {
  char *arr[] = {"B", "D", "A", "W", "Z", "X", "M", "O"};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Original char array:  ");
  for (int i = 0; i < size; i++) {
    printf("%s ", arr[i]);
  }
  printf("\n");

  my_qsort(arr, size, sizeof(char *), compare_str);

  printf("Sorted char array:   ");
  for (int i = 0; i < size; i++) {
    printf("%s ", arr[i]);
  }
  printf("\n\n");
  return 0;
}
