#include <stdio.h>
#include <stdlib.h>
#include "project2.h"
#include "game_of_lines.h"

void scan_settings(int *opponent_is_ai, int *size_of_arena, int *size_of_win_line);
void game_of_lines(int opponent_is_ai, int size_of_arena, int size_of_win_line);

int project2() {
  int opponent_is_ai, size_of_arena, size_of_win_line;
  // scan_settings(...); should prompt the user for
  //  1. whether to play against AI or person,
  //  2. the size of the arena,
  //  3. how long a winning line needs to be.

  scan_settings(&opponent_is_ai, &size_of_arena, &size_of_win_line);  


  // Run the game
  game_of_lines(opponent_is_ai, size_of_arena, size_of_win_line);

  return 0;
}


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

void game_of_lines(int opponent_is_ai, int size_of_arena, int size_of_win_line) {
  // Create an arena (e.g. use HINT 1)
  int **arena = create_arena(size_of_arena);  // Allocate memory and set all cells to 0

  print_arena(arena, size_of_arena);

  int whose_turn = 0;  // Who should perform the next move: Player 0 or Player/Computer 1?
  int the_winner;
  do {
    // scan_move(...);
    //     or
    // ai_move(...);
    if (whose_turn == 0 || !opponent_is_ai) {
      scan_move(arena, size_of_arena, whose_turn);
    } else {
      ai_move(arena, size_of_arena, whose_turn);
    }

     // update_arena(...);

    // print_arena(...);
    print_arena(arena, size_of_arena);

     // the_winner = winner(...);
    the_winner = winner(arena, size_of_arena, size_of_win_line);

    whose_turn = 1 - whose_turn; // Switch player

  } while (the_winner == -1);

  printf("Player %d wins!\n", the_winner);
  free_arena(arena, size_of_arena); 
  // Print who won (the_winner).
}

