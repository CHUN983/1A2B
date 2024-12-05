#ifndef _GAME_
#define _GAME_

extern int PlayerguessTime; // Global variable declaration
extern int PcguessTime; // Global variable declaration

void player();
void questioner();
void twoPlayerGame();
void generateTable(char *record);
int isValidInput(char *record, char *numGuess, int a, int b);

#endif