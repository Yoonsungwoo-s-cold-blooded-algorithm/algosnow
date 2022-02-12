#include <iostream>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    int *list = new int[N];

    for (int i = 0; i < N; i++) {
        std::cin >> list[i];
    }

    std::sort(list, list + N);

    for (int i = 0; i < N; i++) {
        printf("%d\n", list[i]);
    }

    return 0;
}