#include <malloc.h>
#include <stddef.h>
// HashTable, 1. Two Sum
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {

  static int result[2]; // static so it survives after function returns

  // Check numbers through first time

  for (int i = 0; i < numsSize; i++) {

    // check numbers second time

    for (int j = i + 1; j < numsSize; j++) {

      // if numbers from first time plus second time equals the target then
      // return it

      if (nums[i] + nums[j] == target) {

        result[0] = i;

        result[1] = j;

        // tell how many numbers get returned

        *returnSize = 2;

        return result;
      }
    }
  }

  // if it does not add up nothing is returned

  *returnSize = 0;

  return NULL;
}

// HashTable, 1. Two Sum v2
#define TABLE_SIZE 20011 // prime number > max input size

typedef struct {
  int key;
  int value;
  int used;
} HashNode;

int hash(int key) { return (key % TABLE_SIZE + TABLE_SIZE) % TABLE_SIZE; }

int *twoSumV2(int *nums, int numsSize, int target, int *returnSize) {
  HashNode table[TABLE_SIZE] = {0};

  for (int i = 0; i < numsSize; i++) {
    int complement = target - nums[i];
    int idx = hash(complement);

    // Search for complement
    while (table[idx].used) {
      if (table[idx].key == complement) {
        int *result = (int *)malloc(2 * sizeof(int));
        result[0] = table[idx].value;
        result[1] = i;
        *returnSize = 2;
        return result;
      }
      idx = (idx + 1) % TABLE_SIZE;
    }

    // Insert current number
    idx = hash(nums[i]);
    while (table[idx].used) {
      idx = (idx + 1) % TABLE_SIZE;
    }
    table[idx].used = 1;
    table[idx].key = nums[i];
    table[idx].value = i;
  }

  *returnSize = 0;
  return NULL;
}
