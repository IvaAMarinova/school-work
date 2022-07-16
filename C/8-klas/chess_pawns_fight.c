// chess board filled with pawns
// two human players fight

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define True 1
#define False 0


typedef struct {
    unsigned char sx;
    unsigned char sy;
    unsigned char dx; 
    unsigned char dy;
} move_t; 

typedef enum {
    E_BLACK,
    E_WHITE
} color_e;

typedef enum {
    E_INGAME,
    E_OUTOFGAME
} status_e;

typedef enum {
    E_PAWN,
    E_KNIGHT,
    E_BISHOP,
    E_KING,
    E_QUEEN,
    E_ROOK
} typefig_e;

typedef struct {
    unsigned char x;
    unsigned char y;
    color_e color;
    typefig_e type;
    status_e status;
} piece_t;

piece_t white_pawns[8];
piece_t black_pawns[8];

piece_t* board[8][8];

void init_board();
void print_board();
void player_white_move();
void player_black_move();
int check_winner();
void print_board();
int input_check_format();
int input_check_source_white();
int input_check_destination_white();
move_t parse_input();
unsigned char transform(char);
void player_do_move(move_t);
int input_check_source_black(move_t);
int input_check_destination_black(move_t);

int main()
{
    init_board();

    printf("Hi! You are looking at my game of chess. \nUnfortunately it has only pawns for now, but hey, it still works!\n");
    printf("The game is made for two players, two human players. \nSo bring a friend, if you have one, of course...\n");
    printf("No worries if you don't, you can still play against yourself! Good luck!\n");

    print_board();

    for (;;) {
        player_white_move();
        print_board();
        if (check_winner() == True) {
            return;
        }

        player_black_move();
        print_board();
        if (check_winner() == True) {
            return;
        }
    }

    return 0;
}
void init_board()
{
    int i, j;
    for (i = 0; i <= 7; i++) {

        white_pawns[i].x = i;
        white_pawns[i].y = 6;
        white_pawns[i].color = E_WHITE;
        white_pawns[i].type = E_PAWN;
        white_pawns[i].status = E_INGAME;

        black_pawns[i].x = i;
        black_pawns[i].y = 1;
        black_pawns[i].color = E_BLACK;
        black_pawns[i].type = E_PAWN;
        black_pawns[i].status = E_INGAME;

        for (j = 0; j <= 7; j++) {
            if (j == 1) {
                board[i][j] = &black_pawns[j];
            }
            else if (j == 6) {
                board[i][j] = &white_pawns[j];
            }
            else {
                board[i][j] = NULL;
            }
        }
    }
}
void player_white_move()
{
    char inp[32];
    move_t move;
    for (;;) {
        printf("Enter your move, White. It must be in this format \"a2->a3\": ");
        scanf("%s", inp);
        if (input_check_format(inp) == False) {
            printf("Move format invalid, please try again.\n");
            continue;
        }

        move = parse_input(inp);

        if (input_check_source_white(move) == False) {
            printf("Source field is invalid, please try again.\n");
            continue;
        }
        if (input_check_destination_white(move) == False) {
            printf("Destination field is invalid, please try again.\n");
            continue;
        }
        player_do_move(move);
        break;
    }
}
void print_board()
{
    int i, j;
    for (j = 0; j <= 7; j++) {
        printf("  +---+---+---+---+---+---+---+---+\n");
        printf("%d |", 8 - j);
        for (i = 0; i <= 7; i++) {
            printf(" %s ", (board[i][j] == NULL ? " " : (board[i][j]->color == E_WHITE ? "W" : "B")));
            printf("|");
        }
        printf("\n");
    }
    printf("  +---+---+---+---+---+---+---+---+\n");
    printf("    A   B   C   D   E   F   G   H\n");
}
int input_check_format(char* s)
{
    if (strlen(s) != 6) {
        return False;
    }

    if (s[2] != '-' && s[3] != '>') {
        return False;
    }

    if (s[0] < 'a' || s[0] > 'h') {
        return False;
    }

    if (s[4] < 'a' || s[4] > 'h') {
        return False;
    }

    if (s[1] < '1' || s[1] > '8') {
        return False;
    }

    if (s[1] < '1' || s[5] > '8') {
        return False;
    }
    if (s[0] == s[4] && s[2] == s[5]) {
        return False;
    }
    return True;
}
int input_check_source_white(move_t move)
{
    if (board[move.sx][move.sy] == NULL) {
        return False;
    }
    else if (board[move.sx][move.sy]->color == E_BLACK) {
        return False;
    }
    return True;
}

int input_check_destination_white(move_t move)
{
    if (board[move.dx][move.dy] != NULL && board[move.dx][move.dy]->color == E_WHITE) {
        return False;
    }

    if (board[move.dx][move.dy] == NULL && move.sx == move.dx) {
        if (move.sy - 1 == move.dy) {
            return True;
        }
        if (move.sy - 2 == move.dy && move.sy == 6) {
            return True;
        }
        return False;
    }

    if (board[move.dx][move.dy]->color == E_BLACK) {
        if (((move.sy - 1) != move.dy && (move.sx - 1) != move.dx) &&
            ((move.sy + 1) != move.dy && (move.sx - 1) != move.dx))
        {
            return False;
        }
    }
    return True;
}

move_t parse_input(char* inp)
{
    move_t m;

    m.sx = transform(inp[0]);
    m.sy = transform(inp[1]);
    m.dx = transform(inp[4]);
    m.dy = transform(inp[5]);

    return m;
}
unsigned char transform(char a)
{
    unsigned char result;

    switch (a) {
    case 'h':
    case '1':
        result = 7;
        break;
    case 'g':
    case '2':
        result = 6;
        break;
    case 'f':
    case '3':
        result = 5;
        break;
    case 'e':
    case '4':
        result = 4;
        break;
    case 'd':
    case '5':
        result = 3;
        break;
    case 'c':
    case '6':
        result = 2;
        break;
    case 'b':
    case '7':
        result = 1;
        break;
    case 'a':
    case '8':
        result = 0;
        break;
    }
    return result;
}
void player_do_move(move_t move)
{
    piece_t* a;
    if (board[move.dx][move.dy] != NULL) {
        board[move.dx][move.dy]->status = E_OUTOFGAME;
    }

    a = board[move.sx][move.sy];
    board[move.sx][move.sy] = NULL;
    board[move.dx][move.dy] = a;

    a->x = move.dx;
    a->y = move.dy;
}
void player_black_move()
{
    char inp[32];
    move_t move;

    for (;;) {
        printf("Enter your move, Black. It must be in this format \"a7->a6\": ");
        scanf("%s", inp);
        if (input_check_format(inp) == False) {
            printf("Move format invalid, please try again.\n");
            continue;
        }

        move = parse_input(inp);

        if (input_check_source_black(move) == False) {
            printf("Source field is invalid, please try again.\n");
            continue;
        }
        if (input_check_destination_black(move) == False) {
            printf("Destination field is invalid, please try again.\n");
            continue;
        }
        player_do_move(move);
        break;
    }
}
int input_check_source_black(move_t move)
{
    if (board[move.sx][move.sy] == NULL) {
        return False;
    }
    else if (board[move.sx][move.sy]->color == E_WHITE) {
        return False;
    }

    return True;
}
int input_check_destination_black(move_t move)
{

    if (board[move.dx][move.dy] != NULL && board[move.dx][move.dy]->color == E_BLACK) {
        return False;
    } // if its empty or they can take

    if (board[move.dx][move.dy] == NULL && move.sx == move.dx) { // 1 or 2 boxes forward
        if (move.sy + 1 == move.dy) {
            return True;
        }
        if (move.sy + 2 == move.dy && move.sy == 1) {
            return True;
        }
        return False;
    }

    if (board[move.dx][move.dy]->color == E_WHITE) {
        if (((move.sy - 1) != move.dy && (move.sx + 1) != move.dx) &&
            ((move.sy + 1) != move.dy && (move.sx + 1) != move.dx))
        {
            return False;
        }
    }
    return True;
}
int check_winner()
{
    int i;

    for (i = 0; i <= 7; i++) {
        if (board[i][0] != NULL) {
            printf("---- WHITE WON. CONGRATS! ----");
            return True;
        }
        else if (board[i][7] != NULL) {
            printf("---- BLACK WON. CONGRATS! ----");
            return True;
        }
    }
    return False;
}

