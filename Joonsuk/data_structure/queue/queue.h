#include <array>

#ifndef H_QUEUE
#define H_QUEUE

#define MAX_QUEUE_SIZE 5

class My_queue {
public:
    void push(int num);
    void pop();
    int size();
    int front();
private:
    int in_idx = 1, out_idx = 0;
    std::array<int, MAX_QUEUE_SIZE> queue;
};

inline void My_queue::push(int num){
    if(in_idx == out_idx)
        return;
    
    queue.at(in_idx) = num;
    if(in_idx == MAX_QUEUE_SIZE - 1)
        in_idx = 0;
    else
        ++in_idx;
}

void My_queue::pop(){
    if(in_idx == out_idx + 1)
        return;
    
    if(out_idx == MAX_QUEUE_SIZE - 1)
        out_idx = 0;
    else
        ++out_idx;
}

inline int My_queue::size(){
    if(in_idx > out_idx)
        return in_idx - out_idx - 1;
    else
        return MAX_QUEUE_SIZE - (out_idx - in_idx) - 1;
}

int My_queue::front(){
    if(this->size() == 0)
        return -1;
    
    if(out_idx == MAX_QUEUE_SIZE - 1)
        return queue.at(0);
    else
        return queue.at(out_idx + 1);
}

#endif 