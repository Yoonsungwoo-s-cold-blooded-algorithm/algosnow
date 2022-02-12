#include <iostream>

void swap_values(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void quick_sort(int *list, int start_idx, int end_idx) {
    if (start_idx < end_idx) {
        int search_from_left = start_idx;
        int search_from_right = end_idx + 1;
        int pivot = list[start_idx];
        do {
            do search_from_left++; while (list[search_from_left] < pivot);
            do search_from_right--; while (list[search_from_right] > pivot);
            if (search_from_left < search_from_right) {
                swap_values(list[search_from_left], list[search_from_right]);
            }
        } while (search_from_left < search_from_right);
        swap_values(list[start_idx], list[search_from_right]);

        quick_sort(list, start_idx, search_from_right - 1);
        quick_sort(list, search_from_right + 1, end_idx);
    }
}

int main() {
    int list[10] = {2, 8, 3, 5, 1, 9, 0, 4, 7, 6};

    quick_sort(list, 0, 9);

    for (int i = 0; i < 10; i++) std::cout << list[i] << ' ';

    return 0;
}