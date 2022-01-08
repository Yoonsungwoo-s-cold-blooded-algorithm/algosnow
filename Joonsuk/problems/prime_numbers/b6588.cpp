#include <iostream>
#include <vector>

void eratos(std::vector<bool>& is_prime);
int idx_of_first_true(std::vector<bool>& vec, int start);
void delete_multiple(std::vector<bool>& vec, int idx);

int main(){
    std::vector<bool> is_prime(1000001, true); // idx: 0~1000000
    eratos(is_prime);

    std::vector<int> vector_of_n;
    while (true) {
        int user_input;
        std::cin >> user_input;

        if(user_input == 0)
            break;
        else
            vector_of_n.push_back(user_input);
    }
    
    int a = 3, b;
    for(int n : vector_of_n){
        int a = 3, b;
        while(true){
            if(a * 2 > n){
                std::cout << "Goldbach's conjecture is wrong." << std::endl;
                break;
            }
            if(is_prime.at(n - a)){
                b = n - a;
                break;
            }
            a = idx_of_first_true(is_prime, a + 1);
        }
        std::cout << n << " = " << a << " + " << b << "\n"; 
        // 1. 제일 작은 소수에 대해서 (n - 소수)가 소수인지 확인한다.
        // 2. 소수가 아니면 그 다음 소수에 대해서 1을 반복한다.
        // 3. n / 2 보다 작은 모든 소수에 대해서 수행했다면 골드바흐의 추측이 틀렸음을 출력한다.
    }

}

void eratos(std::vector<bool>& is_prime){
    is_prime.at(0) = false;
    is_prime.at(1) = false;

    int next_prime_idx = 0;
    while(true){
        next_prime_idx = idx_of_first_true(is_prime, next_prime_idx + 1);
        if(next_prime_idx == is_prime.size())
            break;
        // std::cout << "next prime: " << next_prime_idx << "\n";
        delete_multiple(is_prime, next_prime_idx);
    }
}

int idx_of_first_true(std::vector<bool>& vec, int start){
    for(int i = start; i < vec.size(); ++i) {
        if(vec.at(i) == true)
            return i;
    }
    return vec.size();
}

void delete_multiple(std::vector<bool>& vec, int idx){
    int multiplier = 2;
    while(idx * multiplier < vec.size()){
        vec.at(idx * multiplier) = false;
        ++multiplier;
    }
}
