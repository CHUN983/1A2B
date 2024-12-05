// two_player_game.c
#include <stdio.h>
#include"game.h"

void twoPlayerGame() {
    char guesser[5];
    char record[10001];//to record who can use who can't use
    generateTable(record);
    record[10000]= '\0';

    int NumA=0, NumB=0;
    int guessPlayer1Num=0,guessPlayer2Num=0;//record player1 and player2's score who can guess less time
    char round=0;

    while(1){
        if(round>1){
            break;
        }
        printf("Player%d guesses first!\n", round%2+1);
        printf("Please input your answer.\n(Input four different number between 0 and 9)\n");

        //first input the number
        if(round%2+1 == 1){
            guessPlayer1Num++;
        }else{
            guessPlayer2Num++;
        }
        while(1){
            fflush(stdin);
            scanf("%4s",guesser);
            guesser[4]='\0';

            //check the input not have the same number
            int check=0;
            for(int i=0; i<4; i++){
                for(int j=i+1; j<4; j++){
                    if( guesser[i]==guesser[j]){
                        printf("Please input four different number between 0 and 9 again.\n");
                        check=1;
                        break;
                    }
                }
            }
            if(check==0){
                break;
            }
        }

        //second let the other player to input NumA and NumB, and we should check the player have cheat or not
        printf("Player%d give the hint!\n", round%2==0? 2 : 1);
        printf("Please input _A_B(For example:1A0B->input 1 0)\n");
        scanf("%d %d",&NumA, &NumB);

        //the number who isn't 4a should be cannel
        if(NumA!=4){
            int place=0;
            for(int i=0; i<4; i++){
                place+=guesser[i]-'0';
                place*=10;
            }
            place/=10;
            record[place] = 'X';
        }else{
            printf("Done!\n");
            printf("Player%d guess %d times.\n",round%2+1, round%2+1==1? guessPlayer1Num : guessPlayer2Num);
            round++;
            generateTable(record);
            continue;
        }

        if(!isValidInput(record, guesser, NumA, NumB)){
            printf("Player%d CHEAT!\n",round%2+1);
            break;
        }


    }

    if(guessPlayer1Num > guessPlayer2Num){
        printf("Player2 Win the game!\n");
    }else{
        printf("Player1 Win the game!\n");
    }



}
