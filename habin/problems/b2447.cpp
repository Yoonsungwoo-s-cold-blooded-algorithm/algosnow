#include <iostream>
#include <cmath>

using namespace std;
void Hole(char **arr, int size, int level)
{
    if (level == 0)
        return;
    for (int i = level / 3; i < size; i += level)
    {
        for (int j = level / 3; j < size; j += level)
        {
            for (int m = 0; m < level / 3; ++m)
            {
                for (int n = 0; n < level / 3; ++n)
                {
                    arr[i + m][j + n] = ' ';
                }
            }
        }
    }
    Hole(arr, size, level / 3);
}

void Print(char **arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
            cout << arr[i][j];
        cout << '\n';
    }
}

int main()
{
    int N;
    cin >> N;
    char **arr = new char *[N];
    for (int i = 0; i < N; ++i)
    {
        arr[i] = new char[N];
        for (int j = 0; j < N; ++j)
            arr[i][j] = '*';
    }
    Hole(arr, N, N);
    Print(arr, N);
}