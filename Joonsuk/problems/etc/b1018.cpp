#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int calculate_paint_count(char (*chess_board)[50], int row, int col, char start_color);
inline char switch_need(char need);

int main() {
    // 1. M과 N을 입력 받는다.
    // 2. 2차원 배열에 순차적으로 저장한다.

    // 3. 1번 원소에 대해서 필요한 개수를 vector에 저장한다.
        // 3-1. 첫 원소가 B라고 가정한 경우
        // 3-2. 첫 원소가 W라고 가정한 경우

        // 3-3. need = 'B'일 때
            // W인 경우 paint_count 값을 1 올린 후, need = 'W'로 변경한다.
            // B인 경우 need = 'W'로 변경한다.
            // 동일한 행의 다음 열로 넘어가는 경우에는 바로 스킵, 다음 행으로 넘어가는 경우에는 need를 뒤집는다.   

    // 4. 모든 것에 대해서 수행한 후, vector를 정렬한 뒤, 첫 원소를 출력한다.

    int M, N;
    vector<int> need_to_paint;
    std::cin >> M >> N;

    char chess_board[50][50];
    for(int i = 0; i != M; ++i)
        for(int j = 0; j != N; ++j)
            std::cin >> chess_board[i][j];

    for(int i = 0; i != (M - 7); ++i) {
        for(int j = 0; j != (N - 7); ++j){
            int paint_count = calculate_paint_count(chess_board, i, j, 'B');
            need_to_paint.push_back(paint_count);

            paint_count = calculate_paint_count(chess_board, i, j, 'W');
            need_to_paint.push_back(paint_count);
        }
    }

    std::sort(need_to_paint.begin(), need_to_paint.end());
    std::cout << need_to_paint.front() << std::endl;
}

int calculate_paint_count(char (*chess_board)[50], int row, int col, char start_color){
    char need = start_color;
    int paint_count  = 0;

    for(int i = row; i != row + 8; ++i){
        for(int j = col; j != col + 8; ++j){
            if(chess_board[i][j] != need)
                ++paint_count;
            need = switch_need(need);
        }
        need = switch_need(need);
    }

    return paint_count;
}

char switch_need(char need){
    return (need == 'B') ? 'W' : 'B';
}