#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> cut_array(vector<int> array, int i, int j) {
    vector<int> new_vec;
    while (i <= j) {
        new_vec.push_back(array[i - 1]);
        i++;
    }
    return new_vec;
}


vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int vec_count = 0; vec_count < commands.size(); vec_count++) {
        int i = commands[vec_count][0];
        int j = commands[vec_count][1];
        int k = commands[vec_count][2];
        vector<int> temp_array = cut_array(array, i, j);
        sort(temp_array.begin(), temp_array.end());
        answer.push_back(temp_array[k - 1]);

        temp_array.clear();
    }

    return answer;
}