#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool table[250000] = {false};
    for (long long int i = 2; i <= 246912;)
    { // i: current prime
        for (long long int j = i * i; j <= 246912; j += i)
            table[j] = true;
        while (table[++i])
            ;
    }

    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        int count = 0;
        for (int i = n + 1; i <= 2 * n; ++i)
        {
            if (!table[i])
                ++count;
        }
        cout << count << endl;
    }
}