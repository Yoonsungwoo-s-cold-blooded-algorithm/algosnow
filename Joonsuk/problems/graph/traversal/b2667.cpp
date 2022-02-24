#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>

struct POS {
    POS(int x, int y) : x(x), y(y) {}
    int x;
    int y;
};

POS get_next_root();
int DFS(POS pos);
bool valid_to_DFS(int x, int y);

std::array<std::array<int, 25>, 25> map;
std::array<std::array<int, 25>, 25> visitied;
int MAP_SIZE;

int main() {
    int N;
    std::cin >> N;
    MAP_SIZE = N;

    for (int i = 0; i != N; ++i) {
        std::string input;
        std::cin >> input;

        for (int j = 0; j != N; ++j) {
            map[i][j] = input[j] - 48;
        }
    }

    std::vector<int> linked_houses;
    int city_count = 0;

    POS next_root = get_next_root();
    while (next_root.x != -1) {
        ++city_count;
        // 해당 루트노드에서 DFS를 수행한다. (visitied 배열을 이용해서)
        int linked_house = DFS(next_root);
        linked_houses.push_back(linked_house);

        // 다시 루트 노드를 받는다.
        next_root = get_next_root();
    }

    std::sort(linked_houses.begin(), linked_houses.end());
    std::cout << city_count << "\n";
    for (int count : linked_houses) {
        std::cout << count << "\n";
    }
}

POS get_next_root() {
    // valid한 아무 노드 1개를 반환하면 됨
    for (int i = 0; i != MAP_SIZE; ++i) {
        for (int j = 0; j != MAP_SIZE; ++j) {
            if (valid_to_DFS(i, j))
                return POS(i, j);
        }
    }
    return POS(-1, -1);
}

int DFS(POS pos) {
    visitied[pos.x][pos.y] = 1;

    int house_count = 0;

    if (valid_to_DFS(pos.x - 1, pos.y))
        house_count += DFS(POS(pos.x - 1, pos.y));
    if (valid_to_DFS(pos.x, pos.y - 1))
        house_count += DFS(POS(pos.x, pos.y - 1));
    if (valid_to_DFS(pos.x + 1, pos.y))
        house_count += DFS(POS(pos.x + 1, pos.y));
    if (valid_to_DFS(pos.x, pos.y + 1))
        house_count += DFS(POS(pos.x, pos.y + 1));

    return house_count + 1;
}

bool valid_to_DFS(int x, int y) {
    // 1. 벽을 넘어갔는가?
    if (x < 0 || x == MAP_SIZE)
        return false;
    if (y < 0 || y == MAP_SIZE)
        return false;

    // 2. map에서 건물을 탐색하는가?
    if (map[x][y] == 0)
        return false;

    // 3. 방문하지 않은 노드인가?
    if (visitied[x][y] == 1)
        return false;

    return true;
}