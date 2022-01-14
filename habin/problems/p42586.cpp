#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    int start = 0;
    while (progresses.size() > start)
    {
        int count = 0;
        for (int i = start; i < progresses.size(); ++i)
            progresses[i] += speeds[i];
        for (int i = start; progresses[i] >= 100;)
        {
            ++count;
            if (++i >= progresses.size())
                break;
        }
        if (count)
        {
            answer.push_back(count);
            start += count;
        }
    }
    return answer;
}