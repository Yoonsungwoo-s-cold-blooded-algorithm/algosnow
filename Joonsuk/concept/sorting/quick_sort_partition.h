#ifndef QUICK_SORT_PARTITION_H
#define QUICK_SORT_PARTITION_H

#include <vector>
std::vector<int>::iterator partition(std::vector<int>::iterator begin, std::vector<int>::iterator end);

std::vector<int>::iterator partition(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if(begin == end)
        return begin; // undefined
    if(begin == end-1)
        return begin;
    
    auto pivot = begin;

    auto low = begin + 1;
    auto high = end - 1;
    
    while(low <= high){
        if(*low < *pivot)
            ++low;
        if(*high > *pivot)
            --high;
        
        if(low > high)
            break;

        if(*low > *pivot && *high < *pivot){
            int temp = *low;
            *low = *high;
            *high = temp;
            ++low; --high;
        }
    }

    int temp = *high;
    *high = *pivot;
    *pivot = temp;

    return high; // high와 pivot을 교환하였기 때문에, pivot이 아닌 high를 반환합니다. 반환값은 pivot의 위치입니다.
}

#endif