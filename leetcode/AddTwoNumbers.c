#include <malloc.h>
#include <stddef.h>

// Linked lists, 2 add Two numbers
// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
  // Create a dummy head to simplify list construction
  struct ListNode *dummyHead =
      (struct ListNode *)malloc(sizeof(struct ListNode));
  dummyHead->val = 0;
  dummyHead->next = NULL;

  struct ListNode *current = dummyHead;
  int carry = 0;

  // Process both lists while at least one has nodes remaining
  while (l1 != NULL || l2 != NULL || carry != 0) {
    // Get values from current nodes (0 if list is exhausted)
    int val1 = (l1 != NULL) ? l1->val : 0;
    int val2 = (l2 != NULL) ? l2->val : 0;

    // Calculate sum and new carry
    int sum = val1 + val2 + carry;
    carry = sum / 10;
    int digit = sum % 10;

    // Create new node with the digit
    struct ListNode *newNode =
        (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = digit;
    newNode->next = NULL;

    current->next = newNode;
    current = current->next;

    // Move to next nodes if they exist
    if (l1 != NULL)
      l1 = l1->next;
    if (l2 != NULL)
      l2 = l2->next;
  }

  // Return the actual head (skip dummy)
  struct ListNode *result = dummyHead->next;
  free(dummyHead);
  return result;
}
