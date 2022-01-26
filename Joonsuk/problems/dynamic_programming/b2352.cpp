// 라인을 하나의 엔트리라고 생각해보자.
// 하나의 라인이 추가될때마다 해당 라인을 포함하는 LCS 길이를 구할 수 있을까?
// 라인을 pair라고 하면, 해당 pair보다 작은 pair의 길이 + 1이 새로운 pair의 길이가 될 것이다.
// 해당 pair보다 작은 pair가 존재하지 않는다면 새로운 pair의 길이는 1이다. -> LIS가 된다.
#include <iostream>
#include <utility>
#include <vector>
void LIS(int n);

typedef std::pair<int, int> Line;
int lenght[40001]; // 0, 1~~40000
Line lines[40001];

int main(){
    int N;
    std::cin >> N;

    Line input_line;
    for(int i = 0; i != N; ++i){ // N
        input_line.first = i+1;
        std::cin >> input_line.second;
        lines[i+1] = input_line;

        LIS(i+1);
    }

    std::cout << lenght[N];
}

// TODO : 시간 복잡도 줄이기.
void LIS(int n) {
    int max_length = 1;
    for (int i = n - 1; i != 0; --i) { // K번 수행
        // 항상 first는 lines[n]이 크다. 따라서 second만 크다면 lines[n]이 전체적으로 크다.
        if (lines[n].second > lines[i].second) {
            if(max_length < lenght[i]+1)
                max_length = lenght[i]+1;
        }
    }
    lenght[n] = max_length;
}


