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

#endif