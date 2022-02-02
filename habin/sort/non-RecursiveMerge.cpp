#include <iostream>
#include <random>

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

void Merge(int *arr, int *temp, int start, int mid, int end)
{
    int list1 = start, list2 = mid, i = start;
    while (list1 < mid && list2 < end)
    {
        if (arr[list1] <= arr[list2])
            temp[i++] = arr[list1++];
        else
            temp[i++] = arr[list2++];
    }
    if (list1 != mid)
        while (i != end)
            temp[i++] = arr[list1++];
    else if (list2 != end)
        while (i != end)
            temp[i++] = arr[list2++];
    for (int j = start; j < end; ++j)
        arr[j] = temp[j];
}

void MergeSort(int *arr, int *temp, int start, int end)
{
    if (start < end - 1)
    {
        int m = (start + end + 1) / 2;
        MergeSort(arr, temp, start, m);
        MergeSort(arr, temp, m, end);
        Merge(arr, temp, start, m, end);
    }
}

void MergeSort(int *arr, int start, int end)
{
    int *temp = new int[end];
    int m = (start + end + 1) / 2;
    MergeSort(arr, temp, start, m);
    MergeSort(arr, temp, m, end);
    Merge(arr, temp, start, m, end);
    delete[] temp;
}

int main()
{
    int N;
    cin >> N;
    int arr[1000];
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    MergeSort(arr, 0, N);
    for (int i = 0; i < N; ++i)
        cout << arr[i] << '\n';
}