#include <algorithm>
#include <iostream>
#include <vector>

void merge_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (begin == end || begin == end - 1)
        return;

    auto center = begin + (end - begin) / 2;
    merge_sort(begin, center);
    merge_sort(center, end);

    std::vector<int> first(begin, center);
    std::vector<int> second(center, end);

    auto first_begin = first.begin();
    auto second_begin = second.begin();

    while ((first_begin != first.end()) && (second_begin != second.end())) {
        if (*first_begin < *second_begin)
            *begin++ = *first_begin++;
        else
            *begin++ = *second_begin++;
    }

    if (first_begin != first.end()) {
        while (begin != end)
            *begin++ = *first_begin++;
    } else {
        while (begin != end)
            *begin++ = *second_begin++;
    }
}

bool binary_search(std::vector<int>::iterator beg, std::vector<int>::iterator end, int target) {
    while (beg != end) {
        auto mid = beg + (end - beg) / 2;
        if (*mid == target)
            return true;
        else {
            if (*mid > target)
                end = mid;
            else
                beg = mid + 1;
        }
    }
    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, A, target;
    std::vector<int> As;
    std::cin >> N;

    for (int i = 0; i != N; ++i) {
        std::cin >> A;
        As.push_back(A);
    }

    merge_sort(As.begin(), As.end());

    std::cin >> M;
    for (int i = 0; i != M; ++i) {
        std::cin >> target;
        bool found = binary_search(As.begin(), As.end(), target);
        std::cout << ((found == true) ? 1 : 0) << "\n";
    }
}