// 첫번째 아이디어
// 1. 배열을 정렬한다.
// 2. 제일 작은것 2개를 합친후 적절한 위치에 삽입한다.
// 3. 제일 작은거 2개를 다시 합친후, 적절한 위치에 삽입한다.
// 4. 위 과정을 반복한다.
// -> 파일이 연속적인 것들만 병합할수 있었다... 문제를 잘 읽어보자.

// 두번째 아이디어
// 1. 리스트를 돌면서 합이 최소인 2개를 찾는다.
// 2. a, b가 있으면 a에 a+b의 값을 넣고,
// 3. b를 erase 한다..
// 4. 원소의 개수가 1개가 될 때까지 반복한다.
// -> 2번째 예제와 답이 틀리게 나오는데, 이 방법이 최소가 아니기 때문이다.
// 이는 연속적인 것들만 더할 수 있기 때문인데, 5 4 3 5 와 같은 예제에서 확인할 수 있다. (최소가 아닌것들끼리 덧셈이 일어나기 때문!)

// 세번째 아이디어
// 1. 기준이 되는 원소를 정한다.
// 2. 해당 원소가

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

int merge_files(std::list<int> &files);
auto find_sum_is_min(std::list<int>::iterator beg, std::list<int>::iterator end) -> std::list<int>::iterator;

int main() {
    int T, K;
    std::cin >> T;

    for (int i = 0; i != T; ++i) {
        std::cin >> K;
        int file_size = 0;
        std::list<int> files;

        for (int j = 0; j != K; ++j) {
            std::cin >> file_size;
            files.push_back(file_size);
        }

        int min_size = merge_files(files);
        std::cout << min_size << "\n";
    }
}

int merge_files(std::list<int> &files) {

    int min_value = 0;
    while (files.size() != 1) {
        auto first = find_sum_is_min(files.begin(), files.end());

        // list의 연산자는 산술 연산을 지원하지 않는다.
        auto second = first;
        ++second;

        *first = *second + *first;

        min_value += *first;

        files.erase(second);
    }
    return min_value;
}

auto find_sum_is_min(std::list<int>::iterator beg, std::list<int>::iterator end) -> std::list<int>::iterator {
    auto first = beg;
    auto second = ++beg;

    auto min_first = first;
    auto min_second = second;

    while (second != end) {
        if (*min_first + *min_second > *first + *second) {
            min_first = first;
            min_second = second;

            ++first;
            ++second;
        }
    }
    return min_first;
}