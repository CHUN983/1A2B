#ifndef _GAME_
#define _GAME_

extern int PlayerguessTime; // Global variable declaration
extern int PcguessTime; // Global variable declaration

void player(); // Function prototype for the player's game logic.
void questioner(); // Function prototype for the questioner's game logic.
void twoPlayerGame(); // Function prototype for the two-player game mode.
void generateTable(char *record); // Function prototype for generating a candidate table.
int isValidInput(char *record, char *numGuess, int a, int b); // Function prototype for validating input against rules.

#endif