#include <stdio.h>
#include <conio.h>
#include "game.h"
#include "gameUI.h"
#include "gameHistory.h"

// Helper function to calculate grade (attempt count as a string)
void calculateGrade(int attempts, char *grade) {
    int i = 0, j = 0, temp = attempts;
    char tempGrade[20];

    // Convert number to string in reverse order
    while (temp > 0) {
        tempGrade[i++] = (temp % 10) + '0';
        temp /= 10;
    }
    tempGrade[i] = '\0';

    // Reverse the string to get the correct order
    for (j = 0; j < i; j++) {
        grade[j] = tempGrade[i - j - 1];
    }
    grade[j] = '\0';
}

// Main game loop
int main() {
    char select; // User input selection

    while (1) {
        // Display the main menu
        displayGameStart();

        fflush(stdin); // Clear input buffer
        select = getch();

        // Validate main menu input
        if (select != 'a' && select != 'b' && select != 'c' && select != 'x') {
            printf("Invalid input! Please enter 'a', 'b', 'c', or 'x'.\n");
            continue;
        }

        if (select == 'a') {
            // Show game instructions
            displayGameInstructions();
            fflush(stdin);
            getch(); // Wait for user to proceed
        } else if (select == 'b') {
            // Enter game mode selection
            while (1) {
                displayGameModel(); // Show game modes menu
                fflush(stdin);
                select = getch();

                // Validate game mode input
                if (select != '1' && select != '2' && select != '3' && select != '4' && select != 'b') {
                    printf("Invalid input! Please enter '1', '2', '3', '4', or 'b'.\n");
                    continue;
                }

                if (select == '1') {
                    // Questioner mode
                    printf("==================================================\n");
                    printf("                GAME QUESTIONER MODE              \n");
                    printf("==================================================\n");
                    questioner();

                    // Record history
                    char grade[20];
                    calculateGrade(PcguessTime, grade);
                    generateRecord("Player", "QUESTIONER", grade);

                    printf("Press any key to continue.\n");
                    fflush(stdin);
                    getch();

                } else if (select == '2') {
                    // Guesser mode
                    printf("==================================================\n");
                    printf("                 GAME GUESSER MODE                \n");
                    printf("==================================================\n");
                    player();

                    printf("You Win!\n");
                    printf("You have guessed %d times!\n", PlayerguessTime);

                    // Record history
                    char grade[20];
                    calculateGrade(PlayerguessTime, grade);
                    generateRecord("Player", "GUESSER", grade);

                    printf("Press any key to continue.\n");
                    fflush(stdin);
                    getch();

                } else if (select == '3') {
                    // Two-Player mode
                    printf("==================================================\n");
                    printf("                GAME TWO-PLAYER MODE              \n");
                    printf("==================================================\n");
                    twoPlayerGame();

                    printf("Press any key to continue.\n");
                    fflush(stdin);
                    getch();

                } else if (select == '4') {
                    // PC vs Player mode
                    printf("==================================================\n");
                    printf("               GAME PC VS PLAYER MODE             \n");
                    printf("==================================================\n");

                    int playerGuessTime, pcGuessTime;

                    // Player guesses first
                    printf("You guess first!\n");
                    player();
                    playerGuessTime = PlayerguessTime;

                    printf("------------------------------------------------------------\n");
                    printf("Now you are the questioner!\n");
                    questioner();
                    pcGuessTime = PcguessTime;

                    // Display results
                    printf("Player vs Computer: %d : %d\n", playerGuessTime, pcGuessTime);
                    if(playerGuessTime!=100 && pcGuessTime!=100){
                        if (playerGuessTime < pcGuessTime) {
                            printf("Player wins!\n");
                            generateRecord("Player", "PC VS PLAYER", "Player Win");
                        } else if (playerGuessTime > pcGuessTime) {
                            printf("Computer wins!\n");
                            generateRecord("Player", "PC VS PLAYER", "Computer Win");
                        } else {
                            printf("It's a tie!\n");
                            generateRecord("Player", "PC VS PLAYER", "Tie");
                        }
                    }else{
                        printf("You cheat! So computer Win!");
                    }

                    // Prompt user for next action
                    printf("Press 'c' to continue or 'x' to exit.\n");
                    while (1) {
                        fflush(stdin);
                        select = getch();
                        if (select == 'c' || select == 'x') break;
                    }
                    if (select == 'x') return 0;

                } else {
                    // Back to main menu
                    break;
                }
            }
        } else if (select == 'c') {
            // Display game history
            displayGameHistory();
            printf("Press any key to continue.\n");
            fflush(stdin);
            getch();
        } else if (select == 'x') {
            // Exit the game
            printf("Exiting the game. Goodbye!\n");
            break;
        }
    }

    return 0;
}
