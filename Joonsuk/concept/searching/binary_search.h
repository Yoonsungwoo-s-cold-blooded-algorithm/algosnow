#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <vector>

auto binary_search(std::vector<int>::iterator beg, std::vector<int>::iterator end, int target) -> std::vector<int>::iterator {
    if (beg == end)
        return end;

    auto center = beg + (end - beg) / 2;

    if (*center == target) {
        return center;
    } else {
        if (*center > target) {
            auto result = binary_search(beg, center, target);

            if (result == center)
                return end;
            else
                return result;
        } else {
            auto result = binary_search(center + 1, end, target);

            if (result == end)
                return end;
            else
                return result;
        }
    }
}

auto non_recursive_binary_search(std::vector<int>::iterator beg, std::vector<int>::iterator end, int target) -> std::vector<int>::iterator {
    auto cannot_find = end;
    while (beg != end) {
        auto center = beg + (end - beg) / 2;

        if (*center == target)
            return center;

        if (*center > target)
            end = center;
        else
            beg = center + 1;
    }
    return cannot_find;
}

// 1 2 2 3 3 3 3 4 5 5
//       ^       ^
//     lower    upper

// target 보다 큰 첫번째 원소.
auto upper_bound(std::vector<int>::iterator beg, std::vector<int>::iterator end, int target) -> std::vector<int>::iterator {
    while (beg != end) {
        auto center = beg + (end - beg) / 2;

        if (*center == target) {
            while (*center == target)
                ++center;
            return center;
        }

        if (*center > target)
            end = center;
        else
            beg = center + 1;
    }
    // while문이 빠져나가는 경우는 2가지 밖에 존재하지 않는다. (if else 문을 거치고 나면 while조건이 검사되므로)
    // 반복문이 종료되면 end는 항상 target보다 크다(이는 target보다 큰 첫번째 원소가 된다.)
    return end;
}

// target 보다 작거나 큰 첫번째 원소.
auto lower_bound(std::vector<int>::iterator beg, std::vector<int>::iterator end, int target) -> std::vector<int>::iterator {
    while (beg != end) {
        auto center = beg + (end - beg) / 2;

        if (*center == target) {
            while (*center == target)
                --center;
            return center + 1;
        }

        if (*center > target)
            end = center;
        else
            beg = center + 1;
    }
    // while문이 빠져나가는 경우는 target과 동일한 값이 존재하지 않는 경우이다.
    // end는 항상 target보다 큰 첫번째 원소를 가리킨다.
    return end;
}

#endif