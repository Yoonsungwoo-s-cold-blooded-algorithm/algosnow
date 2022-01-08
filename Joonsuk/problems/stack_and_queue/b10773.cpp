#include <stack>
#include <iostream>

int main(){
    int K;
    std::stack<int> stack;

    std::cin >> K;

    for(int i = 0; i != K; ++i){
        int input;
        std::cin >> input;

        if(input == 0)
            stack.pop();
        else
            stack.push(input);
    }

    int sum = 0;
    while(!stack.empty()){
        sum += stack.top();
        stack.pop();
    }

    std::cout << sum << "\n";
}