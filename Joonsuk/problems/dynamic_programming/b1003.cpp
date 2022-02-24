#include <array>
#include <iostream>

void fibonacci(int n);

std::array<int, 41> zero_storage;
std::array<int, 41> one_storage;

int main() {
    int T, N;
    std::cin >> T;

    zero_storage[0] = 1;
    one_storage[1] = 1;

    for (int i = 0; i != T; ++i) {
        std::cin >> N;

        fibonacci(N);
        std::cout << zero_storage[N] << " " << one_storage[N] << "\n";
    }
}

void fibonacci(int n) {
    if (n == 0) {
        return;
    } else if (n == 1) {
        return;
    } else {
        if (zero_storage[n - 1] == 0 && one_storage[n - 1] == 0)
            fibonacci(n - 1);
        if (zero_storage[n - 2] == 0 && one_storage[n - 1] == 0)
            fibonacci(n - 2);

        zero_storage[n] = zero_storage[n - 1] + zero_storage[n - 2];
        one_storage[n] = one_storage[n - 1] + one_storage[n - 2];
    }
}