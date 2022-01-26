#include <iostream>
#include <string>

std::string lcs[1001][1001]; // 0은 바깥
bool lcs_found[1001][1001];
std::string A, B;
std::string ans;

void find_lcs(int a, int b);

int main(){
    std::cin >> A >> B;
    find_lcs(A.size(), B.size());
    std::cout << (lcs[A.size()][B.size()]).size() << "\n" << lcs[A.size()][B.size()];
}

void find_lcs(int a, int b){
    lcs_found[a][b] = true;
    if(a == 0 || b == 0)
        return;
    
    if(A[a-1] == B[b-1]){
        if(!lcs_found[a-1][b-1])
            find_lcs(a-1, b-1);
        lcs[a][b] = lcs[a-1][b-1] + A[a-1]; // string + 연산
        ans.push_back(A[a-1]);
    }
    else{
        if(!lcs_found[a-1][b])
            find_lcs(a-1, b);
        if(!lcs_found[a][b-1])
            find_lcs(a, b-1);

        lcs[a][b] = ((lcs[a-1][b]).size() > (lcs[a][b-1]).size()) ? (lcs[a-1][b]) : (lcs[a][b-1]);
    }
}

// lcs를 거슬러 올라가는 과정을 통해서 string배열 없이도 해결할 수 있다.
// 다음에 다시 비슷한 문제를 보게 되면 시도해 볼 것.
