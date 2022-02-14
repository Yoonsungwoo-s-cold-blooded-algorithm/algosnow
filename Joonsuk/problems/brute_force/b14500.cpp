// 합이 최대가 되는 정수 4개를 고른다.
// 해당 정수들의 모양이 테트로미노인가?
// y-> 해당 조합의 값을 저장
// n-> 그다음으로 최대인 정수 4개를 고른다. (또는 크기가 같지만 모양은 다른 조합)

// 최적화
// 만약 가능한 테트로미노 조합을 찾았다면 값을 저장할 것이다.
// 새로운 조합을 비교할때, 지금 조합의 값과 앞으로 나올 조합의 값이 현재 찾은 값보다 작다면,
// break를 통해서 필요 없는 연산을 제거한다.

#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

struct POS {
    POS(int x, int y, int value) : x(x), y(y), value(value) {}
    int x;
    int y;
    int value;
};

bool verify_tetromino(POS pos1, POS pos2, POS pos3, POS pos4);
void DFS_selected_positions(int next_idx, std::vector<POS> &selected_positions, std::array<int, 4> &visited);
int calculate_case_value(POS pos1, POS pos2, POS pos3, POS pos4);
bool is_linked(POS pos1, POS pos2);

int N, M;
int total_max = 0;
std::vector<POS> positions; // 총 N*M개 -> 제일 큰 값이 맨 앞에 오도록 정렬해야 한다.

int main() {
    std::cin >> N >> M;
    int input;
    for (int i = 0; i != N; ++i) {
        for (int j = 0; j != M; ++j) {
            std::cin >> input;
            positions.push_back(POS(i, j, input));
        }
    }
    std::sort(positions.begin(), positions.end(), [](const POS &a, const POS &b) -> bool { return a.value > b.value; });

    // 이전 경우를 제외하고, 합이 최대인 정수 4개를 고른다. (합이 찾은 조합의 크기보다는 커야한다.)
    for (int i = 0; i != N * M; ++i) {
        if (calculate_case_value(positions[i], positions[i], positions[i], positions[i]) <= total_max) // 최적화
            break;
        for (int j = i + 1; j < N * M; ++j) { // < 기호 필수!
            if (calculate_case_value(positions[i], positions[j], positions[j], positions[j]) <= total_max)
                break;

            for (int k = j + 1; k < N * M; ++k) {
                if (calculate_case_value(positions[i], positions[j], positions[k], positions[k]) <= total_max)
                    break;

                for (int l = k + 1; l < N * M; ++l) {
                    int case_value = calculate_case_value(positions[i], positions[j], positions[k], positions[l]);
                    if (case_value <= total_max)
                        break;

                    if (verify_tetromino(positions[i], positions[j], positions[k], positions[l])) {
                        total_max = case_value; // 값이 이전보다 크고, 테트로미노 모양일 경우
                        break;
                    }
                }
            }
        }
    }

    std::cout << total_max;
}

int calculate_case_value(POS pos1, POS pos2, POS pos3, POS pos4) {
    // 세 위치의 값을 반환
    return pos1.value + pos2.value + pos3.value + pos4.value;
}

bool verify_tetromino(POS pos1, POS pos2, POS pos3, POS pos4) {
    std::vector<POS> selected_positions = {pos1, pos2, pos3, pos4};
    std::array<int, 4> visited = {0, 0, 0, 0};

    DFS_selected_positions(0, selected_positions, visited);

    for (int i : visited) {
        if (i == 0)
            return false;
    }
    return true;
}

void DFS_selected_positions(int next_idx, std::vector<POS> &selected_positions, std::array<int, 4> &visited) {
    visited[next_idx] = 1;

    for (int i = 0; i != 4; ++i) {
        if (visited[i] == 1)
            continue;

        if (is_linked(selected_positions[i], selected_positions[next_idx]))
            DFS_selected_positions(i, selected_positions, visited);
    }

    return;
}

bool is_linked(POS pos1, POS pos2) {
    if (pos1.x - 1 == pos2.x && pos1.y == pos2.y) { // 왼쪽
        return true;
    }
    if (pos1.x + 1 == pos2.x && pos1.y == pos2.y) { // 오른쪽
        return true;
    }
    if (pos1.x == pos2.x && pos1.y - 1 == pos2.y) { // 아래
        return true;
    }
    if (pos1.x == pos2.x && pos1.y + 1 == pos2.y) { // 위
        return true;
    }
    return false;
}
