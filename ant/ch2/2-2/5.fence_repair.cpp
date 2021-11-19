#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_N 100000

typedef long long ll;
//typedef long long : 超巨大な整数値でも扱えるようにする定義

//入力
int N = 3;
int L[MAX_N] = {8,5,8};

void solve(){
    ll ans = 0;

    while(N > 1){
        int mii1 = 0;
        int mii2 = 1;
        //L[mii1] > L[mii2]ならmii1とmii2の値を入れ替える
        if(L[mii1] > L[mii2]){
            swap(mii1, mii2);
        }

        for (int i = 2; i<N; i++){
            if(L[i] < L[mii1]){
                mii2 = mii1;
                mii1 = i;
            }
            else if(L[i] < L[mii2]){
                mii2 = i;
            }
        }
        
        //それらを結合
        int t = L[mii1] + L[mii2];
        ans += t;

        if (mii1 == N - 1){
            swap(mii1, mii2);
        }
        L[mii1] = t;
        L[mii2] = L[N - 1];
        N--;
    }

    printf("%d\n", ans);
}

int main(){
    solve();
    return 0;
}