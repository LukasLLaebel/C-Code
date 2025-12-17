//        {0, 0, 0, 0, 0, 0, 0, 0, 0},
//        {0, 0, 0, 0, 0, 0, 0, 0, 0},
//        {0, 0, 0, 0, 0, 0, 0, 0, 0},
//        {0, 0, 0, 0, 0, 0, 0, 0, 0},
//        {0, 0, 0, 0, 0, 0, 0, 0, 0},
//        {0, 0, 0, 0, 0, 0, 0, 0, 0},
//        {0, 0, 0, 0, 0, 0, 0, 0, 0},
//        {0, 0, 0, 0, 0, 0, 0, 0, 0},
//        {0, 0, 0, 0, 0, 0, 0, 0, 0}

#include <stdbool.h>
#include <stdio.h>

#define SIZE 9

// Function to print the grid
void printGrid(int grid[SIZE][SIZE]) {
  for (int row = 0; row < SIZE; row++) {
    for (int col = 0; col < SIZE; col++) {
      printf("%d ", grid[row][col]);
    }
    printf("\n");
  }
}

// Function to check if a number can be placed at grid[row][col]
bool isSafe(int grid[SIZE][SIZE], int row, int col, int num) {
  // Check if the number is already in the row
  for (int x = 0; x < SIZE; x++) {
    if (grid[row][x] == num) {
      return false;
    }
  }

  // Check if the number is already in the column
  for (int x = 0; x < SIZE; x++) {
    if (grid[x][col] == num) {
      return false;
    }
  }

  // Check if the number is already in the 3x3 subgrid
  int startRow = row - row % 3;
  int startCol = col - col % 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (grid[i + startRow][j + startCol] == num) {
        return false;
      }
    }
  }

  // If the number is not found in row, column, and subgrid, it's safe to place
  return true;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(int grid[SIZE][SIZE]) {
  int row, col;
  bool empty = false;

  // Find the next empty space (denoted by 0)
  for (row = 0; row < SIZE; row++) {
    for (col = 0; col < SIZE; col++) {
      if (grid[row][col] == 0) {
        empty = true;
        break;
      }
    }
    if (empty) {
      break;
    }
  }

  // If there are no empty spaces, the puzzle is solved
  if (!empty) {
    return true;
  }

  // Try all numbers from 1 to 9
  for (int num = 1; num <= SIZE; num++) {
    // Check if it's safe to place the number
    if (isSafe(grid, row, col, num)) {
      grid[row][col] = num;

      // Recursively attempt to solve the rest of the grid
      if (solveSudoku(grid)) {
        return true;
      }

      // If the number didn't work, backtrack
      grid[row][col] = 0;
    }
  }

  // If no number fits, return false (backtrack)
  return false;
}

int SudokuSolver() {
  // Example Sudoku puzzle (0 means empty)
  int grid[SIZE][SIZE] = {
      {0, 0, 0, 0, 3, 7, 2, 0, 0}, {0, 0, 7, 5, 9, 0, 0, 8, 6},
      {0, 4, 0, 0, 0, 0, 0, 0, 0}, {2, 0, 4, 0, 7, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 1, 0, 2, 0}, {0, 6, 0, 0, 2, 0, 8, 0, 7},
      {3, 0, 0, 6, 0, 0, 0, 0, 9}, {0, 7, 0, 0, 0, 0, 0, 0, 0},
      {5, 0, 0, 0, 0, 0, 0, 0, 0}};

  if (solveSudoku(grid)) {
    printf("Solved Sudoku:\n");
    printGrid(grid);
  } else {
    printf("No solution exists\n");
  }

  return 0;
}
