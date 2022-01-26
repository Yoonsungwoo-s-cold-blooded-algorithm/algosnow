#include <iostream>

void shell_sort(int *list, int list_size) {
    int gap = list_size / 2;
    while (gap >= 1) {
        for (int i = 0; i < gap; i++) {
            for (int j = i + gap; j < list_size; j += gap) {
                int temp = list[j];
                int k = j - gap;
                while (list[k] > temp && k >= 0) {
                    list[k + gap] = list[k];
                    k -= gap;
                }
                list[k + gap] = temp;
            }
        }
        gap /= 2;
    }
}

int main() {
    int list[10] = {2, 8, 3, 5, 1, 9, 0, 4, 7, 6};

    shell_sort(list, 10);

    for (int i = 0; i < 10; i++) std::cout << list[i] << ' ';

    return 0;
}