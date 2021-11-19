#include <cstdio>
#include <string.h>
#include <queue>

using namespace std;

#define MAX_N 100000

typedef long long ll;

//入力
int N = 3;
int L[MAX_N] = {8,5,8};

void solve(){
    ll ans = 0;

    //順位キューを用意(小さい値から出てくるように)
    priority_queue<int, vector<int>, greater<int> > que;
    for (int i = 0; i < N; i++){
        que.push(L[i]);
    }

    //板が一枚になるんで適用
    while(que.size()>1){
        //一番短い板，次に短い板を取り出す
        int l1,l2;
        l1 = que.top();
        que.pop();
        l2 = que.top();
        que.pop();

        //それらを併合
        ans += l1+l2;
        que.push(l1+l2);
    }
    printf("%lld\n",ans);
} 

int main(){
    solve();
    return 0;
}