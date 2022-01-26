#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int nums[1000001];
    for (int i = 0; i < 1000001; i++) {
        nums[i] = i;
    }
    

    int k = 2;
    while (k * k <= 1000000) {
        int j = k * k;
        while (j <= 1000000) {
            nums[j] = 0;
            j += k;
        }
        k++;
    }
    
    nums[0] = 0;
    nums[1] = 0;
    int n = -1;
    while (true) {
        std::cin >> n;
        if (!n) break;
        if (!(n % 2 == 0)) continue;
    
        for (int i = 3; i < 1000001; i += 2) {
            if (!(nums[n - i] == 0) && !(nums[i] == 0)) {
                std::cout << n << " = " << i << " + " << n - i << '\n';
                goto end;
            }
        }
        std::cout << "Goldbach's conjecture is wrong." << '\n';

        end:
        continue;
    }

    return 0;
}