// a long way to multiply two numbers

unsigned mul(unsigned x, unsigned y)
{
    unsigned t, result = 0;

    for(int i = 31; i >= 0 && y > 0; i--) {
        t = 1 << i;
        if (t <= y) {
            result += x << i;
            y = y & (~t);
        }
    }

    return result;
}

void main()
{
	mul(3, 5);
    mul(13, 55);
    mul(170, 31);
    mul(331, 3);
}