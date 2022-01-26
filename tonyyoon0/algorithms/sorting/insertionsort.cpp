#include <iostream>

void insertion_sort(int *list, int list_size) {
    for (int i = 1; i < list_size; i++) {
        int temp = list[i];
        int j = i - 1;
        while (list[j] > temp && j >= 0) {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = temp;
    }
}

int main() {
    int list[10] = {2, 8, 3, 5, 1, 9, 0, 4, 7, 6};

    insertion_sort(list, 10);

    for (int i = 0; i < 10; i++) std::cout << list[i] << ' ';

    return 0;
}