#include <iostream>
#include <random>
#define SIZE 10
using namespace std;

void PrintArr(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
        cout << arr[i] << ' ';
    cout << endl;
}

void RandomNumber(int *arr, int size)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 99);
    for (int i = 0; i < size; ++i)
        arr[i] = dis(gen);
}

void ShellSort(int *arr, int size, bool descending = false)
{
    for (int k = size / 2; k > 0; k /= 2)
    {
        for (int i = 0; i < size; ++i)
        {
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

int main()
{
    int arr[SIZE];
    RandomNumber(arr, SIZE);
    cout << "Before: ";
    PrintArr(arr, SIZE);
    ShellSort(arr, SIZE);
    cout << "After: ";
    PrintArr(arr, SIZE);
}
