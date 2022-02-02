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
    for (int i = size; i > 0; --i)
    {
        for (int j = 0; j < i - 1; ++j)
            if (arr[j] > arr[j + 1] != descending)
                Swap(arr[j], arr[j + 1]);
    }
}

int main()
{
    int arr[SIZE];
    RandomNumber(arr, SIZE);
    cout << "Before: ";
    PrintArr(arr, SIZE);
    BubbleSort(arr, SIZE);
    cout << "After: ";
    PrintArr(arr, SIZE);
}