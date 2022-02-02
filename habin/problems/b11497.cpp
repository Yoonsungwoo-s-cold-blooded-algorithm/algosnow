#include <iostream>
#include <deque>
#include <queue>

using namespace std;

int main()
{
    // cin.tie(NULL);
    // ios_base::sync_with_stdio(false);
    int T, N, temp;
    cin >> T;
    while (T)
    {
        deque<int> dq;
        priority_queue<int> pq;
        cin >> N;
        for (int i = 0; i < N; ++i)
        {
            cin >> temp;
            pq.push(-temp);
        }
        dq.push_back(-pq.top());
        pq.pop();
        dq.push_back(-pq.top());
        pq.pop();
        int diff = dq[1] - dq[0];
        while (!pq.empty())
        {
            if (dq.front() < dq.back())
            {
                dq.push_front(-pq.top());
                diff = diff < dq[0] - dq[1] ? dq[0] - dq[1] : diff;
            }
            else
            {
                dq.push_back(-pq.top());
                diff = diff < dq[dq.size() - 1] - dq[dq.size() - 2] ? dq[dq.size() - 1] - dq[dq.size() - 2] : diff;
            }
            pq.pop();
        }
        cout << diff << '\n';
        --T;
    }
}