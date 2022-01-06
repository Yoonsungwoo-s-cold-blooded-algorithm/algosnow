#include <iostream>

using namespace std;
/*
1. 초기 소수 2
2. 2에 배수에 대한 테이블 거름
3. 다음 소수 현재 소수에 대해 하나씩 더하면서 찾음
4. 찾은 소수에 대한 테이블 거름
5. 3번부터 반복


*/
int main()
{
    bool table[1001] = {false};
    int N, K, next_P = 2;
    cin >> N >> K;
    while (true)
    {
        int i = next_P;
        while (table[i])
            i++;
        next_P = i;
        table[i] = true;
        if (--K == 0)
        {
            cout << next_P;
            return 0;
        }

        for (int i = next_P * next_P; i <= N; i += next_P)
        {
            if (!table[i])
            {
                table[i] = true;
                if (--K == 0)
                {
                    cout << i;
                    return 0;
                }
            }
        }
    }
}