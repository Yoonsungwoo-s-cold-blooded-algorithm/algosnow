#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int primes[500000] = {0};
    int primes_size = 0;
    bool table[1000010] = {false};

    for (long long int i = 2; i <= 1000000;)
    { // i: current prime
        primes[primes_size++] = i;
        for (long long int j = i * i; j <= 1000000; j += i)
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
        int i = 0;
        while (i < primes_size)
        {
            int prime = primes[i++];
            if (!table[n - prime])
            {
                cout << n << " = " << prime << " + " << n - prime << '\n';
                break;
            }
        }
        if (i == primes_size)
            cout << "Goldbach's conjecture is wrong." << '\n';
    }
    return 0;
}