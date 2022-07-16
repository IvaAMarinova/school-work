// well.. memory move

void mem_move(void* dest, void* src, unsigned size)
{
    char* d = dest, * s = src;

    if (dest > src) {
        for (int i = size + 1; i >= 0; i--) {
            *(d + i) = *(s + i);
        }
    }
    else {
        for (int i = 0; i < size; i++) {
            *(d + i) = *(s + i);
        }
    }
}

void main()
{
    char buffer[] = "one two three  ";
    mem_move(buffer + 3, buffer, 10);
    char buffer2[] = "one two three  ";
    mem_move(buffer2, buffer2 + 3, 10);
}