// E * (((A + B) * C) + D) 
// 출력 : E    A B+ C* D+* -> EAB+C*D+*
// 스택 :  *((( + )* )+ )
#include <iostream>
#include <string>
using std::string;

int main() {
    string expression;
    std::cin >> expression;

    add_parentheses_to_expression(expression);
    get_postfix_expression(expression);
}

void add_parentheses_to_expression(string& expr){
    
}

void get_postfix_expression(string& expr){

}