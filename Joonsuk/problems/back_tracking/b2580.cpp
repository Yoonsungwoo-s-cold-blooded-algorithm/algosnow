// 칸을 채워 넣고
// 가능하다면, 다음 칸으로
// 만약 불가능 하다면 다른 숫자에 대해서 채워 넣고 검증을 반복.

// 모든 숫자에 대해서 불가능 하다면 직전의 칸에 있는 숫자를 변경.

// 모든 숫자가 채워졌다면 종료.

#include <array>
#include <iostream>

int DFS(int x, int y);
void find_next_zero(int &x, int &y);
int check_valid(int x, int y);
bool check_horizontal(int x, int y);
bool check_vertical(int x, int y);
bool check_square(int x, int y);
bool check_complete();
void print_sudoku();

typedef std::array<std::array<int, 9>, 9> SUDOKU;
SUDOKU sudoku_board;

int main() {
    int input_num;
    for (int i = 0; i != 9; ++i) {
        for (int j = 0; j != 9; ++j) {
            std::cin >> input_num;
            sudoku_board[i][j] = input_num;
        }
    }

    int next_x, next_y;
    find_next_zero(next_x, next_y);
    DFS(next_x, next_y);
}

int DFS(int x, int y) {
    // 1. 해당자리에 숫자를 넣고 검증을 반복한다.
    // 2. vaild한 숫자를 찾으면 다음 칸을 찾아서 DFS를 수행한다.
    // 3. 모든 숫자에 대해서 invalid하면 1을 반환한다.
    // 4. 스도쿠를 완성하면 결과를 출력한뒤 0을 반환한다.

    for (int i = 1; i != 10; ++i) {
        sudoku_board[x][y] = i;

        int is_valid = check_valid(x, y);

        if (is_valid == 1) {
            int next_x, next_y;
            find_next_zero(next_x, next_y);

            if (DFS(next_x, next_y) == 0) {
                return 0;
            }
        }

        if (is_valid == 2) {
            print_sudoku();
            return 0;
        }
    }
    sudoku_board[x][y] = 0;
    return 1;
}

void find_next_zero(int &x, int &y) {
    for (int i = 0; i != 9; ++i) {
        for (int j = 0; j != 9; ++j) {
            if (sudoku_board[i][j] == 0) {
                x = i;
                y = j;
                return;
            }
        }
    }
}

// 1을 반환하면 가능하지만, 자리가 남은 경우, 2를 반환하면 스도쿠가 완료된 경우.
int check_valid(int x, int y) {
    if (check_horizontal(x, y)) {     // 좌우
        if (check_vertical(x, y)) {   // 상하
            if (check_square(x, y)) { // 3x3
                // x, y칸에 있는 숫자가 valid하면, 스토쿠가 완성됬는지 확인.
                if (check_complete())
                    return 2;
                else
                    return 1;
            }
        }
    }
    return 0;
}

bool check_horizontal(int x, int y) {
    int target_number = sudoku_board[x][y];
    for (int i = 0; i != 9; ++i) {
        if (sudoku_board[i][y] == target_number && i != x) {
            return false;
        }
    }
    return true;
}

bool check_vertical(int x, int y) {
    int target_number = sudoku_board[x][y];
    for (int i = 0; i != 9; ++i) {
        if (sudoku_board[x][i] == target_number && i != y) {
            return false;
        }
    }
    return true;
}

bool check_square(int x, int y) {
    // x,y가 존재하는 3x3사각형의 좌상단 좌표  (주의: 나눗셈의 소수점 버림을 이용)
    int target_number = sudoku_board[x][y];
    int x_square = (x / 3) * 3;
    int y_square = (y / 3) * 3;

    for (int i = 0; i != 3; ++i) {
        for (int j = 0; j != 3; ++j) {
            if (sudoku_board[x_square + i][y_square + j] == target_number && (x_square + i != x || y_square + j != y)) {
                return false;
            }
        }
    }
    return true;
}

bool check_complete() {
    for (int i = 0; i != 9; ++i) {
        for (int j = 0; j != 9; ++j) {
            if (sudoku_board[i][j] == 0)
                return false;
        }
    }
    return true;
}

void print_sudoku() {
    for (int i = 0; i != 9; ++i) {
        for (int j = 0; j != 9; ++j) {
            std::cout << sudoku_board[i][j];
            if (j == 8)
                std::cout << "\n";
            else
                std::cout << " ";
        }
    }
}