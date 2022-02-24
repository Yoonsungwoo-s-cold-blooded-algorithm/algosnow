
// 1. 인접 리스트로 그래프 구현
// 2. 인접 리스트로 프림 알고리즘 사용하기
// -> 왜 인접 행렬로 구현하는가? closest_dist를 갱신하기 위해서
// -> 인접 리스트가 노드 번호와 가중치를 함께 저장하고 있다면 해결!
// graph[node]의 모든 linked_node에 대해서
// closest_dist[linked_node.num] = closest_dist[linked_node.num] or linked_node.weight

#include <iostream>
#include <vector>

// 어떤 노드와 연결된 노드
struct Linked_Node {
    Linked_Node(int num, int weight) : node_num(num), weight(weight) {}
    int node_num;
    int weight;
};

int find_mst_with_prim(int V, int root, std::vector<std::vector<Linked_Node>> graph);

const int INF = 1000001; // 항상 이 값보다는 가중치가 작다.

int main() {
    int V, E;
    std::cin >> V >> E;

    std::vector<std::vector<Linked_Node>> graph(V); // 그래프의 정보를 담는 벡터

    int a, b, weight;
    for (int i = 0; i != E; ++i) {
        std::cin >> a >> b >> weight;
        graph[a - 1].push_back(Linked_Node(b - 1, weight));
        graph[b - 1].push_back(Linked_Node(a - 1, weight));
    }

    int minimum_total_weight = find_mst_with_prim(V, 0, graph);
    std::cout << minimum_total_weight;
}

int find_mst_with_prim(int V, int root, std::vector<std::vector<Linked_Node>> graph) {
    int total_weight = 0;
    std::vector<bool> visitied(V, false);
    std::vector<int> closest_dist(V, INF);

    // closest_dist 초기값 할당.
    visitied[root] = true;
    for (auto linked_node : graph[root]) {
        closest_dist[linked_node.node_num] = linked_node.weight;
    }

    for (int i = 0; i != V - 1; ++i) {
        // dist의 값 중에서 가장 작은 친구의 값이 추가될 노드가 된다.
        int closest_node_num = -1;
        int closest_node_dist = INF;

        for (int j = 0; j != V; ++j) {
            if (!visitied[j] && (closest_node_dist > closest_dist[j])) {
                closest_node_num = j;
                closest_node_dist = closest_dist[j];
            }
        }

        if (closest_node_num == -1) {
            std::cout << "partial graph!!!!";
            return -1;
        }

        visitied[closest_node_num] = true;
        total_weight += closest_node_dist;

        // 추가된 노드를 이용해서 dist 재생성.
        for (auto linked_node : graph[closest_node_num]) { // closest_node의 차수 만큼 반복.
            if (closest_dist[linked_node.node_num] > linked_node.weight)
                closest_dist[linked_node.node_num] = linked_node.weight;
        }
    }

    return total_weight;
}