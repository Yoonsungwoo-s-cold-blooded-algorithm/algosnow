#include <iostream>
#include <string>
#include <vector>

struct NODE {
    NODE(char node_name, char left_node, char right_node) : name(node_name), left(left_node), right(right_node) {}

    char name;
    char left;
    char right;
};

NODE get_node(char name);
void pre_order(NODE node);
void in_order(NODE node);
void post_order(NODE node);

std::vector<NODE> nodes;

int main() {
    int N;
    std::cin >> N;

    std::string input_line;
    std::getline(std::cin, input_line); // 버퍼 비우기.

    for (int i = 0; i != N; ++i) {
        std::getline(std::cin, input_line);
        nodes.push_back(NODE(input_line[0], input_line[2], input_line[4]));
    }

    pre_order(nodes[0]);
    std::cout << "\n";
    in_order(nodes[0]);
    std::cout << "\n";
    post_order(nodes[0]);
    std::cout << "\n";
}

NODE get_node(char name) {
    for (auto beg = nodes.begin(); beg != nodes.end(); ++beg) {
        if (beg->name == name) {
            return *beg;
        }
    }
    std::cout << "impossible";
}

void pre_order(NODE node) {
    std::cout << node.name;

    if (node.left != '.') {
        NODE left_node = get_node(node.left);
        pre_order(left_node);
    }
    if (node.right != '.') {
        NODE right_node = get_node(node.right);
        pre_order(right_node);
    }
}

void in_order(NODE node) {
    if (node.left != '.') {
        NODE left_node = get_node(node.left);
        in_order(left_node);
    }
    std::cout << node.name;
    if (node.right != '.') {
        NODE right_node = get_node(node.right);
        in_order(right_node);
    }
}

void post_order(NODE node) {
    if (node.left != '.') {
        NODE left_node = get_node(node.left);
        post_order(left_node);
    }
    if (node.right != '.') {
        NODE right_node = get_node(node.right);
        post_order(right_node);
    }
    std::cout << node.name;
}