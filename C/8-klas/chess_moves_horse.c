// checks how many empty spaces on the chess there are to move a horse
// from random position

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int MovesHorse(int, int);
int main()
{
    int horse[8][8];
    int i, j;

    for(i = 0; i <= 7; i++){
        for(j = 0; j <= 7; j++){
            printf("position Horse - %d/%d has %d moves!\n", i + 1, j + 1, MovesHorse(i, j));
        }
    }
    return 0;
}

int MovesHorse(int i, int j)
{
    int br = 0;

    if(i - 2 <= 0){
        if(j - 1 >= 0) br++;
        if(j + 1 <= 7) br++;
    }
    if(j + 2 <= 7){
        if(i - 1 >= 0) br++;
        if(i + 1 <= 7) br++;
    }
    if(i + 2 <= 7){
        if(j - 1 >= 0) br++;
        if(j + 1 <= 7) br++;
    }
    if(j - 2 <= 0){
        if(i - 1 >= 1) br++;
        if(i + 1 <= 7) br++;
    }
    return br;
}
