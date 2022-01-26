#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int idx = 0;
    while (progresses.size() > idx) {
        while (progresses[idx] < 100) {
            for (int i = idx; i < progresses.size(); i++) {
                progresses[i] += speeds[i];
            }
        }

        int count = 0;
        for (int i = idx; i < progresses.size(); i++) {
            if (progresses[i] >= 100) count++;
            else break;
        }
        if (count) {
            answer.push_back(count);
            idx += count;
        }
    }

    return answer;
}