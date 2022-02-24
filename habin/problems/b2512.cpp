#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, M, temp, sum = 0;
    priority_queue<int> pq;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> temp;
        sum += temp;
        pq.push(temp);
    }
    cin >> M;

    int budget = M - sum;
    if (budget >= 0)
        cout << pq.top();
    else
    {
        int count = 0;
        while (budget < 0)
        {
            int top;
            do
            {
                top = pq.top();
                pq.pop();
                ++count;
            } while (!pq.empty() && (top == pq.top()));
            if (pq.empty())
            {
                cout << M / N;
                return 0;
            }
            budget += (top - pq.top()) * count;
        }
        cout << pq.top() + budget / count;
    }
}