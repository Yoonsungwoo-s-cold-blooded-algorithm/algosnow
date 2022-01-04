#include <iostream>
#include <vector>
// 1. 랜덤 엑세스가 필요함
// 2. 컨테이너의 크기를 조정 or 컨테이너 원소의 값을 변경 
// 3. 크기의 조정과 값의 변경이 자료구조의 중간에서 발생
// 따라서 vector를 사용

size_t get_first_false(std::vector<bool>& vec);
void delete_multiple_of_P(std::vector<bool>& vec, size_t P, int& delete_count, int K);

int main(){
    std::vector<bool> is_deleted;
    int N, K, delete_count = 0;
    std::cin >> N >> K;

    for(int i = 0; i != N + 1; ++i) // idx : 0 ~ N
        is_deleted.push_back(false);
    is_deleted.at(0) = true;
    is_deleted.at(1) = true;
    
    while(true) {
        size_t P = get_first_false(is_deleted);
        // std::cout << "next prime number : " << P << std::endl;
        if(P == is_deleted.size())
            break;
        
        delete_multiple_of_P(is_deleted, P, delete_count, K);
    }
}

size_t get_first_false(std::vector<bool>& vec) {
    for(size_t idx = 0; idx != vec.size(); ++idx){
        if(vec.at(idx) == false)
            return idx;
    }
    return vec.size();
}

void delete_multiple_of_P(std::vector<bool>& vec, size_t P, int& delete_count, int K) {
    size_t multiplier = 1;
    while((P * multiplier) < vec.size()){
        if(vec.at(P * multiplier) == true){
            ++multiplier;
            continue;
        }
        vec.at(P * multiplier) = true;

        ++delete_count;
        // std::cout << "deleted_count : " << delete_count << std::endl;
        if(delete_count == K)
            std::cout << P * multiplier;

        ++multiplier;
    }
}