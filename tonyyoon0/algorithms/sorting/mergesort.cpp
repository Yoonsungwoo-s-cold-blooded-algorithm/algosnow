#include <iostream>

void merge(int *list, int start, int middle, int end) {
    int list_left_size = middle - start,
        list_right_size = end - middle + 1,
        merged_list_size = end - start + 1;
    int *merged_list = new int[merged_list_size];

    int list_left_idx = start,
        list_right_idx = middle,
        merged_list_idx = 0;
    
    while (merged_list_idx < merged_list_size) {
        if (list_left_idx == middle) {
            for (int k = list_right_idx; k <= end; k++) {
                merged_list[merged_list_idx] = list[list_right_idx];
                merged_list_idx++;
            }
        }
        else if (list_right_idx == end + 1) {
            for (int k = list_left_idx; k < middle; k++) {
                merged_list[merged_list_idx] = list[list_left_idx];
                merged_list_idx++;
            }
        }
        else if (list[list_left_idx] < list[list_right_idx]) {
            merged_list[merged_list_idx] = list[list_left_idx];
            list_left_idx++;
            merged_list_idx++;
        }
        else {            
            merged_list[merged_list_idx] = list[list_right_idx];
            list_right_idx++;
            merged_list_idx++;
        }
    }

    for (int i = start; i <= end; i++) {
        list[i] = merged_list[i - start];
    }
    delete[] merged_list;
}

void merge_sort(int *list, int start_idx, int end_idx) {
    if (start_idx >= end_idx) return;
    int middle = start_idx + (end_idx - start_idx) / 2 + 1;
    merge_sort(list, start_idx, middle - 1);
    merge_sort(list, middle, end_idx);
    merge(list, start_idx, middle, end_idx);
}

int main() {
    int list[10] = {2, 8, 3, 5, 1, 9, 0, 4, 7, 6};

    merge_sort(list, 0, 9);

    for (int i = 0; i < 10; i++) std::cout << list[i] << ' ';

    return 0;
}