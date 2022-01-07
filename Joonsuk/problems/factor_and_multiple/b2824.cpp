#include <iostream>
#include <vector>

// 1. 입력을 두 벡터에 받는다.
// 2. 각각의 벡터에 담긴 모든 원소들에 대해서 소인수 분해를 한다.
    // 2-1. 2부터 루트n 까지의 수에 대해서 소수 판정을 한다.
        // 만약 소수라면
            // 소수들을 담는 벡터에 따로 저장한다.
            // 2로 돌아가 다음 원소에 대해서 소인수 분해 
        // 만약 나누어진다면, 해당 숫자로 나눌 수 있는 만큼 나누고, 나머지에 대해서 다시 2-1을 수행한다.
// 3. 두 벡터를 동시에 돌면서, 동시에 0이 아닌 인덱스에 멈춘다.
// 4. 해당 인덱스에 접근하여, 작은값을 반환한다.
// 5. 최종 결과에 작은 값 * 인덱스를 곱한다.
// 6. 만약 최종 결과가 9자리 보다 큰 경우에는 10번째 자리가 1이고 나머지 9자리를 유지하는 수로 만든다.
#define SIZE_OF_FACTOR 32000

int factorization(int number, std::vector<int>& storage);
int give_smaller(int i, int j);
int power(int base, int exponent);
unsigned int ensure_validity_of_final_result(unsigned long long final_result);

std::vector<int> factor_of_n(SIZE_OF_FACTOR + 1, 0), factor_of_m(SIZE_OF_FACTOR + 1, 0);
std::vector<int> huge_prime_of_n, huge_prime_of_m;

int main(){ 
    int N, M;
    std::vector<int> vector_of_n, vector_of_m;

    std::cin >> N;
    for(int i = 0; i != N; ++i){
        int input_n;
        std::cin >> input_n;
        vector_of_n.push_back(input_n);
    }
    std::cin >> M;
    for(int i = 0; i != M; ++i){
        int input_m;
        std::cin >> input_m;
        vector_of_m.push_back(input_m);
    }

    for(int n : vector_of_n){
        while(true){
            int flag = factorization(n, factor_of_n);
            if(flag == 1)
                break;
            if(flag == -1){
                huge_prime_of_n.push_back(n);
                break;
            }
            n = flag;
        }
    }

    for(int m : vector_of_m){
        while(true){
            int flag = factorization(m, factor_of_m);
            if(flag == 1)
                break;
            if(flag == -1){
                huge_prime_of_m.push_back(m);
                break;
            }
            m = flag;
        }
    }

    unsigned long long int final_result = 1;
    for(int i = 0; i != factor_of_n.size(); ++i){
        if(factor_of_n.at(i) != 0 && factor_of_m.at(i) != 0){
            int mulitplier = give_smaller(factor_of_n.at(i), factor_of_m.at(i));
            final_result *= power(i, mulitplier);
            final_result = ensure_validity_of_final_result(final_result);
        }
    }

    if(!(huge_prime_of_m.empty() || huge_prime_of_n.empty())){
        for(int each_prime : huge_prime_of_n){
            for(int i = 0; i != huge_prime_of_m.size(); ++i){
                if(each_prime == huge_prime_of_m.at(i)){
                    final_result *= each_prime;
                    final_result = ensure_validity_of_final_result(final_result);
                }
            }
        }
    }
    
    unsigned int ten_digit = 1000000000;
    if(final_result > ten_digit){
        int final_result_with_0 = final_result - ten_digit;
        printf("%09d",final_result_with_0);
    }
    else
        std::cout << final_result << std::endl;
}


// 매우 큰 소수이면 -1, 1이면 1을 반환.  그렇지 않다면 나머지 반환
int factorization(int number, std::vector<int>& storage){
    for(int i = 2; i*i <= number; ++i){
        if(number % i == 0){
            while(number % i == 0){ 
                number /= i;
                ++(storage.at(i));
            }
            return number;
        }
    }
    // 소수 또는 1인 경우

    

    if(number > SIZE_OF_FACTOR)
        return -1;
    else
        ++(storage.at(number));
        
    return 1;
}

int give_smaller(int i, int j){
    return (i > j) ? j : i;
}

int power(int base, int exponent){
    int result = 1;
    for(int i = 0; i != exponent; ++i){
        result *= base;
    }
    return result;
}

unsigned int ensure_validity_of_final_result(unsigned long long final_result){
    unsigned ten_digit = 1000000000;
    if(final_result > ten_digit){
        unsigned remain = (final_result % ten_digit) + ten_digit;
        return remain;
    }
    return final_result;
}