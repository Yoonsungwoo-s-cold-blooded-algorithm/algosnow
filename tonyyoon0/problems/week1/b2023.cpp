#include <iostream>
#include <cmath>
 
int nums[100000000];
 
bool prime_checker(int prime){
    if (!(nums[prime] == 0)) return true;
    else return false;
}
 
bool special_prime_checker(int prime, int N) {
    for (int i = N; i > 1; i--) {
        if (!(prime_checker(prime / pow(10, i - 1)))) return false;
    }
    return true;
}
 
int main() {
    int N;
    std::cin >> N;
 
    for (int i = 0; i < pow(10, N); i++) {
        nums[i] = i;
    }
    nums[0] = 0;
    nums[1] = 0;
 
    // 에라토스테네스의 체 (2부터 10^N 까지)
    for (int i = 2; i * i < pow(10, N); i++) {
        for (int j = i * i; j < pow(10, N); j += i) {
            nums[j] = 0;
       }
    }
 
    // 결과 출력
    for (int i = pow(10, N - 1); i < pow(10, N); i++) {
        if (nums[i] != 0) {
            if(special_prime_checker(i, N)) std::cout << i << std::endl;
        } 
    }
}