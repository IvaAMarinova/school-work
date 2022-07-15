// uppcases all first letters in a word and lowcases the rest

is_alpha(char c)
{
    return 'a' <= c && c <= 'z' || 'A' <= c && c <= 'Z';
}

char to_upper(char c)
{
    return c >= 'a' && c <= 'z' ? ('A' - 'a') + c : c;
}

char to_lower(char c)
{
    return c >= 'A' && c <= 'Z' ? ('a' - 'A') + c : c;
}

void title_cap(char* s)
{
    for (int in_word = 0; *s; s++)
    {
        int new_in_word = is_alpha(*s);
        if (new_in_word)
            if (in_word) *s = to_lower(*s);
            else *s = to_upper(*s); 
         
        in_word = new_in_word;
    }
}

int main()
{
    char s[] = "one TWO tHrEe fOUR";

    title_cap_trim_longest(s);
}
