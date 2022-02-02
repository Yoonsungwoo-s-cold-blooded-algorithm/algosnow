#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, temp;
    int arr[10001] = {0};
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> temp;
        ++arr[temp];
    }
    for (int i = 1; i <= 10000; ++i)
    {
        if (arr[i])
            while (arr[i]--)
                cout << i << '\n';
    }
}