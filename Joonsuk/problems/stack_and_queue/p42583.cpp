#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
int bridge_weight(const deque<int>& bridge);
int trucks_on_bridge(const deque<int>& bridge);

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    reverse(truck_weights.begin(), truck_weights.end());
    deque<int> bridge(bridge_length, 0);
    int answer = 0;

    while(!truck_weights.empty()){
        if((bridge_length >= trucks_on_bridge(bridge)) && (weight >= bridge_weight(bridge) + truck_weights.back())){
            int next_truck = truck_weights.back();
            truck_weights.pop_back();

            bridge.push_back(next_truck);
            bridge.pop_front();
        } 
        else{
            bridge.push_back(0);
            bridge.pop_front();
        }
        ++answer;
    }

    while(trucks_on_bridge(bridge) != 0){
        bridge.push_back(0);
        bridge.pop_front();
        ++answer;
    }

    return answer;
}

// 마지막 차의 무게는 세지 않는다.
int bridge_weight(const deque<int>& bridge) {
    int total_weight = 0;
    for(int weight : bridge)
        total_weight += weight;
    
    total_weight -= bridge.front();
    return total_weight;
}

// 마지막 차까지 센다.
int trucks_on_bridge(const deque<int>& bridge){
    int total_trucks = 0;
    for(int weight : bridge){
        if(weight != 0)
            ++total_trucks;
    }
    return total_trucks;
}