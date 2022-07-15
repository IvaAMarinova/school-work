// returns size of longest word in a string

unsigned isnt_space(char* c) {
	return c != ' ' ? 1 : 0;
}

unsigned longest_word(const char* s)
{
	unsigned max = 0;
	unsigned in_word = 0;
	char* word_start = s;

	for (; *s; s++)
	{
		in_word = isnt_space(*s);
		
		if (in_word) {
			if (!isnt_space(*(s + 1))) {
				if (max < (s - word_start)) {
					max = s - word_start;
				}
			}
		} 
		if (!isnt_space(*(s - 1)) && isnt_space(*s)) {
			word_start = s;
		}
	}

	if (max < (s - word_start)) {
		max = s - word_start;
	}

	return max;
}

void main()
{
	longest_word("  one two three four ");
	longest_word(" one  two tthree fouur ");
	longest_word("one  two tthree fouur ");

}
