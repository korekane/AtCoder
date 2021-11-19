#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;

#define MAX_N 100
#define MAX_W 100

//入力
int n = 4;
int W = 5;
int w[MAX_N]={2, 1, 3, 2};
int v[MAX_N]={3, 2, 4, 2};

int dp[MAX_N + 1][MAX_W + 1];

void solve(){
    for (int  i = 0; i < n; i++){
        for (int j = 0; j < W; i++){
            if (j < w[i]){
                printf("aaa\n");
                dp[i + 1][j] = dp[i][j];
            }else{
                printf("bbb\n");
                dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
            }
        }
    }
    printf("%d\n", dp[n][W]);
}

int main(){
    solve();
    return 0;
}