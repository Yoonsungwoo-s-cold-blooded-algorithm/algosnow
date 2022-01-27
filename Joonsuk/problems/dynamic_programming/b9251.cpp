

#include <string>
#include <iostream>
void find_lcs(int a, int b);

int lcs [1000][1000];
int lcs_found [1000][1000];
std::string A, B;

int main() {
    std::cin >> A >> B;
    find_lcs(A.size()-1, B.size()-1);
    std::cout << lcs[A.size()-1][B.size()-1];
}

void find_lcs(int a, int b){
    lcs_found[a][b] = 1;
    if(a == 0 || b == 0){
        if(A[a] == B[b]){
            lcs[a][b] = 1;
        } 
        else if(a > b){
            if(lcs_found[a-1][b] == 0)
                find_lcs(a-1, b);
            lcs[a][b] = lcs[a-1][b];
        }
        else if(a < b){
            if(lcs_found[a][b-1] == 0)
                find_lcs(a, b-1);
            lcs[a][b] = lcs[a][b-1];
        }
        return;
    }

    if(A[a] == B[b]){
        if(lcs_found[a-1][b-1] == 0)
            find_lcs(a-1, b-1);
        lcs[a][b] = lcs[a-1][b-1] + 1;
    }
    else{
        if(lcs_found[a-1][b] == 0)
            find_lcs(a-1, b);
        if(lcs_found[a][b-1] == 0)
            find_lcs(a, b-1);
        
        lcs[a][b] = (lcs[a-1][b] > lcs[a][b-1]) ? (lcs[a-1][b]) : (lcs[a][b-1]);
    }
}
