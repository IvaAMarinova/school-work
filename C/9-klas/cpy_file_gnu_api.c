// copy file using GNU C API with buffer

#define _CRT_SECURE_NO_WARNINGS
#define BUFFER_SIZE   64

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <io.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int f1 = _open(argv[1], _O_RDONLY), f2 = _open(argv[2], _O_CREAT | _O_WRONLY, _S_IWRITE);
        
    if (f1 == -1)
    {
        _close(f1);
        return 0;
    }
    if (f2 == -1)
    {
        _close(f2);
        return 0;
    }
    int size_read_bytes = 0;  
    char buffer[BUFFER_SIZE];

    do {
        size_read_bytes = _read(f1, buffer, BUFFER_SIZE);
        _write(f2, buffer, size_read_bytes);
    } while (size_read_bytes == BUFFER_SIZE);
    
    _close(f1);
    _close(f2);
    return 0;
}

