#include <iostream>
#include <vector>

std::vector<bool> is_prime(1000000, true); // 0~99999999
void eratos(std::vector<bool>& is_prime);
int idx_of_first_true(std::vector<bool>& vec, int start);
void delete_multiple(std::vector<bool>& vec, int idx);
bool is_special_prime(int num);
bool is_prime_sqrt(int num);

int main() {
    eratos(is_prime);
    int N = 0;
    std::cin >> N;

    // 6자리 수인 경우
    if(N < 7){
        int digit = 1;
        for(int i = 0; i != N - 1; ++i)
            digit *= 10;

        for(int i = digit; i != digit * 10; ++i){
            if(is_special_prime(i))
                std::cout << i << "\n";
        }
    }
    else{
        std::vector<int> special_primes_6digit;
        std::vector<int> special_primes_7digit;
        int digit = 1;
        for(int i = 0; i != 5; ++i)
            digit *= 10; // 100000

        for(int i = digit; i != digit * 10; ++i){
            if(is_special_prime(i))
                special_primes_6digit.push_back(i);
        }

        // 7th digit
        for(int num : special_primes_6digit){
            for(int i = 1; i != 10; ++i){
                if(is_prime_sqrt(num*10 + i)){
                    if(N == 7)
                        std::cout << num*10 + i << "\n";
                    else
                        special_primes_7digit.push_back(num*10 + i);
                }
                    
            }
        }
        if(N == 8){
            for(int num : special_primes_7digit){
                for(int i = 1; i != 10; ++i){
                    if(is_prime_sqrt(num*10 + i)){
                        std::cout << num*10 + i << "\n";
                    }
                    
                }
            }
        }
    }

    
}

bool is_special_prime(int num){
    while(true) {
        if(is_prime.at(num)){
            num /= 10;
            if(num == 0)
                return true;
        } 
        else{
            return false;
        }
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

bool is_prime_sqrt(int num){
    for(int i = 2; i*i <= num; ++i){
        if(num % i == 0)
            return false;
    }
    return true;
}