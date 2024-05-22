extern "C"
{
    void add(long long* res, const long long* l, const long long* r, size_t cnt);
    void sub(long long* res, const long long* l, const long long* r, size_t cnt);
    void neg(long long* res, const long long* l, size_t cnt);
    void mul(long long* res, const long long* l, const long long* r, size_t cnt); // *
}
int main() {
    long long res[3];
    //long long l[3] = { 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff };
    //long long r[3] = { 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff };
    //long long l[3] = { 0xffffffffffffffff, 1, 0 };
    //long long r[3] = { 1, 0, 0 };
    //long long l[3] = { 0xffffffffffffffff, 5, 4 };
    long long r[3] = { 3, 2, 1 };

    neg(res, r, 3);

    return 0;
}