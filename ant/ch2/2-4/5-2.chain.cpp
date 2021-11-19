#include <cstdio>
#include <string.h>

using namespace std;
#define MAX_N 100000
#define MAX_K 100000

int par[MAX_N]; //親
int rank[MAX_N]; //深さ

//入力(Tは情報のタイプ)
int N, K;
int T[MAX_K], X[MAX_K], Y[MAX_K];

void init(int n){
    for (int i = 0; i < n; i++){
        par[i] = i;
        rank[i] = 0;
    }
}

//木の根を求める
int find(int x){
    if (par[x] == x){
        return x;
    }else{
        return par[x] = find(par[x]);
    }
}

//xとyの属する集合を併合
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if (x==y) return;

    if (rank[x] < rank[y]){
        par[x] = y;
    }else{
        par[y] = x;
        if (rank[x] == rank[y]){
            rank[x]++;
        }
    }
}

//xとyが同じ集合に属するか否か
bool same(int x,int y){
    return find(x) == find(y);
}

void solve(){
    //Union-Find木の初期化
    //x.x+n.x+N*2をx-A,x-Bx-Cの要素とする
    init(N*3);
    
    int ans = 0;
    for (int i = 0; i < K; i++){
        int t = T[i];
        int x = X[i] -1;
        int y = Y[1] -1;

        //正しくない番号
        if (x<0||N<=x||y<0||N<=y){
            ans++;
            continue;
        }

        if (t == 1){
            //「xとyは同じ種類」という情報
            if (same(x,y+N)||same(x,y+2*N)){
                ans++;
            }else{
                unite(x,y);
                unite(x+N,y+N);
                unite(x+N*2,y+N*2);
            }
        }
        else{
            //「xはyを食べる」という情報
            if (same(x,y)||same(x,y+2*N)){
                ans++;
            }else{
                unite(x,y+N);
                unite(x+N,y+2*N);
                unite(x+N*2,y);
            }
        }
    }
    printf("%d\n",ans);
}

int main(){
    solve();
    return 0;
}