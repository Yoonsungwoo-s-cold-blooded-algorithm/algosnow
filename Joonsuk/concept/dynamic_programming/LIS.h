// LIS는 최장 증가 부분 수열을 뜻한다.
#ifndef LIS_H
#define LIS_H

// bottom up
// bottom up은 top down 방식보다 상대적으로 간단한다.
// 대신 시간 복잡도가 O(n^2)이라는 단점이 존재한다.

// 수열에 끝 부분에 새로운 원소가 추가되었다고 가정하자.
// 해당 원소가 제일 마지막 원소가 되는 증가 수열의 길이를 구할 수 있다면, 
// 다음 원소가 추가되었을때 동일한 방법으로 다음 원소의 증가 수열 길이 또한 구할 수 있다.

// 추가된 원소의 증가 수열의 길이를 구하는 방법은 간단하다.
// 해당 원소보다 작은 원소들 중에서 가장 긴 증가 수열의 길이 + 1이 추가된 원소의 증가수열 길이가 된다.

// n번째 원소의 증가 수열 길이를 구하는 함수
int length[1001]; // 0 ~ 1000까지
void LIS_bu(int n){
    int length_of_n = 1;
    for(int i = 0; i != n; ++i){
        if(length[i]+1 > length_of_n)
            length_of_n = length[i] + 1;
    }

    if(length_of_n > length[n])
        length[n] = length_of_n;
}



// top down
// TODO: 이진 탐색 공부후 작성...

#endif