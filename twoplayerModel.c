// two_player_game.c
#include <stdio.h>
#include "game.h"

void twoPlayerGame() {
    char guesser[5]; // Array to store the player's guess (4 digits + null terminator)
    char record[10001]; // Array to record valid (O) and invalid (X) guesses
    generateTable(record); // Initialize the record table
    record[10000] = '\0'; // Null-terminate the record string

    int NumA = 0, NumB = 0; // Variables to store the number of correct digits in the correct position (A) and correct digits in the wrong position (B)
    int guessPlayer1Num = 0, guessPlayer2Num = 0; // Variables to store the number of guesses made by player 1 and player 2
    char round = 0; // Variable to keep track of the current round (turn)

    // Main game loop
    while (1) {
        if (round > 1) {
            break; // End the game after 2 rounds
        }

        // Print the current player's turn
        printf("Player%d guesses first!\n", round % 2 + 1);
        printf("Please input your answer.\n(Input four different number between 0 and 9)\n");

        // Update the guess count for the current player
        if (round % 2 + 1 == 1) {
            guessPlayer1Num++;
        } else {
            guessPlayer2Num++;
        }

        // Input loop to check for valid guesses (4 unique digits)
        while (1) {
            fflush(stdin); // Clear input buffer
            scanf("%4s", guesser); // Read the guess input
            guesser[4] = '\0'; // Null-terminate the string

            // Check if the guess contains duplicate digits
            int check = 0;
            for (int i = 0; i < 4; i++) {
                for (int j = i + 1; j < 4; j++) {
                    if (guesser[i] == guesser[j]) {
                        printf("Please input four different number between 0 and 9 again.\n");
                        check = 1; // Mark the guess as invalid
                        break;
                    }
                }
                if(check==1){
                    break;
                }
            }
            if (check == 0) {
                break; // Break out of the loop if the guess is valid
            }
        }

        // Ask the other player for the number of correct digits in the correct and incorrect positions (A and B)
        printf("Player%d give the hint!\n", round % 2 == 0 ? 2 : 1);
        printf("Please input _A_B(For example:1A0B->input 1 0)\n");
        scanf("%d %d", &NumA, &NumB); // Read the hint values (A and B)

        // If the guess is not fully correct (NumA != 4), invalidate the guess in the record
        if (NumA != 4) {
            int place = 0;
            for (int i = 0; i < 4; i++) {
                place += guesser[i] - '0'; // Convert the character digit to integer and accumulate
                place *= 10;
            }
            place /= 10;
            record[place] = 'X'; // Mark the guess as invalid in the record
        } else {
            // If the guess is correct (4A), print the results and proceed to the next round
            printf("Done!\n");
            printf("Player%d guess %d times.\n", round % 2 + 1, round % 2 + 1 == 1 ? guessPlayer1Num : guessPlayer2Num);
            round++; // Switch to the next round
            generateTable(record); // Regenerate the record table for the next round
            continue;
        }

        // Check if the input is valid, if not, print a cheat message
        if (!isValidInput(record, guesser, NumA, NumB)) {
            printf("Player%d CHEAT!\n", round % 2 + 1); // Print a message if cheating is detected
            break;
        }
    }

    // Determine the winner based on the number of guesses made
    if (guessPlayer1Num > guessPlayer2Num) {
        printf("Player2 Win the game!\n");
    } else {
        printf("Player1 Win the game!\n");
    }
}
