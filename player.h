#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int player(){


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
    int check=0;
    while(1){
        
        char playerNum[5];
        if(check==0){
            printf("Please input your answer.\n(Input four different number between 0 and 9)\n");
        }
        check=0;

        //player input number
        gets(playerNum);
        playerNum[4]='\0';

        //check the input not have the same number
        for(int i=0; i<4; i++){
            for(int j=i+1; j<4; j++){
                if( playerNum[i]==playerNum[j]){
                    printf("Please input four different number between 0 and 9 again.\n");
                    check=1;
                    break;
                }
            }
        }
        if(check==1){
            continue;
        }
        
        

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