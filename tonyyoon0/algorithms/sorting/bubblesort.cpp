#include <iostream>

void bubble_sort(int *list, int list_size) {
    for (int i = list_size - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (list[j] > list[j + 1]) {
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

int main() {
    int list[10] = {2, 8, 3, 5, 1, 9, 0, 4, 7, 6};

    bubble_sort(list, 10);

    for (int i = 0; i < 10; i++) std::cout << list[i] << ' ';

    return 0;
}