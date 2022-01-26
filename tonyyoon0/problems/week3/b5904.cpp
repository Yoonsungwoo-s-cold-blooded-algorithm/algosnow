#include <iostream>

// S(n)의 문자 수를 세는 함수
int letter_count(int n) {
    if (n == 0) return 3;
    else return 2 * letter_count(n - 1) + (n + 3);
}

char s0[3] = {'m', 'o', 'o'};

char m_check(int count, int n) {
    
    if (n <= 3) return s0[n - 1];
    else if (n <= letter_count(count - 1)) {
        return m_check(count - 1, n);
    }
    else if (n < letter_count(count - 1) + (count + 4)) {
        if (n == letter_count(count - 1) + 1) return 'm';
        else return 'o';
    }
    else {
        return m_check(count - 1, n - letter_count(count - 1) - (count + 3));
    }
}

int main() {
    int N;
    std::cin >> N;
    int count = 0;

    while (letter_count(count) <= N) {
        count++;
    }

    std::cout << m_check(count, N);

    return 0;
}