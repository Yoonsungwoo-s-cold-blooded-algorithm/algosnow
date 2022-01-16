// 전체 길이 - 필요한 길이 = 필요 없는 길이
// 낮은 순서대로 정렬
    // if (현재 나무 길이보다 작은 나무들의 길이 합 + 현재 나무 길이 * 해당 길이 이상인 나무의 개수) < 필요 없는 길이
        // 현재 나무 길이를 다음으로 제일 작은 나무로 변경, 작은 나무들의 길이 합 갱신
    // else
        // 현재 나무의 개수는 고정됨


#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> heights;
    int N, M;
    long long int sum_of_heights = 0;
    std::cin >> N >> M;

    // n
    for(int i = 0; i != N; ++i){
        int input;
        std::cin >> input;
        sum_of_heights += input;
        heights.push_back(input);
    }

    // n log n
    std::sort(heights.begin(), heights.end());

    long long int sum_of_useless_heights = sum_of_heights - M; 
    int max_height = 0, smaller_woods_count = 0, sum_heights_of_smaller = 0;

    while(true) {
        // n
        auto it = std::find_if(heights.begin(), heights.end(),
            [max_height] (const int& current_height) { return max_height < current_height; });
        max_height = *it;
        smaller_woods_count = it - heights.begin();

        if(sum_heights_of_smaller + max_height * (N - smaller_woods_count) < sum_of_useless_heights){
            // n
            auto end = std::find_if(heights.begin(), heights.end(),
            [max_height] (const int& current_height) { return max_height < current_height; });

            sum_heights_of_smaller += (max_height * (end - it));
        }
        else {
            while(sum_heights_of_smaller + max_height * (N - smaller_woods_count) > sum_of_useless_heights)
                --max_height;
            
            std::cout << max_height << "\n";
            break;
        }
    }

    // 총 시간 복잡도 : nlogn
}

