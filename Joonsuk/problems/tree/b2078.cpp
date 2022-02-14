#include <iostream>

int main() {
    int A, B;
    std::cin >> A >> B;

    int right = 0, left = 0;
    while (A != 1 && B != 1) {
        if (A > B) {
            left += A / B;
            A = A % B;
        } else if (A < B) {
            right += B / A;
            B = B % A;
        }
    }
    if (A != 1) {
        left += A - 1;
    } else {
        right += B - 1;
    }
    std::cout << left << " " << right;
}