#include <iostream>
#include <algorithm>

int max = -1000000000,
    min = 1000000000;

void calculate(int *nums, int *op_list, int op_list_size) {
    std::sort(op_list, op_list + op_list_size);
    do {
        int i = 1;
        int temp = nums[0];
        for (int k = 0; k < op_list_size; k++) {
            int op = op_list[k];
            switch (op) {
                case 0: // +
                    temp += nums[i];
                    break;
                
                case 1: // -
                    temp -= nums[i];
                    break;

                case 2: // *
                    temp *= nums[i];
                    break;
                
                case 3: // /
                    temp /= nums[i];
                    break;
            }
            i++;
        }
        if (temp > max) max = temp;
        if (temp < min) min = temp;
    } while (std::next_permutation(op_list, op_list + op_list_size));
}

int main() {
    int num_count;
    int op_count[4];

    std::cin >> num_count;

    int nums[num_count];
    for (int i = 0; i < num_count; i++) {
        std::cin >> nums[i];
    }
    for (int i = 0; i < 4; i++) {
        std::cin >> op_count[i];
    }

    // creating op_list
    int op_list_size = 0;
    for (int i = 0; i < 4; i++) {
        op_list_size += op_count[i];
    }
    int op_list[op_list_size];
    int k = 0;
    int op_list_idx = 0;
    while (op_list_idx < op_list_size) {
        if (op_count[k]) {
            op_list[op_list_idx] = k;
            op_count[k]--;
            op_list_idx++;
        }
        else {
            k++;
        }
    }

    calculate(nums, op_list, op_list_size);
    std::cout << max << '\n' << min;

    return 0;
}