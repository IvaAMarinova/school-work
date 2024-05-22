// Задача: Реализирайте обект за атомични операции на асемблер.

#include <stdint.h>
#include <thread>
#include <mutex>

struct atomic
{
	uint64_t i;
	uint64_t operator++();
	uint64_t operator--();
	atomic& operator=(uint64_t); // result rcx, parameter rdx
	atomic& operator+=(atomic&);
	atomic& operator-=(atomic&);
	atomic& operator*=(atomic&);
	atomic& operator/=(atomic&);
};

int main()
{
	atomic x1 = { 10 };
	atomic x2 = { 2 };
	atomic x3;
	x1 /= x2;
	return 0;
}