#include <iostream>
#include <string>

// 핵심 아이디어: 
// 1. n번째 moo 수열에서 k번째 칸에 목표 단어가 있다고 하자.
// 2. moo 수열에서 비 대칭인 부분(중간 부분)에 목표 단어가 있다면 바로 구할 수 있다.
// 3. 그렇지 않다면 n-1번째 moo 수열에서 목표 단어를 구할 수 있다는 뜻이다.
    // 3-1. n-1번째 moo 수열의 길이보다 k가 크지 않다면 1번을 n-1 moo수열에 대해서 수행한다.
    // 3-2. 그렇지 않다면 k -= (n-1 moo 수열의 길이 + 비대칭 길이)로 조정한뒤, 1번을 n-1 moo 수열에 대해서 수행한다.

using std::string;
int length_of_Sn(int n);
char S(int n_th, int pos);


int main() {
    int N;
    std::cin >> N;

    int n_th = 0;
    while(length_of_Sn(n_th) < N)
        ++n_th;
    
    std::cout << S(n_th, N) << "\n";
}

char S(int n_th, int pos){
    if(n_th == 0){
        string moo = "moo";
        return moo[pos - 1];
    }

    int length = length_of_Sn(n_th - 1);
    // 앞 부분
    if(pos < length + 1){
        return S(n_th - 1, pos);
    }
    // 중간 부분
    else if(pos < length + n_th + 4){
        pos -= length;
        return (pos == 1) ? 'm' : 'o';
    }
    // 뒤 부분
    else{
        pos -= length;
        pos -= n_th + 3;
        return S(n_th - 1, pos);
    }
}

int length_of_Sn(int n){
    if(n == 0)
        return 3;
    
    return 2 * length_of_Sn(n - 1) + n + 3;
}

