#include <iostream>
using namespace std;
char s0[4] = "moo";

char GetMoo(int k, int n, int length)
{
    // cout << "GetMoo: " << k << "/" << length << "/" << n << '\n';
    if (n <= 3)
        return s0[n - 1];
    else if (n <= length - (length - k - 3) / 2 && n > (length - k - 3) / 2)
    {
        if (n == (length - k - 3) / 2 + 1)
            return 'm';
        else
            return 'o';
    }
    else
    {
        int next_n = n <= (length - k - 3) / 2 ? n : n - (length - (length - k - 3) / 2);
        return GetMoo(k - 1, next_n, (length - k - 3) / 2);
    }
}

char Moo(int k, int N, int length)
{
    // cout << "Moo: " << k << "/" << length << "/" << N << '\n';
    if (N <= length)
        return GetMoo(k, N, length);
    else
        return Moo(k + 1, N, length * 2 + k + 4);
}

int main()
{
    int N;
    cin >> N;
    cout << Moo(0, N, 3);
}
// moomooomoomoooomoomooomoomooooomooooooooomoooomoom