#include <iostream>
#include <vector>

int get_lower_bound(int beg, int end, int max_budget);
void merge_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end);
int calculate_budget(int upper_budget);

std::vector<int> budgets;
int main() {
    int N, budget, M;

    std::cin >> N;
    for (int i = 0; i != N; ++i) {
        std::cin >> budget;
        budgets.push_back(budget);
    }
    std::cin >> M;

    merge_sort(budgets.begin(), budgets.end());

    int average_budget = M / N;
    if (average_budget > budgets.back()) {
        std::cout << budgets.back();
    } else {
        int answer = get_lower_bound(average_budget, budgets.back() + 1, M);
        std::cout << answer;
    }
}

int get_lower_bound(int beg, int end, int max_budget) {
    while (beg != end) {
        int center = beg + (end - beg) / 2; // 현재 상한가격

        if (max_budget == calculate_budget(center)) { // 현재 상한가로 계산한 예산이 최대 예산과 동일하면
            return center;
        } else if (max_budget > calculate_budget(center)) {
            // 예산이 남는 경우.
            beg = center + 1;
        } else {
            // 예산이 부족한 경우
            end = center;
        }
    }
    return (end - 1);
}

int calculate_budget(int upper_budget) {
    int sum = 0;
    for (int i = 0; i != budgets.size(); ++i) {
        if (budgets[i] < upper_budget) {
            sum += budgets[i];
        } else {
            sum += (budgets.size() - i) * upper_budget;
            break;
        }
    }
    return sum;
}

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
