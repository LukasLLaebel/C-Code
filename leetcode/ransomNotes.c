#include <malloc.h>
#include <stdbool.h>
#include <string.h>

// HashTable, 383. Ransom Note
bool canConstruct(char *ransomNote, char *magazine) {
  int lenR = strlen(ransomNote);
  int lenM = strlen(magazine);
  if (lenR > lenM) {
    return false;
  }
  int *mapRansomeNote = calloc(256, sizeof(int));
  int *mapMagazine = calloc(256, sizeof(int));
  for (int i = 0; i < lenR; i++) {
    mapRansomeNote[ransomNote[i]]++;
  }
  for (int i = 0; i < lenM; i++) {
    mapMagazine[magazine[i]]++;
  }
  for (int i = 0; i < 256; i++) {
    if (mapRansomeNote[i] > mapMagazine[i]) {
      return false;
    }
  }
  free(mapMagazine);
  free(mapRansomeNote);
  return true;
}
