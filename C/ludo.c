// 8 klas

// classical ludo game

#include <stdio.h>
#include <stdlib.h>

#define  MAX_TURNS (500)

typedef enum {
    COLOR_GREEN = 0,
    COLOR_YELLOW,
    COLOR_RED,
    COLOR_BLUE
} t_color;

char* color_to_str[] = {
    "Green",
    "Yellow",
    "Red",
    "Blue"
};

typedef enum {
    STATE_START_POS = 0,
    STATE_REGULAR_ROAD,
    STATE_COLORED_ROAD,
    STATE_FINAL_POS
} t_state;

char* state_to_str[] = {
    "STATE_START_POS",
    "STATE_REGULAR_ROAD",
    "STATE_COLORED_ROAD",
    "STATE_FINAL_POS"
};

typedef struct {
    t_color   color;
    int       position;
    t_state   state;
    int       finished;
    void* pplayer;
} t_pawn;


typedef struct {
    t_pawn* ppawn;
}t_box;

typedef enum {
    PTYPE_BOT = 0,
    PTYPE_HUMAN
} t_player_type;

char* ptype_to_str[] = {
    "Bot",
    "Human"
};

typedef struct {
    t_color color;
    t_player_type type;
    int last_dice;
    int winner;
    int winner_on_turn;
    int pawns_taken;
    int rounds_played;
    t_pawn pawns[4];
}t_player;

t_box regular_road[56];
t_box colored_road[4][5];
t_player players[4];

int road_boarders_start[4] = { 0, 14, 28, 42 };
int road_boarders_end[4] = { 55, 13, 27, 41 };

void initialize_arrays(); // initializes
unsigned char roll_dice(); // dice
void do_game(); // game loop
int do_move_bot(t_player*); // function for bot
int do_move_human(t_player*); // function for human
int move_pawn_road(t_pawn*, unsigned char); // function that moves pawns on the normal road
int move_pawn_special(t_pawn*, unsigned char); // function that moves pawns on the colored road
void check_winner(t_player*); // checks for winner
void print_everything(); // prints stats
void print_regular_road(); // prints all boxes
void dialog_how_many_bots(); // asks how many bots you want in the game
void print_human_pawn_states(t_player*); // tells the human which pawn is where
void dialog_which_pawn(t_player*, unsigned char); // asks which pawn you want to use
char ret_char_color(int, int);
char ret_char_houses(int, int);

int global_turn = 0;

int main()
{
    srand(time(NULL));

    initialize_arrays();
    dialog_how_many_bots();
    do_game();

    return 0;
}

unsigned char roll_dice()
{
    return (rand() % 6) + 1;
}

void print_board_visuals()
{
    //houses
    printf("\n\n");
    printf("House Green: |%c| |%c| |%c| |%c|\n", ret_char_houses(0, 0), ret_char_houses(0, 1), ret_char_houses(0, 2), ret_char_houses(0, 3));
    // first argument for player, 0 for colored green, 1 yellow, 2 red, 3 blue
    // second argument for count pawn in line
    printf("House Yellow: |%c| |%c| |%c| |%c|\n", ret_char_houses(1, 0), ret_char_houses(1, 1), ret_char_houses(1, 2), ret_char_houses(1, 3));
    printf("House Red: |%c| |%c| |%c| |%c|\n", ret_char_houses(2, 0), ret_char_houses(2, 1), ret_char_houses(2, 2), ret_char_houses(2, 3));
    printf("House Blue: |%c| |%c| |%c| |%c|\n", ret_char_houses(3, 0), ret_char_houses(3, 1), ret_char_houses(3, 2), ret_char_houses(3, 3));
    printf("\n");

    printf("____________________________________________________________\n");
    // final top line
    printf("|                       | %c | %c | %c |                       |\n",
        ret_char_color(38, 0), ret_char_color(27, 0), ret_char_color(26, 0)); // first argument for position, second for type of road
    printf("|                       -------------                       |\n");
    // next line above
    printf("|                       | %c = %c = %c |                       |\n",
        ret_char_color(29, 0), ret_char_color(0, 3), ret_char_color(25, 0)); // first argument for position, second for type of road
    printf("|                       -------------                       |\n");
    // next line above
    printf("|                       | %c = %c = %c |                       |\n",
        ret_char_color(30, 0), ret_char_color(1, 3), ret_char_color(24, 0)); // first argument for position, second for type of road
    printf("|                       -------------                       |\n");
    // next line above
    printf("|                       | %c = %c = %c |                       |\n",
        ret_char_color(31, 0), ret_char_color(2, 3), ret_char_color(23, 0)); // first argument for position, second for type of road
    printf("|                       -------------                       |\n");
    // next line above
    printf("|                       | %c = %c = %c |                       |\n",
        ret_char_color(32, 0), ret_char_color(3, 3), ret_char_color(22, 0)); // first argument for position, second for type of road
    printf("|                   ---------------------                   |\n");
    // next line above
    printf("|                   | %c | %c = %c = %c | %c |                   |\n",
        ret_char_color(34, 0), ret_char_color(33, 0), ret_char_color(4, 3), // first argument for position, second for type of road
        ret_char_color(21, 0), ret_char_color(20, 0));
    printf("|-----------------------------------------------------------|\n");
    //the one above the middle
    printf("| %c | %c | %c | %c | %c | %c [   \\ %d /   ] %c | %c | %c | %c | %c | %c |\n",
        ret_char_color(40, 0), ret_char_color(39, 0), ret_char_color(38, 0), // first argument for position, second for type of road
        ret_char_color(37, 0), ret_char_color(36, 0), ret_char_color(35, 0),
        ret_count_pawns_final(2), // 0 for color green, 1 yellow, 2 red, 3 blue
        ret_char_color(19, 0), ret_char_color(18, 0), ret_char_color(17, 0),
        ret_char_color(16, 0), ret_char_color(15, 0), ret_char_color(14, 0));
    printf("|---=====================           =====================---|\n");
    //middle line
    printf("| %c | %c | %c | %c | %c | %c [ %d | X | %d ] %c | %c | %c | %c | %c | %c |\n",
        ret_char_color(41, 0), ret_char_color(0, 4), ret_char_color(1, 4), // first argument for position, second for type of road
        ret_char_color(2, 4), ret_char_color(3, 4), ret_char_color(4, 4),
        ret_count_pawns_final(3), ret_count_pawns_final(1), // 0 for color green, 1 yellow, 2 red, 3 blue
        ret_char_color(4, 2), ret_char_color(3, 2), ret_char_color(2, 2),
        ret_char_color(1, 2), ret_char_color(0, 2), ret_char_color(13, 0)); // 1 for colored green, 2 yellow, 3 red, 4 blue, 0 nothing
    printf("|---=====================           =====================---|\n");
    //the one under the middle
    printf("| %c | %c | %c | %c | %c | %c [   /\ %d \\   ] %c | %c | %c | %c | %c | %c |\n",
        ret_char_color(42, 0), ret_char_color(43, 0), ret_char_color(44, 0), // first argument for position, second for type of road
        ret_char_color(45, 0), ret_char_color(46, 0), ret_char_color(47, 0),
        ret_count_pawns_final(0),
        ret_char_color(7, 0), ret_char_color(8, 0), ret_char_color(9, 0),
        ret_char_color(10, 0), ret_char_color(11, 0), ret_char_color(12, 0));
    printf("|-----------------------------------------------------------|\n");
    // next line under
    printf("|                   | %c | %c = %c = %c | %c |                   |\n",
        ret_char_color(48, 0), ret_char_color(49, 0), ret_char_color(4, 1), // first argument for position, second for type of road
        ret_char_color(5, 0), ret_char_color(6, 0));
    printf("|                   ---------------------                   |\n");
    // next line under
    printf("|                       | %c = %c = %c |                       |\n",
        ret_char_color(50, 0), ret_char_color(3, 1), ret_char_color(4, 0)); // first argument for position, second for type of road
    printf("|                       -------------                       |\n");
    // next line under
    printf("|                       | %c = %c = %c |                       |\n",
        ret_char_color(51, 0), ret_char_color(2, 1), ret_char_color(3, 0)); // first argument for position, second for type of road
    printf("|                       -------------                       |\n");
    // next line under
    printf("|                       | %c = %c = %c |                       |\n",
        ret_char_color(52, 0), ret_char_color(1, 1), ret_char_color(2, 0)); // first argument for position, second for type of road
    printf("|                       -------------                       |\n");
    // next line under
    printf("|                       | %c = %c = %c |                       |\n",
        ret_char_color(53, 0), ret_char_color(0, 1), ret_char_color(1, 0)); // first argument for position, second for type of road
    printf("|                       -------------                       |\n");
    // final bottom line
    printf("|                       | %c | %c | %c |                       |\n",
        ret_char_color(54, 0), ret_char_color(55, 0), ret_char_color(0, 0)); // first argument for position, second for type of road
    printf("|                       -------------                       |\n");

    printf("____________________________________________________________\n");

}
int ret_count_pawns_final(int c)
{
    int i, count_pawns_in = 0;

    for (i = 0; i <= 3; i++) {
        if (players[c].pawns[i].state == STATE_FINAL_POS) {
            count_pawns_in++;
        }
    }

    return count_pawns_in;
}

char ret_char_houses(int p, int n)
{
    if (players[p].pawns[n].state != STATE_START_POS) {
        return ' ';
    }

    switch (players[p].pawns[n].color) {
    case COLOR_GREEN:
        return 'G';
    case COLOR_YELLOW:
        return 'Y';
    case COLOR_RED:
        return 'R';
    case COLOR_BLUE:
        return 'B';
    }


}

char ret_char_color(int n, int c)
{
    switch (c) {
    case(1):
        if (colored_road[n]->ppawn == NULL) {
            return ' ';
        }
        return 'G';
    case(2):
        if (colored_road[n]->ppawn == NULL) {
            return ' ';
        }
        return 'Y';
    case(3):
        if (colored_road[n]->ppawn == NULL) {
            return ' ';
        }
        return 'R';
    case(4):
        if (colored_road[n]->ppawn == NULL) {
            return ' ';
        }
        return 'B';
    }

    if (regular_road[n].ppawn == NULL) {
        return ' ';
    }

    switch (regular_road[n].ppawn->color) {
    case COLOR_GREEN:
        return 'G';
    case COLOR_YELLOW:
        return 'Y';
    case COLOR_RED:
        return 'R';
    case COLOR_BLUE:
        return 'B';
    }
}

void initialize_arrays()
{
    int i, j;

    players[0].color = COLOR_GREEN;
    players[1].color = COLOR_YELLOW;
    players[2].color = COLOR_RED;
    players[3].color = COLOR_BLUE;

    for (i = 0; i <= 4; i++) {
        players[i].type = PTYPE_HUMAN;
        players[i].last_dice = 0;
        players[i].pawns_taken = 0;
        players[i].rounds_played = 0;
        players[i].winner = 0;
        players[i].winner_on_turn = -1;
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            players[i].pawns[j].pplayer = (void*)&players[i];
            players[i].pawns[j].color = players[i].color;
            players[i].pawns[j].state = STATE_START_POS;
            players[i].pawns[j].position = -1;
        }
    }

    for (i = 0; i <= 55; i++) {
        regular_road[i].ppawn = NULL;
    }

    for (i = 0; i <= 5; i++) {
        colored_road[COLOR_GREEN][i].ppawn = NULL;
        colored_road[COLOR_RED][i].ppawn = NULL;;
        colored_road[COLOR_RED][i].ppawn = NULL;;
        colored_road[COLOR_BLUE][i].ppawn = NULL;;

    }

}

void do_game()
{
    int stop, a, i;

    for (;;) {
        stop = 0;
        global_turn++;
        if (global_turn > MAX_TURNS) {
            break;
        }
        printf("Turn %d ########################################################\n", global_turn);
        for (i = 0; i < 4; i++) {
            if (players[i].winner == 0) {
                printf("----------------------------------------------------------------\n");
                printf("The %s (%d) player, who is a %s, is on move\n", color_to_str[players[i].color], i + 1, ptype_to_str[players[i].type]); // color, num, human/bot
                if (players[i].type == PTYPE_BOT) {
                    do_move_bot(&players[i]);
                }
                else {
                    do_move_human(&players[i]);
                }
                check_winner(&players[i]);
            }
            else {
                stop++;
            }

        }

        print_everything(); // prints final results
        print_board_visuals();

        printf("\n\n");

        if (stop >= 3) {
            break;
        }

    }
}

int do_move_bot(t_player* pplayer)
{
    int i, pos, move_done;
    unsigned char dice;
    t_pawn* ppawn;

    for (i = 0; i < 3; i++) {
        dice = roll_dice();

        printf("The dice was rolled and it gave %d\n", dice);

        // tries to move the first pawn from colored road, because its prioritized
        move_done = 0;
        for (i = 0; i < 4; i++) {
            if (pplayer->pawns[i].state == STATE_COLORED_ROAD) {
                if (move_pawn_special(&pplayer->pawns[i], dice)) {
                    move_done = 1;
                    break;
                }
            }
        }

        if (move_done) {
            if (dice == 6) {
                continue;
            }
            break;
        }

        // tries to move pawns from regular road
        move_done = 0;
        for (i = 0; i < 4; i++) {
            if (pplayer->pawns[i].state == STATE_REGULAR_ROAD) {
                if (move_pawn_road(&pplayer->pawns[i], dice)) {
                    move_done = 1;
                    break;
                }
            }
        }

        if (move_done) {
            if (dice == 6) {
                continue;
            }
            break;
        }

        if (dice == 6) {
            ppawn = NULL;
            for (i = 0; i < 4; i++) {
                if (pplayer->pawns[i].state == STATE_START_POS) {
                    ppawn = &pplayer->pawns[i];
                    break;
                }
            }

            if (ppawn == NULL) {
                printf("No more pawns on start position!\n");
                continue;
            }

            pos = road_boarders_start[pplayer->color];

            if (regular_road[pos].ppawn != NULL) {
                if (regular_road[pos].ppawn->color == ppawn->color) {
                    printf("Cannot move!\n");
                    continue;
                }
                else {
                    printf("A %s pawn from regular road on position %d was hit and was "
                        "returned to the start position\n",
                        color_to_str[regular_road[pos].ppawn->color], regular_road[pos].ppawn->position);

                    regular_road[pos].ppawn->position = -1;
                    regular_road[pos].ppawn->state = STATE_START_POS;
                    regular_road[pos].ppawn = NULL;

                    pplayer->pawns_taken++;
                }
            }

            pplayer->pawns[i].state = STATE_REGULAR_ROAD;
            pplayer->pawns[i].position = pos;
            regular_road[pos].ppawn = &pplayer->pawns[i];

            printf("%s player placed a new pawn on the regular road on position %d\n",
                color_to_str[pplayer->color], pos);

        }

        if (dice != 6) {
            break;
        }
    }
}

int do_move_human(t_player* pplayer)
{
    int i;
    unsigned char dice;

    for (i = 0; i < 3; i++) {
        dice = roll_dice();

        printf("The dice was rolled and it gave %d\n", dice);
        print_human_pawn_states(pplayer); // tells the human which pawn is where
        dialog_which_pawn(pplayer, dice);

        if (dice != 6) {
            break;
        }
    }
}

int move_pawn_road(t_pawn* ppawn, unsigned char dice)
{
    int diff, i, pos, old_pos;
    t_player* pplayer;

    // goes to colored road
    if ((ppawn->position <= road_boarders_end[ppawn->color]) &&
        ((ppawn->position + dice) > road_boarders_end[ppawn->color])) {
        regular_road[ppawn->position].ppawn = NULL;
        old_pos = ppawn->position;
        ppawn->position += dice;
        ppawn->state = STATE_COLORED_ROAD;
        diff = ppawn->position - road_boarders_end[ppawn->color];

        if (diff == 6) {
            // goes to final position
            printf("A %s pawn from regular road, on position %d was moved to final position\n",
                color_to_str[ppawn->color], old_pos);
            ppawn->position = -1;
            ppawn->state = STATE_FINAL_POS;
        }
        else {
            colored_road[ppawn->color][diff].ppawn = ppawn;
            ppawn->position = diff - 1;
            printf("A %s pawn from regular road, on position %d was moved to colored road on position %d\n",
                color_to_str[ppawn->color], old_pos, ppawn->position);
        }
        return 1;
    }

    pos = ppawn->position + dice;

    if (pos > 55) {
        pos = pos - 55;
    }

    printf("desired position %d\n", pos);

    if (regular_road[pos].ppawn != NULL) {
        printf("desired position is occupied\n");
        if (regular_road[pos].ppawn->color != ppawn->color) {
            printf("A %s pawn from regular road on position %d was hit and "
                "returned to the start position\n",
                color_to_str[regular_road[pos].ppawn->color], pos);
            regular_road[pos].ppawn->position = -1;
            regular_road[pos].ppawn->state = STATE_START_POS;
            printf("A %s pawn from regular road on position %d moved to position %d\n",
                color_to_str[ppawn->color],
                ppawn->position, pos);
            regular_road[pos].ppawn = ppawn;

            regular_road[ppawn->position].ppawn = NULL;
            ppawn->position = pos;
            pplayer = (t_player*)ppawn->pplayer;
            pplayer->pawns_taken++;
            return 1;
        }
        return 0;
    }

    regular_road[ppawn->position].ppawn = NULL;
    printf("A %s pawn from regular road on position %d was moved to position %d\n",
        color_to_str[ppawn->color],
        ppawn->position, pos);

    ppawn->position = pos;
    regular_road[ppawn->position].ppawn = ppawn;
    return 1;
}


int move_pawn_special(t_pawn* ppawn, unsigned char dice)
{
    int i, old_pos;

    if (ppawn->position + dice > 5) {
        return 0;
    }

    colored_road[ppawn->color][ppawn->position].ppawn = NULL;
    old_pos = ppawn->position;
    ppawn->position += dice;

    if (ppawn->position > 4) {
        ppawn->position = -1;
        ppawn->state = STATE_FINAL_POS;
        return 1;
    }

    colored_road[ppawn->color][ppawn->position].ppawn = ppawn;

    printf("A %s pawn from colored road on position %d "
        "was moved to position %d\n",
        color_to_str[ppawn->color], old_pos, ppawn->position);

    return 1;
}

void check_winner(t_player* pplayer)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (pplayer->pawns[i].state != STATE_FINAL_POS) {
            return;
        }
    }

    pplayer->winner = 1;
    pplayer->winner_on_turn = global_turn;
}

void print_everything()
{

    int i, j;
    printf("---------\n");
    printf("Stats of the end of the turn:\n");
    for (i = 0; i < 4; i++) {
        printf("\tPlayer %s (%s): %s", color_to_str[players[i].color], ptype_to_str[players[i].type], players[i].winner == 0 ? "still in the game\n" : "winner on turn ");
        if (players[i].winner) {
            printf("%d\n", players[i].winner_on_turn);
        }
        printf("\t\tTaken pawns: %d\n", players[i].pawns_taken);
        for (j = 0; j < 4; j++) {
            //trace()
            printf("\t\tPawn[%d] - state: %s, position: %d\n", j, state_to_str[players[i].pawns[j].state], players[i].pawns[j].position);
        }
    }
}

void print_regular_road()
{
    int i;
    for (i = 0; i < 56; i++) {
        if (regular_road[i].ppawn == 0) {
            printf("%d - NULL\n", i);
        }
        else {
            printf("%d - %s\n", i, color_to_str[regular_road[i].ppawn->color]);
        }
    }
}


void dialog_how_many_bots()
{
    int b = 0;
    printf("How many bots do you want to add [0-4]: ");

    do {
        scanf("%d", &b);
    } while (b < 0 || b > 4);

    while (b) {
        players[b - 1].type = PTYPE_BOT;
        b -= 1;
    }
}

void print_human_pawn_states(t_player* pplayer)
{
    int pawns_in_start = 0, pawns_on_regular = 0,
        pawns_on_colored = 0, pawns_finished = 0, i;

    for (i = 0; i < 4; i++) {
        switch (pplayer->pawns[i].state)
        {
        case STATE_START_POS:
            pawns_in_start += 1;
            break;
        case STATE_REGULAR_ROAD:
            pawns_on_regular += 1;
            break;
        case STATE_COLORED_ROAD:
            pawns_on_colored += 1;
            break;
        case STATE_FINAL_POS:
            pawns_finished += 1;
            break;

        default:
            break;
        }
    }

    printf("%s player is human and has:\n", color_to_str[pplayer->color]);
    printf("\t%d pawns on start position\n", pawns_in_start);
    printf("\t%d pawns on regular road\n", pawns_on_regular);
    printf("\t%d pawns on colored road\n", pawns_on_colored);
    printf("\t%d pawns on final position\n", pawns_finished);
    printf("\n");
}

void dialog_which_pawn(t_player* pplayer, unsigned char dice)
{
    int i, pos, old_pos, diff, choice = 0;
    int possibles[4] = { 0, 0, 0, 0 };
    int possibles_count = 0;
    t_pawn* ppawn;

    for (i = 0; i < 4; i++) {
        ppawn = &pplayer->pawns[i];
        switch (ppawn->state) {
        case (STATE_START_POS):
            if (dice == 6) {
                if (regular_road[road_boarders_start[pplayer->color]].ppawn == NULL ||
                    regular_road[road_boarders_start[pplayer->color]].ppawn->color != pplayer->color)
                {
                    printf("You can move pawn number %d from start position to playing field.\n", i + 1);
                    possibles[i] = 1;
                    possibles_count++;
                }
            }
            break;
        case (STATE_REGULAR_ROAD):

            if ((ppawn->position <= road_boarders_end[ppawn->color]) &&
                ((ppawn->position + dice) > road_boarders_end[ppawn->color]))
            {
                pos = ppawn->position + dice;
                diff = pos - road_boarders_end[ppawn->color];

                if (diff == 6) {
                    // go to final position
                    printf("You can move pawn number %d from pos %d, regular road, "
                        "and it will go to final position.\n", i + 1, ppawn->position);
                    possibles[i] = 1;
                    possibles_count++;
                }
                else {
                    // go to colored road
                    pos = diff - 1;
                    if (colored_road[pplayer->color][pos].ppawn == NULL) {
                        printf("You can move pawn number %d from pos %d, regular "
                            "road, and it will go to colored road, position %d.\n",
                            i + 1, ppawn->position, pos);
                        possibles[i] = 1;
                        possibles_count++;
                    }
                }
            }
            else {
                // only regular road
                pos = ppawn->position + dice;
                if (pos > 55) {
                    pos = pos - 55;
                }

                if (regular_road[pos].ppawn == NULL || regular_road[pos].ppawn->color != pplayer->color) {
                    printf("You can move pawn number %d from pos %d, regular "
                        "road, to position %d on the same road.\n",
                        i + 1, ppawn->position, pos);
                    possibles[i] = 1;
                    possibles_count++;
                }
            }

            break;
        case (STATE_COLORED_ROAD):
            if (ppawn->position + dice > 5) {
                break;
            }

            pos = ppawn->position + dice;

            if (ppawn->position > 4) {
                printf("You can move pawn number %d from pos %d, colored road, "
                    "and it will go to final position.\n", i + 1, ppawn->position);
                possibles[i] = 1;
                possibles_count++;
            }
            else {
                printf("You can move pawn number %d from pos %d, colored "
                    "road, to position %d on the same road.\n",
                    i + 1, ppawn->position, pos);
                possibles[i] = 1;
                possibles_count++;
            }
            break;
        case (STATE_FINAL_POS):
            break;
        }
    }

    if (possibles_count == 0) {
        printf("Unfortunately, you cannot move!\n");
        return;
    }

    do {
        printf("You have %d options. Please, make a choice between ", possibles_count);
        for (i = 0; i < 4; i++) {
            if (possibles[i]) {
                printf("%d ", i + 1);
            }
        }
        printf(": ");
        choice = -1;
        scanf("%d", &choice);
    } while (choice < 1 || choice > 4 || possibles[choice - 1] == 0);

    ppawn = &pplayer->pawns[choice - 1];

    switch (ppawn->state) {
    case (STATE_START_POS):
        pos = road_boarders_start[pplayer->color];
        if (regular_road[pos].ppawn != NULL) {
            printf("A %s pawn from regular road on position %d was hit and was "
                "returned to the start position\n",
                color_to_str[regular_road[pos].ppawn->color],
                regular_road[pos].ppawn->position);

            regular_road[pos].ppawn->position = -1;
            regular_road[pos].ppawn->state = STATE_START_POS;
            regular_road[pos].ppawn = NULL;

            pplayer->pawns_taken++;
        }

        ppawn->state = STATE_REGULAR_ROAD;
        ppawn->position = pos;
        regular_road[pos].ppawn = ppawn;

        printf("%s player placed a new pawn on the regular road on position %d\n",
            color_to_str[pplayer->color], pos);
        break;
    case (STATE_REGULAR_ROAD):
        move_pawn_road(ppawn, dice);
        break;
    case (STATE_COLORED_ROAD):
        move_pawn_special(ppawn, dice);
        break;
    case (STATE_FINAL_POS):
        break;
    }
}
