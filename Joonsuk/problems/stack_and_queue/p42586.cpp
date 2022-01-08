#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 모든 프로그래스를 queue에 넣는다.
// 반복문 1회당 스피드의 값 만큼 프로그래스를 갱신한다.
// 맨 앞이 100 이상이면 맨 앞이 100이 아닐때까지 pop한다. 
// pop한 개수를 answer에 push_back한다.

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    // vector는 맨 뒤 원소를 제외한 나머지 원소에 대해서 erase 연산을 수행하는데 많은 시간이 걸립니다.
    reverse(progresses.begin(), progresses.end());
    reverse(speeds.begin(), speeds.end());
    vector<int> answer;

    while(!progresses.empty()){
        for(int i = 0; i != progresses.size(); ++i){
            progresses.at(i) += speeds.at(i);
        }

        int completed_task_count = 0;
        while(progresses.back() >= 100){
            progresses.pop_back();
            ++completed_task_count;
        }

        if(completed_task_count != 0)
            answer.push_back(completed_task_count);
    }

    return answer;
}