#include <iostream>
#include <string>
#include <vector>

int main(){
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    std::vector<int> queue(2000000);
    auto first = queue.begin();
    auto last = queue.begin();

    std::string command = "";
    for(int i = 0; i != N; ++i){
        std::cin >> command;
        if (command == "push"){
            int input;
            std::cin >> input;
            *last = input;
            ++last;
        }
        else if (command == "pop"){
            if(first == last)
                std::cout << -1 << "\n";
            else {
                std::cout << *first << "\n";
                ++first;
            }
        }
        else if (command == "empty"){
            if(first == last)
                std::cout << 1 << "\n";
            else   
                std::cout << 0 << "\n";
        }
        else if (command == "size"){
            std::cout << last - first << "\n";
        }
        else if (command == "front"){
            if(first == last)
                std::cout << -1 << "\n";
            else
                std::cout << *first << "\n";
        }
        else if (command == "back"){
            if(first == last)
                std::cout << -1 << "\n";
            else
                std::cout << *(last - 1) << "\n";
        }
    }
}