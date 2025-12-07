#ifndef AN_HASH_TABLE_H
#define AN_HASH_TABLE_H

#include <stdbool.h>

#define TABLE_SIZE 50

typedef struct team {
  char team[32];
  int team_points;
  int opponent_points;
  int points;
  struct team *next;
} team;

typedef struct match {
  char against[32];
  char date[8];
  char timestamp[16];
  char positions[16];
  char spectators[6];
  team *teams;
  struct match *next;
} match;

typedef struct hash_node {
  char key[32];   // team name
  match *matches; // linked list of matches for this team
  struct hash_node *next;
} hash_node;

// Global hash table
extern hash_node *hash_table[TABLE_SIZE];

// Hash table functions
void print_table();
void init_hash_table();
void hash_insert_team(const char *team_name, match *m);
void free_all_matches();
void track_match(match *m);

void printScoreBoard(char *teams[], int team_num);
void print_team_matches(const char *team);
#endif
