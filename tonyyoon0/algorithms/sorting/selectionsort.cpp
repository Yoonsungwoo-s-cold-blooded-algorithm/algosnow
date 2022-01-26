#include <iostream>

int get_min_idx(int *list, int list_size, int start_idx) {
    int min_idx = start_idx;
    for (int i = start_idx; i < list_size; i++) {
        if (list[min_idx] > list[i]) {
            min_idx = i;
        }
    }
    return min_idx;
}

// int get_max_idx(int *list, int list_size, int start_idx) {
//     int max_idx = start_idx;
//     for (int i = start_idx; i < list_size; i++) {
//         if (list[max_idx] < list[i]) {
//             max_idx = i;
//         }
//     }
//     return max_idx;
// }

void selection_sort(int *list, int list_size) {
    for (int i = 0; i < list_size; i++) {
        int temp = list[get_min_idx(list, list_size, i)];
        list[get_min_idx(list, list_size, i)] = list[i];
        list[i] = temp;
    }
}

// void double_selection_sort(int *list, int list_size) {
//     for (int i = 0; i < list_size / 2; i++) {
//         int min_temp = list[get_min_idx(list, list_size, i)];
//         list[get_min_idx(list, list_size, i)] = list[i];
//         list[i] = min_temp;

//         int max_temp = list[get_max_idx(list, list_size, i)];
//         list[get_max_idx(list, list_size, i)] = list[list_size - 1 - i];
//         list[list_size - 1 - i] = max_temp;
//     }
// }

int main() {
    int list[10] = {2, 8, 3, 5, 1, 9, 0, 4, 7, 6};

    selection_sort(list, 10);

    for (int i = 0; i < 10; i++) std::cout << list[i] << ' ';

    return 0;
}