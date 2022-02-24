// 크루스칼 알고리즘은 최소 신장 트리(MST)를 찾는 알고리즘중 하나이다.
// 크루스칼과 프림 알고리즘의 시간 복잡도를 좌우하는 원인이 다르기 때문에 둘다 익혀놓는것이 좋다.

// 크루스칼 알고리즘은 매 순간 최소 가중치의 간선을 mst에 포함시킨다.
// 매 순간 최적의 해를 찾으므로 그리디 알고리즘중 하나이다.

// 크루스칼 알고리즘의 그리디 증명
// ->

// 크루스칼 알고리즘의 구현
// 1. (노드1, 노드2, 가중치)로 간선들을 표현한 뒤, 정렬한다.
// 2. 가중치가 제일 작은 간선부터 선택한뒤, 2개의 노드가 서로소 집합에 들어가면 이를 추가한다.
// 3. 간선의 개수가 V-1이 될때까지 반복한다.

// 시간 복잡도 (V는 노드의 개수, E는 간선의 개수이다)
// 1. 간선들을 정렬하는 작업 -> E logE
// 2. 간선을 선택하는 작업 -> 상수시간(트리구조로 서로소 집합을 구현한 경우에만)
// 3. 간선이 valid 한지 확인하는 작업 -> find와 union 함수의 시간 복잡도 O(1), 즉 상수시간
// 따라서 E logE + (V-1)*(상수 + 상수) = O(E logE)

#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <algorithm>
#include <vector>

struct edge {
    edge(int node_one, int node_two, int weight) : node_one(node_one), node_two(node_two), weight(weight) {}
    int node_one;
    int node_two;
    int weight;
};

// 배열로 구현된 서로소 집합.
class disjoint_set {
  public:
    disjoint_set(int set_size) : size(set_size) {
        for (int i = 0; i != set_size; ++i) {
            set.push_back(i);
        }
    }
    void my_union(int x, int y) {
        // y의 집합을 x에 집합에 포함.
        int set_number_y = set[y];
        for (int i = 0; i != size; ++i) {
            if (set[i] == set_number_y)
                set[i] = set[x];
        }
    }
    int find(int x) {
        // x의 집합 번호 반환
        return set[x];
    }

  private:
    std::vector<int> set;
    int size = 0;
};

int find_mst_by_kruskal(std::vector<edge> &graph, int root_node, int V) {
    int total_weight = 0;
    // 간선 리스트로 구성된 graph를 weigth에 따라 정렬한다.

    // 0번째 간선부터 V-1번째 간선까지...
    // 해당 간선에 근접한 두 노드가 서로소 집합이면 mst에 추가하고,
    // 그렇지 않으면 mst에 추가하지 않는다.
    std::sort(graph.begin(), graph.end(), [](const edge &first, const edge &second) -> bool { return first.weight < second.weight; });

    disjoint_set set(V);
    int mst_edge_count = 0;
    for (int i = 0; i != graph.size(); ++i) {
        if (mst_edge_count == V - 1)
            break;

        int node_one = graph[i].node_one;
        int node_two = graph[i].node_two;
        if (set.find(node_one) != set.find(node_two)) {
            ++mst_edge_count;
            set.my_union(node_one, node_two);
            total_weight += graph[i].weight;
        }
    }

    return total_weight;
}

#endif