#include <iostream>
#include <stack>
#include <utility>
#define PII pair<int, int>
using namespace std;

// + - * /

int Operator(int a, int b, int op)
{
    if (op == 0)
        return a + b;
    if (op == 1)
        return a - b;
    if (op == 2)
        return a * b;
    if (op == 3)
        return a / b;
    cout << "error!" << endl;
    return INT32_MAX;
}

void Pass(int *num, int *op, int curr_result, int level, int N, int &max, int &min)
{
    if (level < N)
    {
        for (int op_index = 0; op_index < 4; ++op_index)
        {
            if (op[op_index])
            {
                --op[op_index];
                int next_result = Operator(curr_result, num[level], op_index);
                Pass(num, op, next_result, level + 1, N, max, min);
                ++op[op_index];
            }
        }
    }
    else
    {
        if (curr_result > max)
            max = curr_result;
        if (curr_result < min)
            min = curr_result;
    }
}

PII Solution(int *num, int *op, int N)
{
    int max = INT32_MIN;
    int min = INT32_MAX;
    Pass(num, op, num[0], 1, N, max, min);
    return PII(max, min);
}

int main()
{
    int N;
    int num[11];
    int op[4];
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> num[i];
    for (int i = 0; i < 4; ++i)
        cin >> op[i];
    PII ans = Solution(num, op, N); // first: max, second: min
    cout << ans.first << '\n'
         << ans.second;
}