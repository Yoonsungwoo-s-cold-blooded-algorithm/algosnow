#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> svec;

    std::string user_input;
    do {
        std::cin >> user_input;
        svec.push_back(user_input);
    } while(user_input != "0");
    svec.pop_back(); // 0은 출력 결과에 포함하지 않음

    for(std::string s : svec){
        bool yes = true;
        
        auto beg = s.begin();
        auto end = s.end();
        for(int i = 0; i != s.size() / 2; ++i) {
            if(*(beg + i) != *(end - i - 1)){
                yes = false;
                break;
            }
        }

        if(yes)
            std::cout << "yes" << std::endl;
        else
            std::cout << "no" << std::endl;
    }
}