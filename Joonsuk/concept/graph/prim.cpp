// 프림 알고리즘은 최소 신장 트리(MST)를 찾는 알고리즘중 하나이다.
// 크루스칼과 프림 알고리즘의 시간 복잡도를 좌우하는 원인이 다르기 때문에 둘다 익혀놓는것이 좋다.

// 프림 알고리즘은 매 순간마다, 현재까지 연결된 트리에서 가장 짧은 노드를 연결하여 트리를 신장한다.
// 매 순간 최적의 해를 찾으므로 그리디 알고리즘중 하나이다.

// 프림 알고리즘의 그리디 증명
// ->

// 프림 알고리즘의 구현 (인접 행렬)
// 1. 그래프를 인접 행렬로 구현한다.
// 2. closest_dist[i] 라는 배열에는 i와 트리에 포함된 노드간의 최소 거리를 저장한다.
// 3. visitied[i]라는 배열에는 i번째 노드를 방문했는지에 대한 정보를 0과 1로 표현한다.
// 4. 따라서 visitied가 0이고 closest_dist가 가장 작은 i가 그다음으로 추가되는 노드가 된다.
// 5. 노드가 추가되면, visitied[i]를 1로 바꾸고,
// 6. closest_dist를 새로 갱신해야 한다. 이전의 closest_dist[j]와 graph[i][j]를 비교하여 작은 값이 새로운 closest_dist가 된다.
// 7. 노드의 개수 만큼 반복한다.

// 인접 행렬로 구현하므로 메모리가 많이 낭비된다...
// 인접 리스트로 그래프를 표현하는 경우에도 사용할 수 있을까? -> yes! : b1176번을 참고하세요
// 인접 리스트로 구현하는 것이 훨 나은 듯? (하지만 시간 복잡도는 여전히 O(n^2)이라는 점!)

// 프림 알고리즘의 구현 (우선순위 큐)
// ->

// 시간 복잡도 (V는 노드의 개수, E는 간선의 개수이다)

// 인접 행렬의 경우 시간복잡도는 O(V^2)이다.
// 각 반복마다 closet_dist의 모든 원소를 탐색하므로 V
// closest_dist의 갱신을 위해서 V
// 위 2가지가 V번 반복하므로...
// (V + V) * V= O(V^2)

// 우선순위 큐를 이용하면 시간 복잡도를 O(E logV)로 줄일 수 있다.
// ->

#ifndef PRIM_H
#define PRIM_H

#include <array>
#include <iostream>
#include <vector>

int find_mst_by_prim(int V, int root, std::array<std::array<int, 10>, 10> &graph);
const int INF = 100000; // 무한대 값이라고 가정하자.

// 노드가 0번 부터 V-1번 까지 존재한다고 가정하는 그래프 (현재 최대 V는 10)
int find_mst_by_prim(int V, int root, std::array<std::array<int, 10>, 10> &graph) {
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

#endif