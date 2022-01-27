#include <vector>
#include <iostream>
#include <algorithm>
void merge_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end);

int main(){
    int N, K, X;
    std::vector<int> levels;
    std::cin >> N >> K;
    for(int i = 0; i != N; ++i){
        std::cin >> X;
        levels.push_back(X);
    }
    merge_sort(levels.begin(), levels.end());
    // 제일 작은 원소를 가져온다.
    // 그 다음으로 작은 원소와 동일한 값을 갖기 위해서 얼마만큼의 레벨이 필요한지 계산한다.
    // 해당 레벨 만큼 올릴 수 있다면, 올린다.
    // 그렇지 않다면 가능한 만큼 올린 후 출력한다.
    int minimum_count = 0;
    auto minimum = levels.begin();
    while (true) {
        auto first_greater_then_minimum = std::find_if(minimum, levels.end(), [minimum](const int& a) {return a > *minimum;});
        minimum_count = (first_greater_then_minimum - levels.begin());

        if(first_greater_then_minimum == levels.end()){ // 모든 레벨을 동일하게 조정했음에도 불구하고 K가 남은 경우
            break;
        }

        int level_need = (*first_greater_then_minimum - *minimum) * minimum_count;
        if(K >= level_need){ // 레벨이 충분한 경우
            K -= level_need;
            minimum = first_greater_then_minimum;
        }
        else{ // 레벨이 부족한 경우
            break;
        }

        // minimum_count = 제일 낮은 값을 갖는 원소의 개수
        // minimum = 제일 낮은 값을 갖는 원소 중 1개
    }

    int current_level = *minimum;
    current_level += (K / minimum_count);
    std::cout << current_level;    
}

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

