#include <cstdio>
#include <queue>
using namespace std;

const int V[6] = {1,5,10,50,100,500};
//入力
int C[6] = {3,2,1,3,0,2};
int A = 620;

void solve(){
    int ans = 0;

    for (int i = 5; i >= 0; i--){
        int t = min(A/V[i],C[i]);
        A -= t*V[i];
        ans += t;
    }
    printf("%d\n",ans);
}

int main(){
    solve();
    return 0;
}