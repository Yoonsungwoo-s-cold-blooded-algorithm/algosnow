#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end(), greater<int>());
    int baby = 1;
    int min = arr.back();
    arr.pop_back();
    while (K >= baby)
    {
        if (min < arr.back())
        {
            ++min;
            K -= baby;
        }
        else
        {
            ++baby;
            arr.pop_back();
        }
    }
    cout << min;
}