// 현재 스택보다 높은 숫자가 나왔다. 그런경우 무조건 push해야됨.
// 현재 스택보다 낮은 숫자가 나왔다. 그런경우 무조건 pop해야됨.

// 따라서 언제 실패하는가?
    // 1. push를 해서 원하는 숫자가 나오지 않은 경우
    // 2. pop을 했을 때 원하는 숫자가 한번에 나오지 않은 경우

#include <iostream>
#include <stack>
#include <vector>

int main() {
    int N;
    std::vector<int> numbers;
    std::stack<int> stack;
    std::vector<int> sequence;
    std::vector<char> answer;

    std::cin >> N;

    for(int i = 0; i != N; ++i)
        numbers.push_back(N - i);

    for(int i = 0; i != N; ++i){
        int input;
        std::cin >> input;
        sequence.push_back(input);
    }

    bool impossible = false;
    for(int next_seq_num : sequence){
        if(stack.empty() || stack.top() < next_seq_num){
            // stack과 number가 동시에 empty일 수는 없다.
            while(stack.empty() || (!numbers.empty() && stack.top() < next_seq_num)){
                stack.push(numbers.back());
                numbers.pop_back();
                answer.push_back('+');
            }
        }

        if(stack.top() == next_seq_num){
            stack.pop();
            answer.push_back('-');
        } 
        else{
            impossible = true;
            break;
        }
    }

    if(impossible)
        std::cout << "NO" << "\n";
    else{
        for(char oper : answer)
            std::cout << oper << "\n";
    }
}