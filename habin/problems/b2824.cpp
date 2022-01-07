#include <iostream>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

void Factorization(int number, map<int, int> &store)
{
    for (int i = 2; i <= sqrt(number); ++i)
    {
        auto it = store.find(i);
        if (number % i == 0)
        {
            if (it == store.end())
            {
                store.insert({i, 0});
                it = store.find(i);
            }
        }
        while (number % i == 0)
        {
            number /= i;
            ++(it->second);
        }
    }
    if (number != 1)
    {
        if (store.find(number) != store.end())
            ++(store.find(number)->second);
        else
            store.insert({number, 1});
    }
}

int main()
{
    int N, M, tmp;
    map<int, int> N_map, M_map;

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> tmp;
        Factorization(tmp, N_map);
    }

    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        cin >> tmp;
        Factorization(tmp, M_map);
    }

    unsigned long long int common_factor = 1;
    while (N_map.size())
    {
        auto dest1 = N_map.begin();
        auto dest2 = M_map.find(dest1->first);
        if (dest2 != M_map.end())
        {
            common_factor *= (dest1->second > dest2->second
                                  ? pow(dest1->first, dest2->second)
                                  : pow(dest1->first, dest1->second));
        }
        N_map.erase(dest1);
    }
    string print;
    for (int i = 0; i < 9 && common_factor; ++i)
    {
        print.push_back(common_factor % 10 + '0');
        common_factor /= 10;
    }
    reverse(print.begin(), print.end());
    cout << print;
}