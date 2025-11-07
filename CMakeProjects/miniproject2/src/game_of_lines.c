#include <stdio.h>
#include <stdlib.h>

#include "game_of_lines.h"

// Implement functions defined in game_of_lines.h

void scan_settings(int *opponent_is_ai, int *size_of_arena, int *size_of_win_line) {
    printf("Welcome to Game of Lines!\n");

    printf("Play against (0) another player or (1) the computer? ");
    scanf("%d", opponent_is_ai);

    printf("Enter arena size (e.g. 3 for 3x3): ");
    scanf("%d", size_of_arena);

    printf("Enter how many in a row to win: ");
    scanf("%d", size_of_win_line);

    printf("\nSettings saved:\n");
    printf("  Opponent: %s\n", *opponent_is_ai ? "Computer" : "Player");
    printf("  Arena size: %d\n", *size_of_arena);
    printf("  Win line: %d\n\n", *size_of_win_line);
}

void print_arena(int size_of_arena) {
  //char board[size_of_arena][size_of_arena];
  cell board[size_of_arena][size_of_arena];
  for (int i = 0;i < size_of_arena;i++) {
    for (int j = 0; j < size_of_arena; j++) {
      board[i][j] = empty;
      print_cell(board[i][j]); 
    }
    printf("\n");
  }
}

void print_cell(cell c) {
  switch (c) {
    case empty: 
      printf("_ ");
      break;
    case p1:
      printf("X ");
      break;
    case p2: 
      printf("O ");
      break;
    case pc:
      printf("O ");
      break;
    default:
      printf("\nTABER FEJL!!!");
      exit(-1);
  }
}





