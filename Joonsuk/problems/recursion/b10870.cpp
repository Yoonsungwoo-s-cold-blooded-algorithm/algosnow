#include <iostream>

int F(int n_th); 
int main() {
    int n;
    std::cin >> n;

    std::cout << F(n) << "\n";
}

int F(int n_th) {
    if(n_th == 0)
        return 0;
    if(n_th == 1)
        return 1;
    
    return F(n_th - 1) + F(n_th - 2);
}