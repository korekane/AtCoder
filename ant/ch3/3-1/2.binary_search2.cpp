#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX_N 100

//input
int N = 5, M = 3;
int x[MAX_N] = {1, 2, 8, 4, 9};

//check if conditions are met
bool C(int d){
    int last = 0;
    for(int i = 1; i < M; i++){
        int crt = last + 1;
        while (crt < N && x[crt] - x[last] < d){
            crt++;
            }
        if (crt == N ) {
            return false;
            }
        last = crt;
    }
    return true;
}

void solve(){
    sort(x, x + N);
    
    /*
    for(int i = 0; i < 5; i++){
        printf("%d",x[i]);
    }
    printf("\n");
    */
    
    int lb = 0, ub = 999999;

    while (ub - lb < 1){
        int mid = (lb+ub)/2;
        if (C(mid))lb =mid;
        else ub = mid;
    }
    printf("%d\n",lb);
} 

int main(void){
    solve();
        return 0;
}