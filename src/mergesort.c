#include <stdio.h>
#include <stdlib.h>

void Merge(int L[], int start, int end, int mid);
void MergeSort(int L[], int start, int end);
void printList(int L[], int size);

int workshop3(void){
  int L[] = { 5, 3, 8, 1, 6, 10, 7, 2, 4, 9 , 11};
  int L_size = sizeof(L) / sizeof(L[0]);

  printf("Given list \n");
  printList(L, L_size);

  MergeSort(L, 0, L_size - 1);

  printf("The sorted list \n");
  printList(L, L_size);
  return 0;
}

void Merge(int L[], int start, int end, int mid){
    int n1 = mid - start + 1;     // size of left subarray
    int n2 = end - mid;           // size of right subarray

    int *L1 = (int *)malloc(n1 * sizeof(int));
    int *L2 = (int *)malloc(n2 * sizeof(int));

    // Copy data into temporary arrays
    for (int i = 0; i < n1; i++)
        L1[i] = L[start + i];
    for (int j = 0; j < n2; j++)
        L2[j] = L[mid + 1 + j];

    int i = 0, j = 0, k = start;

    // Merge both arrays back into L
    while (i < n1 && j < n2) {
        if (L1[i] <= L2[j]) {
            L[k] = L1[i];
            i++;
        } else {
            L[k] = L2[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L1[], if any
    while (i < n1) {
        L[k] = L1[i];
        i++;
        k++;
    }

    // Copy remaining elements of L2[], if any
    while (j < n2) {
        L[k] = L2[j];
        j++;
        k++;
    }

    free(L1);
    free(L2); 
}

void MergeSort(int L[], int start, int end){
  if (start < end) {
    int mid = (end + start) / 2;
    MergeSort(L, start, mid);
    MergeSort(L, mid + 1, end);
    Merge(L, start, end, mid);
  }
}

void printList(int L[], int size){
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", L[i]);
  printf("\n");
}
