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

void InsertionSort(int *arr, int size, bool descending = false)
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

int main()
{
    int arr[SIZE];
    RandomNumber(arr, SIZE);
    cout << "Before: ";
    PrintArr(arr, SIZE);
    InsertionSort(arr, SIZE);
    cout << "After: ";
    PrintArr(arr, SIZE);
}
