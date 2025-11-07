#ifndef GAME_OF_LINES_H
#define GAME_OF_LINES_H

void print_arena(char **arena, int size);
void update_arena(char **arena, int row, int col, char symbol);
int winner(char **arena, int size, int win_length);
void scan_move(char **arena, int size_of_arena, int player);
void ai_move(char **arena, int size_of_arena, int player);

#endif
