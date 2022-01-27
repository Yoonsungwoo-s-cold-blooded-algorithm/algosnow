#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <iostream>
#include <vector>
#include <iterator>
#include "quick_sort_partition.h"

void quick_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end);
void quick_sort(std::vector<int>::reverse_iterator begin, std::vector<int>::reverse_iterator end);
void show_quick_sort();
void swap_value(int& a, int& b);

void quick_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end){
    // if(begin == end - 1) return -> 크기가 1
    // pivot을 선택하고
    // pivot을 기준으로 정렬한뒤
    // quick_sort(작은 범위)
    // quick_sort(큰 범위)

    if(begin == end)
        return;

    if(begin == end-1)
        return;
    
    auto pivot = partition(begin, end);

    if(pivot != begin)
        quick_sort(begin, pivot);
    
    if(pivot != end-1)
        quick_sort(pivot + 1, end);
    
    // 퀵 정렬은 분할 정복을 사용하고 있다.
    // 레코드의 크기가 1/2로 계속해서 나누어 진다고 하면, nlog2(n)의 시간 복잡도로 빠르게 구할 수 있다.
    // 하지만 레코드가 대부분 정렬된 경우, 레코드의 분할이 매우 비대칭적이게 되어, 비효율적인 정렬이 된다.
    // 최악의 경우 = O(n^2)

    // 또한 partition에서 거리가 먼 원소와 swap이 일어나므로, 불안정 정렬에 속한다.
}


void quick_sort(std::vector<int>::reverse_iterator begin, std::vector<int>::reverse_iterator end){
    if(begin == end)
        return;

    if(begin == end-1)
        return;
    
    auto pivot = begin;
    int greater_then_pivot_count = 0;
    while(pivot + greater_then_pivot_count < end-1){
        auto comparation_target = pivot + greater_then_pivot_count + 1;

        if(*pivot > *comparation_target){
            swap_value(*(pivot + 1), *comparation_target);
            swap_value(*pivot, *(pivot + 1));
            ++pivot;
        }
        else {
            ++greater_then_pivot_count;
        }
    }

    if(pivot != begin)
        quick_sort(begin, pivot);
    
    if(pivot != end-1)
        quick_sort(pivot + 1, end);
}

void swap_value(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}


void show_quick_sort(){
    std::vector<int> ivec;
    std::cout << "enter numbers to sort (enter eof to finish)" << std::endl;

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
    quick_sort(ivec.begin(), ivec.end());
    for(int elem : ivec)
        std::cout << elem << " ";
    std::cout << "\n\n";

    std::cout << "descending\n";
    quick_sort(ivec.rbegin(), ivec.rend());
    for(int elem : ivec)
        std::cout << elem << " ";
    std::cout << "\n\n";
}

#endif