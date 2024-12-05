#include <stdio.h>
#include"game.h"
#include"gameUI.h"

void displayGameInstructions() {
    printf("==================================================\n");
    printf("                  1A2B Game Rules                 \n");
    printf("==================================================\n");
    printf("Welcome to the 1A2B Number Guessing Game!\n\n");
    printf("Game Instructions:\n");
    printf("1. The game is played between two roles: the 'Questioner' and the 'Guesser'.\n");
    printf("2. The goal is to guess a secret 4-digit number with no repeated digits.\n\n");
    
    printf("Definitions:\n");
    printf(" - 'A': A digit that is correct and in the correct position.\n");
    printf(" - 'B': A digit that is correct but in the wrong position.\n");
    printf("   Example: Secret = 1234, Guess = 1326 -> Response = 1A2B.\n\n");
    
    printf("Game Modes:\n");
    printf("1. Player as the Questioner:\n");
    printf("   - You think of a 4-digit number (e.g., 1234).\n");
    printf("   - The computer will attempt to guess it.\n");
    printf("   - After each guess, you must respond with the correct number of A's and B's.\n");
    printf("   - If inconsistent inputs are detected, the computer will declare 'YOU CHEAT'.\n\n");

    printf("2. Player as the Guesser:\n");
    printf("   - The computer generates a 4-digit secret number.\n");
    printf("   - You must guess the number and input your guess.\n");
    printf("   - The computer will respond with A's and B's until you get 4A0B ('YOU WIN').\n\n");

    
    printf("Enjoy the game and challenge your logic skills!\n");



    
    printf("Press any key can go back\n");
    printf("==================================================\n");
}

void displayGameStart(){
        printf("\n\
            ||-------------------------------------------------------------------------||\n\
            ||                 ____   _____    _________________                       ||\n\
            ||                /_   | /  _  \\   \\_____  \\______  \\                      ||\n\
            ||                 |   |/  /_\\  \\  /  ____/|    |  _/                      ||\n\
            ||                 |   /    |    \\/       \\|    |   \\                      ||\n\
            ||                 |___\\____|__  /\\_______ \\______  /                      ||\n\
            ||                             \\/         \\/      \\/                       ||\n\
            ||                                                                         ||\n\
            ||                                                                         ||\n\
            ||                     GAME INSTRUCTION       (press a)                    ||\n\
            ||                     GAME MODE              (press b)                    ||\n\
            ||                     GAME HISTORY           (press c)                    ||\n\
            ||                     GAME EXIT              (press x)                    ||\n\
            ||                                                                         ||\n\
            ||-------------------------------------------------------------------------||\n");
}

void displayGameModel() {
    printf("==================================================\n");
    printf("                  GAME MODE SELECTION             \n");
    printf("==================================================\n");
    printf("Please select a game mode by entering the corresponding number:\n\n");

    printf("1. Questioner Mode\n");
    printf("   - You think of a secret number, and the computer will guess it.\n");
    printf("   - Provide A and B feedback to guide the computer.\n\n");

    printf("2. Guesser Mode\n");
    printf("   - The computer thinks of a secret number, and you guess it.\n");
    printf("   - Receive A and B feedback until you find the correct answer.\n\n");

    printf("3. Two-Player Mode\n");
    printf("   - Two players take turns being the Questioner and Guesser.\n");
    printf("   - Enjoy a competitive and interactive gameplay experience.\n\n");

    printf("4. Computer vs. Player Mode\n");
    printf("   - Compete against the computer in a challenge to solve the number faster.\n");
    printf("   - Test your skills against an intelligent opponent!\n\n");

    printf("b. Back to Main Menu\n\n");

    printf("Enter your choice (1-4 or b): \n");
}
