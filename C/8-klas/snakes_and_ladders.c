// plays a whole game of snakes and ladders and returns result + all made moves
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <malloc.h>

#define MAX_POSITION 100

typedef struct {
    unsigned char position;
    unsigned int move_count;
    unsigned char dice;
}player;

typedef struct {
    unsigned char from;
    unsigned char to;
}special_place;

special_place jumps[6] = { {26, 51}, {44, 54}, {37, 41}, {35, 15}, {57, 24}, {97, 78} };
int game_over = 0;

void do_move(player*, int);
int start_game(player*, int);
unsigned char roll_dice(void);

int main()
{
    int n, i;
    player* players;

    srand(time(NULL));

    printf("Hi!\n");
    printf("How many players are gonna be playing: ");
    scanf("%d", &n);

    players = calloc(n, sizeof(player));
    if (players == NULL) {
        printf("Not enough memory\n");
        return 0;
    }

    start_game(players, n);

    for (i = 0; i < n; i++) {
        if (players[i].position == MAX_POSITION) {
            printf("Player ->%d<- is the winner. This was their (%d) move and their last dice equaled to (%d)!\n", i + 1, players->move_count, players->dice);
            printf("Thanks for playing!");
        }
    }

    free(players);

    return 0;
}
int start_game(player* players, int n)
{
    int i;

    for (;;) {
        for (i = 0; i < n; i++) {
            do_move(&players[i], i);
            if (game_over) {
                return;
            }
        }
    }

    printf("game over");
}

unsigned char roll_dice()
{
    unsigned char dice;

    dice = rand() % 6;

    return dice + 1;
}

void do_move(player* p, int a)
{
    unsigned char dice, wanted_position, i, first_position = p->position;

    do {
        dice = roll_dice();
        p->dice = dice;

        if (p->position == 0 && dice != 6) {
            return;
        }

        if (p->position + dice > MAX_POSITION) {
            return;
        }

        wanted_position = p->position + dice;

        for (i = 0; i < 6; i++) {
            if (wanted_position == jumps[i].from) {
                wanted_position = jumps[i].to;
                break;
            }
        }

        p->position = wanted_position;
        p->move_count++;

        printf("This move was made by player (%d) he moved from position (%d) to position (%d) and his dice was (%d)\n", a + 1, first_position, p->position, dice);

        if (p->position == MAX_POSITION) {
            game_over = 1;
        }

    } while (dice == 6);
}

