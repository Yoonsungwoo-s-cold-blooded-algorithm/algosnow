#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <vector>
#include <iostream>
#include <iterator>

void insertion_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end);
void insertion_sort(std::vector<int>::reverse_iterator begin, std::vector<int>::reverse_iterator end);
void swap(int& a, int& b);
void show_insertion_sort();

void insertion_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end){
    if(begin == end)
        return;
    
    for(auto key = begin + 1; key != end; ++key){ // n
        auto old_state_key = key;

        for(; key != begin; --key){ // k번
            if(*key < *(key - 1)) 
                swap(*key, *(key - 1));
            else
                break;
        }

        key = old_state_key;
    }
    // 시간 복잡도: 1 + 2 + 3 + ... + n-1 = O(n^2)
    // 하지만 대부분의 요소가 정렬되어 있다면 효율적일 수 있다. (안에 break문 덕분)

    // 버블정렬과의 비교
    // 버블정렬과 시간 복잡도는 동일하지만 삽입정렬의 경우 내부에 break문이 존재한다.
    // 내부 for문이 모두 수행되지 않고 중간에 break되는 경우가 존재할 수 있으므로,
    // 삽입정렬보다 대부분의 경우에서 더 좋은 정렬법이라 할 수 있다.
    // 이는 오메가 표기법(best)에서 시간복잡도 n과 n^2의 차이를 통해서 확인할 수 있다.
}

void insertion_sort(std::vector<int>::reverse_iterator begin, std::vector<int>::reverse_iterator end){
    if(begin == end)
        return;
    
    for(auto key = begin + 1; key != end; ++key){
        auto old_state_key = key;

        for(; key != begin; --key){
            if(*key < *(key - 1)) 
                swap(*key, *(key - 1));
        }
        
        key = old_state_key;
    }
}

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void show_insertion_sort(){
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
    insertion_sort(ivec.begin(), ivec.end());
    for(int elem : ivec)
        std::cout << elem << " ";
    std::cout << "\n\n";

    std::cout << "descending\n";
    insertion_sort(ivec.rbegin(), ivec.rend());
    for(int elem : ivec)
        std::cout << elem << " ";
    std::cout << "\n\n";
}

#endif