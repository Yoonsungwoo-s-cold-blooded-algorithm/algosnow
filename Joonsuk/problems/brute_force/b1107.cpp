// 해당 채널로 도달하는 방법은 2가지이다.
// 1. 숫자를 눌러서 이동한 후에, +,-로 이동하기.
// 2. 현재 채널인 100채널에서 +,-로 이동하기.

// 사용가능한 숫자를 담은 배열이 있다고 하자. 예) 0,1,2,3만 있는 배열
// 원하는 채널의 자릿수를 구한다. 예) 428
// 맨 첫번째 자리수도 0이 가능하다고 하자. (후에 처리)

#include <iostream>
#include <vector>

void brute_force(int level);
void conduct_case();
int get_digit_size(int num);

int min_press, target_channel;
std::vector<int> test_case;
std::vector<int> available_numbers;

int main() {
    int N, M;
    std::vector<int> broken_numbers;
    std::cin >> N >> M;
    target_channel = N;
    for (int i = 0; i != M; ++i) {
        int broken_number;
        std::cin >> broken_number;
        broken_numbers.push_back(broken_number);
    }

    for (int i = 0; i != 10; ++i) {
        available_numbers.push_back(i);
        for (int broken : broken_numbers) {
            if (i == broken) {
                available_numbers.pop_back();
                break;
            }
        }
    }

    // 100에서 +,-로 이동한 횟수를 min_press의 초기화에 사용

    bool inavailable_zero = false;
    // 0이 available하지 않을때, 적은 digit의 숫자를 만들수 없는 문제가 발생.
    for (int inavailable : broken_numbers) {
        if (inavailable == 0) {
            inavailable_zero = true;
        }
    }

    // 0이 available 할때는 문제 x
    min_press = (N > 100) ? (N - 100) : (100 - N);
    int digit_of_N = get_digit_size(target_channel);
    int initial_level = (digit_of_N == 6) ? 6 : (digit_of_N + 1);

    if (inavailable_zero) {
        for (int i = 1; i != initial_level + 1; ++i)
            brute_force(i);
    } else
        brute_force(initial_level);
    std::cout << min_press;
}

// 백의 자리면 level = 3.
void brute_force(int level) {
    for (int num : available_numbers) {
        test_case.push_back(num);
        if (level == 1)
            conduct_case();
        else
            brute_force(level - 1);
        test_case.pop_back();
    }
}

void conduct_case() {
    int test_number = 0;
    for (int i = 0; i != test_case.size(); ++i) {
        test_number = (test_number * 10) + test_case[i];
    }

    if (test_number > target_channel) {
        // 숫자 번호를 누르는 횟수와 +,-를 누르는 횟수를 더한 값이 누르는 횟수이다.
        if (get_digit_size(test_number) + (test_number - target_channel) < min_press) {
            min_press = get_digit_size(test_number) + (test_number - target_channel);
        }
    } else if (test_number < target_channel) {
        if (get_digit_size(test_number) + (target_channel - test_number) < min_press) {
            min_press = get_digit_size(test_number) + (target_channel - test_number);
        }
    } else {
        if (get_digit_size(test_number) < min_press) {
            min_press = get_digit_size(test_number);
        }
    }
}

int get_digit_size(int num) {
    int digit = 0;

    if (num == 0)
        return 1;

    while (num != 0) {
        num /= 10;
        ++digit;
    }
    return digit;
}