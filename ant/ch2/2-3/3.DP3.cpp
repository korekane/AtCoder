#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;
#define MAX_N 10000
#define MAX_W 10000

//入力
int n = 4, W = 5;
int w[MAX_N]={2, 1, 3, 2}, v[MAX_N]={3, 2, 4, 2};

int dp[MAX_N + 1][MAX_W + 1];

void solve(){
    for (int i = n - 1; i >= 0; i--){
        for (int j = 0; j <= W; j++){
            if (j < w[i]){
                dp[i][j] = dp[i + 1][j];
            }else{
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
            }
        }
    }
    printf("%d\n",dp[0][W]);
}

int main(){
    solve();
    return 0;
}