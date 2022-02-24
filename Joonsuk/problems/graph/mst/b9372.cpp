#include <array>
#include <iostream>
#include <vector>

int find_mst_by_prim(int V, int root, std::array<std::array<int, 1000>, 1000> &graph);
void init_graph(std::array<std::array<int, 1000>, 1000> &graph);
const int INF = 100000; // 무한대 값이라고 가정하자.

int main() {
    int T, N, M;
    std::cin >> T;
    for (int i = 0; i != T; ++i) {
        std::cin >> N >> M;
        std::array<std::array<int, 1000>, 1000> graph;
        init_graph(graph);

        int a, b;
        for (int j = 0; j != M; ++j) {
            std::cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }

        int weight = find_mst_by_prim(N, 0, graph);
        std::cout << weight << "\n";
    }
}

// 노드가 0번 부터 V-1번 까지 존재한다고 가정하는 그래프 (최대 V는 10)
int find_mst_by_prim(int V, int root, std::array<std::array<int, 1000>, 1000> &graph) {
    std::vector<bool> visitied(V, false);
    std::vector<int> closest_dist(V, INF);
    int total_weight = 0; // mst의 총 가중치

    // 초기 root에 대해서 visitied와 closest_dist를 갱신해 주어야 한다.
    visitied[root] = true;
    for (int i = 0; i != V; ++i) {
        closest_dist[i] = graph[root][i];
    }

    for (int i = 0; i != V - 1; ++i) {
        // closed_dist에서 제일 가까운 노드를 visitied에서 true로 갱신한다.
        int next_closest_node = -1;
        int next_closest_dist = INF;

        for (int j = 0; j != V; ++j) {
            if (!visitied[j] && (closest_dist[j] < next_closest_dist)) {
                next_closest_node = j;
                next_closest_dist = closest_dist[j];
            }
        }

        if (next_closest_node == -1) { // 중간에 연결이 끊겨있는 부분 그래프인 경우.
            std::cout << "this graph is partial graph!!!";
            return -1;
        }
        visitied[next_closest_node] = true;
        total_weight += next_closest_dist;

        // 직전에 visitied된 노드에 대해서 closest_dist를 갱신한다.
        for (int j = 0; j != V; ++j) {
            closest_dist[j] = (closest_dist[j] < graph[next_closest_node][j]) ? (closest_dist[j]) : (graph[next_closest_node][j]);
        }
    }

    return total_weight;
}

void init_graph(std::array<std::array<int, 1000>, 1000> &graph) {
    for (int i = 0; i != graph.size(); ++i) {
        for (int j = 0; j != graph[0].size(); ++j) {
            graph[i][j] = INF;
        }
    }
}