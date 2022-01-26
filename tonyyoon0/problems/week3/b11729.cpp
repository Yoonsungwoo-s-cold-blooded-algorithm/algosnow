#include <iostream>

void move_disc(int A, int B) {
    printf("%d %d\n", A, B);
}

void tower_of_hanoi(int start, int end, int via, int discs) {
    if (discs == 1) move_disc(start, end);
    else {
        tower_of_hanoi(start, via, end, discs - 1);
        move_disc(start, end);
        tower_of_hanoi(via, end, start, discs - 1);
    }
}

int main() {
    int disc_num;
    std::cin >> disc_num;

    std::cout << (1 << disc_num) - 1 << std::endl;

    tower_of_hanoi(1, 3, 2, disc_num);

    return 0;
}