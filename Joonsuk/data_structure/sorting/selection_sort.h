#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <iostream>
#include <vector>
#include <iterator>

void selection_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end);
void selection_sort(std::vector<int>::reverse_iterator begin, std::vector<int>::reverse_iterator end);
void swap(int& a, int& b);
void show_selection_sort();

void selection_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end){
    if(begin == end)
        return;
    
    for(; begin != end - 1; ++begin){ // n번
        auto old_status_begin = begin;
        
        auto smallest = begin; 
        for(begin += 1; begin != end; ++begin){ // k번
            if(*smallest > *begin)
                smallest = begin;
        }

        begin = old_status_begin;
        swap(*begin, *smallest);
    }

    // 시간 복잡도 : n + n-1 + n-2 + ... + 1 = O(n^2)
    // 버블 정렬과 마찬가지로 항상 n^2의 시간 복잡도를 가진다. -> 최소한 삽입 정렬을 구현하자...
    // 선택 정렬은 불안정 정렬인데, 이는 다시 말해 동일한 값을 갖는 경우에, 동일한 값 간의 상대적인 위치가 변경될 수 있다는 말이다.
    // 이는 swap의 대상이 되는 요소들이 인접해 있지 않기 때문이다.
    // 예) 3(a) 3(b) 2 1  -->  1 2 3(b) 3(a)

    // 그에 반해 버블과 삽입 정렬은 안정 정렬이다.
    // 버블 정렬과 삽입 정렬은 인접한 두 요소의 순서를 바꾸기 때문이다.
    // 인접한 두 요소가 같다면 swap이 일어나지 않으므로, 항상 상대적 순서가 유지된다.
}

void selection_sort(std::vector<int>::reverse_iterator begin, std::vector<int>::reverse_iterator end){
    if(begin == end)
        return;
    
    for(; begin != end - 1; ++begin){ // n번
        auto old_status_begin = begin;
        
        auto smallest = begin; 
        for(begin += 1; begin != end; ++begin){ // k번
            if(*smallest > *begin)
                smallest = begin;
        }

        begin = old_status_begin;
        swap(*begin, *smallest);
    }
}

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void show_selection_sort(){
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
    selection_sort(ivec.begin(), ivec.end());
    for(int elem : ivec)
        std::cout << elem << " ";
    std::cout << "\n\n";

    std::cout << "descending\n";
    selection_sort(ivec.rbegin(), ivec.rend());
    for(int elem : ivec)
        std::cout << elem << " ";
    std::cout << "\n\n";
}

#endif