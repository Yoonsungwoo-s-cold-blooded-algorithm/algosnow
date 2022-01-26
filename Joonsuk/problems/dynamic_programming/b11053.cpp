// 10 20 10 30 20 50
// 1  2  1  3  2  4
// 새로운 값의 길이 = 자기보다 제일 가깝게 작은 값의 길이 + 1 

// 1부터 1000까지의 배열이 있다면
// 새로운 값이 등장할 때의 탐색 : 자신에서 --

// length_of_k = k보다 작고 제일 가까운 값의 길이 + 1;

#include <iostream>

void LIS(int An);
int find_length_of_An(int An);

int max_length_of_An[1001]; // 1~1000

int main() {
    int N, An;
    std::cin >> N;
    for(int i = 0; i != N; ++i){
        std::cin >> An;
        LIS(An);
    }
    
    int max = 1;
    for(int i = 1; i != 1001; ++i){
        if(max_length_of_An[i] > max)
            max = max_length_of_An[i];
    }
    std::cout << max;
}

// // bottom up - 시간 복잡도 : O(n^2)
void LIS(int An){
    int length_of_An = find_length_of_An(An);

    if(max_length_of_An[An] < length_of_An){
        max_length_of_An[An] = length_of_An;
    }
}

int find_length_of_An(int An){
    // 반례 : 5 \n 1 6 4 5 7
    // --An;
    // int max = 0;
    // while(An != 0){
    //     if(max_length_of_An[An] > max){
    //         max = max_length_of_An[An] + 1;
    //     }
    //     --An;
    // }

    // if(max == 0)
    //     return 1;
    // else
    //     return max;

    int max = 1;
    for(int i = 0; i != An; ++i){
        if(max_length_of_An[i]+1 > max){
            max = max_length_of_An[i] + 1;
        }
    }
    return max;
}

// int length[1001];
// int arr[1001];
// void LIS2(int n);
// int main(){
//     int N;
//     std::cin >> N;
    
//     for(int i = 0; i != N; ++i){
//         std::cin >> arr[i]; 
//     }

//     LIS2(N);
    
//     int max = 1;
//     for(int i = 0; i != N; ++i){
//         if(length[i] > max)
//             max = length[i];
//     }
//     std::cout << max;
// }

// void LIS2(int n){
//     for(int k = 0; k < n; ++k){
//         length[k] = 1; // 기본 길이는 1
//         for(int i = 0; i < k; ++i){
//             // 인덱스가 k보다 작은 모든 i들 중에서 값도 k보다 작은 i들에 대하여
//             if(arr[i] < arr[k]){
//                 // 제일 긴 i의 length + 1이 k의 length가 된다.
//                 length[k] = (length[k] > length[i]+1) ? (length[k]) : (length[i]+1);
//             }
//         }
//     }
// }