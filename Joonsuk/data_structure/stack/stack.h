#include <vector>

#ifndef H_STACK
#define H_STACK

class My_stack {
public:
    void push(int num);
    int pop();
    int size();
    int top();
private:
    std::vector<int> stack;
};

inline void My_stack::push(int num){
    stack.push_back(num);
}

int My_stack::pop(){
    int last = stack.back();
    stack.pop_back();
    return last;
}

inline int My_stack::size(){
    return stack.size();
}

inline int My_stack::top(){
    return stack.back();
}

#endif