#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

// EXTERNAL CHANING

// OPEN ADDRESSING
typedef struct person {
  char name[MAX_NAME];
  int age;
  struct person *next;
} person;
// making hashtable (array of pointers to people)
// We use pointers mostly because of space
// We do not need space for the full table unless we accturly fill up
// the full table
// Make it easy to tell if the position is empty : NULL
person *hash_table[TABLE_SIZE];

unsigned int hashing(char *name) {

  // using a checkSum
  int length = strnlen(name, MAX_NAME);

  unsigned int hash_value = 0;
  // go thought the chars one at the time
  for (int i = 0; i < length; i++) {
    hash_value += name[i];
    hash_value = (hash_value * name[i]) % TABLE_SIZE;
  }
  // return sum
  return hash_value;
}

// initialize hashtable
void init_hash_table() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    hash_table[i] = NULL;
  }
  // empty table
}

void print_table() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    if (hash_table[i] == NULL) {
      printf("\t%i\t---\n", i);
    } else {
      printf("\t%i\t", i);
      person *tmp = hash_table[i];
      while (tmp != NULL) {
        printf("%s - ", tmp->name);
        tmp = tmp->next;
      }
      printf("\n");
    }
  }
}

bool hash_table_insert(person *p) {
  // no one is inputted
  if (p == NULL)
    return false;
  // compute hash on name
  int index = hashing(p->name);
  // add person to the front of list
  p->next = hash_table[index];
  hash_table[index] = p;
  return true;
}

person *hash_table_lookup(char *name) {
  // compute hash on name
  int index = hashing(name);
  person *tmp = hash_table[index];
  while (tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0) {
    tmp = tmp->next;
  }
  return tmp;
}

// with linear proping
person *hash_table_delete(char *name) {
  // compute hash on name
  int index = hashing(name);
  person *tmp = hash_table[index];
  person *prev = NULL;
  while (tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0) {
    prev = tmp;
    tmp = tmp->next;
  }
  if (tmp == NULL)
    return NULL;
  if (prev == NULL) {
    // Deleting the head
    hash_table[index] = tmp->next;
  } else {
    prev->next = tmp->next;
  }
  return tmp;
}

int EC_hashtableExample() {

  init_hash_table();
  // print_table(); // EMPTY TABLE

  // make some people:
  person jacob = {.name = "Jacob", .age = 26};
  person kate = {.name = "Kate", .age = 25};
  person tobias = {.name = "Tobias", .age = 17};
  person sarah = {.name = "Sarah", .age = 30};
  person edna = {.name = "Edna", .age = 16};
  person maren = {.name = "Maren", .age = 10};
  person robert = {.name = "Robert", .age = 50};
  person jane = {.name = "Jane", .age = 19};

  hash_table_insert(&jacob);
  hash_table_insert(&kate);
  hash_table_insert(&tobias);
  hash_table_insert(&sarah);
  hash_table_insert(&edna);
  hash_table_insert(&maren);
  hash_table_insert(&robert);
  hash_table_insert(&jane);

  print_table();

  // look up some names

  person *tmp = hash_table_lookup("Jacob");

  // did we find him?
  if (tmp == NULL) {
    printf("NOT FOUND! \n");
  } else {
    printf("Found %s\n", tmp->name);
  }

  tmp = hash_table_lookup("George");

  // did we find him?
  if (tmp == NULL) {
    printf("NOT FOUND! \n");
  } else {
    printf("Found %s\n", tmp->name);
  }

  // deleting
  hash_table_delete("Kate");

  tmp = hash_table_lookup("Kate");

  // did we find him?
  if (tmp == NULL) {
    printf("NOT FOUND! \n");
  } else {
    printf("Found %s\n", tmp->name);
  }
  print_table();

  /*
    printf("Jacob => %u\n", hashing("Jacob"));
    printf("Kate => %u\n", hashing("Kate"));
    printf("Tobias => %u\n", hashing("Tobias"));
    printf("Henrik => %u\n", hashing("Henrik"));
  */
  return 0;
}
