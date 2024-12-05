#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"game.h"

int PcguessTime=0;

void generateNum(char *arr){
    srand(time(NULL));

    for(int i=0; i<4; i++){
        arr[i] = rand()%10+'0';
        for(int j=0; j<i; j++){
            if(arr[i] == arr[j]){
                arr[i] = rand()%10+'0';
                j=-1;
            }
        }
    }

}

int is_repeat(int num){
    int check[10]={0};
    for(int i=0; i<4; i++){
        int place = num%10;
        check[place] = 1;
        num/=10;
    }
    int sum=0;
    for(int i=0; i<10; i++){
        sum+=check[i];
    }
    return sum==4? 0 : 1;
}

void generateTable(char *record){
    for(int i=0; i<10000; i++){
        int digits[4];
        if(is_repeat(i) == 1){
            record[i] = 'X';
        }else{
            record[i] = 'O';
        }
    }
}


void updateRecord(char *record, char *numGuess, int a, int b) {
    for (int i = 0; i < 10000; i++) {
        if (record[i] == 'O') {
            char candidate[5];
            int temp = i;
            for (int j = 3; j >= 0; j--) {
                candidate[j] = temp % 10 + '0';
                temp /= 10;
            }
            candidate[4] = '\0';

            // 計算候選答案的 A 和 B
            int aCount = 0, bCount = 0;
            for (int j = 0; j < 4; j++) {
                if (candidate[j] == numGuess[j]) {
                    aCount++;
                } else {
                    for (int k = 0; k < 4; k++) {
                        if (candidate[j] == numGuess[k]) {
                            bCount++;
                        }
                    }
                }
            }

            // 若不符合，將候選答案標記為無效
            if (aCount != a || bCount != b) {
                record[i] = 'X';
            }
        }
    }
}

int isValidInput(char *record, char *numGuess, int a, int b) {
    if (a + b > 4 || a < 0 || b < 0) {
        return 0; // 無效輸入
    }
    updateRecord(record, numGuess, a, b);

    int validCount = 0;
    for (int i = 0; i < 10000; i++) {
        if (record[i] == 'O') {
            validCount++;
        }
    }
    return validCount > 0; // 若無合法的候選答案，則視為作弊
}


void questioner(){
    int a=0,b=0;//for user to input A and B

    char numGuess[5];//the number that we guess
    char record[10001];//to record who can use who can't use
    generateNum(numGuess);
    generateTable(record);
    numGuess[4]= '\0';
    record[10000]= '\0';

    while (a!=4)
    {
        PcguessTime++;
        printf("The answer is %s?\n", numGuess);
        printf("Please input _A_B(For example:1A0B->input 1 0)\n");
        scanf("%d %d",&a, &b);

        //the number who isn't 4a should be cannel
        if(a!=4){
            int place=0;
            for(int i=0; i<4; i++){
                place+=numGuess[i]-'0';
                place*=10;
            }
            place/=10;
            record[place] = 'X';
        }

        if(!isValidInput(record, numGuess, a, b)){
            PcguessTime=100;
            printf("YOU CHEAT\n");
            break;
        }

        int OSum=0;
        for(int i=0; i<10000; i++){
            if(record[i]=='O'){
                OSum++;
            }
        }

        OSum/=2;
        for(int i=0; i<10000; i++){
            if(record[i]=='O'){
                OSum--;
                if(OSum==0 || OSum==-1){
                    for(int j=3; j>=0; j--){
                        numGuess[j] = i%10+'0';
                        i/=10;
                    }
                    break;
                }
            }
        }
        
    }
    
    

}