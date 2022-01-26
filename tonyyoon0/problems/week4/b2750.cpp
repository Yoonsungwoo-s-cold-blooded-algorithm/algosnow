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

void selection_sort(int *list, int list_size) {
    for (int i = 0; i < list_size; i++) {
        int temp = list[get_min_idx(list, list_size, i)];
        list[get_min_idx(list, list_size, i)] = list[i];
        list[i] = temp;
    }
}

int main() {
    int N;
    std::cin >> N;

    int *list = new int[N];

    for (int i = 0; i < N; i++) {
        std::cin >> list[i];
    }

    selection_sort(list, N);

    for (int i = 0; i < N; i++) {
        std::cout << list[i] << std::endl;
    }

    return 0;
}