// 1. 언제 일직선인가?
// C(a, b)가 AB직선 위에 있을때

// 2. 언제 시계방향인가?
// C(a, b)가 AB직선보다 위에 있을때

// 3. 언제 반시계 방향인가?
// C(a, b)가 AB직선보다 아래에 있을때

// 직선 = 기울기(x - x1) + y1 에서 a를 대입했을때 나오는 값과 비교. 
#include <iostream>

struct COORD {
    COORD(int x, int y): pos_x(x), pos_y(y) {}
    COORD() = default;
    int pos_x;
    int pos_y;
};

struct Linear {
    COORD coord;
    COORD coord2;
    double slope;
    bool direction; // 1이면 오른쪽 방향, 0이면 왼쪽 방향
};

void relative_position_to_linear(Linear linear_equation, COORD C);

int main() {
    int x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    if(x1 != x2){
        Linear linear;
        linear.coord = COORD(x1, y1);
        linear.coord2 = COORD(x2, y2);
        linear.slope = (static_cast<double>(y2 - y1)) / (x2 - x1);
        if(x1 > x2)
            linear.direction = 0;
        else
            linear.direction = 1;

        relative_position_to_linear(linear, COORD(x3, y3));
    }
    else{ // slope가 무한대인 경우
        int answer;

        if(x1 == x3)
            answer = 0;
        else if(x1 < x3)
            answer = -1; // 위 방향이면 시계
        else
            answer = 1; // 위 방향이면 반시계

        if(y2 < y1) // 아래 방향인 경우
            answer *= -1;
        
        std::cout << answer;
    }

    
}

// slope가 무한대인 경우에 대한 예외 처리 필요.
void relative_position_to_linear(Linear linear_equation, COORD C){
    if(linear_equation.coord2.pos_x != C.pos_x){
        double slope2 = (static_cast<double>(C.pos_y - linear_equation.coord2.pos_y)) / (C.pos_x - linear_equation.coord2.pos_x); 
        if(slope2 == linear_equation.slope){
            std::cout << 0;
            return;
        }
    }

    double solution = linear_equation.slope * (C.pos_x - linear_equation.coord.pos_x) + linear_equation.coord.pos_y;
    int answer;
    if(solution > C.pos_y){ // 정방향이면 시계방향
        answer = -1;
    }
    else if(solution < C.pos_y){ // 정방향이면 반시계방향
        answer = 1;
    }
    // else{ // 직선
    //     answer = 0;
    // }

    if(!linear_equation.direction)
        answer *= -1;
    
    std::cout << answer;
}
