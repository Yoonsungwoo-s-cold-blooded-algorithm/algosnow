// 2차원 배열이 2개 있다.
// 첫번째는 visited 배열이고,
// 두번째는 현재 체스판의 퀸을 놓을 수 있는 곳을 찾기 위한 배열이다. (퀸의 위치만 저장)

// 퀸이 해당 자리에 있었다면 1, 없다면 0이다.

// 체스판에는 퀸의 위치만 존재하는데, 퀸이 없는 어느 칸에 대해서 invalid 하다면 다음 칸에 대해서 valid함을 확인한다.
// 만약 valid 하다면 해당 위치에 대해서 DFS를 수행한다. (valid = !visited && possible)

// 맨 처음 시작이 되는 위치에 대해서는 visited 배열에 추가하여 중복을 방지한다.

#include <iostream>
#include <vector>

struct POS
{
    POS(int x_in, int y_in) : x(x_in), y(y_in) {}
    int x;
    int y;
};

void DFS(POS pos);
bool valid_position(POS pos);
bool check_updown_validation(POS pos);
bool check_rightleft_validation(POS pos);
bool check_diagonal_validation(POS pos);
void check_and_update_cases();
int count_queen_amount();

int chess_board[15][15];
int N, total_count;

int main()
{
    std::cin >> N;
    for (int i = 0; i != N; ++i)
    {
        DFS(POS(i, 0));
    }

    std::cout << total_count;
}

// 항상 주어지는 노드의 다음 노드부터 탐색하므로, 중복될 일이 존재하지 않는다.
void DFS(POS pos)
{
    chess_board[pos.x][pos.y] = 1;
    bool terminal_node = true; // 단말 노드

    // // 맨 위의 줄 -> 항상 invalid
    // for (int i = pos.x + 1; i < N; ++i)
    // { // < 괄호 필수
    //     if (valid_position(POS(i, pos.y)))
    //     {
    //         DFS(POS(i, pos.y));
    //         terminal_node = false;
    //     }
    // }
    // 그 다음 줄
    // for (int i = 0; i != N; ++i)
    // {
    //     for (int j = pos.y + 1; j < N; ++j)
    //     { // < 괄호 필수
    //         if (valid_position(POS(i, j)))
    //         {
    //             DFS(POS(i, j));
    //             terminal_node = false;
    //         }
    //     }
    // }

    // 한 행에 대해서만 수행하면 됨 -> 퀸이 총 N개이어야 하기 때문.
    for (int i = 0; i != N; ++i) {
        if (valid_position(POS(i, pos.y + 1)))
        {
            DFS(POS(i, pos.y + 1));
            terminal_node = false;
        }
    }

    if (terminal_node && (pos.y != N - 1))
    {
        // 개수가 부족한경우 (한 행에 들어간 퀸이 한개도 없음) -> 계산 필요 x
        chess_board[pos.x][pos.y] = 0;
        return;
    }

    if (terminal_node)
    { // DFS가 호출되었을때, 추가적인 DFS를 호출하지 않은 경우.
        check_and_update_cases();
    }

    chess_board[pos.x][pos.y] = 0;
    return;
}

bool valid_position(POS pos)
{
    // 상하
    if (!check_updown_validation(pos))
        return false;
    // 좌우
    if (!check_rightleft_validation(pos))
        return false;
    // 대각선
    if (!check_diagonal_validation(pos))
        return false;

    return true;
}

bool check_updown_validation(POS pos)
{
    for (int i = 0; i != N; ++i)
    {
        if (chess_board[pos.x][i] == 1)
            return false;
    }
    return true;
}

bool check_rightleft_validation(POS pos)
{
    for (int i = 0; i != N; ++i)
    {
        if (chess_board[i][pos.y] == 1)
            return false;
    }
    return true;
}

bool check_diagonal_validation(POS pos)
{
    int x = pos.x;
    int y = pos.y;
    while (x >= 0 && y >= 0)
    {
        if (chess_board[x][y] == 1)
            return false;
        --x;
        --y;
    }

    x = pos.x;
    y = pos.y;
    while (x < N && y < N)
    {
        if (chess_board[x][y] == 1)
            return false;
        ++x;
        ++y;
    }

    x = pos.x;
    y = pos.y;
    while (x >= 0 && y < N)
    {
        if (chess_board[x][y] == 1)
            return false;
        --x;
        ++y;
    }

    x = pos.x;
    y = pos.y;
    while (x < N && y >= 0)
    {
        if (chess_board[x][y] == 1)
            return false;
        ++x;
        --y;
    }

    return true;
}

void check_and_update_cases()
{
    int count = count_queen_amount();
    if (count == N)
    {
        ++total_count;
    }
}

int count_queen_amount()
{
    int count = 0;
    for (int i = 0; i != N; ++i)
    {
        for (int j = 0; j != N; ++j)
        {
            if (chess_board[i][j] == 1)
            {
                ++count;
            }
        }
    }
    return count;
}