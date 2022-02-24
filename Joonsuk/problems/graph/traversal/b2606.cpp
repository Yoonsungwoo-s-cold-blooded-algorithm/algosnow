// 1. 그래프를 인접 행렬의 형태로 나타낸다.
// 2. 1번 노드부터 시작하는데, 해당 노드를 방문함을 표시한다.
// 3. 해당 노드와 연결되었고, 방문하지 않은 모든 노드들에 대해서
// 4. 2,3번을 반목한다.

#include <array>
#include <iostream>
#include <vector>

void DFS(int i);

std::array<std::array<int, 101>, 101> graph;
std::array<int, 101> visitied;

int main() {
    int N, T;

    std::cin >> N >> T;
    for (int i = 0; i != T; ++i) {
        int x, y;
        std::cin >> x >> y;
        graph[x][y] = y;
        graph[y][x] = x;
    }

    DFS(1);

    int count = 0;
    for (int visit : visitied) {
        if (visit == 1)
            ++count;
    }

    std::cout << count - 1;
}

void DFS(int i) {
    visitied[i] = 1;

    for (int node : graph[i]) {
        // 0이 아닌 노드중 방문하지 않은 경우
        if (node != 0 && visitied[node] == 0) {
            DFS(node);
        }
    }
}