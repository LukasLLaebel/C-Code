#include <stdio.h>
#include <string.h>
#include "../lib/lecture9.h"

char *my_strrev(char *str);
int my_strcmp(char *str1, char *str2); 
char *strplural(char *str);
void longest_common_suffix(char *str1, char *str2);

//---------------- Funktionen strrev---------------------
int exercise10_1() {
    char input[50];

    printf("Enter text: ");
    scanf("%49s", input);

    printf("Reversed: %s\n", my_strrev(input));
    //printf("Reversed-STR_REV: %s\n", strrev(input));
  return 0;
}


char *my_strrev(char *str) {
    if (str == NULL) return NULL;  // handle null pointer safely

    char *start = str;
    char *end = str;
    char temp;

    // Move 'end' pointer to the end of the string
    while (*end != '\0') {
        end++;
    }
    end--; // step back from null terminator

    // Swap characters from start and end moving toward the center
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }

    return str; // return pointer to the reversed string
}


// --------------- Din egen udgave af funktionen strcmp ---------------

int exercise10_2() {
  char input[50];
  char* str = "String";
  //char arr[50] = {'S','t','r','i','n','g'};
  printf("Enter text ");
  scanf("%49s", input);
  
  int result = my_strcmp(input, str); 
 
  //printf("%d\n", strlen(str));
  //printf("%d\n", strlen(input));
  if (result == 0) {
    printf("Equal");
  } else {
    printf("Unequal");
  }


  //printf("strcmp %d\n",strcmp(input, str));
  
  return 0;
}

int my_strcmp(char* str1, char* str2) {
  int i = 0;
  while (str1[i] != '\0' && str2[i] != '\0') {
    if (str1[i] != str2[i]) {
      return str1[i] - str2[i];  // Return difference between chars
    }
    i++;
  }
  return str1[i] - str2[i];  // Handles different lengths too
}


// --------------------- Flertals navneord -----------------------

// rule
//1    Hvis et navneord ender i et "y" fjernes "y" og der tilføjes "ies".
//2    Hvis et navneord ender i et "s", "ch" eller "sh" tilføjes et "es".
//3    I alle andre tilfælde tilføjes et "s" til navneordet.

int exercise10_3() {
  // change to plural 
  char input[200];
  printf("Enter words: ");
  fgets(input, sizeof(input), stdin);

  // remove newline if present
  input[strcspn(input, "\n")] = '\0';

  char *token = strtok(input, " ");
  while (token != NULL) {
    char word[50];
    strcpy(word, token);
    strplural(word);
    printf("%s ", word);
    token = strtok(NULL, " ");
  }

    printf("\n");
}

char* strplural(char *str) {
    int len = strlen(str);
    
    
    // if word ends with 'y' replace with "ies"
    if (len > 0 && str[len - 1] == 'y') {
        str[len - 1] = 'i';
        str[len] = 'e';
        str[len + 1] = 's';
        str[len + 2] = '\0';
    }
        // if word ends with s, x, ch, sh → add "es"
    else if ((len > 0 && str[len - 1] == 's') ||
             (len > 1 && str[len - 2] == 'c' && str[len - 1] == 'h') ||
             (len > 1 && str[len - 2] == 's' && str[len - 1] == 'h') ||
             (len > 0 && str[len - 1] == 'x')) {
        str[len] = 'e';
        str[len + 1] = 's';
        str[len + 2] = '\0';

    } else {
        str[len] = 's';
        str[len + 1] = '\0';
    }

    return str;
}


// --------------------- Længste fælles endelse af to ord -------------------
int exercise10_4() {
  char input1[10];
  char input2[10];

  scanf("%9s", input1);
  scanf("%9s", input2);

  longest_common_suffix(input1, input2);


  return 0;
}

void longest_common_suffix(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i = len1 - 1;
    int j = len2 - 1;

    char suffix[50];
    int k = 0;

    // Compare from the end backwards
    while (i >= 0 && j >= 0 && str1[i] == str2[j]) {
        suffix[k++] = str1[i];
        i--;
        j--;
    }

    if (k == 0) {
        printf("No common ending\n");
        return;
    }

    // Reverse the suffix since we built it backwards
    suffix[k] = '\0';
    for (int a = 0; a < k / 2; a++) {
        char tmp = suffix[a];
        suffix[a] = suffix[k - a - 1];
        suffix[k - a - 1] = tmp;
    }

    printf("Longest common ending: %s\n", suffix);
}
