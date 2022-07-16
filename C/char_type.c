// checks character's type using macros
// "a" equals 1 for true, 0 for false

#define LETTER 0
#define CAP_LETTER 1
#define NUMBER 2
#define PUNCT 3
#define CONTROL 4

#define ALP(c) ((c)>= 'a' && (c) <= 'z')
#define CAP(c) ((c) >= 'A' && (c) <= 'Z')
#define NUM(c) ((c) >= '0' && (c) <= '9')
#define PUN(c) ((c) >= 32 && (c) <= 47 || (c) >= 58 && (c) <= 64 || (c) >= 91 && (c) <= 96 || (c) >= 123 && (c) <= 127)
#define CNT(c) ((c) >= 0 && (c) <= 31)

#define M(c) (ALP(c) ? LETTER : CAP(c) ? CAP_LETTER : NUM(c) ? NUMBER : PUN(c) ? PUNCT : CONTROL)
#define L1(c) M((c)*4), M((c)*4+1), M((c)*4+2), M((c)*4+3),
#define L2(c) L1((c)*4) L1((c)*4+1) L1((c)*4+2) L1((c)*4+3)
#define L3(c) L2((c)*4) L2((c)*4+1) L2((c)*4+2) L2((c)*4+3)

int char_type[128] = { L3(0) L3(1) };

void main(void)
{
    unsigned a;
    a = (char_type['a'] == LETTER);
    a = (char_type['A'] == CAP_LETTER);
    a = (char_type['5'] == NUMBER);
    a = (char_type['-'] == PUNCT);
    a = (char_type['\n'] == CONTROL);
}