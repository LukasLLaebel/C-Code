#include "hashtables.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global hash table
hash_node *hash_table[TABLE_SIZE];
static match *all_matches_head = NULL;

void track_match(match *m) {
  m->next = all_matches_head;
  all_matches_head = m;
}

// FNV-1a hash function
unsigned int hashing(const char *team) {
  uint32_t hash = 2166136261u;
  while (*team) {
    hash ^= (uint8_t)*team++;
    hash *= 16777619u;
  }
  return hash % TABLE_SIZE;
}

// Initialize hash table
void init_hash_table() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    hash_table[i] = NULL;
  }
}

// Insert a match into hash table for a team
void hash_insert_team(const char *team_name, match *m) {
  unsigned int index = hashing(team_name);
  hash_node *node = hash_table[index];

  // Check if team already exists
  while (node) {
    if (strcmp(node->key, team_name) == 0) {
      // Add match to front of matches list
      m->next = node->matches;
      node->matches = m;
      return;
    }
    node = node->next;
  }

  // Create new node for this team
  node = calloc(1, sizeof(hash_node));
  if (!node) {
    printf("Allocation error!\n");
    return;
  }
  strncpy(node->key, team_name, sizeof(node->key) - 1);
  node->matches = m;
  node->next = hash_table[index];
  hash_table[index] = node;
}

void print_team_matches(const char *team) {
  unsigned int index = hashing(team);
  hash_node *node = hash_table[index];

  while (node) {
    if (strcmp(node->key, team) == 0) {
      match *m = node->matches;
      while (m) {
        printf("Team: %s, match: %s, Team points: %d, opponent points: %d \n",
               team, m->against, m->teams->team_points,
               m->teams->opponent_points);
        m = m->next;
      }
      return; // done, we found the team
    }
    node = node->next;
  }

  printf("No matches found for team %s\n", team);
}

int compare_points(const void *a, const void *b) {
  // Sort descending by points
  team *teamA = (team *)a;
  team *teamB = (team *)b;
  return teamB->points - teamA->points;
}

void printScoreBoard(char *teams[], int team_num) {
  team stats[100];

  for (int i = 0; i < team_num; i++) {
    unsigned int index = hashing(teams[i]);
    hash_node *node = hash_table[index];
    int team_sum = 0;
    int opponent_sum = 0;
    int teamPoints = 0;

    while (node) {
      if (strcmp(node->key, teams[i]) == 0) {
        match *m = node->matches;
        while (m) {
          if (m->teams->team_points > m->teams->opponent_points) {
            teamPoints += 3;
          } else if (m->teams->team_points == m->teams->opponent_points) {
            teamPoints += 1;
          }
          team_sum += m->teams->team_points;
          opponent_sum += m->teams->opponent_points;
          m = m->next;
        }
        break;
      }
      node = node->next;
    }

    strcpy(stats[i].team, teams[i]);
    stats[i].points = teamPoints;
    stats[i].team_points = team_sum;
    stats[i].opponent_points = opponent_sum;
  }

  // Sort teams by points
  qsort(stats, team_num, sizeof(team), compare_points);

  // Print table
  printf("| %-4s | %-6s | %-15s | %-15s |\n", "Team", "Points", "Team scored",
         "Opponent scored");
  printf("|------|--------|-----------------|-----------------|\n");

  for (int i = 0; i < team_num; i++) {
    printf("| %-4s | %-6d | %-15d | %-15d |\n", stats[i].team, stats[i].points,
           stats[i].team_points, stats[i].opponent_points);
  }
}

// Print entire hash table
void print_table() {
  printf("Hash table contents:\n");
  for (int i = 0; i < TABLE_SIZE; i++) {
    printf("[%03d]: ", i);
    hash_node *node = hash_table[i];
    if (!node) {
      printf("---\n");
      continue;
    }

    while (node) {
      match *m = node->matches;
      while (m) {
        printf("%s", m->teams->team);
        if (m->next)
          printf(" -> ");
        m = m->next;
      }
      if (node->next)
        printf(" | ");
      node = node->next;
    }
    printf("\n");
  }
}

void free_all_matches() {
  match *curr = all_matches_head;
  while (curr) {
    match *next = curr->next;
    free(curr);
    curr = next;
  }
  all_matches_head = NULL;

  for (int i = 0; i < TABLE_SIZE; i++) {
    hash_node *node = hash_table[i];
    while (node) {
      hash_node *next_node = node->next;
      free(node);
      node = next_node;
    }
    hash_table[i] = NULL;
  }
}
