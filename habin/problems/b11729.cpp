#include <iostream>
#include <cmath>
using namespace std;

void Move(int from, int to, int rest, int level)
{
    if (level == 1)
        cout << from << ' ' << to << '\n';
    else
    {
        Move(from, rest, to, level - 1);
        cout << from << ' ' << to << '\n';
        Move(rest, to, from, level - 1);
    }
}

int main()
{
    int N;
    cin >> N;
    cout << static_cast<int>(pow(2, N)) - 1 << '\n';
    Move(1, 3, 2, N);
}