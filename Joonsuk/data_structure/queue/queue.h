#include <deque>

#ifndef H_QUEUE
#define H_QUEUE

class My_queue {
public:
    void push(int num);
    int pop();
    int size();
    int front();
    int back();
private:
    std::deque<int> queue;
};

inline void My_queue::push(int num){
    queue.push_back(num);
}

int My_queue::pop(){
    int first = queue.front();
    queue.pop_front();
    return first;
}

inline int My_queue::size(){
    return queue.size();
}

inline int My_queue::front(){
    return queue.front();
}

inline int My_queue::back(){
    return queue.back();
}

#endif 