#include <iostream>

int A[1001]; // 0 ~ 1000
int reverse_A[1001]; // 0, 1000 ~ 1
int length[1001];
int increasing_length_of_entry[1001];
int decreasing_length_of_entry[1001];
int bitonic_length[1001];
int LIS(int n);

int main(){
    int N, single_A;
    std::cin >> N;
    
    for(int i = 0; i != N; ++i){
        std::cin >> single_A;
        A[i+1] = single_A;
        reverse_A[N-i] = single_A;
    }
    
    // 각 요소에 대한 LIS 길이를 저장
    for(int i = 0; i != N; ++i)
        increasing_length_of_entry[i+1] = LIS(A[i+1]);
    // length 초기화
    for (int i = 0; i != 1000; ++i)
        length[i + 1] = 0;
    // 각 요소에 대한 LDS 길이를 저장
    for(int i = 0; i != N; ++i)
        decreasing_length_of_entry[N-i] = LIS(reverse_A[i+1]);
    
    // 각 요소들의 LIS + LDS - 1이 바이토닉 길이가 된다.
    for(int i = 0; i != N; ++i)
        bitonic_length[i+1] = increasing_length_of_entry[i+1] + decreasing_length_of_entry[i+1] - 1;
    
    // 바이토닉 길이의 최댓값 찾기
    int max_bitonic_length = 1;
    for(int i = 0; i != N; ++i){
        if(bitonic_length[i+1] > max_bitonic_length)
            max_bitonic_length = bitonic_length[i+1];
    }

    std::cout << max_bitonic_length;
}

int LIS(int n){
    int length_of_n = 1;
    for(int i = 1; i != n; ++i){ // 1부터 n-1까지 제일 높은 길이 + 1을 n의 길이로 한다.
        if(length[i]+1 > length_of_n)
            length_of_n = length[i]+1;
    }

    if(length_of_n > length[n])
        length[n] = length_of_n;

    return length_of_n;
}

