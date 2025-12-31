#ifndef LEETCODE_H
#define LEETCODE_H
#include <stdbool.h>

int romanToInt(char *s);
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2);
struct TreeNode *lcaDeepestLeaves(struct TreeNode *root);
int minimumOperations(int *nums, int numsSize);
int *twoSum(int *nums, int numsSize, int target, int *returnSize);
int *twoSumV2(int *nums, int numsSize, int target, int *returnSize);
bool canConstruct(char *ransomNote, char *magazine);
int lengthOfLongestSubstring(char *s);
int maxSubArray(int *nums, int numsSize);
#endif
