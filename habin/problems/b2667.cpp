#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#define PII pair<int, int>

using namespace std;

void Search(bool arr[][25], int size, int r, int c, queue<PII> &q)
{
    if (c - 1 >= 0)
        if (arr[r][c - 1])
        {
            q.push({r, c - 1});
            arr[r][c - 1] = false;
        }
    if (c + 1 < size)
        if (arr[r][c + 1])
        {
            q.push({r, c + 1});
            arr[r][c + 1] = false;
        }
    if (r - 1 >= 0)
        if (arr[r - 1][c])
        {
            q.push({r - 1, c});
            arr[r - 1][c] = false;
        }
    if (r + 1 < size)
        if (arr[r + 1][c])
        {
            q.push({r + 1, c});
            arr[r + 1][c] = false;
        }
}

int CountSet(bool arr[][25], int size, int r, int c)
{
    queue<PII> q;
    arr[r][c] = false;
    q.push({r, c});
    int count = 0;
    do
    {
        Search(arr, size, q.front().first, q.front().second, q);
        q.pop();
        ++count;
    } while (!q.empty());
    return count;
}

int main()
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    bool arr[25][25];
    int N;
    vector<int> v;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        string s;
        cin >> s;
        for (int j = 0; j < N; ++j)
            arr[i][j] = (s[j] == '1');
    }
    int count = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (arr[i][j])
            {
                v.push_back(CountSet(arr, N, i, j));
                ++count;
            }
        }
    }

    sort(v.begin(), v.end());
    cout << count << '\n';
    for (auto i : v)
        cout << i << '\n';
}