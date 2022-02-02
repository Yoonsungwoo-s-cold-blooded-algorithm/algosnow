#include <iostream>

using namespace std;

int Work(int start, int end, int money, int *day, int *reward)
{
    int max = 0;
    for (int i = start; i < end; ++i)
    {
        if (i + day[i] <= end)
        {
            int temp = Work(i + day[i], end, money + reward[i], day, reward);
            if (temp > max)
                max = temp;
        }
    }
    return max ? max : money;
}

int main()
{
    int day[15];
    int reward[15];
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> day[i] >> reward[i];
    cout << Work(0, N, 0, day, reward);
}