#include <iostream>
#include <vector>
#include "header.h"

std::vector<bool> sieveOfEratosthenes(int n) {
    std::vector<bool> numbers(n, true);

    for (int i = 2; i < n; i++) {
        if (numbers[i]) {
            for (int j = 2; j * j < n; j++) {
                numbers[i * j] = false;
            }
        }
    }

    return numbers;
}

std::vector<bool> divisibility_testing(int n) {
    std::vector<bool> numbers(n, true);

    for (int i = 2; i < n; i++) {
        for (int j = 1; i * j <= n; j++) {
            numbers[i * j] = false;
        }
    }
    return numbers;
}

std::vector<bool> sieveOfAtkin(int n) {
    std::vector<bool> numbers(n, true);
    int z;

    for (int x = 0; x * x <= n; x++) {
        for (int y = 0; y * y < n; y++) {
            z = 4 * x * x + y * y;
            if ((z <= n) and (z % 12 == 7)) {
                numbers[z] = not numbers[z];
            }

            z = 3 * x * x + y * y;
            if ((z <= n) and ((z % 12 == 1) or (z % 12 == 5))) {
                numbers[z] = not numbers[z];
            }

            z = 3 * x * x - y * y;
            if ((z <= n) and (z % 12 == 11) and (x > y)) {
                numbers[z] = not numbers[z];
            }
        }
    }

    for (int x = 2; x * x < n; x++) {
        if (numbers[x]) {
            for (int y = x ^ 2; y < n; y += x ^ 2) {
                numbers[y] = false;
            }
        }
    }

    return numbers;
}

int print(std::vector<bool> numbers) {
    for (int i = 2; i < numbers.size(); i++) {
        if (numbers[i]) {
            std::cout << i << " ";
        }
    }

    return 0;
}


int main()
{
    std::cout << "Hello World!\n";

    print(sieveOfEratosthenes(100));
}