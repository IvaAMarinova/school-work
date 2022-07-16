// counts words in a string

int is_letter(char c)
{
	return 'a' <= c && c <= 'z' || 'A' <= c && c <= 'Z';
}
int is_alpha(char c)
{
	return 'A' <= c && c <= 'Z';
}

char lower(char c)
{
	return c >= 'A' && c <= 'Z' ? ('a' - 'A') + c : c;
}

char upper(char *c)
{
	return c >= 'a' && c <= 'z' ? ('A' - 'a') + c : c;
}

unsigned count_words(const char* s)
{
	unsigned cnt = 0;
	int in_word = 0;
	for (; *s; s++)
	{
		cnt += !in_word && is_alpha(*s);
		in_word = is_alpha(*s);
	}
	return cnt;
}


void main()
{
	char s[] = "One  Two  Three Four ";;
	count_words(s);
}