// upcases every odd numbered word in a tring
// "One  Two  Three Four " -> "ONE  two  THREE four"
int is_letter(char c)
{
	return 'a' <= c && c <= 'z' || 'A' <= c && c <= 'Z';
}

char lower(char c)
{
	return c >= 'A' && c <= 'Z' ? ('a' - 'A') + c : c;
}

char upper(char* c)
{
	return c >= 'a' && c <= 'z' ? ('A' - 'a') + c : c;
}

void upcase_odd_words(char* s)
{
	unsigned cnt = 0;
	int in_word = 0;
	for (; *s; s++)
	{
		cnt += !in_word && is_letter(*s);
		in_word = is_letter(*s);

		if (in_word) {
			if (cnt & 1) *s = upper(*s);
			else *s = lower(*s);
		}
	}
}

void main()
{
	char s1[] = "One  Two  Three Four ";
	char s2[] = "  One   Two  Three Four Five ";
	char s3[] = "One  Two";
	upcase_odd_words(s1);
	upcase_odd_words(s2); 
	upcase_odd_words(s3); 
}