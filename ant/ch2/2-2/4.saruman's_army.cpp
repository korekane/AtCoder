#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_N 100000

int N=6;
int R=10;
int X[MAX_N]={1,7,15,20,30,50};

void solve(){
    sort(X,X+N);
    
    int i = 0;
    int ans = 0;
    while(i<N){
        //sはカバーされていない一番左の点の位置
        int s = X[i++];
        //sから距離Rを超えるまで進む
        while (i<N && X[i]<=s+R){
            i++;
        }

        //pは新しく印をつける点の位置
        int p = X[i-1];
        //pから距離Rを超える点まで進む
        while(i<N&&X[i]<=p+R){
            i++;
        }
        ans++;
    }
    printf("%d\n",ans);
}

int main(){
    solve();
    return 0;
}
