// binary search for number in an array
// if not present, returns position where it should be

int* find(int* a, unsigned size, int searched)
{
    int* p = a;

    if (searched <= *p) {
        return p;
    }

    if (searched >= *(p + size - 1)) {
        return p + size - 1;
    }

    size /= 2;
    p = a + size;

    while (size) {
        size /=  2;
        if (*p == searched || (searched > *p && searched < *(p + 1))) {
            return p;
        }
        
        if (*p < searched) {
            p += size;
        }
        else {
            p -= size;
        }
    }
}

void main()
{
    int a[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };

    find(a, 9, -15);
    find(a, 9, 1000);
    find(a, 9, 10);
    find(a, 9, 20);
    find(a, 9, 30);
    find(a, 9, 9);
    find(a, 9, 34);
    find(a, 9, 80);
    find(a, 9, 90);

}