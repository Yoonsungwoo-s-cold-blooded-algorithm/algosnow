#include <iostream>
#include <vector>
#include <utility>

using std::vector;

void move(int plate, vector<int>& dest_pole);
int pole_number(vector<int>& pole);
auto find_empty_pos(vector<int>& my_pole, vector<int>& dest_pole) -> vector<int>&;
auto find_my_pole(int plate) -> vector<int>&;

vector<int> pole_1;
vector<int> pole_2;
vector<int> pole_3;
vector<std::pair<int, int>> moves;
int move_count = 0;

int main(){
    int N;
    std::cin >> N;
    for(int i = 0; i != N; ++i)
        pole_1.push_back(N - i);
    pole_2.push_back(200);
    pole_3.push_back(300);
    move(N, pole_3);

    std::cout << move_count << "\n";
    for(auto elem : moves)
        std::cout << elem.first << " " << elem.second << "\n";
}

void move(int plate, vector<int>& dest_pole){
    
    // pos = my_pos, dest_pos, empty_pos
    // move(plate - 1, empty_pos)
    // plate -> dest_pos
    // move(plate - 1, dest_pos)
    ++move_count;

    vector<int>& my_pole = find_my_pole(plate);
    vector<int>& empty_pole = find_empty_pos(my_pole, dest_pole);

    if(plate == 1){
        my_pole.pop_back();
        dest_pole.push_back(1);
        moves.push_back(std::pair<int, int>(pole_number(my_pole), pole_number(dest_pole)));
        return;
    }
    
    move(plate - 1, empty_pole);

    my_pole.pop_back();
    dest_pole.push_back(plate);
    moves.push_back(std::pair<int, int>(pole_number(my_pole), pole_number(dest_pole)));

    move(plate - 1, dest_pole);
}

int pole_number(vector<int>& pole){
    if(pole == pole_1)
        return 1;
    else if(pole == pole_2)
        return 2;
    else
        return 3;
}

// trailing return type과 참조 타입 반환의 유의점 int (*) (int, int)
auto find_empty_pos(vector<int>& my_pole, vector<int>& dest_pole) -> vector<int>& {
    if(my_pole == pole_1){
        if(dest_pole == pole_2)
            return pole_3;
        else
            return pole_2;
    }
    else if(my_pole == pole_2){
        if(dest_pole == pole_1)
            return pole_3;
        else
            return pole_1;
    }
    else{
        if(dest_pole == pole_1)
            return pole_2;
        else
            return pole_1;
    }
}

auto find_my_pole(int plate) -> vector<int>& {
    for(auto beg = pole_1.begin(); beg != pole_1.end(); ++beg){
        if(*beg == plate)
            return pole_1;
    }
    for(auto beg = pole_2.begin(); beg != pole_2.end(); ++beg){
        if(*beg == plate)
            return pole_2;
    }
    for(auto beg = pole_3.begin(); beg != pole_3.end(); ++beg){
        if(*beg == plate)
            return pole_3;
    }
}