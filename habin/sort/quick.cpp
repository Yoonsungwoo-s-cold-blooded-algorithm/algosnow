#include <iostream>
#include <random>
#define SIZE 100

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

void Swap(int &source, int &dest)
{
    int temp = source;
    source = dest;
    dest = temp;
}

int Partition(int *arr, int start, int end)
{
    int pivot = start;
    int left = start, right = end;
    do
    {
        do
            --right;
        while (arr[pivot] < arr[right]);

        do
            ++left;
        while (arr[pivot] > arr[left]);

        if (right > left)
            Swap(arr[right], arr[left]);

    } while (right > left);

    Swap(arr[pivot], arr[right]);
    return right;
}

void QuickSort(int *arr, int start, int end)
{
    if (start < end - 1)
    {
        int pivot = start; // select pivot as leftmost
        pivot = Partition(arr, start, end);
        QuickSort(arr, start, pivot);
        QuickSort(arr, pivot + 1, end);
    }
}

int main()
{
    int arr[SIZE];
    RandomNumber(arr, SIZE);
    cout << "Before: ";
    QuickSort(arr, 0, SIZE);
    cout << "After: ";
    PrintArr(arr, SIZE);
}