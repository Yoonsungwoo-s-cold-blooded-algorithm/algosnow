#include <iostream>
#include <algorithm>

int search(int *num_list, int num, int start_idx, int end_idx) {
    int middle_idx = start_idx + (end_idx - start_idx) / 2;
    if (num == num_list[middle_idx]) return 1;
    else if (start_idx == middle_idx) {
        if (num == num_list[middle_idx] || num == num_list[end_idx]) return 1;
        else return 0;
    }
    else if (num > num_list[middle_idx]) {
        return search(num_list, num, middle_idx, end_idx);
    }
    else if (num < num_list[middle_idx]) {
        return search(num_list, num, start_idx, middle_idx);
    }
}

int main() {
    int N;
    std::cin >> N;
    int N_nums[N];
    for (int i = 0; i < N; i++) {
        std::cin >> N_nums[i];
    }

    int M;
    std::cin >> M;
    int M_nums[M];
    for (int i = 0; i < M; i++) {
        std::cin >> M_nums[i];
    }

    std::sort(N_nums, N_nums + N);

    for (int i = 0; i < M; i++) {
        std::cout << search(N_nums, M_nums[i], 0, N - 1) << '\n';
    }

    return 0;
}