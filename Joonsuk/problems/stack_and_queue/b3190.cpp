#include <iostream>
#include <deque>
#include <vector>
#include <utility>

using COORD = std::pair<int, int>;
using DIRECTION = std::pair<int, char>;

void move_head(std::deque<COORD>& snake, char direction);
bool check_game_over(std::deque<COORD>& snake, int board_size);
char check_direction_change(char current_direction, std::deque<DIRECTION>& directions, int time);
char switch_direction(char current, char rotate);
bool check_snake_ate_apple(std::deque<COORD>& snake, std::vector<COORD>& apples);

int main() {
    int N, K, L;
    int time_elapsed = 0;
    char snake_direction = 'r'; // u, d, r, l 순서대로 위 아래 오른쪽 왼쪽 
    std::vector<COORD> apples;
    std::deque<COORD> snake; 
    std::deque<DIRECTION> directions;

    std::cin >> N;

    std::cin >> K;
    for(int i = 0; i != K; ++i){
        int pos_x, pos_y;
        std::cin >> pos_x >> pos_y;

        apples.push_back(COORD(pos_x, pos_y));
    }

    std::cin >> L;
    for(int i = 0; i != L; ++i){
        int time;
        char direction;
        std::cin >> time >> direction;

        directions.push_back(DIRECTION(time, direction));
    }

    snake.push_front(COORD(1, 1));
    while (true)
    {
        // 1. 지정 방향으로 머리를 옮긴다. - push COORD
            // 2-1. 머리가 충돌 지점이면 게임 종료
            // 2-2. 머리가 방향 전환 지점이면 방향을 변경
                // - direction에서 pop
        
        // 3-1. 머리에 사과가 없으면 꼬리 이동 - pop
        // 3-2. 머리에 사과가 있으면 꼬리 이동 x

        move_head(snake, snake_direction);
        ++time_elapsed;

        bool isOver = check_game_over(snake, N);
        if(isOver)
            break;

        snake_direction = check_direction_change(snake_direction, directions, time_elapsed);

        bool ate_apple = check_snake_ate_apple(snake, apples);

        if(!ate_apple)
            snake.pop_back();   
    }

    std::cout << time_elapsed;
    
}

void move_head(std::deque<COORD>& snake, char direction){
    COORD head_coord = snake.front();
    switch (direction)
    {
    case 'u':
        head_coord = COORD(head_coord.first - 1, head_coord.second);
        break;
    case 'd':
        head_coord = COORD(head_coord.first + 1, head_coord.second);
        break;
    case 'r':
        head_coord = COORD(head_coord.first, head_coord.second + 1);
        break;
    case 'l':
        head_coord = COORD(head_coord.first, head_coord.second - 1);
        break;
    default:
        break;
    }
    snake.push_front(head_coord);
}

bool check_game_over(std::deque<COORD>& snake, int board_size){
    COORD snake_head = snake.front();

    // 1. 벽에 부딪혀서 게임 오버인가?
    if(snake_head.first == 0 || snake_head.second == 0)
        return true;
    if(snake_head.first == board_size+1 || snake_head.second == board_size+1)
        return true;
    
    // 2. 자기 몸에 부딪혀서 게임 오버인가? 
    if(snake.size() == 1)
        return false;
    for(auto beg = snake.cbegin() + 1; beg != snake.cend(); ++beg){ // 예외 처리시 beg += 2 가능
        if(*beg == snake_head)
            return true;
    }

    return false;
}

char check_direction_change(char current_direction, std::deque<DIRECTION>& directions, int time){
    if(time != directions.front().first)
        return current_direction;
    
    char rotation = directions.front().second;
    char new_direction = switch_direction(current_direction, rotation);

    directions.pop_front();
    return new_direction;
}

char switch_direction(char current, char rotate){
    switch (current)
    {
    case 'u':
        if(rotate == 'L')
            current = 'l';
        else
            current = 'r';
        break;
    case 'd':
        if(rotate == 'L')
            current = 'r';
        else
            current = 'l';
        break;
    case 'r':
        if(rotate == 'L')
            current = 'u';
        else
            current = 'd';
        break;
    case 'l':
        if(rotate == 'L')
            current = 'd';
        else
            current = 'u';
        break;
    default:
        break;
    }
    return current;
}

bool check_snake_ate_apple(std::deque<COORD>& snake, std::vector<COORD>& apples){
    COORD snake_head = snake.front();
    for(COORD& apple : apples){
        if(apple == snake_head){
            apple.first = -1;
            apple.second = -1;
            return true;
        }
    }
    return false;
}