#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer;
    // 기준 인덱스 다음의 원소 중 기준 인덱스의 값보다 작은 원소의 인덱스 구하기.
    for (int i = 0; i < prices.size(); i++)
    {
        int period = 0;
        for (int j = i + 1; j < prices.size(); j++)
        {
            ++period;
            if (prices[i] > prices[j])
                break;
        }
        answer.push_back(period);
    }
    return answer;
}