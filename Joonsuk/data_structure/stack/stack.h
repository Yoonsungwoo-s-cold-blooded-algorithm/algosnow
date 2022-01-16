#include <array>

#ifndef H_STACK
#define H_STACK

#define MAX_STACK_SIZE 100
class My_stack {
public:
    void push(int num);
    void pop();
    int size();
    int top();
private:
    int top_idx = 0;
    std::array<int, MAX_STACK_SIZE> stack;
};

inline void My_stack::push(int num){
    if(top_idx < MAX_STACK_SIZE)
        stack.at(top_idx) = num;
    ++top_idx;
}

void My_stack::pop(){
    if(top_idx > 0){
        --top_idx;
    }
}

inline int My_stack::size(){
    return top_idx;
}

inline int My_stack::top(){
    if(top_idx > 0)
        return stack.at(top_idx - 1);
    else
        return -1;
}

#endif