#ifndef GAME_OF_LINE_H
#define GAME_OF_LINE_H

typedef enum cell { empty, p1, p2, pc } cell;

void scan_settings(int *opponent_is_ai, int *size_of_arena,
                   int *size_of_win_line);

void print_arena(int size_of_arena);
void print_cell(cell c);
void scan_move(int size_of_arena, int *posX, int *posY);
void ai_move(int size_of_arena, int *posX, int *posY);
int winner(int size_of_arena, int size_of_win_line);
void update_arena(cell player, int size_of_arena, int posX, int posY);
#endif
