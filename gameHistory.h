#ifndef _History_
#define _History_

// Structure to store a single game record
typedef struct {
    char name[50];
    char mode[20];
    char grade[20];
    char date[20];
} GameRecord;

void displayGameHistory();
void generateRecord(char *name, char *mode, char *grade);


#endif