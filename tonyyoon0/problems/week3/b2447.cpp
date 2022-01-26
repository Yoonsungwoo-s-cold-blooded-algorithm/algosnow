#include <iostream>
#include <algorithm>

char stars[6561][6561];

void star_erase(int row, int col, int N) {
    if (N > 3) {
        for (int i = row; i < row + N; i += (N / 3)) {
            for (int j = col; j < col + N; j += (N / 3)) {
                // 가운데는 공백으로 채우기
                if (i == (row + (N / 3)) && j == (col + (N / 3))) {
                    for (int k = 0; k < (N / 3); k++) {
                        std::fill_n(&stars[i + k][j], (N / 3), ' ');
                    }
                }
                else star_erase(i, j, (N / 3));
            }
        }
    }
    else {
        stars[row + 1][col + 1] = ' ';
    }
}

int main() {
    int N;
    std::cin >> N;

    // 별 채우기
    for (int row = 0; row < N; row++) {
        std::fill_n(stars[row], N, '*');
    }

    // 별 지우기
    star_erase(0, 0, N);

    // 별 출력
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) std::cout << stars[row][col];
        std::cout << '\n';
    }

    return 0;
}