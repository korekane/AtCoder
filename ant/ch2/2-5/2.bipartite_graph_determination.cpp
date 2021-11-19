#include <cstdio>
#include <string.h>
#include <vector>
using namespace std;

#define MAX_V 100

//inout
vector<int> G[MAX_V];       //graph
int V = 4;                  //the number of vertex

int color[MAX_V];           //the color of vertex_i

//color the vertexes by -1 and 1
bool dfs(int v, int c){
    color[v] = c;
    for (int i = 0; i < G[v].size(); i++){
        //隣接している頂点が同じ色ならfalse
        if (color[G[v][i]] == c){
            return false;
            }
        //隣接している頂点が未着色なら-cで塗る
        if (color[G[v][i]] == 0 && !dfs(G[v][i], -c)){
            return false;
        }
    //全ての頂点が塗れたなら終了
    return true;
    }
}

void solve() {
    for (int i = 0; i < V; i++){
        if(color[i] == 0){
            //まだ頂点iが塗られていないならば1で塗る
            if(!dfs(i, 1)){
                printf("No\n");
                return;
            }
        }
    }
    printf("Yes\n");
}

int main(){
    solve();
    return 0;
}