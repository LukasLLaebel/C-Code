#include "../lib/lecture12.h"
#include "../lib/ANSI-color-codes.h"
#include <stdio.h>
#include <string.h>

int getWords(FILE *pRf, int k, char *words);

int exercise13_1() {
  FILE *pRf = fopen(
      "personer-ind.txt",
      "r"); // fopen("filename.type", "mode: [w = write, a = append, r = read]")

  // Store the content of the file
  // char myString[100];

  // fgets(myString, 100, pRf);

  int k = 300;

  char words[k];

  int n = getWords(pRf, k, words);

  printf("the amount of words: %d in: \n\n%s", n, words);

  fclose(pRf); // close file

  return 0;
}

int getWords(FILE *pRf, int k, char *words) {
  int count = 0;
  char word[128];

  int used = 0;
  words[0] = '\0';

  while (count < k && fscanf(pRf, "%s", word) == 1) {
    int need = strlen(word) + (count > 0 ? 1 : 0);

    if (used + need + 1 >= k) {
      break; // no more room
    }

    if (count > 0) {
      strcat(words, " ");
      used++;
    }

    strcat(words, word);
    used += strlen(word);

    count++;
  }
  return count;
}

int exercise13_2(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: %s <search_string> <file>\n", argv[0]);
    return 1;
  }

  FILE *pRf = fopen(argv[2], "r");
  if (!pRf) {
    perror("Error opening file");
    return 1;
  }

  char line[1024];
  int num = 0;
  char *pos;
  size_t word_len = strlen(argv[1]);

  while (fgets(line, sizeof(line), pRf)) {
    char *current = line;
    int found_in_line = 0;

    while ((pos = strstr(current, argv[1])) != NULL) {
      // Print text before the match
      printf("%.*s", (int)(pos - current), current);
      // Print the matched word in red
      printf(RED "%.*s" WHT, (int)word_len, pos);

      current = pos + word_len;
      found_in_line = 1;
      num++;
    }

    if (found_in_line) {
      // Print remaining text after last match
      printf("%s", current);
    }
  }

  fclose(pRf);

  printf("\nFound " RED "%s" WHT " %d times\n", argv[1], num);
  return 0;
}
