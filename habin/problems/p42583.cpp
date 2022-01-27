#include <string>
#include <vector>
#include <queue>
#define PII pair<int, int>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0, i = 0, j = 0, sum = 0;
    int count = 10;
    vector<PII> v;
    do
    {
        if (j < v.size())
        {
            for (int m = j; m < v.size(); ++m)
                ++(v[m].second);
            if (v[j].second == bridge_length)
                sum -= v[j++].first;
        }
        if (v.size() - j < bridge_length && i < truck_weights.size())
        {
            if (sum + truck_weights[i] <= weight)
            {
                sum += truck_weights[i];
                v.push_back({truck_weights[i++], 0});
            }
        }
        ++answer;
    } while (j < truck_weights.size());
    return answer;
}