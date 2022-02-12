#include <iostream>
#include <algorithm>

int calculate(int *list, int N) {
    int temp = 0;
    for (int i = 0; i < N - 1; i++) {
        if (list[i] - list[i + 1] > 0) temp += list[i] - list[i + 1];
        else temp += list[i + 1] - list[i];
    }
    return temp;
}

int main() {
    int N;
    std::cin >> N;
    int nums[N];

    for (int i = 0; i < N; i++) {
        std::cin >> nums[i];
    }

    std::sort(nums, nums + N);

    int max = calculate(nums, N);

    while (std::next_permutation(nums, nums + N)) {
        int temp = calculate(nums, N);
        if (max < temp) max = temp;
    }

    std::cout << max;

    return 0;
}