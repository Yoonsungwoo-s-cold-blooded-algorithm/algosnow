#include <iostream>

int main() {
    int n, del_count, k;
    while (true) {
        del_count = 0;
        std::cin >> n;
        if (!n) break;

        // 배열 생성, 할당
        int *nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = n + i;
        }

        // 소수 판정
        k = n - 1;
        while (k != 2) {
            
        }

        // 결과 출력
        std::cout << del_count << std::endl;

        // 배열 공간 해제
        delete[] nums;
    }

    return 0;
}
