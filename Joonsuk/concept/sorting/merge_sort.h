#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <vector>
#include <iostream>
#include <iterator>

void merge_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end);
void show_merge_sort();

void merge_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end){
    if(begin == end || begin == end-1)
        return;
    
    auto center = begin + (end - begin)/2;
    merge_sort(begin, center);
    merge_sort(center, end);

    std::vector<int> first(begin, center);
    std::vector<int> second(center, end);

    auto first_begin = first.begin();
    auto second_begin = second.begin();

    while((first_begin != first.end()) && (second_begin != second.end())){
        if(*first_begin < *second_begin)
            *begin++ = *first_begin++;
        else
            *begin++ = *second_begin++;
    }
    
    if(first_begin != first.end()){
        while (begin != end)
            *begin++ = *first_begin++;
    }
    else{
        while(begin != end)
            *begin++ = *second_begin++;
    }
}


void show_merge_sort(){
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
    merge_sort(ivec.begin(), ivec.end());
    for(int elem : ivec)
        std::cout << elem << " ";
    std::cout << "\n\n";
}


#endif