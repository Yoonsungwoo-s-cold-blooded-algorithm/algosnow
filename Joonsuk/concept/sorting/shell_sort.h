#ifndef SHELL_SORT_H
#define SHELL_SORT_H

#include <iostream>
#include <vector>
#include <iterator>

void shell_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end);
void shell_sort(std::vector<int>::reverse_iterator begin, std::vector<int>::reverse_iterator end);
void swap(int& a, int& b);
void show_shell_sort();

// random-access iterator만 가능 (+= 연산)
void shell_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end){
    if(begin == end)
        return;

    int gap = (end - begin) / 2; // 최소 1회의 begin += gap을 보장
    while(true){
        // sub 레코드의 모든 요소에 대해서
        for(int i = 0; i != gap; ++i){
            // 각 요소의 간격이 gap인 레코드의 삽입 정렬.
            for(auto key = begin + i;; key += gap){ 
                auto old_state_key = key;

                for(; key != (begin+i); key -= gap){
                    if(*key < *(key - gap))
                        swap(*key, *(key - gap));
                    else
                        break;
                }

                key = old_state_key;

                // ((마지막 요소 + 1) - 현재 처리한 요소)가 gap보다 작거나 같으면 break;
                // why? 현재 처리한 요소가 마지막인 경우 gap보다 작다.
                // 0,1,2    3,4,5   6 인 경우 gap = 3
                // size() - 6 <= 3
                if(end - key <= gap)
                    break;
            }
        }
        if(gap == 1)
            break;
        else
            gap /= 2;
    }
    
    // 셸 정렬은 다음과 같다.
    // 1. 큰 레코드를 작은 레코드로 분해한다.
    // 2. 각 레코드들의 동일한 인덱스를 가진 요소끼리 삽입 정렬을 수행한다.
    // 3. 다시, 큰 레코드를 더 작은 레코드로 분해하고 삽입 정렬을 수행하는 것을 반복한다.
    // 4. 만약 더 작은 레코드로 분해할 수 없을 때, 즉 레코드의 크기가 1이 될 때 정렬이 완료된다.

    // 셸 정렬의 핵심 아이디어는 먼 요소들과의 자리 교환이다.
    // 삽입 정렬은 어느정도 정렬된 레코드에서는 속도가 매우 빠르기 때문에,
    // 먼 요소와 교환을 통해 미리 어느정도 정렬을 해놓은 후, gap이 1인 삽입정렬을 빠르게 수행하는 것이다.

    // 셸 정렬은 선택 정렬과 마찬가지로 먼 요소끼리 교환이 일어나기 때문에,
    // 불 안정 정렬에 속한다.
}

void shell_sort(std::vector<int>::reverse_iterator begin, std::vector<int>::reverse_iterator end){
    if(begin == end)
        return;

    int gap = (end - begin) / 2; // 최소 1회의 begin += gap을 보장
    while(true){
        // sub 레코드의 모든 요소에 대해서
        for(int i = 0; i != gap; ++i){
            // 각 요소의 간격이 gap인 레코드의 삽입 정렬.
            for(auto key = begin + i; ; key += gap){ 
                auto old_state_key = key;

                for(; key != (begin+i); key -= gap){
                    if(*key < *(key - gap))
                        swap(*key, *(key - gap));
                    else
                        break;
                }

                key = old_state_key;

                if(end - key <= gap)
                    break;
            }
        }
        if(gap == 1)
            break;
        else
            gap /= 2;
    }
}

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void show_shell_sort(){
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
    shell_sort(ivec.begin(), ivec.end());
    for(int elem : ivec)
        std::cout << elem << " ";
    std::cout << "\n\n";

    std::cout << "descending\n";
    shell_sort(ivec.rbegin(), ivec.rend());
    for(int elem : ivec)
        std::cout << elem << " ";
    std::cout << "\n\n";
}


#endif