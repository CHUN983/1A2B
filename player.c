#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(){


    //generate four numbers and they don't repeat
    char CPNum[5]={'0'};//store numbers series
    srand(time(0));    //let the random numbers don't the same that everytimes open;
    for(int i=0; i<4 ;i++){
        CPNum[i]  = (char) (rand()%10+'0');
        for(int j=0; j<i; j++){
            if(CPNum[j]==CPNum[i]){
                i--;
            }
        }
    }
    CPNum[4]='\0';


    int guessTime=0;//record user have guessed how many time
    while(1){
        char playerNum[5];

        printf("Please input your answer.\n\
(Input four different number between 0 and 9)\n");

        //player input number
        gets(playerNum);
        playerNum[4]='\0';

        //record the player have guessed the number of A and B
        int numA=0, numB=0;
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                if(CPNum[i]==playerNum[j]){
                    i==j? numA++ : numB++;
                    break;
                }
            }
        }

        guessTime++;
        printf("%dA%dB\n",numA,numB);//tell user how many A and B

        if(numA==4){
            printf("You Win!\n");
            printf("You have guessed %d times!", guessTime);
            break;
        }

    }

}