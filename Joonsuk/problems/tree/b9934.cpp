#include <iostream>
#include <vector>

void make_binary_tree(std::vector<int>::iterator beg, std::vector<int>::iterator end, int level);
int pow_of_two(int exp);

std::vector<std::vector<int>> binary_tree(10);

int main() {
    int K, node;
    std::cin >> K;

    std::vector<int> nodes;
    int node_count = pow_of_two(K) - 1;
    for (int i = 0; i != node_count; ++i) {
        std::cin >> node;
        nodes.push_back(node);
    }

    make_binary_tree(nodes.begin(), nodes.end(), 0);

    for (int i = 0; i != K; ++i) {
        for (int j = 0; j != binary_tree[i].size(); ++j) {
            std::cout << binary_tree[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void make_binary_tree(std::vector<int>::iterator beg, std::vector<int>::iterator end, int level) {
    auto center = beg + (end - beg) / 2;
    binary_tree[level].push_back(*center);

    // 최하단 노드
    if (beg == center) {
        return;
    }

    make_binary_tree(beg, center - 1, level + 1);
    make_binary_tree(center + 1, end, level + 1);
}

int pow_of_two(int exp) {
    int result = 1;
    for (int i = 0; i != exp; ++i) {
        result *= 2;
    }
    return result;
}
