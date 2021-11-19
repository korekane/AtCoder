#include <cstdio>
#include <string.h>
#include <queue>

using namespace std;
#define MAX_N 100

//入力
int N =4, L = 25, P = 10;
int A[MAX_N+1] = {10, 14, 20, 21};
int B[MAX_N+1] = {10,5,2,4};

void solve(){
    //簡単のためにゴールをガソリンスタンドに追加
    A[N] = L;
    B[N] = 0;
    N++;

    //ガソリンスタンドを管理するための順位キュー
    priority_queue<int> que;

    //ans : 補給回数，pos : 今いる場所，tank : タンクのガソリン量
    int ans = 0, pos = 0, tank = P;

    for (int i = 0 ; i < N ; i++){
        //次に進む距離
        int d = A[i] - pos;

        //十分な量になるまでガソリンを補給
        while(tank - d < 0){
            //次に進む距離
            if (que.empty()){
                puts("-1");
                return;
            }
            tank += que.top();
            que.pop();
            ans++;
        }
        tank -= d;
        pos = A[i];
        que.push(B[i]);
    }
    printf("%d\n", ans);
}

int main(){
    solve();
    return 0;
}