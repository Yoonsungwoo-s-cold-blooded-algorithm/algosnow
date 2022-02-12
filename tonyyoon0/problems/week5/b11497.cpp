#include <iostream>
#include <algorithm>

int main() {
    int test_case;
    std::cin >> test_case;

    for (int test = 0; test < test_case; test++) {
        int log_count;
        std::cin >> log_count;
        int *logs = new int[log_count];
        for (int i = 0; i < log_count; i++) {
            std::cin >> logs[i];
        }
        std::sort(logs, logs + log_count);

        int max_difficulty = 0;
        for (int i = 2; i < log_count; i++) {
            max_difficulty = std::max(max_difficulty, logs[i] - logs[i - 2]);
        }
        
        std::cout << max_difficulty << std::endl;

        delete[] logs;
    }
}