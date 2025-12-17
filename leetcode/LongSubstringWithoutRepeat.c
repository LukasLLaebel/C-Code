#include <string.h>

int lengthOfLongestSubstring(char *s) {
  int lastSeen[128]; // ASCII character positions
  for (int i = 0; i < 128; i++) {
    lastSeen[i] = -1;
  }

  int maxLen = 0;
  int start = 0;

  for (int i = 0; i < strlen(s); i++) {
    // If character was seen and is in current window
    if (lastSeen[(unsigned char)s[i]] >= start) {
      start = lastSeen[(unsigned char)s[i]] + 1;
    }

    lastSeen[(unsigned char)s[i]] = i;

    int currentLen = i - start + 1;
    if (currentLen > maxLen) {
      maxLen = currentLen;
    }
  }

  return maxLen;
}
