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
                questioner();
            }else if(select=='2'){
                player();
            }else if(select =='3'){

            }else if(select =='4'){

            }else{
                continue;
            }
        }else if(select=='c'){

        }else{
            break;
        }
    }

    
        // while (1){
        //     fflush(stdin);
        //     scanf("%c", &select);
        //     if(select!='a' && select!='b'){
        //         printf("Please input 'a' or 'b' again.\n");
        //     }else if(select=='a'){
                
        //         break;
        //     }else{
                
        //         break;
        //     }

        // }

        // printf("Do you want to play again? Yes or No\nPlease input y or n\n");
        // while(1){
        //     fflush(stdin);
        //     scanf("%c", &select);
        //     if(select!='y' && select != 'n'){
        //         printf("Please input 'y' or 'n' again.\n");
        //     }else{
        //         break;
        //     }
        // }

}