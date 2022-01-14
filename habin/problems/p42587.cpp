#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int &dest = priorities[location];
    priority_queue<int> pq(priorities.begin(), priorities.end());

    int answer = 0;
    while (!pq.empty())
    {
        int i = priorities.front();
        if (i == pq.top())
        {
            ++answer;
            if (location == 0)
                break;
            else
            {
                priorities.erase(priorities.begin());
                pq.pop();
                --location;
            }
        }
        else
        {
            if (location == 0)
                location = priorities.size() - 1;
            else
                --location;
            priorities.push_back(priorities.front());
            priorities.erase(priorities.begin());
        }
    }
    return answer;
}