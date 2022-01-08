#include <vector>
#include <stack>

using namespace std;

struct Stock {
    Stock(int p, int pos): price(p), position(pos) {} 

    int price = 0;
    int position = 0; // pop 될 때, 현재 pos - position을 구하면 answer를 구할 수 있다.
};

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<Stock> stack;
    for(int i = 0; i != prices.size(); ++i){
        int current_price = prices.at(i);
        if(stack.empty() || stack.top().price <= current_price){
            stack.push(Stock(current_price, i));
        }
        else{
            while(!stack.empty() && stack.top().price > current_price){
                answer.at(stack.top().position) = i - stack.top().position;
                stack.pop();
            }
            stack.push(Stock(current_price, i));
        }
    }

    while(!stack.empty()){
        Stock stock = stack.top();
        answer.at(stack.top().position) = prices.size() - 1 - stack.top().position;
        stack.pop();
    }

    return answer;
}

int main(){
    solution({1, 2, 3, 2, 3});
}