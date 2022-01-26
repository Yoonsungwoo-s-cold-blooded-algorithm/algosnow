// bottom up 방식으로 LCS를 수행하게 되면, 교차하는 전기줄은 고려되지 않는다.

#include <iostream>
#include <string>
#include <set>
#include <utility>

void LCS(int a, int b);
int lcs[501][501]; // 0(끝 값) ~ 500 까지
std::set<std::pair<int, int>> connected_lines; // 이어진 전기줄들을 저장

int main(){
    int N;
    std::cin >> N; // 총 연결된 전기줄의 개수

    int a, b;
    int max_a = 0, max_b = 0;
    for(int i = 0; i != N; ++i){
        std::cin >> a >> b;

        if(a > max_a)
            max_a = a;
        if(b > max_b)
            max_b = b;

        connected_lines.emplace(a, b);
    }

    LCS(max_a, max_b); // 최대 전깃줄 a, b까지
    int deleted_lines = N - lcs[max_a][max_b];
    std::cout << deleted_lines;
}

void LCS(int a, int b){
    for (int i = 0; i != a+1; ++i){
        for(int j = 0; j != b+1; ++j){
            if(i == 0 || j == 0)
                lcs[i][j] = 0;
            else if(connected_lines.find(std::pair<int, int>(i, j)) != connected_lines.end())
                lcs[i][j] = lcs[i-1][j-1] + 1; // lcs[i-1][j-1]은 이전에 도출되었음을 확신한다.
            else
                lcs[i][j] = (lcs[i-1][j] > lcs[i][j-1]) ? (lcs[i-1][j]) : (lcs[i][j-1]); // lcs[i-1][j], lcs[i][j-1]도 마찬가지.              
        }
    }
}
