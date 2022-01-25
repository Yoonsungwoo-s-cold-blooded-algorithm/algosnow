// 버블 정렬은 순차적으로 모든 요소를 접근하여 다음 요소와 비교한 뒤, 순서를 변경해야 하면 값을 맞바꾸는 정렬이다.
// 1순회를 한 뒤에는 마지막 요소가 정렬되며, 2순회를 하면 마지막에서 2번째, 3순회를 하면 마지막에서 3번째 까지 정렬된다.

#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <vector>
#include <iterator>
#include <iostream>

void bubble_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end);
void bubble_sort(std::vector<int>::reverse_iterator begin, std::vector<int>::reverse_iterator end);
void swap(int& a, int& b);
void show_bubble_sort();

void bubble_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end){
    if(begin == end)
        return;

    auto old_state_begin = begin;
    for(;begin != end; --end){  
        for(; begin != end - 1; ++begin){ // 초기에 begin == end 인 경우 무한 루프
            if(*begin > *(begin+1)){
                swap(*begin, *(begin+1));
            }
        }
        begin = old_state_begin;
    }
}

// 구현부가 iterator 버전하고 완전히 동일 -> 구현부가 타입에 종속되지 않도록 하는 방법이 있을까?
void bubble_sort(std::vector<int>::reverse_iterator begin, std::vector<int>::reverse_iterator end){
    if(begin == end)
        return;

    auto old_state_begin = begin;
    for(;begin != end; --end){ // n ~ 1까지 n번 수행
        for(; begin != end - 1; ++begin){ // k번 수행
            if(*begin > *(begin+1)){
                swap(*begin, *(begin+1));
            }
        }
        begin = old_state_begin;
    }
    // 시간 복잡도
    // 1 + 2 + 3 + ... + n = n(n+1)/2 = O(n^2)의 시간 복잡도를 가진다.

    // 좀 많이 안 좋은 정렬법.. 최소한 삽입 정렬을 구현하도록 하자.
    // 구현 난이도가 동일하지만 시간 복잡도가 상위 호환격이니...
}

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

// 확인용
void show_bubble_sort(){
    std::vector<int> ivec;
    std::cout << "enter numbers to sort (enter eof to finish)" << std::endl;

    // in의 경우 초기화 하자 마자 첫번째 값을 읽어옵니다. (cashed value data member를 초기화 하기 위함)
    std::istream_iterator<int> in(std::cin), eof; 
    while(in != eof){
        ivec.push_back(*in++);
    }
    std::cout << "\n";

    std::cout << "input vector\n";
    for(int elem : ivec)
        std::cout << elem << " ";
    std::cout << "\n\n";

    std::cout << "ascending\n";
    bubble_sort(ivec.begin(), ivec.end());
    for(int elem : ivec)
        std::cout << elem << " ";
    std::cout << "\n\n";

    std::cout << "descending\n";
    bubble_sort(ivec.rbegin(), ivec.rend());
    for(int elem : ivec)
        std::cout << elem << " ";
    std::cout << "\n\n";
}

#endif