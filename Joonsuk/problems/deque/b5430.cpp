// 두개의 포인터가 있다. top과 bottom
// top 부터 bottom 까지의 숫자들을 출력하게 된다.
// 따라서 top과 bottom이 교차하게되면, error를 출력한다.

// 초기 순서는 top -> bottom 방향이다.
// R이 일어나면 bottom -> top 방향이 된다.

// D가 일어나면 top과 bottom중 앞의 방향에 있는 포인터를 뒤로 한칸 이동시킨다.

// 모든 명령어가 끝나면 출력한다.
// 출력은 (유효한 경우에) top 부터 bottom 까지의 substring을 복사하는 방식으로 출력한다.
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void conduct_test_case();
bool is_not_number(const char &ch);

int main() {
    int T;
    std::cin >> T;

    for (int i = 0; i != T; ++i) {
        conduct_test_case();
    }
}

void conduct_test_case() {
    std::string p, test_array;
    std::vector<int> numbers;
    int n;

    std::cin >> p >> n >> test_array;
    if (n == 0) {
        for (char ch : p) {
            if (ch == 'D') {
                std::cout << "error"
                          << "\n";
                return;
            }
        }
        std::cout << "[]"
                  << "\n";
        return;
    }

    // test_array중에 숫자를 추출해서 numbers에 저장.
    for (auto beg = test_array.begin(); beg != test_array.end(); ++beg) {
        if (!is_not_number(*beg)) {
            auto next_not_number = std::find_if(beg, test_array.end(), is_not_number);
            numbers.push_back(std::stoi(std::string(beg, next_not_number)));
            beg = next_not_number;
        }
    }

    // 후에 top 부터 bottom까지 print 할 것임.
    auto top = numbers.begin();
    auto bottom = numbers.end();

    bool is_top_to_bottom = true;
    bool is_error = false;

    for (char operation : p) {
        if (operation == 'R') {
            is_top_to_bottom = !is_top_to_bottom;
        } else {
            if (top == bottom) {
                is_error = true;
                break;
            }

            if (is_top_to_bottom)
                ++top;
            else
                --bottom;
        }
    }

    if (is_error) {
        std::cout << "error"
                  << "\n";
        return;
    }

    std::cout << "[";
    while (top != bottom) {
        if (is_top_to_bottom)
            std::cout << *top++;
        else {
            std::cout << *(bottom - 1);
            --bottom;
        }

        if (top == bottom)
            break;
        std::cout << ",";
    }
    std::cout << "]"
              << "\n";
}

bool is_not_number(const char &ch) { // , [ ] 인경우 true 반환
    if (ch != ',' && ch != '[' && ch != ']')
        return false;
    return true;
}