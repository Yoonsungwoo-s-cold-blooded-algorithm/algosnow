#include <iostream>
#include <vector>

// 브루트포스는 모든 경우의 수를 탐색하는 무식한 방법이다.
// 멋있는 풀이는 무식하지 않아!!!

// 모든 배열의 가짓수에 대해서 max 값을 갱신한다.
void do_insertion(int goal, int n);
int conduct_test();

std::vector<int> A;
std::vector<int> answer;
int max = 0;

int main() {
    int N, a;

    std::cin >> N;
    for (int i = 0; i != N; ++i) {
        std::cin >> a;
        A.push_back(a);
    }

    // 1번 원소
    answer.push_back(A[0]);
    do_insertion(N-1, 1);
    std::cout << max;
}

// 순열을 완성하는 과정이다.
// 1
// 2 1 , 1 2 -> 2가지 (1의 양 옆에 2를 넣을 수 있다.)
// 3 2 1, 2 3 1, 2 1 3 / 3 1 2, 1 3 2, 1 2 3 -> 3가지 (o 1 o 2 o : o에 3이 들어갈 수 있다.)
void do_insertion(int goal, int n) {
    for (int i = 0; i != n+1; ++i) {
        answer.insert(answer.begin() + i, A[n]);
        if (n != goal)
            do_insertion(goal, n + 1);
        else {
            int test_case_value = conduct_test();
            if (test_case_value > max)
                max = test_case_value;
        }
        answer.erase(answer.begin() + i);
    }
}

int conduct_test() {
    int total = 0;
    for (int i = 0; i != answer.size() - 1; ++i) {
        if (answer[i] > answer[i + 1])
            total += answer[i] - answer[i + 1];
        else
            total += answer[i + 1] - answer[i];
    }
    return total;
}
