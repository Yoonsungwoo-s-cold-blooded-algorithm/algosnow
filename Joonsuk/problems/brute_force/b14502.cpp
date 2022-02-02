// case 1이 주어진다고 하자.

// 바이러스의 근원을 1개 찾는다.
// 해당 근원으로 부터 DFS를 수행한다.
// 다음 근원으로 간다.
// 해당 근원으로 부터 DFS를 수행한다. 이때, 이전
// 근원에서 방문한 곳들은 2,3으로 되어있기 때문에
// 중복해서 방문하지 않는다.

// 마지막 근원까지 DFS를 수행하고 나면, 해당 case의 안전영역을 계산한다.
// 해당 case의 기록을 바탕으로 안전영역의 크기를 갱신한다. 다음 case2가 주어진다.

#include <array>
#include <iostream>

struct POS {
    POS(int x, int y) : x(x), y(y) {}
    int x;
    int y;
};
void generate_cases(int first, int second, int third);
void copy_original_map();
void conduct_given_case(int given_map[][8]);
void DFS(POS pos);
int calculate_safe_area_count(int given_map[][8]);

int N, M;                // 맵 크기
int max_safety_area = 0; // 최종 답안
int labatory_map_original[8][8];
int labatory_map[8][8]; // 지역변수로 할 예정

int main() {
    int type;
    std::cin >> N >> M;
    for (int i = 0; i != N; ++i) {
        for (int j = 0; j != M; ++j) {
            std::cin >> type;
            labatory_map_original[i][j] = type;
        }
    }

    // map을 기반으로 각 case를 생성하여 conduct 한다.
    for (int i = 0; i < N * M; ++i) {
        if (labatory_map_original[i % N][i / N] != 0) // 1번 벽을 세우는 곳이 0인가?
            continue;
        for (int j = i + 1; j < N * M; ++j) {
            if (labatory_map_original[j % N][j / N] != 0) // 2번 벽을 세우는 곳이 0인가?
                continue;
            for (int k = j + 1; k < N * M; ++k) {
                if (labatory_map_original[k % N][k / N] != 0) // 3번 벽을 세우는 곳이 0인가?
                    continue;
                generate_cases(i, j, k);
                conduct_given_case(labatory_map);
            }
        }
    }
    std::cout << max_safety_area;
}

void generate_cases(int first, int second, int third) {
    copy_original_map();
    labatory_map[first % N][first / N] = 1;
    labatory_map[second % N][second / N] = 1;
    labatory_map[third % N][third / N] = 1;
}

void copy_original_map() {
    for (int i = 0; i != N; ++i) {
        for (int j = 0; j != M; ++j) {
            labatory_map[i][j] = labatory_map_original[i][j];
        }
    }
}

void conduct_given_case(int given_map[][8]) {
    for (int i = 0; i != N; ++i) {
        for (int j = 0; j != M; ++j) {
            if (given_map[i][j] == 2) {
                DFS(POS(i, j)); // 근원또한 3으로 변경되지만 처리하지 않은 근원만 2이면 되므로 관계 x.
            }
        }
    }

    // 해당 case에 대해서 모든 바이러스가 퍼진 상태.
    int safe_area_count = calculate_safe_area_count(given_map);
    if (safe_area_count > max_safety_area) {
        max_safety_area = safe_area_count;
    }
}

void DFS(POS pos) {
    labatory_map[pos.x][pos.y] = 3; // 퍼진 바이러스 = 3 (근원과 퍼진 바이러스를 구분하기 위함)

    if (pos.x > 0) {
        if (labatory_map[pos.x - 1][pos.y] == 0)
            DFS(POS(pos.x - 1, pos.y));
    }
    if (pos.y > 0) {
        if (labatory_map[pos.x][pos.y - 1] == 0)
            DFS(POS(pos.x, pos.y - 1));
    }
    if (pos.x < N - 1) {
        if (labatory_map[pos.x + 1][pos.y] == 0)
            DFS(POS(pos.x + 1, pos.y));
    }
    if (pos.y < M - 1) {
        if (labatory_map[pos.x][pos.y + 1] == 0)
            DFS(POS(pos.x, pos.y + 1));
    }

    return;
}

int calculate_safe_area_count(int given_map[][8]) {
    int count = 0;
    for (int i = 0; i != N; ++i) {
        for (int j = 0; j != M; ++j) {
            if (given_map[i][j] == 0)
                ++count;
        }
    }
    return count;
}
