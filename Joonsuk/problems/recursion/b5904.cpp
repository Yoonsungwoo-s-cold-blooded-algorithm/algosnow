#include <iostream>
#include <string>

// 1. 원하는 수가 어떤 S(n)에 들어 있는지 구한다.
// 2. 해당 원하는 수가 k+2 내부에 있는 수인지 구한다. 
    // 3. 그렇다면 출력
    // 4. 그렇지 않다면 S(n-1)의 길이 + k+3 만큼을 N에서 빼고, 

using std::string;
int length_of_Sn(int n);
char S(int n_th, int pos);


int main() {
    int N;
    std::cin >> N;
    string moo = "";

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

