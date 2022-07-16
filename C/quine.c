#include <stdio.h>
main() { char* s = "#include <stdio.h> %cmain() { char* s = %c%s%c; printf(s, 10, 34, s, 34); }"; printf(s, 10, 34, s, 34); }
