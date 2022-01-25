#include <vector>
#include <iostream>

void merge_sort(std::vector<int>::iterator, std::vector<int>::iterator);
int calculate_minimum_height(std::vector<int>::iterator begin, std::vector<int>::iterator end);

int main() {
    int T, N, L;
    int single_height;
    std::cin >> T;

    for(int i = 0; i != T; ++i){
        std::cin >> N;
        std::vector<int> log_height;
        for(int j = 0; j != N; ++j){
            std::cin >> single_height;
            log_height.push_back(single_height);
        }
        merge_sort(log_height.begin(), log_height.end());
        int minimun_height = calculate_minimum_height(log_height.begin(), log_height.end());
        std::cout << minimun_height << "\n";
    }
}

void merge_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end){
    if(begin == end)
        return;
    if(begin == end - 1)
        return;
    
    auto center = begin + (end-begin)/2;
    merge_sort(begin, center);
    merge_sort(center, end);

    std::vector<int> first(begin, center);
    std::vector<int> second(center, end);

    auto first_begin = first.begin(), first_end = first.end();
    auto second_begin = second.begin(), second_end = second.end();

    while ((first_begin != first_end) && (second_begin != second_end)){
        if(*first_begin < *second_begin){
            *begin++ = *first_begin++;
        }
        else{
            *begin++ = *second_begin++;
        }
    }

    if(first_begin != first_end){
        while(first_begin != first_end){
            *begin++ = *first_begin++;
        }
    }
    else{
        while(second_begin != second_end){
            *begin++ = *second_begin++;
        }
    }
}

int calculate_minimum_height(std::vector<int>::iterator begin, std::vector<int>::iterator end){
    if(begin == end)
        return 0;
    if(begin == end-1)
        return 0;

    int minimun = 0;
    auto even_begin = begin, odd_begin = begin + 1;

    if((end - begin)%2 == 0){
        while(even_begin != end-2){
            if(*(even_begin + 2) - *even_begin > minimun)
                minimun = *(even_begin + 2) - *even_begin;
            even_begin += 2;
        }

        while(odd_begin != end-1){
            if(*(odd_begin + 2) - *odd_begin > minimun)
                minimun = *(odd_begin + 2) - *odd_begin;
            odd_begin += 2;
        }
    }
    else{
        while(even_begin != end-1){
            if(*(even_begin + 2) - *even_begin > minimun)
                minimun = *(even_begin + 2) - *even_begin;
            even_begin += 2;
        }

        while(odd_begin != end-2){
            if(*(odd_begin + 2) - *odd_begin > minimun)
                minimun = *(odd_begin + 2) - *odd_begin;
            odd_begin += 2;
        }
    }

    return minimun;
}