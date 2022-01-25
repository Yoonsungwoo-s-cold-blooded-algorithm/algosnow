#include <vector>
#include <iostream>
#include <iterator>

void merge_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end);

int main(){
    std::ios::sync_with_stdio(false);

    int N, K;
    std::vector<int> ivec;
    std::cin >> N >> K;
    for(int i = 0; i != N; ++i){
        int temp;
        std::cin >> temp; // 전역 변수로 할당하면 불필요한 메모리 할당이 적을것이다.
        ivec.push_back(temp);
    }

    merge_sort(ivec.begin(), ivec.end());

    std::cout << ivec.at(K - 1);
}


void merge_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end){
    if(begin == end)
        return;
    if(begin == end-1)
        return;
    
    auto center = begin + (end - begin)/2;
    merge_sort(begin, center);
    merge_sort(center, end);

    std::vector<int> first(begin, center);
    std::vector<int> second(center, end);

    auto first_begin = first.begin(), first_end = first.end();
    auto second_begin = second.begin(), second_end = second.end();

    while((first_begin != first_end) && (second_begin != second_end)){
        if(*first_begin < *second_begin){
            *begin = *first_begin;
            ++begin; ++first_begin;
        } 
        else{
            *begin = *second_begin;
            ++begin; ++second_begin;
        }
    }

    if(first_begin != first_end){
        while(begin != end){
            *begin = *first_begin;
            ++begin; ++first_begin;
        }
    }
    else if(second_begin != second_end){
        while(begin != end){
            *begin = *second_begin;
            ++begin; ++second_begin;
        }
    }

    return;
}