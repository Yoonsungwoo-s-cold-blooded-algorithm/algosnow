#include <iostream>

#include <set>
#include <queue>
#define PII pair<int, int>
using namespace std;

struct compare
{
    bool operator()(const PII a, const PII b)
    {
        return a.second > b.second;
    }
};

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int V, E;
    cin >> V >> E;
    vector<vector<PII>> v(V);
    for (int i = 0; i < E; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;
        v[a - 1].push_back({b - 1, w});
        v[b - 1].push_back({a - 1, w});
    }
    set<int> s;
    priority_queue<PII, vector<PII>, compare> pq;
    s.insert(0);
    for (auto it : v[0])
        pq.push(it);
    int sum = 0;
    while (s.size() != V)
    {
        while (s.find(pq.top().first) != s.end())
            pq.pop();
        PII next = pq.top();
        pq.pop();
        s.insert(next.first);
        sum += next.second;
        for (auto it : v[next.first])
            pq.push(it);
    }
    cout << sum;
}
