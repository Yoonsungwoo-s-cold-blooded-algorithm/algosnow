
// main point = 어떻게 연산들의 조합을 생성할 것인가?
// 조합만 제한시간을 만족하면서 만들어 낼 수 있다면, 이후에는 b10819와 동일하게 구할 수 있다.

// 4번 반복 고정 -> 연산자가 4개뿐.
// for문의 한번의 회차에서 insert가 여러번 일어난다. 하지만 insert의 가능한 자리는 변하지 않는다.

// ----------------------------------- 1번 방법 --------------------------
// + 연산자를 combination에 insert 한다고 하자.
// 가능한 자리는 combination.size()+1 만큼 존재한다.

// 어디에 얼마만큼을 insert 할지를 결정해야 한다. (총 insert 해야하는 연산자 수는 operator_count[n]을 통해 가져온다)

// 조합의 경우의 수 대신에, '(자리수)^넣을 개수' 의 경우의 수를 가진 vector를 가져온다.
// 해당 벡터 안 원소의 값 만큼을, 해당 위치에 insert 한다고 가정하자.
// 0 0 0 1 4 0 이면   combination 벡터의 4,5번째에 각각 1개, 4개의 + 연산자를 insert 하겠다는 것이다.
// 해당 vector는 이전 vector의 정보를 저장하고 있으므로 다음 vector를 이전 vector를 기반으로 가져온다.

// 해당 insert가 끝나면 다음 연산자를 insert 한다.

// 마지막 연산자의 insert가 끝나면 해당 연산자 조합을 바탕으로 값을 계산하여 max와 min을 갱신한다.

// 경우의 수 벡터를 가져오는 것 부터 다음 연산자를 insert하는 과정은 몇번 일어나는가?
// -> 경우의 수 벡터의 총 경우의 수 : '(자리수)^넣을 개수'

// ------------------------------------2번 방법 -------------------------------
// 제일 많을 걸 깐다.
// 나머지로 순열을 만든다.

#include <iostream>
#include <vector>
#include <deque>

// 제일 많은 순서대로 1 1 1 2 2 3 4 로 queue가 존재한다고 하자.
// 맨 앞의 숫자가 insert할 숫자가 된다.
// vector에 모든 곳에 insert 시도한다.
// insert 했을때, 끝이 아니면 재귀 호출
// 끝이라면 계산후, 결과에 따른 처리

std::vector<int> operators_inserted;
std::vector<int> operators_left;
std::deque<int> numbers_original;

int operator_count[4];
bool first_calculation = true;
int total_max;
int total_min;

void insertion(int n);
int calculate(int n);
int arithmetic(int a, int b, int operator_number);
int find_biggest();
void init_operator_left(int idx);

int main()
{
    int N, A, count;
    std::cin >> N;

    for (int i = 0; i != N; ++i)
    {
        std::cin >> A;
        numbers_original.push_back(A);
    }

    for (int i = 0; i != 4; ++i)
    {
        std::cin >> count;
        operator_count[i] = count;
    }

    int biggest_idx = find_biggest(); // 제일 많은 연산자의 idx
    for (int i = 0; i != operator_count[biggest_idx]; ++i)
    {
        operators_inserted.push_back(biggest_idx);
        operators_left.push_back(biggest_idx);
    }

    init_operator_left(biggest_idx);
    if (operators_left.size() != operator_count[biggest_idx])
        insertion(operator_count[biggest_idx]); // 6개면, 6부터 시작
    else
    {
        int calculation_result = calculate(operator_count[biggest_idx] - 1);
        total_max = calculation_result;
        total_min = calculation_result;
    }

    std::cout << total_max << "\n"
              << total_min;
}

int find_biggest()
{
    int tmp1 = (operator_count[0] > operator_count[1]) ? 0 : 1;
    int tmp2 = (operator_count[2] > operator_count[3]) ? 2 : 3;

    return (operator_count[tmp1] > operator_count[tmp2]) ? tmp1 : tmp2;
}

void init_operator_left(int idx)
{
    for (int i = 0; i != 4; ++i)
    {
        if (i != idx)
        {
            for (int j = 0; j != operator_count[i]; ++j)
            {
                operators_left.push_back(i);
            }
        }
    }
}

void insertion(int n)
{ // index가 n인 요소의 insertion
    int target = operators_left[n];

    auto old_state = operators_inserted;
    for (int i = 0; i != operators_inserted.size() + 1; ++i)
    {
        operators_inserted.insert(operators_inserted.begin() + i, target);

        if (n == operators_left.size() - 1)
        {
            int calculation_result = calculate(n);

            if (first_calculation)
            {
                total_max = calculation_result;
                total_min = calculation_result;
                first_calculation = false;
            }
            else
            {
                if (calculation_result > total_max)
                    total_max = calculation_result;
                if (calculation_result < total_min)
                    total_min = calculation_result;
            }
        }
        else
        {
            insertion(n + 1);
        }

        operators_inserted = old_state;
    }
}

int calculate(int n) // 마지막 요소의 인덱스
{
    std::deque<int> numbers = numbers_original;
    for (int i = 0; i != n + 1; ++i)
    { // n+1번 수행 (n == 연산자 개수-1)
        int first = numbers.front();
        numbers.pop_front();

        int second = numbers.front();
        numbers.pop_front();

        int operator_number = operators_inserted[i];

        numbers.push_front(arithmetic(first, second, operator_number));
    }
    return numbers.front();
}

int arithmetic(int a, int b, int operator_number)
{
    switch (operator_number)
    {
    case 0:
        return a + b;
    case 1:
        return a - b;
    case 2:
        return a * b;
    case 3:
        return a / b;
    default:
        break;
    }
}