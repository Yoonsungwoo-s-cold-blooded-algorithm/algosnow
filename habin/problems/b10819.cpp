#include <iostream>
#include <deque>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main()
{
    deque<int> dq;
    deque<int> ans;
    int N, temp;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> temp;
        dq.push_back(temp);
    }
    sort(dq.begin(), dq.end());
    bool twinkle = false;
    while (dq.size() > 1)
    {
        if (!twinkle)
        {
            ans.push_front(dq.front());
            ans.push_back(dq.back());
        }
        else
        {
            ans.push_front(dq.back());
            ans.push_back(dq.front());
        }
        dq.pop_back();
        dq.pop_front();
        twinkle = !twinkle;
    }
    if (dq.size() == 1)
    {
        int tmp1 = abs(ans.back() - dq.front());
        int tmp2 = abs(ans.front() - dq.front());
        if (tmp1 < tmp2)
            ans.push_front(dq.front());
        else
            ans.push_back(dq.front());
    }

    int sum = 0;
    for (int i = 0; i < N - 1; ++i)
        sum += abs(ans[i] - ans[i + 1]);
    cout << sum;
}
