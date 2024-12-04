#include<stdio.h>
#include<

int main(){
    printf("Which do you want to be?\n");
    char select;
    printf("a.Questioner  b.Player (input a or b)");
    scanf("%c", select);
    if(select=='a'){
        questioner();
    }else if(select=='b'){
        player();
    }else{
        printf("Please input 'a' or 'b' again.");
    }
}