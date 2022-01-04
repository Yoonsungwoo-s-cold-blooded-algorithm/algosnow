#include <iostream>
#include <vector>

int find_prime(int start, int end);
bool is_prime(int num);

void eratos(int size);
size_t get_next_true(std::vector<bool>& vec, size_t start);
void delete_multiple_of_prime(std::vector<bool>& vec, size_t P);

std::vector<bool> prime_numbers;

int main(){
    eratos(247000);
    std::vector<int> n;
    while(true){
        int temp;
        std::cin >> temp;

        if(temp == 0)
            break;
        n.push_back(temp);
    }

    for(int i = 0; i != n.size(); ++i){
        std::cout << find_prime(n.at(i) + 1, 2 * n.at(i)) << "\n";
    }
}

void eratos(int size) {
    for(int i = 0; i != size + 1; ++i) 
        prime_numbers.push_back(true);
    prime_numbers.at(0) = false;
    prime_numbers.at(1) = false;

    for(int next_prime_index = 0; next_prime_index < prime_numbers.size(); ++next_prime_index){
        next_prime_index = get_next_true(prime_numbers, next_prime_index);
        delete_multiple_of_prime(prime_numbers, next_prime_index);
    }
}

// n
size_t get_next_true(std::vector<bool>& vec, size_t start) {
    for(size_t idx = start; idx != vec.size(); ++idx){
        if(vec.at(idx) == true)
            return idx;
    }
    return vec.size();
}

// n
void delete_multiple_of_prime(std::vector<bool>& vec, size_t P) {
    size_t multiplier = 2;
    while((P * multiplier) < vec.size()){
        vec.at(P * multiplier) = false;
        ++multiplier;
    }
}

int find_prime(int start, int end){
    int count = 0;
    for(int i = start; i != end + 1; ++i){
        if(is_prime(i))
            ++count;
    }
    return count;
}

bool is_prime(int num){
    if(prime_numbers.at(num) == true)
        return true;
    return false;
}

