#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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

void generateRecord(char *record){
    for(int i=0; i<10000; i++){
        int digits[4];
        if(is_repeat(i) == 1){
            record[i] = 'X';
        }else{
            record[i] = 'O';
        }
    }
}

void updateRecord(char *record, char *numGuess, int type, int a, int b){
    for(int i=0; i<10000; i++){
        int tmp = i;
        if(record[i]=='O'){
            int check=0;//for check the before number have been the same
            if(type==0){
                for(int j=0; j<4; j++){
                    int tmpMod = tmp%10;
                    for(int k=0; k<4; k++){
                        if(numGuess[k]==tmpMod+'0'){
                            record[i] = 'X';
                        }
                    }
                    if(record[i]=='X')
                        break;
                    tmp/=10;
                }
            }else if(type==1 || type == 2){
                if(a==1 || (a==2&&b==0) ){
                    for(int j=3; j>=0; j--){
                        int tmpMod = tmp%10;
                        for(int k=0; k<4; k++){
                            if(numGuess[k]==tmpMod+'0'){
                                if(k!=j){
                                    record[i] = 'X';
                                }else if(k==j){
                                    if(check == a){
                                        record[i] = 'X';
                                    }else{
                                        check ++;
                                    }
                                    
                                }
                                    
                            }
                        }
                        if(record[i]=='X')
                            break;
                        tmp/=10;
                    }
                }else if(b==1 || (b==2&&a==0)){
                    for(int j=3; j>=0; j--){
                        int tmpMod = tmp%10;
                        for(int k=0; k<4; k++){
                            if(numGuess[k]==tmpMod+'0'){
                                if(k==j){
                                    record[i] = 'X';
                                }else if(k!=j){
                                    if(check == b){
                                        record[i] = 'X';
                                    }else{
                                        check ++;
                                    }
                                    
                                }
                                    
                            }
                        }
                        if(record[i]=='X')
                            break;
                        tmp/=10;
                    }
                }else{

                }
            }

        }
    }
}



void ZeroAB(char *record, char *numGuess){

    updateRecord(record, numGuess, 0, 0 ,0);

    //decide new numGuess
    for(int i=0; i<10000; i++){
        if(record[i] == 'O'){
            for(int j=3; j>=0; j--){
                numGuess[j] = i%10+'0';
                i/=10;
            }
            break;
        }
    }


}

void oneAB(char *record, char *numGuess, int a, int b){
    updateRecord(record, numGuess, a+b, a, b);

    //decide new numGuess
    for(int i=0; i<10000; i++){
        if(record[i] == 'O'){
            for(int j=3; j>=0; j--){
                numGuess[j] = i%10+'0';
                i/=10;
            }
            break;
        }
    }
}

void twoAB(char* record, char* numGuess, int a, int b){
    updateRecord(record, numGuess, a+b, a, b);
}


void deleteRecord(char *record, char *numGuess, int a, int b){
    int sum = a+b;
    if(sum==0){
        ZeroAB(record, numGuess);
    }else if(sum==1){
        oneAB(record, numGuess, a, b);
    }else if(sum==2){
        twoAB(record, numGuess, a, b);
    }else if(sum==3){
        //threeAB(record, numGuess, a, b);
    }else{
        //fourAB(record, numGuess, a, b);
    }

    for(int i=0; i<10000; i++){
        if(record[i]=='O')
            printf("%d ", i);
    }
}


int main(){
    int a=0,b=0;//for user to input A and B

    char numGuess[5];//the number that we guess
    char record[10001];//to record who can use who can't use
    generateNum(numGuess);
    generateRecord(record);
    numGuess[4]= '\0';
    record[10000]= '\0';

    while (a!=4)
    {
        printf("The answer is %s?\n", numGuess);
        printf("Please input _A_B(For example:1A0B->input 1 0)\n");
        scanf("%d %d",&a, &b);

        deleteRecord(record, numGuess, a, b);
        
    }
    
    

}