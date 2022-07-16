// copy file using buffer

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE   64

int main(int argc, char* argv[]) {
    
    FILE* f1 = fopen(argv[1],"r"), *f2 = fopen(argv[2], "w+");

    if (f1 == -1)
    {
        fclose(f1);
        return 0;
    }
    if (f2 == -1)
    {
        fclose(f2);
        return 0;
    }

    char buffer[BUFFER_SIZE];
    size_t file_size, bytes_read;

    do {
        bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, f1);
        fwrite(buffer, sizeof(char), bytes_read, f2);
    } while (bytes_read == BUFFER_SIZE);
   
    fclose (f2);
    fclose(f1);
    return 0;
}