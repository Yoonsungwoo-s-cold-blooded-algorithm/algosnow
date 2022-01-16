#include <iostream>
#include <vector>

// 핵심 아이디어: 재귀적 구조로 프린팅을 하게 되면, 필연적으로 줄 바꿈이 생기게 됨.
// 따라서 콘솔창에서 줄바꿈이 일어나게 되면 이전 줄로 갈 수 없기 때문에 (표준 라이브러리엔 없음)
// 콘솔창 대신에 배열에 프린팅을 1차적으로 한 뒤에, 2차 프린팅을 콘솔 창에 해야 한다.
char console[2187][2187] = {0};
int pos_X = 0;
int pos_Y = 0;
void print_console(int n);
void print_blank(int n);

int main() {
    int N;
    std::cin >> N;
    print_console(N);

    for(int i = 0; i != 2187; ++i){
        if(console[0][i] == 0)
            break;
        for(int j = 0; j != 2187; ++j){
            if(console[j][i] == 0)
                break;
            std::cout << console[j][i];
        }
        std::cout << "\n";
    }
}

void print_console(int n){
    int start_X = pos_X;
    int start_Y = pos_Y;

    if(n == 3){
        for(int i = 0; i != 3; ++i)
            console[start_X + i][start_Y] = '*';
        
        console[start_X][start_Y + 1] = '*';
        console[start_X + 1][start_Y + 1] = ' ';
        console[start_X + 2][start_Y + 1] = '*';

        for(int i = 0; i != 3; ++i)
            console[start_X + i][start_Y + 2] = '*';
        
        pos_X = start_X + 3;
        return;
    }

    // top
    for(int i = 0; i != 3; ++i)
        print_console(n/3);
    
    pos_X = start_X;
    pos_Y = start_Y + n/3;

    // middle
    print_console(n/3);
    print_blank(n);
    print_console(n/3);

    // bottom
    pos_X = start_X;
    pos_Y = start_Y + 2*(n/3);
    for(int i = 0; i != 3; ++i)
        print_console(n/3);
    
    pos_X = start_X + n;
    pos_Y = start_Y;
}

void print_blank(int n){
    for(int i = 0; i != n/3; ++i){
        for(int j = 0; j != n/3; ++j){
            console[pos_X + i][pos_Y + j] = ' ';
        }
    }
    pos_X += n/3;
}