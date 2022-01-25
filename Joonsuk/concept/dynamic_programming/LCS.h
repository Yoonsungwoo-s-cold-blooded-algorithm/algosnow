// LCS 알고리즘은 최장 공통 부분 수열을 찾는 알고리즘이다.
// 1. A[i] = B[i]라면 lcs[i][i] = lcs[i-1][i-1] + 1이며
// 2. 아니라면 lcs[i-1][i]와 lcs[i][i-1] 중에 큰 값이 된다.

// 다이나믹 프로그래밍의 해답을 구할때는 점화식을 구하는 것처럼 n을 구하기 위해서 n-1을 구하는 방식으로 접근한다.

// 다이나믹 프로그래밍은 Top_down방식과 Bottom_up 방식이 존재한다.
// top down 방식은 재귀적 구조라고 생각하면 되고,
// bottom up 방식은 1부터 n까지 차근차근 구하는 방식이라고 생각하면 된다.

// 다이나믹 프로그래밍 문제를 풀때는 2가지 방법 모두 사용해서 풀도록 하자.
// top down = td
// bottom up = bu
#ifndef LCS_H
#define LCS_H

#include <iostream>
#include <string>

void LCS_td() {
    // 뒤에서 a-1과 b-1에 접근하므로 a 또는 b가 0인 경우를 처리해 주어야 한다.
    // a == 0 또는 b == 0일때
    // A[a] == B[b] 이면 lcs[a][b] = 1
    // 그렇지 않고 a > b 또는 a < b이면 lcs[a][b] = lcs[a-1][b] 또는 lcs[a][b-1]

    // A[a] == B[b] 이면 lcs[a][b] = lcs[a-1][b-1] + 1
    // 아니라면 lcs[a][b] = max(lcs[a-1][b], lcs[a][b-1])

    // b9251 참고
}

void LCS_bu() {
    // lcs[a][b]를 구하는 데는 lcs[a-1][b-1], lcs[a-1][b], lcs[a][b-1]이 필요하다.
    // 따라서 뒤의 3가지를 lcs[a][b]를 구하기 전에 알 수 있다면, lcs[a][b]를 바로 구할 수 있다.
    // 이는 a, b가 0일때 부터 시작하여 n일때 까지 순차적으로 구하는 것과 같다.

    std::string s1, s2;
    std::cin >> s1 >> s2;

    int n1 = s1.size();
    int n2 = s2.size();

    int lcs[100][100]; 
    for(int i = 0; i != n1+1; ++i){
        for(int j = 0; j != n2+1; ++j){
            if(i==0 || j==0)
                lcs[i][j] == 0;
            else if(s1[i-1] == s2[j-1])
                lcs[i][j] = lcs[i-1][j-1] + 1;
            else
                lcs[i][j] = (lcs[i-1][j] > lcs[i][j-1]) ? (lcs[i-1][j]) : (lcs[i][j-1]);
        }
    }
    std::cout << lcs[n1][n2];
}

#endif