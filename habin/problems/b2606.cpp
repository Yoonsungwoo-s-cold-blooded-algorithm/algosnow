#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 처음에 양방향을 고려 안함.. 그래서 틀림..
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> v(N);
    bool *visited = new bool[N]();
    for (int i = 0; i < M; ++i)
    {
        int src, dest;
        cin >> src >> dest;
        v[src - 1].push_back(dest - 1);
        v[dest - 1].push_back(src - 1);
    }

    queue<int> q;
    q.push(0);
    visited[0] = true;
    int count = 0;
    do
    {
        for (auto i : v[q.front()])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
        q.pop();
        ++count;
    } while (!q.empty());

    cout << count - 1;
}