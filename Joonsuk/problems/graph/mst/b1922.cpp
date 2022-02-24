#include "../../../concept/graph/kruskal.cpp"
#include <iostream>

int main() {
    int V, E;
    std::cin >> V >> E;

    std::vector<edge> graph;
    int a, b, weight;
    for (int i = 0; i != E; ++i) {
        std::cin >> a >> b >> weight;
        graph.push_back(edge(a - 1, b - 1, weight));
    }

    int min_weight = find_mst_by_kruskal(graph, 0, V);
    std::cout << min_weight;
}
