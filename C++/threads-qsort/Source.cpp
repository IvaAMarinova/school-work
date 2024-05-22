#include <iostream>
#include <list>
#include <thread>

long long int MIN_SIZE = 1 << 16; // 1 << 16

void qsort(int* left, int* right, std::list<std::thread>& threads) {
    while (left < right) {
        int* p = left, * q = right, anchor = left[(right - left) / 2];
        while (p <= q) {
            while (*p < anchor) p++;
            while (anchor < *q) q--;

            if (p <= q) {
                int swap = *p;
                *p = *q; *q = swap;
                p++; q--;
            }
        }

        if (p - left <= MIN_SIZE) {
            qsort(p, right, threads);
        }
        else {
            threads.push_back(std::thread([=, &threads]() { qsort(p, right, threads); }));
        }

        qsort(left, q, threads);
        left = p;
        right = q;
    }
}

int main() {
    long long int array_size = 1 << 20;
    int* array = new int[array_size];

    std::list<std::thread> threads;

    for (int i = 0; i < array_size; i++) {
		array[i] = rand();
	}

    qsort(array, array + array_size - 1, threads);

    for (auto& thread : threads) {
        thread.join();
    }
    delete[] array;

    return 0;
}