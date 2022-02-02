#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;
    for (auto command : commands)
    {
        vector<int> sorted(array.begin() + command[0] - 1, array.begin() + command[1]);
        sort(sorted.begin(), sorted.end());
        for (auto i : sorted)
            cout << i << " ";
        cout << endl;
        answer.push_back(sorted[command[2] - 1]);
    }
    return answer;
}