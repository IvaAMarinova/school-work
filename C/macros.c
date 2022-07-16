// macros that check if a character is uppercased, lowercased, number, and turn lower to upper

#define M_upper(c) ('0' <= (c) && (c) <= '9'),
#define L1_num(x) M_upper(4*(x)+0) M_upper(4*(x)+1) M_upper(4*(x)+2) M_upper(4*(x)+3)
#define L2_num(x) L1_num(4*(x)+0) L1_num(4*(x)+1) L1_num(4*(x)+2) L1_num(4*(x)+3)
#define L3_num(x) L2_num(4*(x)+0) L2_num(4*(x)+1) L2_num(4*(x)+2) L2_num(4*(x)+3)
#define L4_num(x) L3_num(4*(x)+0) L3_num(4*(x)+1) L3_num(4*(x)+2) L3_num(4*(x)+3)

const char is_num[256] = { L4_num(0) };


#define M_alpha(c) ('A' <= (c) && (c) <= 'Z'),
#define L1_alpha(x) M_alpha(4*(x)+0) M_alpha(4*(x)+1) M_alpha(4*(x)+2) M_alpha(4*(x)+3)
#define L2_alpha(x) L1_alpha(4*(x)+0) L1_alpha(4*(x)+1) L1_alpha(4*(x)+2) L1_alpha(4*(x)+3)
#define L3_alpha(x) L2_alpha(4*(x)+0) L2_alpha(4*(x)+1) L2_alpha(4*(x)+2) L2_alpha(4*(x)+3)
#define L4_alpha(x) L3_alpha(4*(x)+0) L3_alpha(4*(x)+1) L3_alpha(4*(x)+2) L3_alpha(4*(x)+3)

const char is_alpha[256] = { L4_alpha(0) };

#define M_lower(c) (c >= 'A' && c <= 'Z' ? ('a' - 'A') + c : c),
#define L1_lower(x) M_lower(4*(x)+0) M_lower(4*(x)+1) M_lower(4*(x)+2) M_lower(4*(x)+3)
#define L2_lower(x) L1_lower(4*(x)+0) L1_lower(4*(x)+1) L1_lower(4*(x)+2) L1_lower(4*(x)+3)
#define L3_lower(x) L2_lower(4*(x)+0) L2_lower(4*(x)+1) L2_lower(4*(x)+2) L2_lower(4*(x)+3)
#define L4_lower(x) L3_lower(4*(x)+0) L3_lower(4*(x)+1) L3_lower(4*(x)+2) L3_lower(4*(x)+3)

const char to_lower[256] = { L4_lower(0) };

#define M_upper(c) (c >= 'a' && c <= 'z' ? ('A' - 'a') + c : c),
#define L1_upper(x) M_upper(4*(x)+0) M_upper(4*(x)+1) M_upper(4*(x)+2) M_upper(4*(x)+3)
#define L2_upper(x) L1_upper(4*(x)+0) L1_upper(4*(x)+1) L1_upper(4*(x)+2) L1_upper(4*(x)+3)
#define L3_upper(x) L2_upper(4*(x)+0) L2_upper(4*(x)+1) L2_upper(4*(x)+2) L2_upper(4*(x)+3)
#define L4_upper(x) L3_upper(4*(x)+0) L3_upper(4*(x)+1) L3_upper(4*(x)+2) L3_upper(4*(x)+3)

const char to_upper[256] = { L4_upper(0) };

void main()
{
	is_num['5'];
	is_num['A'];
	is_num[255];

	is_alpha['B'];
	is_alpha['A'];
	is_alpha[255];

	to_upper['a'];
	to_upper['A'];
	to_upper[5];

	to_lower['A'];
	to_lower['a'];
	to_lower[2];
}