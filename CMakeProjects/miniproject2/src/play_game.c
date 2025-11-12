#include "game_of_lines.h"
#include "miniproject2.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game_of_lines(int opponent_is_ai, int size_of_arena, int size_of_win_line);

int miniproject2(void) {
  int opponent_is_ai, size_of_arena, size_of_win_line;

  scan_settings(&opponent_is_ai, &size_of_arena, &size_of_win_line);

  // Run the game
  game_of_lines(opponent_is_ai, size_of_arena, size_of_win_line);

  return 0;
}

void game_of_lines(int opponent_is_ai, int size_of_arena,
                   int size_of_win_line) {
  // used to set random seed. We do that by taking the current time on the
  // Computer it is used in the ai_move() to make random moves
  srand(time(NULL));

  int whose_turn = -1;
  int the_winner = 0;
  do {
    int posX, posY;

    // player 1 turn
    // 1. We scan for inputs
    // 2. We used the input to update the arena
    // 3. We use the updated arena data to print a new arena
    printf("Player 1 turn!\n");
    scan_move(size_of_arena, &posX, &posY);
    update_arena(p1, size_of_arena, posX, posY);
    print_arena(size_of_arena);

    // We check if the opponent_is_ai is true if that is the case it means the
    // user want to play aginst an AI / Computer because ai_move() includes
    // update_arena we do not include that here
    if (opponent_is_ai) {
      printf("Computer turn\n");
      ai_move(size_of_arena, &posX, &posY);
      print_arena(size_of_arena);

      // I opponent is not ai (!opponent_is_ai) it means the user wants to play
      // aginst another player
    } else if (!opponent_is_ai) {
      // We set the turn for player 2 (0) if whose_turn equal (1) then it is
      // player 1s turn
      whose_turn = 0;
      printf("Player 2 turn!\n");
      scan_move(size_of_arena, &posX, &posY);
      update_arena(p2, size_of_arena, posX, posY);
      print_arena(size_of_arena);
      whose_turn = 1;
      // otherwise we print out an error (this happens if user dont know how to
      // count from 0 to 1) or there is an mistake in the game

    } else {
      printf("\nInvalid");
      exit(-1);
    }

    // because winner() returns an int we want to store that in the variable
    // "the_winner" If the winner is equal to -1 the loop will keep going else
    // winner will equal the player identifier
    the_winner = winner(size_of_arena, size_of_win_line);

  } while (the_winner == -1);

  // Just printing the WINNER OF THE GAME!
  // Just to make it more dynamic we use an conditional expression
  // This makes us able to put a %s (string) format specifier into our printf()
  // and return an string equal to "player 2" if "the_winner" is equal to p2
  // else it will print computer
  if (the_winner == p1)
    printf("\nPlayer 1 (X) wins!\n");
  else
    printf("\n%s (O) wins!\n", the_winner == p2 ? "Player 2" : "Computer");
}
