#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define PII pair<int, int>
using namespace std;

// cycle edge is even
int main()
{
    int K;
    cin >> K;
    while (K)
    {
        --K;
        int V, E;
        cin >> V >> E;
        vector<vector<int>> v(V);
        for (int i = 0; i < E; ++i)
        { // make matrix
            int a, b;
            cin >> a >> b;
            v[a - 1].push_back(b - 1);
            v[b - 1].push_back(a - 1);
        }
        for (int i = 0; i < V; ++i)
        {
            bool *visited = new bool[V]();
            stack<PII> s;
            for (auto i : v[i])
                s.push({i, 1});
            while (!s.empty())
            {
                PII curr = s.top();
                s.pop();
                for (auto it : v[curr])
                {
                    if (it == i)
                    {
                    }
                    if (!visited[it])
                    {

                        s.push(it);
                    }
                }
            }

            delete[] visited;
        }
    }
}