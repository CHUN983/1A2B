#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include"game.h"

int PcguessTime = 0; // Global variable to track the number of guesses made by the computer.

// Generates a random 4-digit number with unique digits.
void generateNum(char *arr) {
    srand(time(NULL)); // Initialize random seed based on current time.
    for (int i = 0; i < 4; i++) {
        arr[i] = rand() % 10 + '0'; // Generate a random digit (0-9).
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) { // Ensure digits are unique.
                arr[i] = rand() % 10 + '0';
                j = -1; // Restart the check for duplicates.
            }
        }
    }
}

// Checks if a given 4-digit number contains duplicate digits.
// Returns 0 (no duplicates) or 1 (contains duplicates).
int is_repeat(int num) {
    int check[10] = {0}; // Array to track used digits.
    for (int i = 0; i < 4; i++) {
        int place = num % 10; // Extract the last digit.
        check[place] = 1; // Mark the digit as used.
        num /= 10; // Remove the last digit.
    }
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += check[i]; // Count unique digits.
    }
    return sum == 4 ? 0 : 1; // Return 0 if all digits are unique.
}

// Initializes the candidate table, marking numbers as valid ('O') or invalid ('X').
void generateTable(char *record) {
    for (int i = 0; i < 10000; i++) {
        if (is_repeat(i) == 1) {
            record[i] = 'X'; // Mark numbers with duplicate digits as invalid.
        } else {
            record[i] = 'O'; // Mark numbers with unique digits as valid.
        }
    }
}

// Updates the candidate table based on the guessed number and the (A, B) result.
void updateRecord(char *record, char *numGuess, int a, int b) {
    for (int i = 0; i < 10000; i++) {
        if (record[i] == 'O') {
            char candidate[5];
            int temp = i;
            for (int j = 3; j >= 0; j--) {
                candidate[j] = temp % 10 + '0'; // Convert candidate number to string.
                temp /= 10;
            }
            candidate[4] = '\0';

            int aCount = 0, bCount = 0; // Calculate A and B for the candidate.
            for (int j = 0; j < 4; j++) {
                if (candidate[j] == numGuess[j]) {
                    aCount++; // Count correct digits in the correct position (A).
                } else {
                    for (int k = 0; k < 4; k++) {
                        if (candidate[j] == numGuess[k]) {
                            bCount++; // Count correct digits in the wrong position (B).
                        }
                    }
                }
            }

            if (aCount != a || bCount != b) {
                record[i] = 'X'; // Mark candidates that don't match the result as invalid.
            }
        }
    }
}

// Validates the input (A, B) values and updates the candidate table.
// Returns 1 if input is valid, 0 otherwise.
int isValidInput(char *record, char *numGuess, int a, int b) {
    if (a + b > 4 || a < 0 || b < 0) {
        return 0; // Invalid if A+B exceeds 4 or if A/B are negative.
    }
    updateRecord(record, numGuess, a, b);

    int validCount = 0; // Count the number of remaining valid candidates.
    for (int i = 0; i < 10000; i++) {
        if (record[i] == 'O') {
            validCount++;
        }
    }
    return validCount > 0; // Return 1 if there are still valid candidates.
}

// Main logic for the questioner mode.
void questioner() {
    int a = 0, b = 0; // Variables to store A and B values from the user.
    char numGuess[5]; // String to store the guessed number.
    char record[10001]; // Candidate table.

    generateNum(numGuess); // Generate the first random guess.
    generateTable(record); // Initialize the candidate table.
    numGuess[4] = '\0'; // Ensure the guessed number string is null-terminated.
    record[10000] = '\0'; // Ensure the candidate table is null-terminated.

    while (a != 4) { // Loop until the correct answer is guessed (4A).
        PcguessTime++; // Increment the guess count.
        printf("The answer is %s?\n", numGuess);
        printf("Please input _A_B (e.g., 1A0B -> input 1 0)\n");
        scanf("%d %d", &a, &b); // Get A and B from the user.

        if (a != 4) { // If the guess is not correct:
            int place = 0;
            for (int i = 0; i < 4; i++) {
                place += numGuess[i] - '0';
                place *= 10;
            }
            place /= 10;
            record[place] = 'X'; // Mark the current guess as invalid.
        }

        if (!isValidInput(record, numGuess, a, b)) { // Check for invalid input.
            PcguessTime = 100; // Penalty score for cheating.
            printf("YOU CHEAT\n");
            printf("Press any key to be continue\n");
            fflush(stdin);
            char c = getch();

            break;
        }

        //Count how many record possibly in the record
        int OSum = 0;
        for (int i = 0; i < 10000; i++) {
            if (record[i] == 'O') {
                OSum++;
            }
        }

        OSum /= 2; // Find the midpoint of remaining candidates.
        for (int i = 0; i < 10000; i++) {
            if (record[i] == 'O') {
                OSum--;
                if (OSum == 0 || OSum == -1) {
                    int temp = i;
                    for (int j = 3; j >= 0; j--) {
                        numGuess[j] = temp % 10 + '0';
                        temp /= 10;
                    }
                    break;
                }
            }
        }
    }
}
