// two_player_game.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ATTEMPTS 10

// 檢查玩家1的輸入是否有重複數字
int hasDuplicate(char *num) {
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (num[i] == num[j]) {
                return 1; // 重複
            }
        }
    }
    return 0; // 沒有重複
}

// 計算 A 和 B
void calculateAB(char *guess, char *answer, int *a, int *b) {
    *a = *b = 0;

    // 計算 A
    for (int i = 0; i < 4; i++) {
        if (guess[i] == answer[i]) {
            (*a)++;
        }
    }

    // 計算 B
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (guess[i] == answer[j] && i != j) {
                (*b)++;
            }
        }
    }
}

// 檢查 Player2 的輸入是否合理 (是否作弊)
int isValidAB(char *guess, char *answer, int a, int b) {
    int calculatedA = 0, calculatedB = 0;
    calculateAB(guess, answer, &calculatedA, &calculatedB);

    // 如果計算的 A 和 B 與 Player2 提供的不匹配，則視為作弊
    if (calculatedA != a || calculatedB != b) {
        return 0; // 作弊
    }
    return 1; // 合法
}

void twoPlayerGame() {
    char answer[5] = {'1', '2', '3', '4'};  // 假設答案是 '1234'
    char player1Guess[5];
    int player2A, player2B;
    int attempts = 0;

    printf("Player1, please guess a 4-digit number (with no repeating digits):\n");

    while (1) {
        attempts++;

        // 讓 Player1 輸入猜測
        printf("Attempt %d: Enter your guess: ", attempts);
        scanf("%s", player1Guess);
        if (strlen(player1Guess) != 4 || hasDuplicate(player1Guess)) {
            printf("Invalid input! Please enter 4 different digits.\n");
            continue;
        }

        // Player2 根據 Player1 的猜測輸入 A 和 B
        printf("Player2, enter the number of A and B for the guess '%s' (format: numA numB):\n", player1Guess);
        scanf("%d %d", &player2A, &player2B);

        if (!isValidAB(player1Guess, answer, player2A, player2B)) {
            printf("Player2 is cheating! The A and B values are not valid.\n");
            break;
        }

        // 如果 Player1 猜對了
        if (player2A == 4) {
            printf("Congratulations, Player1! You've guessed the correct number '%s' in %d attempts.\n", player1Guess, attempts);
            break;
        }
    }
}

int main() {
    printf("Welcome to the Two-Player Number Guessing Game!\n");
    twoPlayerGame();
    return 0;
}
