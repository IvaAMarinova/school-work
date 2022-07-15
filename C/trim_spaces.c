// trims all unnecessary spaces between words

void trim_spaces(char* s)
{
    char* p = s, in_word = 0;
    while (*s && *s == ' ')
        s++;
    while (*s)
    {
        if (*s != ' ')
        {
            if (!in_word)
                *p++ = ' ';
            *p++ = *s;
        }
        in_word = ' ' != *s++;
    }
    *p = 0;
}

main()
{
    char s[] = "  one TWO  tHrEe    fOUR ";

    trim_spaces(s);
}


