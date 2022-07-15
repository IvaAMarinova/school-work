// removes duplicated words in a string

is_letter(char c)
{
	return 'a' <= c && c <= 'z' || 'A' <= c && c <= 'Z';
}
int eq_word(const char* l, const char* r)
{
	while (*l == *r && is_letter(*l))
		l++, r++;
	return !is_letter(*l) && !is_letter(*r);
}

void remove_duplicates(char* s)
{
	unsigned in_word = 0;
	char* s1 = s, * p = s, *beggining = s;
	do {
		if (!in_word && is_letter(*s1)) { 
			p = s1;
			unsigned in_word_s = 1;
			do {
				if (!in_word_s && is_letter(*p)) {
					if (eq_word(s1, p)) {
						s = p;
						while (*s && *s != ' ') {
							*s = ' ';
							*s++;
						}
					}
				}
				in_word_s = is_letter(*p);
			} while (*p++);
		}
		in_word = is_letter(*s1);
	} while (*s1++);

	in_word = 0;
	s = beggining;
	char* t = s;

	while (*s && *s == ' ')
		s++;
	while (*s)
	{
		if (*s != ' ')
		{
			if (!in_word)
				*t++ = ' ';
			*t++ = *s;
		}
		in_word = ' ' != *s++;
	}
	*t = 0;
}

main()
{
	char a[] = " one one two two";
	remove_duplicates(a);

	char a1[] = " iva iva iva iva iva iva";
	remove_duplicates(a1);

	char a2[] = " iva ne znae kakuv primer da sloji";
	remove_duplicates(a2);

	char a3[] = " one two three two one four one";
	remove_duplicates(a3);

	char a4[] = " iva";
	remove_duplicates(a4);
}

