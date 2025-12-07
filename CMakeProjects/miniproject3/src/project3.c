#include "hashtables.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printColumns(const char *filename) {
  // Try to open the input file for reading
  FILE *fp = fopen(filename, "r");
  if (!fp) {
    printf("Error: Could not open %s\n", filename);
    return;
  }

  char line[512];

  // Read file line-by-line
  while (fgets(line, sizeof(line), fp)) {

    // Remove trailing newline if present
    size_t len = strlen(line);
    if (len > 0 && line[len - 1] == '\n')
      line[len - 1] = '\0';

    // Buffers for each extracted column (max 5 columns)
    char col1[64] = "", col2[64] = "", col3[128] = "", col4[64] = "",
         col5[64] = "";
    int colIndex = 0;

    // Start scanning the line
    char *start = line;
    char *end;

    // Split columns based on **two or more spaces**
    while (*start && colIndex < 5) {

      // Skip leading spaces before next column
      while (*start == ' ')
        start++;

      end = start;
      int spaceCount = 0;

      // Find the end of this column: two consecutive spaces
      while (*end) {
        if (*end == ' ')
          spaceCount++;
        else
          spaceCount = 0;

        if (spaceCount >= 2) // found a separator
          break;
        end++;
      }

      // Trim trailing spaces inside this column segment
      char *tokenEnd = end - 1;
      while (tokenEnd > start && *tokenEnd == ' ')
        tokenEnd--;

      // Null-terminate the column string
      tokenEnd[1] = '\0';

      // Store extracted column into the right variable
      switch (colIndex) {
      case 0:
        strcpy(col1, start);
        break; // Date
      case 1:
        strcpy(col2, start);
        break; // Timestamp
      case 2:
        strcpy(col3, start);
        break; // Teams
      case 3:
        strcpy(col4, start);
        break; // Score
      case 4:
        strcpy(col5, start);
        break; // Spectators
      }

      colIndex++;
      start = end; // Move to the next section
    }

    // ------------------------------------------------------------
    //   Extract team names from col3
    char team1[32] = "", team2[32] = "";
    char temp[128];
    strcpy(temp, col3);

    char *dash = strstr(temp, "-");
    if (dash) {
      *dash = '\0'; // Split into two strings
      strcpy(team1, temp);
      strcpy(team2, dash + 1);

      // Trim whitespace from both ends of team1 and team2
      while (*team1 == ' ')
        memmove(team1, team1 + 1, strlen(team1));
      while (team1[strlen(team1) - 1] == ' ')
        team1[strlen(team1) - 1] = '\0';

      while (*team2 == ' ')
        memmove(team2, team2 + 1, strlen(team2));
      while (team2[strlen(team2) - 1] == ' ')
        team2[strlen(team2) - 1] = '\0';
    }
    // -----------------------------------------------------------
    // Extract team score from column 4
    int team1_points = -1, team2_points = -1;
    sscanf(col4, "%d - %d", &team1_points, &team2_points);

    // -----------------------------------------------------------
    // Extract only the time portion
    // (Does not get used anymore, but nice feature)
    char timeOnly[16] = "";
    char *space = strchr(col2, ' ');
    if (space)
      strcpy(timeOnly, space + 1);

    // Allocate memory for full match + the 2 teams
    match *m = calloc(1, sizeof(match));
    track_match(m); // Track global match list

    team *t1 = calloc(1, sizeof(team));
    team *t2 = calloc(1, sizeof(team));

    // does allocation fail?
    if (!m || !t1 || !t2) {
      printf("Allocation error!\n");
      continue;
    }

    // Fill match struct
    strncpy(m->date, col1, sizeof(m->date) - 1);
    strncpy(m->timestamp, col2, sizeof(m->timestamp) - 1);
    strncpy(m->against, col3, sizeof(m->against) - 1);
    strncpy(m->positions, col4, sizeof(m->positions) - 1);
    strncpy(m->spectators, col5, sizeof(m->spectators) - 1);

    // Fill team1 in team struct
    strncpy(t1->team, team1, sizeof(t1->team) - 1);
    t1->team_points = team1_points;
    t1->opponent_points = team2_points;

    // Fill team2 in team struct
    strncpy(t2->team, team2, sizeof(t2->team) - 1);
    t2->team_points = team2_points;
    t2->opponent_points = team1_points;

    // Link team list into match
    t1->next = t2;
    m->teams = t1;

    // Insert match into hash table for BOTH teams
    hash_insert_team(team1, m);
    hash_insert_team(team2, m);
  }

  fclose(fp);
}

int miniproject3(void) {

  init_hash_table();
  char choosing[10];
  int num_teams = 12;

  // Teams
  char *teams_24_25[] = {"AGF", "FCM", "FCN", "AaB", "SIF", "SJF",
                         "VB",  "RFC", "VFF", "BIF", "LBK", "FCK"};
  char *teams_25_26[] = {"VFF", "FCK", "FCF", "FCN", "VB",  "RFC",
                         "SJF", "AGF", "FCM", "OB",  "SIF", "BIF"};

  printf("Choose scoreboard: (24-25 or 25-26)");
  scanf("%9s", choosing);

  if (strcmp(choosing, "24-25") == 0) {
    printColumns("../CMakeProjects/miniproject3/src/kampe-2024-2025.txt");
    printScoreBoard(teams_24_25, num_teams);
    printf("================ LOOKUP TEAM MATCHES ================\n");
    for (int line = 0; line < 2; line++) {
      for (int j = line * (num_teams >> 1); j < (line + 1) * (num_teams >> 1);
           j++) {
        printf("    %s\t", teams_24_25[j]);
      }
      printf("\n");
    }

  } else if (strcmp(choosing, "25-26") == 0) {
    printColumns("../CMakeProjects/miniproject3/src/kampe-2025-2026.txt");
    printScoreBoard(teams_25_26, num_teams);
    printf("================ LOOKUP TEAM MATCHES ================\n");
    for (int line = 0; line < 2; line++) {
      for (int j = line * (num_teams >> 1); j < (line + 1) * (num_teams >> 1);
           j++) {
        printf("    %s\t", teams_25_26[j]);
      }
      printf("\n");
    }
  }
  printf("=====================================================");
  printf("\n\nLookup all matches for your team: ");
  scanf("%9s", choosing);

  print_team_matches(choosing);

  // print full table
  // print_table();

  free_all_matches();

  return 0;
}
