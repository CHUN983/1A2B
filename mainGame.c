#include<stdio.h>
#include"game.h"


int main(){
    while(1){
        printf("Which do you want to be?\n");
        char select;
        printf("a.Questioner  b.Player (input a or b)\n");


        
        while (1){
            fflush(stdin);
            scanf("%c", &select);
            if(select!='a' && select!='b'){
                printf("Please input 'a' or 'b' again.\n");
            }else if(select=='a'){
                questioner();
                break;
            }else{
                player();
                break;
            }

        }

        printf("Do you want to play again? Yes or No\nPlease input y or n\n");
        while(1){
            fflush(stdin);
            scanf("%c", &select);
            if(select!='y' && select != 'n'){
                printf("Please input 'y' or 'n' again.\n");
            }else{
                break;
            }
        }

        if(select=='y'){
            continue;
        }else{
            break;
        }
    }

}