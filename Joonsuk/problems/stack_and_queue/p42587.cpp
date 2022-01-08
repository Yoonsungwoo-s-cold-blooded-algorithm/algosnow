#include <string>
#include <vector>
#include <algorithm>

using namespace std;
void pop_last_and_push_to_first(vector<int>& vec);
bool last_is_highest(vector<int> vec);

int solution(vector<int> priorities, int location) {
    reverse(priorities.begin(), priorities.end());
    int answer = 0;

    while(location != -1){
        if(last_is_highest(priorities)){
            priorities.pop_back();
            ++answer;
        }
        else {
            pop_last_and_push_to_first(priorities);
        }
        
        if(location == 0)
            location = priorities.size() - 1;
        else
            --location;
    }

    return answer;
}

void pop_last_and_push_to_first(vector<int>& vec){
    vec.insert(vec.begin(), vec.back());
    vec.pop_back();
}

bool last_is_highest(vector<int> vec){
    int last = vec.back();
    for(int curr : vec){
        if(curr > last)
            return false;
    }
    return true;
}