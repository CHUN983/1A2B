#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"game.h"
#include"gameHistory.h"

int PlayerguessTime = 0; // Initialize a global variable to count the number of player guesses.

void generateNumber(char *CPNum) {
    srand(time(0)); // Seed the random number generator with the current time to ensure variability.
    for (int i = 0; i < 4; i++) {
        CPNum[i] = (char)(rand() % 10 + '0'); // Generate a random digit (0-9).
        for (int j = 0; j < i; j++) {
            if (CPNum[j] == CPNum[i]) { // Ensure no duplicate digits.
                i--; // Retry the current position if a duplicate is found.
            }
        }
    }
    CPNum[4] = '\0'; // Null-terminate the string.
}

void player() {
    char CPNum[5] = {'0'}; // Array to store the computer-generated number.
    generateNumber(CPNum); // Generate a 4-digit non-repeating number.

    int check = 0; // Variable to track input validation status.
    while (1) {
        char playerNum[5]; // Buffer for the player's guess.
        if (check == 0) {
            printf("Please input your answer.\n(Input four different numbers between 0 and 9)\n");
        }
        check = 0;

        gets(playerNum); // Get the player's input. **(Unsafe: Consider using fgets instead.)**
        playerNum[4] = '\0'; // Null-terminate the string.

        // Check for duplicate digits in the player's input.
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                if (playerNum[i] == playerNum[j]) {
                    printf("Please input four different numbers between 0 and 9 again.\n");
                    check = 1;
                    break;
                }
            }
        }
        
        if (check == 1) {
            continue; // Prompt the user again if input is invalid.
        }

        int numA = 0, numB = 0; // Variables to count correct digits (A) and misplaced digits (B).
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (CPNum[i] == playerNum[j]) {
                    i == j ? numA++ : numB++; // Increment A for exact matches, B for partial matches.
                    break;
                }
            }
        }

        PlayerguessTime++; // Increment the guess counter.
        printf("%dA%dB\n", numA, numB); // Display the number of A and B.

        if (numA == 4) { // If the player guesses all 4 digits correctly.
            break; // Exit the loop and end the game.
        }
    }
}
