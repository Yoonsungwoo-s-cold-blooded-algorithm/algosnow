// 2진 탐색 문제, 정렬 문제
#include <iostream>
#include <map>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::map<int, int> number_cards;
    
    std::cin >> N;
    for(int i = 0; i != N; ++i){
        int tmp;
        std::cin >> tmp;
        ++number_cards[tmp];
    }

    std::cin >> M;
    for(int i = 0; i != M; ++i){
        int tmp;
        std::cin >> tmp;

        auto it = number_cards.find(tmp);
        if(it == number_cards.end())
            std::cout << "0 ";
        else
            std::cout << number_cards[tmp] << " ";
    }
}

