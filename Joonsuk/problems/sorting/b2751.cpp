#include <iostream>
#include <vector>

void merge_sort(std::vector<int> &ivec);
void merge(std::vector<int> &ivec, int idx_beg_first, int idx_end_first, int idx_beg_second, int idx_end_second);

int main() {
    std::ios::sync_with_stdio(false);

    int N, num;
    std::cin >> N;
    std::vector<int> numbers;

    for (int i = 0; i != N; ++i) {
        std::cin >> num;
        numbers.push_back(num);
    }
    merge_sort(numbers);

    for (int i : numbers) {
        std::cout << i << "\n";
    }
}

void merge_sort(std::vector<int> &ivec) {
    // ivec의 크기가 짝수인 경우 max_gap은 size()/2까지
    // ivec의 크기가 홀수인 경우 max_gap은 size()/2 + 1까지
    int max_gap = (ivec.size() % 2 == 0) ? (ivec.size() / 2) : (ivec.size() / 2 + 1);

    for (int gap = 1; /*마지막에 처리*/; gap *= 2) {
        for (int beg = 0; beg != ivec.size(); beg += 2 * gap) {

            // case 1. 인덱스가 한개만 남았는가?
            if (beg + gap >= ivec.size()) {
                // 그냥 스킵.
                break;
            }

            // case 2. 두번째 부분 배열의 크기가 작은가?
            if (beg + gap + gap > ivec.size()) {
                // 이런경우 동일하게 merge를 수행해야 한다.
                // 두번째 배열은 beg+gap 부터 ivec.size() - 1까지의 인덱스를 가진다.
                merge(ivec, beg, beg + gap, beg + gap, ivec.size());
                break;
            }

            // 나머지 경우. 일반적인 경우.
            merge(ivec, beg, beg + gap, beg + gap, beg + (2 * gap));
        }

        if (gap >= max_gap)
            break;
    }
}

// beg1 ~ end1 까지의 부분 배열과 beg2 ~ end2 까지의 부분 배열을 merge!
void merge(std::vector<int> &ivec, int idx_beg_first, int idx_end_first, int idx_beg_second, int idx_end_second) {
    int ivec_begin = idx_beg_first;
    int ivec_end = idx_end_second;

    std::vector<int> first;
    std::vector<int> second;

    while (idx_beg_first != idx_end_first)
        first.push_back(ivec[idx_beg_first++]);
    while (idx_beg_second != idx_end_second)
        second.push_back(ivec[idx_beg_second++]);

    auto first_beg = first.begin(), first_end = first.end();
    auto second_beg = second.begin(), second_end = second.end();

    // beg 부터 end 까지 요소들을 merge 한다.
    while ((first_beg != first_end) && (second_beg != second_end)) {
        if (*first_beg < *second_beg) {
            ivec[ivec_begin++] = *first_beg++;
        } else {
            ivec[ivec_begin++] = *second_beg++;
        }
    }

    while (ivec_begin != ivec_end)
        ivec[ivec_begin++] = (first_beg != first_end) ? (*first_beg++) : (*second_beg++);
}