#include <iostream>

int main() {
   int n, del_count, k;
   while (true) {
       del_count = 0;
       std::cin >> n;
       if (!n) break;
       else if (n == 1) {
           std::cout << 1 << std::endl;
           continue;
       }
       else if (n == 2) {
           std::cout << 1 << std::endl;
           continue;
       }
       // 배열 생성, 할당
       int *nums = new int[n];
       for (int i = 0; i < n; i++) {
           nums[i] = n + i + 1;
       }
 
       // 소수 판정
       k = n - 1;
       while (k > 1) {
          int multi = (n / k) + 1;
          while (multi * k <= 2 * n) {
              if (nums[multi * k - (n + 1)] != 0) {
                   nums[multi * k - (n + 1)] = 0;
                   del_count++;
                   multi++;
              }
              else multi++;
          }
          k--;
       }
 
       // 결과 출력
       std::cout << n - del_count << std::endl;
       // 배열 공간 해제
       delete[] nums;
   }
   return 0;
}