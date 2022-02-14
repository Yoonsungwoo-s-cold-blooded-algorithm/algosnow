#include <iostream>
#include <vector>

struct NODE {
    std::vector<int> children;
};

int DFS(NODE node);

std::vector<NODE> nodes(50);
int deleted_node;

int main() {
    int N, parent, root_node;
    std::cin >> N;
    for (int i = 0; i != N; ++i) {
        std::cin >> parent;
        if (parent == -1) {
            root_node = i;
            continue;
        }
        nodes[parent].children.push_back(i);
    }

    std::cin >> deleted_node;

    if (deleted_node == root_node)
        std::cout << 0;
    else
        std::cout << DFS(nodes[root_node]);
}

int DFS(NODE node) {
    // 리프 노드인 경우는 비어있거나, 삭제되는 노드가 유일한 자식 노드인 경우이다.
    if (node.children.empty()) {
        return 1;
    } else if (node.children.size() == 1 && node.children[0] == deleted_node) {
        return 1;
    }

    // 리프노드가 아니라면 삭제 노드가 아닌 자식노드를 탐색한다.
    int sum = 0;
    for (int i = 0; i != node.children.size(); ++i) {
        int child_node = node.children[i];
        if (child_node != deleted_node) {
            sum += DFS(nodes[child_node]);
        }
    }
    return sum;
}
