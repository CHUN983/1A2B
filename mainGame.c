#include<stdio.h>
#include<conio.h>
#include"game.h"


int main(){
    char select;
    while(1){
        displayGameStart();

        fflush(stdin);
        select = getch();
        if(select!='a' && select!='b' && select!='c' && select!='x'){
            printf("Please input 'a' or 'b' or 'c' or 'x' again!\n");
        }else if(select == 'a'){
            displayGameInstructions();
            fflush(stdin);
            select = getch();
        }else if(select=='b'){
            displayGameModel();
            fflush(stdin);
            select = getch();
            if(select!='1' && select!='2' && select!='3' && select!='4' && select!='b'){
                printf("Please input '1' or '2' or '3' or '4' or 'b' again!\n");
            }else if(select=='1'){
                printf("==================================================\n");
                printf("                GAME QUESTIONER MODEL             \n");
                printf("==================================================\n");
                questioner();
            }else if(select=='2'){
                printf("==================================================\n");
                printf("                 GAME GUESSER MODEL               \n");
                printf("==================================================\n");
                player();
                printf("You Win!\n");
                printf("You have guessed %d times!\n", PlayerguessTime);

                printf("Press any key to be continue.\n");
                fflush(stdin);
                select = getch();
            }else if(select =='3'){
                

            }else if(select =='4'){
                int player_GuessTime=0, pc_GuessTime=0;
                printf("==================================================\n");
                printf("               GAME PC VS PLAYER MODEL            \n");
                printf("==================================================\n");
                printf("You guess first!\n");
                player();
                player_GuessTime = PlayerguessTime;
                printf("------------------------------------------------------------\n");
                printf("Turn you are questioner!\n");
                questioner();
                pc_GuessTime = PcguessTime;

                //current problem： the player win and computer win can't show
                printf("player vs computer \n%d : %d\n", player_GuessTime, pc_GuessTime);
                
                if(player_GuessTime < pc_GuessTime){
                    printf("Player win!\n");
                }else if(player_GuessTime > pc_GuessTime){
                    printf("Computer win!\n");
                }else{
                    printf("Tie!\n");
                }

                printf("Press c to be continue.\n");
                printf("Press x to be exit.\n");

                while(1){
                    fflush(stdin);
                    select = getch();
                    if(select!='c' && select !='x'){
                        continue;
                    }else{
                        break;
                    }
                }
                if(select=='x'){
                    break;
                }



            }else{
                continue;
            }
        }else if(select=='c'){

        }else{
            break;
        }
    }


}