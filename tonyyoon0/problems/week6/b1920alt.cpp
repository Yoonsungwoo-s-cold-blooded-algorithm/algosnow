#include <iostream>
#include <set>

int main() {
    int N;
    std::cin >> N;
    std::set<int> N_nums;
    for (int i = 0; i < N; i++) {
        int temp;
        std::cin >> temp;
        N_nums.insert(temp);
    }

    int M;
    std::cin >> M;
    int M_nums[M];
    for (int i = 0; i < M; i++) {
        std::cin >> M_nums[i];
    }

    for (int i = 0; i < M; i++) {
        std::cout << N_nums.count(M_nums[i]) << '\n';
    }
}