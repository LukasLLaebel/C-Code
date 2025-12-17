// HashTable, 3396. Minimum Number of Operations to Make Elements in Array
// Distinct
int minimumOperations(int *nums, int numsSize) {
  int operations = 0;
  for (int i = 0; i < numsSize; i++) {
    for (int j = i + 1; j < numsSize & i < numsSize; j++) {
      if (nums[i] == nums[j]) {
        operations += 1;
        nums += 3;
        numsSize -= 3;
        i = -1;
        break;
      }
    }
  }
  return operations;
}
