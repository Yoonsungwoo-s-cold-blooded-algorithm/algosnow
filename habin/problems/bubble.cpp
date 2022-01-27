#include <iostream>
#include <random>
#define SIZE 10
using namespace std;

void Swap(int &source, int &dest)
{
    int temp = source;
    source = dest;
    dest = temp;
}

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

void BubbleSort(int *arr, int size, bool descending = false)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = i + 1; j < size; ++j)
            if (arr[i] > arr[j] != descending)
                Swap(arr[i], arr[j]);
    }
}

void InsertSort(int *arr, int size, bool descending = false)
{
    for (int i = 1; i < size; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (((key < arr[j]) != descending) && j >= 0)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void SelectionSort(int *arr, int size, bool descending = false)
{
    for (int i = 0; i < size; ++i)
    {
        int max = i;
        for (int j = i + 1; j < size; ++j)
            if ((arr[max] > arr[j]) != descending)
                max = j;
        Swap(arr[max], arr[i]);
    }
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