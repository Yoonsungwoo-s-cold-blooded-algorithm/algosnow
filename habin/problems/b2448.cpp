#include <iostream>
#include <cmath>
using namespace std;

void Print(char **arr, int height, int width)
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (arr[i][j] != ' ' && arr[i][j] != '*')
            {
                cout << "fucck";
                return;
            }
            cout << arr[i][j];
        }
        cout << '\n';
    }
}
void Hole(char **arr, int size, int level)
{
    if (level == 2)
    {
        for (int i = 2; i < size; i += 6)
        {
            for (int j = size / 2 - (i / 6) * 3; j < size - level; j += 6)
                arr[i][j] = ' ';
        }
        return;
    }

    for (int i = level + 1; i < size; i += (level + 1) * 2)
    {
        for (int j = size / 2 - level / 2 - (i / ((level + 1) * 2)) * (level + 1); j < size - level; j += (level + 1) * 2)
        {
            for (int m = 0; m < level; m += 2)
            {
                for (int n = m / 2; n < level - m / 2; ++n)
                    arr[i + m][j + n] = ' ';
            }
        }
    }
    Hole(arr, size, level / 2);
}
// level 0 == 1
// k = 0 => 5 = 5*2^0 + 0  level 1
// k = 1 => 11 = 5*2^1 + 2^1 - 1  level 2
// k = 2 => 23 = 5*2^2 + 2^2 - 1  level 3
// k = 3 => 47 = 5*2^3 + 2^3 - 1  level 4
// ... 6*2^k - 1  level k+1
// 6*2^(k-1)*2 - 2 = 6*2^k - 1 -1
int main()
{
    int N;
    cin >> N;
    char **arr = new char *[N * 2 - 1];
    for (int i = 0; i < N * 2 - 1; ++i)
        arr[i] = new char[N * 2 - 1];
    for (int i = 0; i < N * 2 - 1; ++i)
    {
        for (int j = 0; i % 2 == 0 && j < 2 * N - 1; ++j)
        {
            if (j >= (N * 2 - 1) / 2 - i / 2 && j <= (N * 2 - 1) / 2 + i / 2)
                arr[i][j] = '*';
            else
                arr[i][j] = ' ';
        }
        for (int j = 0; i % 2 != 0 && j < 2 * N - 1; ++j)
            arr[i][j] = ' ';
    }
    Hole(arr, N * 2 - 1, (N * 2 - 1) / 2);
    Print(arr, N * 2 - 1, N * 2 - 1);
}