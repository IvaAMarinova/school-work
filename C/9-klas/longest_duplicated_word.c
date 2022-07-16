// returns longest duplicated word in a string

#include <string.h>

int is_letter(char c)
{
	return 'a' <= c && c <= 'z' || 'A' <= c && c <= 'Z';
}

const char *longest_duplicate_word(const char* s)
{
	unsigned in_word = 0, max = 0;
	const char *start = s, *longest = 0;
	
	do {
		unsigned was_in_word = in_word;
		in_word = is_letter(*s);

		if (!was_in_word && in_word) {
			start = s;
		}

		if (was_in_word && !in_word && max < s - start) {
			const char *p = s, * start2 = p;
			unsigned in_word_2 = 0;

			do {
				unsigned was_in_word2 = in_word_2;
				in_word_2 = is_letter(*p);

				if (!was_in_word2 && in_word_2) {
					start2 = p;
				}

				if (was_in_word2 && !in_word_2 && strncmp(start, start2, s - start)) { // 
					longest = start;
					max = s - start;
				}
			} while (*p++);

		}

	} while (*s++);

	char* result = malloc(max + 1);
	memcpy(result, longest, max);
	result[max] = 0;
	return result;
}

main(void)
{
	longest_duplicate_word("This is is a sentence");
	longest_duplicate_word("This is is is a sentence sentence");
	longest_duplicate_word("This is a sentence sentence iva");
}