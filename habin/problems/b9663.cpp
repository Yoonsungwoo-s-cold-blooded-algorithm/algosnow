#include <iostream>
#include <vector>

using namespace std;

enum Method
{
    FIX = true,
    UNDO = false
};

void Print(int N, bool **arr)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << (!arr[i][j] ? '*' : '@');
        }
        cout << endl;
    }
    cout << endl;
}

void SetQueen(int N, bool **arr, int r, int c, Method method)
{
    cout << (method ? "FIX" : "UNDO") << endl;
    for (int i = 0; i < N; ++i) // set row & column
    {
        arr[r][i] = method;
        arr[i][c] = method;
    }
    for (int i = 1, j = 1;
         (r - i >= 0) || (r + i < N) || (c - j >= 0) || (c + j < N);
         ++i, ++j)
    { // i: row, j: column
        if (r - i >= 0)
        {
            if (c - j >= 0)
                arr[r - i][c - j] = method;
            if (c + j < N)
                arr[r - i][c + j] = method;
        }
        if (r + i < N)
        {
            if (c - j >= 0)
                arr[r + i][c - j] = method;
            if (c + j < N)
                arr[r + i][c + j] = method;
        }
    }
    Print(N, arr);
}

void Pass(int N, int depth, bool **arr, int &count)
{
    if (depth == N)
    {
        ++count;
        return;
    }
    for (int j = 0; j < N; ++j)
    {
        if (!arr[depth][j])
        {
            SetQueen(N, arr, depth, j, FIX);
            Pass(N, depth + 1, arr, count);
            SetQueen(N, arr, depth, j, UNDO);
        }
    }
}

int Queen(int N)
{
    int count = 0;
    bool **arr;
    arr = new bool *[N];
    for (int i = 0; i < N; ++i)
        arr[i] = new bool[N]();
    Pass(N, 0, arr, count);
    for (int i = 0; i < N; ++i)
        delete[] arr[i];
    delete[] arr;
    return count;
}

int main()
{
    int N;
    cin >> N;
    cout << Queen(N);
}