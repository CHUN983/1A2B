#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "gameHistory.h"

#define HISTORY_FILE "game_history.txt"

// Function to get current date as a string
void getCurrentDate(char *buffer) {
    time_t t;
    struct tm *tm_info;

    time(&t);
    tm_info = localtime(&t);
    strftime(buffer, 20, "%Y-%m-%d %H:%M", tm_info);
}

// Function to save a game record to file
void saveGameRecord(GameRecord record) {
    FILE *file = fopen(HISTORY_FILE, "a");
    if (file == NULL) {
        printf("Error: Could not open history file for writing.\n");
        return;
    }

    fprintf(file, "%s,%s,%s,%s\n", record.name, record.mode, record.grade, record.date);
    fclose(file);
}

void generateRecord(char *name, char *mode, char *grade){
    
    GameRecord gameLog;
    strcpy(gameLog.name, name);
    strcpy(gameLog.mode, mode);
    strcpy(gameLog.grade, grade);
    getCurrentDate(gameLog.date);

    saveGameRecord(gameLog);
}

// Function to display game history
void displayGameHistory() {
    FILE *file = fopen(HISTORY_FILE, "r");
    if (file == NULL) {
        printf("No game history found.\n");
        return;
    }

    printf("==============================================================\n");
    printf("                        GAME HISTORY                          \n");
    printf("==============================================================\n");
    printf("%-20s %-15s %-20s %-25s\n", "NAME", "MODEL", "GRADE", "DATE");
    printf("--------------------------------------------------------------\n");

    char line[150];
    while (fgets(line, sizeof(line), file)) {
        char name[50], mode[20], grade[20], date[20];
        sscanf(line, "%49[^,],%19[^,],%19[^,],%19[^\n]", name, mode, grade, date);
        printf("%-20s %-15s %-20s %-25s\n", name, mode, grade, date);
    }

    fclose(file);
    printf("=============================================================\n");
}

// Example of adding a record (can be called in game modes)
void addExampleRecord() {
    GameRecord record;
    strcpy(record.name, "Player1");
    strcpy(record.mode, "Guesser");
    strcpy(record.grade, "3 tries");
    getCurrentDate(record.date);

    saveGameRecord(record);
}
