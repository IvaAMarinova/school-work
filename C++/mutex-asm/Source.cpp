// Задача: mutex на асемблер с bts

#include <iostream>
struct mutex
{
	uint16_t l = 0;
	bool lock();
	void unlock();
};

int main()
{
	mutex m;
	bool result = m.lock();
	result = m.lock();
	result = m.lock();
	m.unlock();
	m.unlock();
	result = m.lock();
}