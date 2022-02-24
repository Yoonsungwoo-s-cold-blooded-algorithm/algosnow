#include <iostream>
#include <string>
#include <vector>

void quad_tree(int x, int y, int size);
bool check_all_same(int x, int y, int size);

std::vector<std::string> panel;

int main() {
    int N;
    std::cin >> N;

    for (int i = 0; i != N; ++i) {
        std::string pixels;
        std::cin >> pixels;

        panel.push_back(pixels);
    }
    quad_tree(0, 0, N);
}

void quad_tree(int x, int y, int size) {
    bool is_all_same = check_all_same(x, y, size);

    if (is_all_same) {
        std::cout << panel[x][y];
    } else {
        std::cout << "(";
        int next_size = size / 2;
        quad_tree(x, y, next_size);
        quad_tree(x, y + next_size, next_size);
        quad_tree(x + next_size, y, next_size);
        quad_tree(x + next_size, y + next_size, next_size);
        std::cout << ")";
    }
}

bool check_all_same(int x, int y, int size) {
    for (int i = 0; i != size; ++i) {
        for (int j = 0; j != size; ++j) {
            if (panel[x + i][y + j] != panel[x][y]) {
                return false;
            }
        }
    }
    return true;
}