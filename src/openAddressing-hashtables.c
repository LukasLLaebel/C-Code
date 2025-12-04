/*#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (person *)(0xFFFFFFFFFFFFFFFFUL)

// EXTERNAL CHANING

// OPEN ADDRESSING
typedef struct {
  char name[MAX_NAME];
  int age;
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

/*void print_table() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    if (hash_table[i] == NULL) {
      printf("\t%i\t---\n", i);
    } else {
      printf("\t%i\t%s\n", i, hash_table[i]->name);
    }
  }
}

void print_table() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    if (hash_table[i] == NULL) {
      printf("\t%i\t---\n", i);
    } else if (hash_table[i] == DELETED_NODE) {
      printf("\t%i\t---<deleted>\n", i);
    } else {
      printf("\t%i\t%s\n", i, hash_table[i]->name);
    }
  }
}

/*bool hash_table_insert(person *p) {
  // no one is inputted
  if (p == NULL)
    return false;
  // compute hash on name
  int index = hashing(p->name);
  // somebody is aready there!
  if (hash_table[index] != NULL) {
    return false;
  }
  // point to table because the space is avalible
  hash_table[index] = p;
  return true;
}

// with linear proping
bool hash_table_insert(person *p) {
  // no one is inputted
  if (p == NULL)
    return false;
  // compute hash on name
  int index = hashing(p->name);
  // using linear proping, a way of dealing with coletions
  for (int i = 0; i < TABLE_SIZE; i++) {
    int try = (i + index) % TABLE_SIZE;
    if (hash_table[try] == NULL || hash_table[try] == DELETED_NODE) {
      hash_table[try] = p;
      return true;
    }
  }
  // every space is taken
  return false;
}

// find person in table
/*person *hash_table_lookup(char *name) {
  // compute hash on name
  int index = hashing(name);

  if (hash_table[index] != NULL &&
      // does the name on the index equal the name
      strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0) {
    return hash_table[index];
  } else {
    // person is not in table
    return NULL;
  }
}

// with linear proping
person *hash_table_lookup(char *name) {
  // compute hash on name
  int index = hashing(name);
  for (int i = 0; i < TABLE_SIZE; i++) {
    int try = (i + index) % TABLE_SIZE;
    if (hash_table[try] == NULL) {
      return false; // not found here
    }
    if (hash_table[try] == DELETED_NODE)
      continue;
    if (hash_table[try] != NULL &&
        // does the name on the index equal the name
        strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0) {
      return hash_table[try];
    }
  }
  // person is not in table
  return NULL;
}

/*person *hash_table_delete(char *name) {
  // compute hash on name
  int index = hashing(name);

  if (hash_table[index] != NULL &&
      // does the name on the index equal the name
      strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0) {
    // make tmp of the name and then setting the space to NULL so its empty,
    // now we return tmp to give user a output
    person *tmp = hash_table[index];
    hash_table[index] = NULL;
    return tmp;
  } else {
    // person is not in table
    return NULL;
  }
}

// with linear proping
person *hash_table_delete(char *name) {
  // compute hash on name
  int index = hashing(name);
  for (int i = 0; i < TABLE_SIZE; i++) {
    int try = (i + index) % TABLE_SIZE;
    if (hash_table[try] == NULL) {
      return NULL;
    }
    if (hash_table[try] == DELETED_NODE)
      continue;
    if (strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0) {
      person *tmp = hash_table[try];
      hash_table[try] = DELETED_NODE;
      return tmp;
    }
  }
  // person is not in table
  return NULL;
}

int hashtableExample() {

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

  return 0;
}*/
