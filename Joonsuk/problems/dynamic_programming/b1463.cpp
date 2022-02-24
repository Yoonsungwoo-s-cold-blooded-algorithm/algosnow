#include <array>
#include <iostream>

std::array<int, 1000001> storage; // 1부터 10^6

int recursion(int num);
int main() {
    int N;
    std::cin >> N;

    std::cout << recursion(N);
}

int recursion(int num) {
    if (num == 1)
        return 0;

    int first_case = 1000000; // third_case가 항상 이 값보다는 작다.
    int second_case = 1000000;
    int third_case = 1000000;

    if (num % 3 == 0) {
        if (storage[num / 3] == 0)
            first_case = recursion(num / 3) + 1;
        else
            first_case = storage[num / 3] + 1;
    }
    if (num % 2 == 0) {
        if (storage[num / 2] == 0)
            second_case = recursion(num / 2) + 1;
        else
            second_case = storage[num / 2] + 1;
    }

    if (storage[num - 1] == 0)
        third_case = recursion(num - 1) + 1;
    else
        third_case = storage[num - 1] + 1;

    int smaller = (first_case < second_case) ? first_case : second_case;
    int smallest = (smaller < third_case) ? smaller : third_case;
    storage[num] = smallest;
    return smallest;
}