// 1. 배열을 정렬한다.
// 한 원소에서 뒤에는 원소로 이동하는 DFS를 구현한다.
// DFS로 찾은 암호가 모음이 없거나, 자음이 1개 이하라면 값을 버리고,
// 그렇지 않다면 출력한다.
#include <algorithm>
#include <iostream>
#include <string>

void DFS(int key);
bool check_password_validity();
int count_vowel();

int L, C;
char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
std::string password;
std::string alphabets;

int main() {
    std::ios::sync_with_stdio(false);

    std::cin >> L >> C;
    char input;
    for (int i = 0; i != C; ++i) {
        std::cin >> input;
        alphabets.push_back(input);
    }
    std::sort(alphabets.begin(), alphabets.end());

    for (int i = 0; i != C; ++i) {
        DFS(i);
    }
}

void DFS(int key) { // key값의 알파벳을 password에 추가하고, 다음 DFS를 수행한다.
    password.push_back(alphabets[key]);

    if (password.size() == L) { // 암호가 다 만들어진 경우
        bool is_valid = check_password_validity();
        if (is_valid)
            std::cout << password << "\n";

        password.pop_back();
        return;
    }

    // 가능성 없는 DFS를 하는 경우를 걸러내야 수행속도가 빠르다.
    for (int i = key + 1; i < C; ++i) {
        // 추가로 필요한 password의 길이보다 key+1 부터 마지막 원소까지의 개수가 더 적다면 break;
        if ((L - password.size()) > (C - i))
            break;

        DFS(i);
    }

    password.pop_back(); // password는 전역 변수이므로 이전 상태로 복귀해야 한다. (DFS)
}

bool check_password_validity() {
    int vowel_count = count_vowel();

    if (vowel_count > 0 && (password.size() - vowel_count) > 1)
        return true;
    else
        return false;
}

int count_vowel() {
    int count = 0;
    for (int i = 0; i != 5; ++i) {
        if (password.find(vowels[i]) != std::string::npos)
            ++count;
    }
    return count;
}