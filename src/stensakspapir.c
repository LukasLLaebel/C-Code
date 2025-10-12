#include "stensakspapir.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROCK 'r'
#define PAPER 'p'
#define SCISSORS 's'

void stensakspapir_game(void) {
    bool uafgjort;
    char player1_choice, player2_choice;
    bool player1_winner;
    bool valid;

    do {
        printf("Indtast to hænder ('r', 'p', 's')\n");
        scanf(" %c %c", &player1_choice, &player2_choice);

        valid = (player1_choice != ROCK && player1_choice != PAPER && player1_choice != SCISSORS) ||
                (player2_choice != ROCK && player2_choice != PAPER && player2_choice != SCISSORS);
    } while (valid);

    printf("Player 1: %c\n Player 2: %c\n", player1_choice, player2_choice);

    player1_winner = (player1_choice == ROCK && player2_choice == SCISSORS) ||
                     (player1_choice == SCISSORS && player2_choice == PAPER) ||
                     (player1_choice == PAPER && player2_choice == ROCK);

    uafgjort =  (player1_choice == player2_choice);

    if (player1_winner) {
        printf("Player 1 wins\n");
    }
    else if (uafgjort) {
        printf("uafgjort\n");
    }
    else {
        printf("Player 2 wins\n");
    }
}
