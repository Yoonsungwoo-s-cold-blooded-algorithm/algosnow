#include <iostream>

int main() {
    int N, K, P, delNum;
    std::cin >> N >> K;
    // std::cout << "N: " << N << "K: " << K << std::endl;

    // 1. 2부터 N까지 모든 정수를 적는다.
    int nums[N];
    for (int i = 0; i < N - 1; i++) nums[i] = i + 2;
    // for (int i = 0; i < N - 1; i++) std::cout << nums[i];
    // std::cout << std::endl;

    // 2. 아직 지우지 않은 수 중 가장 작은 수를 찾는다. 이것을 P라고 하고, 이 수는 소수이다.
    SecondStep:
    for (int i = 0; i < N - 1; i++) {
        if (nums[i] != 0) {
            P = nums[i];
            break;
        }
    }
    // std::cout << "------- current P : " << P << " -------" << std::endl;

    // 3. P를 지우고, 아직 지우지 않은 P의 배수를 크기 순서대로 지운다.
    delNum = P;
    int i = 2;
    while (delNum <= N) {
        int temp = delNum;
        if (nums[delNum - 2] != 0) {
            nums[delNum - 2] = 0;
            // std::cout << "deleted number " << delNum << std::endl;
            K--;
            // std::cout << "reduced K by 1 : current K = " << K << std::endl;
        }
        if (K == 0) {
            std::cout << temp << std::endl;
            return 0;
        }
        delNum = P * i++;
        // std::cout << "new delNum: " << delNum << std::endl;
    }

    // 4. 아직 모든 수를 지우지 않았다면, 다시 2번 단계로 간다.
    goto SecondStep;
}