#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;

#define MAX_N 1000
#define MAX_W 1000

//入力
int n = 4;
int W = 5;
int w[MAX_N]={2, 1, 3, 2};
int v[MAX_N]={3, 2, 4, 2};

int dp[MAX_N + 1][MAX_W + 1];

//i番目以降の品物から重さから重さの総和がj以下となるように選ぶ
//入力 i : 商品の識別番号
//入力 j : その時点での許容できる重さ
int rec(int i, int j) {
    if (dp[i][j] >= 0){
        //すでに調べたことがあるならその結果を再利用
        return dp[i][j];
    }
    int res;
    if (i == n){
        //品物は残っていない
        res = 0;
    }else if(j < w[i]){
        //この品物は入らない　→　次の要素
        res = rec(i + 1, j);
    }else{
        //入れない場合と入れる場合を両方試す
        res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
    }
    //結果をテーブルに記録
    return dp[i][j] = res;
}

void solve(){
    //memset(対象，埋め尽くす要素，埋め尽くす範囲) : メモリを指定された文字で埋め尽くす
    memset(dp, -1, sizeof(dp));
    printf("%d\n", rec(0, W));
}

int main(){
    solve();
    return 0;
}