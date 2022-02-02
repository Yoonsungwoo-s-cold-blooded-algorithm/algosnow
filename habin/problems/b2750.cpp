#include <iostream>
using namespace std;

void ShellSort(int *arr, int size, bool descending = false)
{
    for (int k = size / 2; k > 0; k /= 2)
    {
        for (int i = 0; i < size; ++i)
        { // i: partial list start index
            for (int j = i + k; j < size; j += k)
            { // j: key index
                int key = arr[j];
                int m = j - k;
                while (((key < arr[m]) != descending) && m >= i)
                {
                    arr[m + k] = arr[m];
                    m -= k;
                }
                arr[m + k] = key;
            }
        }
    }
}

void PrintArr(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
        cout << arr[i] << '\n';
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    int arr[1000];
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    ShellSort(arr, N);
    PrintArr(arr, N);
}