#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T)
    {
        int N, M;
        cin >> N >> M;
        for (int i = 0; i < M; ++i)
        {
            int a, b;
            cin >> a >> b;
        }
        cout << N - 1 << '\n';
        --T;
    }
}