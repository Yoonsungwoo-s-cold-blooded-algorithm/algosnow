// 그래프를 순회하면서 visitied 배열을 몇번째로 방문했는지에 관한 int 데이터로 채운다.

// 순회를 하던 중에 다음 노드가 방문 했다면, 몇번째로 방문했는지 확인한다.
// 내가 짝수번째라면, 상대가 짝수번째인 경우 이분 그래프가 아니다. (두 그룹은 항상 홀수와 짝수로 나누어지기 때문)

// 모든 노드를 순회하고 정상적으로 종료됬다면 이분그래프이다.

// 주의) 노드의 개수가 20000개이므로, 인접 행렬보다 인접 리스트로 구현해야한다.

#include <iostream>
#include <vector>
bool DFS(int node, int level, std::vector<std::vector<int>> &graph, std::vector<int> &visitied);
int main() {
    int K, V, E;
    std::cin >> K;

    for (int i = 0; i != K; ++i) {
        std::cin >> V >> E;
        std::vector<std::vector<int>> graph(V + 1);
        std::vector<int> visitied(V + 1);

        // 인접 리스트 생성
        int x, y;
        for (int j = 0; j != E; ++j) {
            std::cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        // 이분 그래프 끼리는 모두 연결되어 있다.
        bool is_bipartial = true;
        for (int i = 1; i != V; ++i) {
            if (visitied[i] == 0)
                is_bipartial = DFS(i, 1, graph, visitied);

            if (!is_bipartial)
                break;
        }

        if (is_bipartial)
            std::cout << "YES";
        else
            std::cout << "NO";
        std::cout << "\n";
    }
}

// node는 현재 탐색하는 노드, level은 몇번째 탐색인지를 나타낸다.
bool DFS(int node, int level, std::vector<std::vector<int>> &graph, std::vector<int> &visitied) {
    visitied[node] = level;

    for (int next_node : graph[node]) {
        if (visitied[next_node] == 0) {
            bool is_bipartial = DFS(next_node, level + 1, graph, visitied);

            if (!is_bipartial)
                return false;
        } else {
            if ((visitied[next_node] % 2) == (level % 2)) {
                return false;
            }
        }
    }
    return true;
}
