// mirrors words in a string

is_letter(char c)
{
    return 'a' <= c && c <= 'z' || 'A' <= c && c <= 'Z';
}

void mirror_words(char* s)
{
    char* p = s, * q = s;
    int in_word = 0;

    while (*s) {
        if (!in_word && is_letter(*s)) {
            p = s;
        }
        if (in_word && !is_letter(*s)) {
            q = s - 1;
            while (p < q) {
                char temp = *p;
                *p = *q;
                *q = temp;
                p++; q--;
            }
        }
        in_word = is_letter(*s);
        s++;
    }

    q = s - 1;
    while (p < q) {
        char temp = *p;
        *p = *q;
        *q = temp;
        p++; q--;
    }
}

int main()
{
    char s1[] = "one two three four";
    mirror_words(s1);

    char s2[] = "iva dnes shte hodi da si kupi kniga";
    mirror_words(s2);

    char s3[] = "eno owt eerht ruof";
    mirror_words(s3);

    char s4[] = "    one   two       three  four ";
    mirror_words(s4);
}