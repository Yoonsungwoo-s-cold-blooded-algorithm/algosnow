#include <iostream>

int fibnum_list[20];

int fib(int idx) {
    if (idx < 2) return idx;
    else {
        if (fibnum_list[idx]) return fibnum_list[idx];
        else {
            fibnum_list[idx] = fib(idx - 1) + fib(idx - 2);
            return fibnum_list[idx];
        }
    }
}

int main() {
    int n;
    std::cin >> n;

    fibnum_list[0] = 0;
    fibnum_list[1] = 1;

    std::cout << fib(n) << std::endl;

    return 0;
}