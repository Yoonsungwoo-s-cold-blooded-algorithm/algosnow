#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b;
    int arr_a[10001] = {0}, arr_b[10001] = {0};
    cin >> a >> b;
    for (int i = 2; i <= sqrt(a); ++i)
    {
        while (!(a % i))
        {
            ++arr_a[i];
            a /= i;
        }
    }
    if (a != 1)
        arr_a[a]++;

    for (int i = 2; i <= sqrt(b); ++i)
    {
        while (!(b % i))
        {
            ++arr_b[i];
            b /= i;
        }
    }
    if (b != 1)
        arr_b[b]++;

    // common factor
    int common_factor = 1, common_multiple = 1;
    for (int i = 1; i < 10001; ++i)
    {
        if (arr_a[i] && arr_b[i])
            common_factor *= arr_a[i] > arr_b[i] ? pow(i, arr_b[i]) : pow(i, arr_a[i]);
        if (arr_a[i] || arr_b[i])
            common_multiple *= arr_a[i] > arr_b[i] ? pow(i, arr_a[i]) : pow(i, arr_b[i]);
    }
    cout << common_factor << endl
         << common_multiple << endl;
}