// 스택이 비어있으면 숫자를 stack에 넣는다.
// 맨 위에 숫자보다 작은 수가 있으면 push한다.
// 맨 위의 숫자보다 큰 수가 있으면, 해당 숫자의 오큰수는 바로 그 '큰 수'이다. 따라서 값을 저장한 뒤에 pop한다.
// pop이 일어나면 다음 숫자에 대해서도 비교를 한다.

// 1. 이전 숫자를 저장하는 stack과
// 2. 해당 숫자들의 오 큰수를 저장하는 배열.

#include <iostream>
#include <vector>

// 수열 A의 각 원소.
struct Elem_A {
    Elem_A(int v, int pos) : value(v), position(pos) {}
    int value;    // 값
    int position; // A(i)의 i
};

int main() {
    std::vector<Elem_A> stack;

    int N;
    std::cin >> N;
    std::vector<int> oh_kun_su(N, -1); // :)

    int input;
    for (int i = 0; i != N; ++i) {
        std::cin >> input;

        // 1. 스택이 비어있거나 맨 위의 원소보다 크지 않으면 push
        if (stack.empty() || (stack.back().value >= input)) {
            stack.push_back(Elem_A(input, i));
        }
        // 2. 스택이 비어있지 않으며, 맨 위의 원소보다 크면 오 큰수를 찾은것.
        else {
            while (!(stack.empty() || (stack.back().value >= input))) {
                oh_kun_su[stack.back().position] = input;
                stack.pop_back();
            }
            stack.push_back(Elem_A(input, i));
        }
    }

    for (int num : oh_kun_su) {
        std::cout << num << " ";
    }
}