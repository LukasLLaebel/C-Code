#include "game_of_lines.h"
#include <stdio.h>
#include <stdlib.h>

// sets an max size
#define MAX_SIZE 100
// sets an 2D array as the board that stores enum cell values
cell board[MAX_SIZE][MAX_SIZE];

// just scans for the input:
// First input: 1 = computer | 0 = player (acts as an true falase (Boolean))
// Second input: enter arena size using one number
// third input: Set the amount of X or O you need to in one line to win
// At last it prints out the settings enabled for the game
void scan_settings(int *opponent_is_ai, int *size_of_arena,
                   int *size_of_win_line) {
  printf("Welcome to Game of Lines!\n");

  printf("Play against (0) another player or (1) the computer? ");
  scanf("%d", opponent_is_ai);

  printf("Enter arena size (e.g. 3 for 3x3): ");
  scanf("%d", size_of_arena);

  printf("Enter how many in a row to win: ");
  scanf("%d", size_of_win_line);

  printf("\nSettings saved:\n");
  // uses conditional expression to choose what to display
  printf("  Opponent: %s\n", *opponent_is_ai ? "Computer" : "Player");
  printf("  Arena size: %d\n", *size_of_arena);
  printf("  Win line: %d\n\n", *size_of_win_line);
}

// Prints an arena using every cell meaning
// if we have an 2x2 with the cell value empty it looks like this:
//  _ _
//  _ _
void print_arena(int size_of_arena) {
  // goes though every row, defined by size_of_arena
  for (int i = 0; i < size_of_arena; i++) {
    // goes though every column, defined by size_of_arena
    for (int j = 0; j < size_of_arena; j++) {
      print_cell(board[i][j]);
    }
    // when there is no more columns in a row we go to next line
    printf("\n");
  }
}

// Inspired by Morten from his "kryds og bolle" game
// This print_cell uses enum values to define specific
// charactors as a identifier
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
    // since it should work even if the user makes an mistake, will this mean
    // something is wrong in the code!
    printf("\nERROR WRONG CELL?");
    exit(-1);
  }
}

// uses data from user input to build the 2D array.
// The print_arena will then use it to make something graphical
void update_arena(cell player, int size_of_arena, int posX, int posY) {
  // first we check if the user has not put anything in.
  // This will make it posible to cheange the design,
  // so if the user want to se the board before the start
  if (player == empty) {
    for (int i = 0; i < size_of_arena; i++) {
      for (int j = 0; j < size_of_arena; j++) {
        board[i][j] = empty;
      }
    }
  }

  // Now we check if the input is a valid position.
  // It cannot be a negative number (-1, -2 ...)
  // It cannot be equal or greater than the size of the arena
  // that makes sense because an array have elements in the index of 0 - max but
  // the size_of_arena will be from 1 - max
  if (posX < 0 || posY < 0 || posX >= size_of_arena || posY >= size_of_arena) {
    // we give an saying message and gives the user another change
    printf("Invalid position!\n");
    scan_move(size_of_arena, &posX, &posY);
  }

  // We will then check if the position is already taken
  if (board[posY][posX] != empty) {
    // if the position is already taken we give an saying message and another
    // change
    printf("Cell already taken! Try again.\n");
    scan_move(size_of_arena, &posX, &posY);
  }
  // if everyhing is fine we just gives the position to the player
  board[posY][posX] = player;
}

// scan more just needs an input nothing fansy we have not seen
void scan_move(int size_of_arena, int *posX, int *posY) {

  // minus 1 because user should know the arena is displayed by 0 - max
  printf("Enter X position (0-%d): ", size_of_arena - 1);
  scanf("%d", posX); // No need to address because its a pointer
  printf("Enter Y position (0-%d): ", size_of_arena - 1);
  scanf("%d", posY);
}

// TODO MAKE THE AI SMARTER :)
void ai_move(int size_of_arena, int *posX, int *posY) {
  // Simple randomizer
  // Still validates if the area is already taken just why not :)
  while (board[*posY][*posX] != empty) {
    *posX = rand() % size_of_arena;
    *posY = rand() % size_of_arena;
  }
  // i do not know why i put the update here but like it makes space in main
  // soo...
  update_arena(pc, size_of_arena, *posX, *posY);
}

int winner(int size_of_arena, int size_of_win_line) {
  // a big nested loop
  // First part goes though every row
  for (int i = 0; i < size_of_arena; i++) {
    // now we goes though every coloumn
    for (int j = 0; j < size_of_arena; j++) {
      // we make an temp variable called current to store board value
      cell current = board[i][j];
      // We firstly checks if the position is empty then we go to next value
      // check. Meaning if its board[0][0] (1 row, 1 coloumn) and its empty, we
      // go to board[0][1]
      if (current == empty)
        continue;

      // <====== Check right ======>
      // if its not empty it means we found one!
      // So we start by counting every identifier we find
      int count = 1;
      // we set our index to k and say if k is shorter than size we will keep
      // going
      for (int k = 1; k < size_of_win_line; k++) {
        // We checks first if we are inside the board we dont want to go to far
        // if we are still inside the board we checks if the number on the right
        // is the same identifier we do that until it is not anymore the same
        // identifier or the size_of_win_line value has been hit
        if (j + k < size_of_arena && board[i][j + k] == current)
          // if that is true we increment the counter
          count++;
        // if these conditionals is not hit then we do not win :(
        // So we check the next win condition maybe we win in another way :)
        else
          break;
      }
      // if the we hit the line size it means we WON! JUUUHUUU!
      // so we returns our identifier so everyone know we won
      if (count >= size_of_win_line)
        return current;

      //  <====== Check down ======>
      // its kinda the same principle so i think you get it but there is just
      // one small diffrence
      count = 1;
      for (int k = 1; k < size_of_win_line; k++) {
        // this time instead of checking by incrementing the columns [j + k]
        // We increment the rows [i + k] This means we only compare every row in
        // this coloumn with each other if that did not make sense lets take an
        // example: lets say we are at board[0][1] (1 row, 2 coloumn) We will go
        // down to board[1][1] (2 row, 2 coloumn) and check if that is the same
        // as the identifier we look for
        if (i + k < size_of_arena && board[i + k][j] == current)
          // the rest is the same :(
          count++;
        else
          break;
      }
      if (count >= size_of_win_line)
        return current;

      // <====== Check down-right diagonal ======>
      // Now it gets fun or like idk not really
      count = 1;
      for (int k = 1; k < size_of_win_line; k++) {
        // this time we need to make sure where we are!
        // We need make sure we do not get out of the board in both the X axis
        // and the Y axis if that is not the issue we can check the right corner
        // we do that by incrementing both the rows and the coloumns
        // MEANING! If board[0 + 1][0 + 1] goes one down in the x axis and one
        // down in the y axis
        if (i + k < size_of_arena && j + k < size_of_arena &&
            board[i + k][j + k] == current)
          // the rest is still the same
          count++;
        else
          break;
      }
      if (count >= size_of_win_line)
        return current;

      // <====== Check down-left diagonal ======>
      // !! Just to make sure everyone gets it, its LEFT CORNER we go down from
      // this time !! Last time was right CORNER.
      count = 1;
      for (int k = 1; k < size_of_win_line; k++) {
        // It is kinda the same though same idea this time we just go the other
        // way We check if the next identifier is have space on the left and
        // have space down then we check if we go down [i+k] and one to the left
        // [j-k] is that then the identifier?
        if (i + k < size_of_arena && j - k >= 0 &&
            board[i + k][j - k] == current)
          // still the same as before
          count++;
        else
          break;
      }
      if (count >= size_of_win_line)
        return current;
    }
    // Just to make it clear i choose to place the diagonal checks at last
    // because its the ones that have the least change to be an case, therefore
    // if it end up being a win case it is more likely an x axis or y axis win
  }
  return -1; // no winner
}
