#include <cstdio>
#include <string.h>
#include <vector>
using namespace std;

#define MAX_V 100

vector<int> G[MAX_V];
/*
    辺に属性がある場合
    struct edge(int to, const; );
    vector<edge> G[MAX_V]
*/

int main(){
    int V, E;
    printf("入力\n");
    scanf("%d %d", &V, &E);
    for (int i = 0; i < E; i++){
        //sからtへの辺をはる
        int s, t;
        scanf("%d %d", &s, &t);
        G[s].push_back(t);
        //G[t].push_back(s) : 無効グラフの場合は更にtにsの辺をはる
    }
    return 0;
}