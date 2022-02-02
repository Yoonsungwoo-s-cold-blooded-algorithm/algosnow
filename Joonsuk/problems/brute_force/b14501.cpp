// 1. DP(다이나믹 프로그래밍)을 이용하기
    // k일차의 최대이익은 k일차의 작업 이익 + k+time일차의 최대 이익    vs    k-1일차의 최대 이익 중 최댓값이다.

// 2. brute force 이용하기. (DFS)
    // 수행시간이 1이 아닌 경우를 기준으로 이진트리구조를 생성할 수 있다.
    // 1일차 포함하는 경우
        // 5일차를 포함하는 경우
        // 5일차를 포함하지 않는 경우
    // 1일차를 포함하지 않는 경우
        // 2일차를 포함하는 경우
        // 2일차를 포함하지 않는 경우

    // 이렇게 구분한 이진트리의 단말노드를 하나씩 비교하는 방법으로 DFS를 수행하면 된다.

#include <iostream>
#include <vector>

struct consult {
    consult(int t, int r): time(t), revenue(r){}
    int time;
    int revenue;
};

int DFS(std::vector<consult>::iterator begin);
std::vector<consult> schedule;

int main(){
    int N;
    int input_time, input_revenue;
   
    
    std::cin >> N;

    for(int i = 0; i != N; ++i){
        std::cin >> input_time >> input_revenue;
        schedule.push_back(consult(input_time, input_revenue));
    }

    int max_revenue = DFS(schedule.begin());

    std::cout << max_revenue;
}

// begin을 포함하는 경우와 포함하지 않는 경우 중 최대 금액을 반환합니다.
// 해당 함수를 호출하기 전에 해당 일정을 수행하는 것이 가능함을 보장해야 합니다.

// begin이 end면 0을 반환한다. (루트 노드)
// begin이 1일 걸리면 DFS(+1)을 수행한다. (최적화)

// begin을 포함하는 경우 -> begin이 수행 가능한지 확인한다.
// begin을 포함하지 않는 경우 -> begin + 1의 DFS를 수행한다.
int DFS(std::vector<consult>::iterator begin){
    // 마지막 일정인 경우
    if(begin == schedule.end())
        return 0;

    // 일정이 1일 걸리는 경우
    if(begin->time == 1)
        return begin->revenue + DFS(begin + 1);
    
    int included_case_revenue = 0;
    int excluded_case_revenue = 0;
    
    // begin을 포함하는 경우
    if((schedule.end() - begin) >= begin->time){ // begin이 수행 가능일 안에 속하는가?
        auto after_schedule = (begin + begin->time);
        included_case_revenue += (begin->revenue + DFS(after_schedule));
    }

    // begin을 포함하지 않는 경우
    excluded_case_revenue = DFS(begin + 1);

    return (included_case_revenue > excluded_case_revenue) ? included_case_revenue : excluded_case_revenue;
}

