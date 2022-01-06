#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    bool table[500100] = {false};
    for (long long int i = 2; i <= 500000;)
    { // i: current prime
        for (long long int j = i * i; j <= 500000; j += i)
            table[j] = true;
        while (table[++i])
            ;
    }

    while (true)
    {
        int n;
        cin >> n;
        if (!n)
            break;
    }
}