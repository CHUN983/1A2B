#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "gameHistory.h"

#define HISTORY_FILE "game_history.txt" // File to store game history

// Function to get the current date as a string
void getCurrentDate(char *buffer) {
    time_t t; // Time variable to store current time
    struct tm *tm_info; // Struct to store broken-down time

    time(&t); // Get current time
    tm_info = localtime(&t); // Convert to local time
    strftime(buffer, 20, "%Y-%m-%d %H:%M", tm_info); // Format as "YYYY-MM-DD HH:MM"
}

// Function to save a game record to the history file
void saveGameRecord(GameRecord record) {
    FILE *file = fopen(HISTORY_FILE, "a"); // Open file in append mode
    if (file == NULL) { // Check for file open error
        printf("Error: Could not open history file for writing.\n");
        return;
    }

    // Write the record in CSV format
    fprintf(file, "%s,%s,%s,%s\n", record.name, record.mode, record.grade, record.date);
    fclose(file); // Close the file
}

// Function to generate and save a game record
void generateRecord(char *name, char *mode, char *grade) {
    GameRecord gameLog; // Create a new game record

    // Copy input values to the record
    strcpy(gameLog.name, name);
    strcpy(gameLog.mode, mode);
    strcpy(gameLog.grade, grade);

    // Get and store the current date
    getCurrentDate(gameLog.date);

    // Save the game record to the history file
    saveGameRecord(gameLog);
}

// Function to display all game history
void displayGameHistory() {
    FILE *file = fopen(HISTORY_FILE, "r"); // Open the history file in read mode
    if (file == NULL) { // Check if the file exists
        printf("No game history found.\n");
        return;
    }

    // Print table headers
    printf("==========================================================================\n");
    printf("                              GAME HISTORY                                \n");
    printf("==========================================================================\n");
    printf("%-20s %-15s %-20s %-25s\n", "NAME", "MODEL", "GRADE", "DATE");
    printf("--------------------------------------------------------------------------\n");

    char line[150]; // Buffer to read each line
    while (fgets(line, sizeof(line), file)) { // Read each line from the file
        char name[50], mode[20], grade[20], date[20];

        // Parse the CSV line into individual fields
        sscanf(line, "%49[^,],%19[^,],%19[^,],%19[^\n]", name, mode, grade, date);

        // Print the parsed fields
        printf("%-20s %-15s %-20s %-25s\n", name, mode, grade, date);
    }

    fclose(file); // Close the file
    printf("==========================================================================\n");
}

// Example function to demonstrate adding a record
void addExampleRecord() {
    GameRecord record; // Create a new game record

    // Fill in example data
    strcpy(record.name, "Player1");
    strcpy(record.mode, "Guesser");
    strcpy(record.grade, "3 tries");

    // Get and store the current date
    getCurrentDate(record.date);

    // Save the example record to the history file
    saveGameRecord(record);
}
