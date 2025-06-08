#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dice(){
    int a;
    a = (rand() % 6) + 1;
    return a;
}

int if_snake(int num){
    int snake[]={33,49,64,78,90,96};
    int new[]={5,25,37,55,75,65};
    int new_num;
    for(int i=0; i<6; i++){
        if(num==snake[i]){
            new_num=new[i];
            printf("The player at %d, snake found!! The player is now at: %d\n",num,new_num);
            return new_num;
        }
    }
    return num;
}

int if_ladder(int num){
    int ladder[]={6,19,34,56,74,80};
    int new[]={24,44,57,66,95,97};
    int new_num;
    for(int i=0; i<6; i++){
        if(num==ladder[i]){
            new_num=new[i];
            printf("The player at %d, ladder found... The player is now at: %d\n",num,new_num);
            return new_num;
        }
    }
    
    return num;
}

int main(){
    int no_dice, current,final_position;
    current=0;
    srand(time(NULL));
   do{
        no_dice=dice();
        printf("You rolled the dice and the number is: %d\n",no_dice);
        current= current+no_dice;
        if(current>100){
            printf("You rolled more than 100, so current position is %d/n",current-no_dice);
            current = current - no_dice;
        }
        current=if_ladder(current);
        current=if_snake(current);
        printf("Your current position is %d\n",current);
        no_dice=0;      
    }
    while(current<100);

    printf("Congratualtion you have won the game...");
}

