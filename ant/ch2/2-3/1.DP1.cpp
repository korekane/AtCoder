#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_N 100000

//入力
int n = 4;//商品数
int W = 5;//許容重さ
int w[MAX_N]={2, 1, 3, 2};//重さ
int v[MAX_N]={3, 2, 4, 2};//価値

//i番目以降の品物から重さから重さの総和がj以下となるように選ぶ
//入力 i : 商品の識別番号
//入力 j : その時点での許容できる重さ
int rec(int i, int j){
    int res; 
    if (i == n){
        //品物は残っていない
        res = 0;
    }else if (j < w[i]){
        //この品物は入らない
        res = rec(i + 1, j);
    }else{
        //入れない場合と入れる場合を両方試す
        res = max(rec(i+1,j), rec(i+1,j-w[i])+v[i]);
    }
    return res;
}

void solve(){
    printf("%d\n", rec(0,W));
}

int main(){
    solve();
    return 0;
}