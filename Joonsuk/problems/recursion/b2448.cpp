#include <iostream>

char console[6143][3072] = {0};
int pos_x = 0;
int pos_y = 0;

void print_stars(int n);
inline int height(int n);
inline int width(int n);
int power_of_2(int k);

int main() {
    std::cout.sync_with_stdio(false);
    std::cout.tie(nullptr);

    int N;
    std::cin >> N;

    int start_N = N;
    pos_y = N-1;

    int k = 0;
    N /= 3;
    while((N/2) != 0){
        N /= 2;
        ++k;
    }

    print_stars(k);

    int max_col = width(k);
    for(int i = 0; i != start_N; ++i){
        for(int j = 0; j != max_col; ++j){
            if(console[j][i] == '*')
                std::cout << '*';
            else
                std::cout << ' ';
        }
        std::cout << "\n";
    }
}

void print_stars(int n){
    int start_x = pos_x;
    int start_y = pos_y;

    if(n == 0){
        console[start_x + 2][start_y - 2] = '*';

        console[start_x + 1][start_y - 1] = '*';
        console[start_x + 3][start_y - 1] = '*';
        
        for(int i = 0; i != 5; ++i)
            console[start_x + i][start_y] = '*';

        pos_x = start_x + 5; 
        return;   
    }

    print_stars(n-1);

    pos_x = start_x + (width(n-1) + 1)/2;
    pos_y = start_y - height(n-1);
    print_stars(n-1);

    pos_x = start_x + width(n-1) + 1;
    pos_y = start_y;
    print_stars(n-1);
}

inline int height(int n){
    return 3*power_of_2(n);
}

inline int width(int n){
    return 6*power_of_2(n) - 1;
}

int power_of_2(int k){
    int v = 1;
    for(int i = 0; i != k; ++i)
        v *= 2;
    return v;
}