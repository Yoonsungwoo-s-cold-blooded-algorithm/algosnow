#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    reverse(progresses.begin(), progresses.end());
    reverse(speeds.begin(), speeds.end());

    while (!(progresses.empty())) {
        while (progresses.back() < 100) {
            for (int i = 0; i < progresses.size(); i++) {
                progresses[i] += speeds[i];
            }
        }
        int count = 0;
        while (progresses.back() >= 100) {
            progresses.pop_back();
            speeds.pop_back();
            count++;
        }
        answer.push_back(count);
    }

    return answer;
}

// 시간 초과