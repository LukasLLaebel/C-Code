#include <math.h>

/* 53. Maximum SubArray */
/* Using Kadane's algorithm */

// making macro for max comparation
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int maxSubArray(int *nums, int numsSize) {
  int current = 0;
  // starting with -infinity this macro is found in <math.h>
  double max = -INFINITY;
  int n = numsSize;

  // Store add up num to current and places the highest number into max
  for (int i = 0; i < n; ++i) {
    current += nums[i];
    max = MAX(max, current);
    // if the num is negative we set to 0
    if (current < 0) {
      current = 0;
    }
  }
  return max;
}
