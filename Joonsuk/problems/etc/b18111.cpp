#include <iostream>
#include <vector>
#include <algorithm>

int length_of_lowest(std::vector<int> height);
int fill_lowest(std::vector<int>& height);
int delete_highest(std::vector<int>& height);
int length_of_highest(std::vector<int> height);

int main() {
    int M, N, B;
    int total_time_eilapsed = 0;
    std::vector<int> height_of_blocks;

    std::cin >> M >> N >> B;
    for(int i = 0; i != M; ++i) {
        for(int j = 0; j != N; ++j){
            int height_of_block;
            std::cin >> height_of_block;
            height_of_blocks.push_back(height_of_block);
        }
    }

    std::sort(height_of_blocks.begin(), height_of_blocks.end());

    while (height_of_blocks.front() != height_of_blocks.back()) {
        if(B >= length_of_lowest(height_of_blocks) // 채울 블럭이 충분하거나
        && (length_of_lowest(height_of_blocks) <= (length_of_highest(height_of_blocks) * 2))){ // 채우는 것이 시간적 이득인 경우에
            int used_blocks = fill_lowest(height_of_blocks);
            B -= used_blocks;
            total_time_eilapsed += used_blocks;
        } 
        else{
            int deleted_blocks = delete_highest(height_of_blocks);
            B += deleted_blocks;
            total_time_eilapsed += 2*deleted_blocks;
        }
    }
    
    std::cout << total_time_eilapsed << " " << height_of_blocks.front() << std::endl;
}

// 가장 낮은 높이를 갖는 칸의 개수 반환
int length_of_lowest(std::vector<int> height){
    for(int i = 0; i != height.size() - 1; ++i){
        if(height.at(i) != height.at(i + 1))
            return i + 1;
    }
    std::cout << "impossible : check while's condition and position of function call" << std::endl;
    return height.size();
}

// 가장 높은 높이를 갖는 칸의 개수 반환
int length_of_highest(std::vector<int> height){
    for(int i = height.size() - 1; i != 0; --i){
        if(height.at(i) != height.at(i - 1))
            return height.size() - i;
    }
    std::cout << "impossible : check while's condition and position of function call" << std::endl;
    return height.size();
}

// 사용한 블럭의 개수 반환
int fill_lowest(std::vector<int>& height){
    int used_blocks = 0;
    for(int i = 0; i != height.size() - 1; ++i){
        if(height.at(i) != height.at(i + 1)){
            height.at(i) = height.at(i) + 1;
            ++used_blocks;
            return used_blocks;
        }
            
        height.at(i) = height.at(i) + 1;
        ++used_blocks;
    }
    return height.size();
}

// 제거한 블럭의 개수 반환
int delete_highest(std::vector<int>& height){
    int deleted_blocks = 0;
    for(int i = height.size() - 1; i != 0; --i){
        if(height.at(i) != height.at(i - 1)) {
            height.at(i) = height.at(i) - 1;
            ++deleted_blocks;
            return deleted_blocks;
        }

        height.at(i) = height.at(i) - 1;
        ++deleted_blocks;
    }
    return height.size();
}