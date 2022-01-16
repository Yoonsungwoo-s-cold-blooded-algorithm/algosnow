#include <iostream>
#include <cmath>
using namespace std;

int start[4] = {2, 3, 5, 7};
int attach[4] = {1, 3, 7, 9};

int AttachNum(int origin, int end)
{
    return origin * 10 + end;
}

bool IsPrime(int number)
{
    for (int i = 2; i <= sqrt(number); ++i)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}

void FindNumberDFS(int curr, int N, int length)
{
    if (IsPrime(curr))
    {
        if (length == N)
        {
            cout << curr << '\n';
            return;
        }
        for (int i = 0; i < 4; ++i)
        {
            int next = AttachNum(curr, attach[i]);
            FindNumberDFS(next, N, length + 1);
        }
    }
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < 4; ++i)
    {
        int num = start[i];
        FindNumberDFS(num, N, 1);
    }
}